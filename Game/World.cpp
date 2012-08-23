#include "Game/World.h"

// Solve circular dependencies
#include "Game/Entity.h"
#include "Game/Entities/Player.h"
#include "Game/Entities/WallLeft.h"
#include "Game/Entities/WallRight.h"

namespace Game
{
  World::World(boost::shared_ptr<Game::Config> conf)
  : b2_world(new b2World(b2Vec2(
      conf->get<float>("gravity-x"), 
      conf->get<float>("gravity-y")
    ))),
    config(conf),
    entities(),
    cdispatcher()
  {
    this->b2_world->SetAllowSleeping(conf->get<bool>("allow-sleeping"));
    this->b2_world->SetContactListener(&(this->cdispatcher));
    this->_setup_entities();
  }
  
  void World::step()
  {
    static const float timestep = 
      this->config->get<float>("timestep");
    static const int velocity_iterations = 
      this->config->get<int>("velocity-iterations");
    static const int position_iterations = 
      this->config->get<int>("position-iterations");
    
    this->b2_world->Step(
      timestep,
      velocity_iterations,
      position_iterations
    );
    
    this->b2_world->ClearForces();
  }

  void World::render(sf::RenderTarget& renderer)
  {
    BOOST_FOREACH(t_entities::value_type entity, this->entities)
    {
      (entity.second)->render(renderer);
    }
  }
  
  Entities::State::state_mask World::update(const sf::View& view)
  {
    Entities::State::state_mask total_entity_state = 0;
    
    BOOST_FOREACH(t_entities::value_type entity, this->entities)
    {
      total_entity_state |= (entity.second)->update(view);
    }
    
    return total_entity_state;
  }

  void World::handle_input(const sf::Event &input)
  {
    BOOST_FOREACH(t_entities::value_type entity, this->entities)
    {
      (entity.second)->handle_input(input);
    }
  }
  
  boost::shared_ptr<b2World> World::b2world() const
  {
    return this->b2_world;
  }
  
  void World::_setup_entities()
  {
    // left wall
    {
      boost::shared_ptr<Game::Entity> wall_left(
        new Game::Entities::WallLeft(this->config, *this)
      );
      this->entities.insert(
        t_entities::value_type(
          wall_left->get_entity_id(),
          wall_left
        )
      );
    }
    
    // right wall
    {
      boost::shared_ptr<Game::Entity> wall_right(
        new Game::Entities::WallRight(this->config, *this)
      );
      this->entities.insert(
        t_entities::value_type(
          wall_right->get_entity_id(),
          wall_right
        )
      );
    }
    
    // player
    {
      boost::shared_ptr<Game::Entities::Player> player(
        new Game::Entities::Player(this->config, *this)
      );
      this->entities.insert(
        t_entities::value_type(
          player->get_entity_id(),
          player
        )
      );
    }
    
    // bars
    {
      boost::shared_ptr<Game::Entity> bartender(
        new Game::Entities::Bartender(this->config, *this)
      );
      this->entities.insert(
        t_entities::value_type(
          bartender->get_entity_id(),
          bartender
        )
      );
    }
  }
}
