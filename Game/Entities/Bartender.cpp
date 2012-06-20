#include "Game/Entities/Bartender.h"
#include "Game/Entities/Bar.h"

namespace Game
{
namespace Entities
{

Bartender::Bartender(
  boost::shared_ptr<Game::Config> conf, 
  Game::World& game_world
)
: Entity(Game::Entities::Id::BARTENDER),
  config(conf),
  world(game_world),
  bars(),
  next_bar_pos_y(0.0f),
  // Buddey bye bye bye I'm planting my seed
  rand_gen(static_cast<unsigned int>(std::time(NULL)))
{
}

void Bartender::render(sf::RenderTarget& renderer)
{
  BOOST_FOREACH(boost::shared_ptr<Game::Entities::Bar> bar, this->bars)
  {
    bar->render(renderer);
  }
}

void Bartender::update(const sf::View& view)
{
  this->_maybe_add_new_bars(view);
  this->_maybe_remove_old_bars(view);
}

void Bartender::_maybe_remove_old_bars(const sf::View& view)
{
  // We start at the oldest bar in our vector.
  // If we encounter a Bar that is visible we stop the loop.
  // There are Bars at the top of the view, that are invisible, but must not be
  // deleted.
  t_map_bars::iterator it = this->bars.begin();
  for(; it != this->bars.end(); ++it)
  {
    if( (*it)->is_in_view(view) == false )
    {
      #ifdef DEBUG
      std::cout << "Removing a bar" << std::endl;
      #endif
      this->bars.erase(it);
    }
    else
    {
      return;
    }
  }
}

void Bartender::_maybe_add_new_bars(const sf::View& view)
{
  // ++ START config options
  static const float bar_pre_fill = 
    this->config->get<float>("bar-pre-fill");

  static const float bar_spacing = 
    this->config->get<float>("bar-spacing");
  
  static const float bar_height = 
    this->config->get<float>("bar-height");
  
  static const float stage_width = 
    static_cast<float>(this->config->get<int>("window-width"));
  
  static const float bar_min_width = 
    this->config->get<float>("bar-min-width")
    * stage_width;

  static const float bar_max_width = 
    this->config->get<float>("bar-max-width")
    * stage_width;
  
  static const int new_level_offset = 
    this->config->get<int>("new-level-offset");
  // -- END config options
  
  // The top line of the view
  const float view_top = 
    view.getCenter().y - view.getSize().y / 2.0f;
  
  // The area we need to fill with bars
  const float fill_height = 
    this->next_bar_pos_y - view_top + bar_pre_fill;
  
  // The amount of bars we need to add
  const int add_bars_amount = 
    static_cast<int>(fill_height / bar_spacing);
  
  for(int i = 0; i < add_bars_amount; ++i)
  {
    float bar_pos_y = this->next_bar_pos_y;
    float bar_pos_x = 0;
    float bar_width = 0;
    
    // On the beginning of every level there's a bar that spans the 
    // whole screen
    if( static_cast<int>(bar_pos_y) % new_level_offset == 0 )
    {
      bar_pos_x = stage_width / 2.0f;
      bar_width = stage_width;
    }
    // Generate randomly sized and randomly placed bars
    else
    {
      // The Bar's size must be in range bar_min_width to bar_max_width
      boost::uniform_real<float> dist_size(bar_min_width, bar_max_width);
      bar_width = dist_size(this->rand_gen);
      
      // The whole bar needs to be visible on the screen
      const float bar_center = bar_width / 2.0f;
      boost::uniform_real<float> dist_pos(
        bar_center, 
        stage_width - bar_center
      );
      bar_pos_x = dist_pos(this->rand_gen);
    }
    
    const sf::Vector2f bar_size(
      bar_width,
      bar_height
    );
      
    const sf::Vector2f bar_position(
      bar_pos_x,
      bar_pos_y
    );
    
    const Game::Entities::RectangleDef rect_def(bar_size, bar_position);
    
    #ifdef DEBUG
    std::cout << "Inserting Bar at " 
              << bar_position.x 
              << ", " 
              << bar_position.y 
              << std::endl;
    #endif
    
    this->_insert_bar(rect_def);
    this->next_bar_pos_y = bar_pos_y - bar_spacing;
  }
}

void Bartender::_insert_bar(const Game::Entities::RectangleDef& rect_def)
{
  boost::shared_ptr<Game::Entities::Bar> ptr_bar(
    new Game::Entities::Bar(this->config, this->world, rect_def)
  );
  this->bars.push_back(ptr_bar);
}


}
}

