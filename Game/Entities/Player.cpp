/*
  This file is part of the "Buggy Bawkses" Project.

  Copyright (C) 2012 Thomas Trapp; mailto: bawkses@thomastrapp.com

  "Buggy Bawkses" is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, 
  Boston, MA  02110-1301, USA.

  See COPYING for details.
*/

#include "Game/Entities/Player.h"

namespace Game
{
  namespace Entities
  {
  
Player::Player(boost::shared_ptr<Game::Config> conf, Game::World& game_world)
: Entity(Game::Entities::Id::PLAYER),
  config(conf),
  physics(NULL),
  visible(),
  foot(),
  current_move_state(MOVEMENT_STOPPED),
  height(
    Game::Util::pixel_to_meter(conf->get<float>("player-height"))
  )
{
  // setup the player
  {
    const sf::Vector2f stage_size(
      static_cast<float>(conf->get<int>("window-width")),
      static_cast<float>(conf->get<int>("window-height"))
    );
    sf::Vector2f box_center_coord(stage_size.x / 2.0f, -100.0f);
    b2BodyDef playerDef;
    playerDef.type = b2_dynamicBody;
    // disable rotation, player shall always be upright
    playerDef.fixedRotation = true;
    playerDef.position.Set(
      Game::Util::pixel_to_meter(box_center_coord.x),
      Game::Util::pixel_to_meter(box_center_coord.y)
    );
    
    this->physics = game_world.b2world()->CreateBody(&playerDef);
  }
  
  sf::Vector2f player_size(
    conf->get<float>("player-width"),
    conf->get<float>("player-height")
  );
  
  /**
   * To easily detect Player collision with "grounds" we set up a foot, that
   * does not participate in the physics simulation, but is subject to 
   * collisions.
   * 
   * We pass a pointer to this Foot to the user data of the fixture, to 
   * instruct the CollisionDispatcher to notify us if we collide with 
   * anything.
   *
   * We therefore can later determine whether the Player is in air or on solid
   * ground ("Can the player jump?").
   */
  this->foot.bind_to_body(this->physics, player_size);
  
  // setup the player's appearance in the physics simulation
  {
    b2PolygonShape playerBox;
    playerBox.SetAsBox(
      Game::Util::pixel_to_meter(player_size.x),
      Game::Util::pixel_to_meter(player_size.y)
    );
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &playerBox;
    fixtureDef.density = conf->get<float>("player-density");
    fixtureDef.friction = conf->get<float>("player-friction");
    b2Fixture * fixture = this->physics->CreateFixture(&fixtureDef);
    fixture->SetUserData(Game::Entities::UserData::to_user_data(this));
  }
  
  // visible (sfml shape that gets rendered on screen)
  {
    this->visible.setFillColor(sf::Color(255, 68, 0));
    // sfml wants the size in total width/height
    this->visible.setSize(player_size * 2.0f);
    // set sfml origin to the center of the shape (just like in box2d)
    this->visible.setOrigin(player_size);
  }
}

Player::~Player()
{
  this->physics->GetWorld()->DestroyBody(this->physics);
}

void Player::handle_input(const sf::Event& input)
{
  if( input.type == sf::Event::KeyPressed )
  {
    this->_handle_key_press(input);
  }
  else if( input.type == sf::Event::KeyReleased )
  {
    this->_handle_key_release(input);
  }
}

void Player::render(sf::RenderTarget& renderer)
{
  renderer.draw(this->visible);
}

State::t_entities_state Player::update(const sf::View& view)
{
  this->_handle_movement();
  this->sync_visible(this->physics, this->visible);
  
  if( this->_is_in_view(view) )
  {
    return State::NONE;
  }
  else
  {
    return State::PLAYER_DEAD;
  }
}

void Player::_handle_movement()
{
  static const float player_top_speed = 
    this->config->get<float>("player-top-speed");
  
  b2Vec2 current_velocity = this->physics->GetLinearVelocity();
  float to_velocity = current_velocity.x;

  switch(this->current_move_state)
  {
    case MOVEMENT_LEFT:
    {
      to_velocity = b2Max(current_velocity.x - 0.3f, -1 * player_top_speed);
      break;
    }
    case MOVEMENT_STOPPED:
    {
      if( current_velocity.x > 0 )
      {
        to_velocity = b2Max(current_velocity.x - 0.4f, 0.0f);
      }
      else
      {
        to_velocity = b2Min(current_velocity.x + 0.4f, 0.0f);
      }
      break;
    }
    case MOVEMENT_RIGHT:
    {
      to_velocity = b2Min(current_velocity.x + 0.3f, player_top_speed);
      break;
    }
    default:
    {
      return;
      break;
    }
  }
  
  const float velocity_delta = to_velocity - current_velocity.x;
  const float impulse = this->physics->GetMass() * velocity_delta;
  
  this->physics->ApplyLinearImpulse(
    b2Vec2(impulse, 0), 
    this->physics->GetWorldCenter()
  );
}

void Player::_handle_key_press(const sf::Event& input)
{
  switch(input.key.code)
  {
    case sf::Keyboard::Up:
    {
      if( this->foot.is_on_ground() )
      {
        // Fixme: This should be a move state
        this->physics->ApplyLinearImpulse(
          b2Vec2(0.0f, -0.5f), this->physics->GetPosition()
        );
      }
      break;
    }
    case sf::Keyboard::Right:
    {
      this->current_move_state = MOVEMENT_RIGHT;
      break;
    }
    case sf::Keyboard::Left:
    {
      this->current_move_state = MOVEMENT_LEFT;
      break;
    }
    default:
    {
      break;
    }
  }
}

void Player::_handle_key_release(const sf::Event& input)
{
  switch(input.key.code)
  {
    case sf::Keyboard::Right:
    case sf::Keyboard::Left:
    {
      this->current_move_state = MOVEMENT_STOPPED;
      break;
    }
    default:
    {
      break;
    }
  }
}

bool Player::_is_in_view(const sf::View& view)
{
  const float player_top = 
    this->physics->GetPosition().y - this->height / 2.0f;
  const float view_bottom = Game::Util::pixel_to_meter(
    view.getCenter().y + view.getSize().y / 2.0f
  );
  
  return ( player_top < view_bottom );
}


}
}
