#include "Game/World.h"

// Solve circular dependencies
#include "Game/Entity.h"
#include "Game/Entities/Stage.h"
#include "Game/Entities/Player.h"

namespace Game
{
  World::World(boost::shared_ptr<Game::Config> conf)
  : b2_world(new b2World(b2Vec2(
      conf->get<float>("gravity-x"), 
      conf->get<float>("gravity-y")
    ))),
    config(conf),
    entities()
  {
    this->b2_world->SetAllowSleeping(true);
    this->_setup_stage();
  }
  
  void World::step_default()
  {
    this->b2_world->Step(
      this->config->get<float>("timestep"), 
      this->config->get<int>("velocity-iterations"), 
      this->config->get<int>("position-iterations")
    );
  }

  void World::render(Game::Window& window)
  {
    window.clear();
    
    /// TODO: Move _update_entities to own method ::update()
    this->_update_entities();
    this->_render_entities(window);
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
  
  void World::_setup_stage()
  {
    // bounds (left, bottom, right)
    {
      boost::shared_ptr<Game::Entity> ptr_stage(
        new Game::Entities::Stage(this->config, *this)
      );
      this->entities.push_back(ptr_stage);
    }
    
    // player
    {
      boost::shared_ptr<Game::Entity> ptr_player(
        new Game::Entities::Player(this->config, *this)
      );
      this->entities.push_back(ptr_player);
    }
  }

  void World::_update_entities()
  {
    BOOST_FOREACH(boost::shared_ptr<Game::Entity> entity, this->entities)
    {
      entity->update();
    }
  }
  
  void World::_render_entities(sf::RenderTarget &renderer)
  {
    BOOST_FOREACH(boost::shared_ptr<Game::Entity> entity, this->entities)
    {
      entity->render(renderer);
    }
  }
}
