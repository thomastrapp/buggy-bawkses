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
    BOOST_FOREACH(boost::shared_ptr<Game::Entity> entity, this->entities)
    {
      entity->render(renderer);
    }
  }
  
  void World::update()
  {
    BOOST_FOREACH(boost::shared_ptr<Game::Entity> entity, this->entities)
    {
      entity->update();
    }
  }

  void World::handle_input(const sf::Event &input)
  {
    BOOST_FOREACH(boost::shared_ptr<Game::Entity> entity, this->entities)
    {
      entity->handle_input(input);
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
      boost::shared_ptr<Game::Entity> ptr_left(
        new Game::Entities::WallLeft(this->config, *this)
      );
      this->entities.push_back(ptr_left);
    }
    
    // right wall
    {
      boost::shared_ptr<Game::Entity> ptr_right(
        new Game::Entities::WallRight(this->config, *this)
      );
      this->entities.push_back(ptr_right);
    }
    
    this->_setup_bars();
    
    // player
    {
      boost::shared_ptr<Game::Entity> ptr_player(
        new Game::Entities::Player(this->config, *this)
      );
      this->entities.push_back(ptr_player);
    }
  }
  
  void World::_setup_bars()
  {
    const int num_bars = 15;
    const float bar_spacing = this->config->get<float>("bar-spacing");
    const float bar_height = this->config->get<float>("bar-height");
    const float stage_width = 
      static_cast<float>(this->config->get<int>("window-width"));
    const float stage_height = 
      static_cast<float>(this->config->get<int>("window-height"));
    
    for(int i = 0; i < num_bars; ++i)
    {
      Game::Entities::RectangleDef rect_def(
        sf::Vector2f(
          stage_width,
          bar_height
        ),
        sf::Vector2f(
          stage_width / 2.0f,
          stage_height - static_cast<float>(i) * bar_spacing
        )
      );
      boost::shared_ptr<Game::Entity> ptr_bar(
        new Game::Entities::Bar(this->config, *this, rect_def)
      );
      this->entities.push_back(ptr_bar);
    }
  }
}
