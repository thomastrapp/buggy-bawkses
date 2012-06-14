#include "Game/Entity.h"

namespace Game
{

Entity::Entity(Game::Entities::Id::t_entities_id id)
: entity_id(id)
{
}

Game::Entities::Id::t_entities_id Entity::get_entity_id() const
{
  return this->entity_id;
}

void Entity::sync_visible(const b2Body * source, sf::Transformable& target)
{
  if( source == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }
  
  // sync position
  {
    b2Vec2 b2_position = source->GetPosition();
    
    sf::Vector2f sf_position(
      Game::Util::meter_to_pixel(b2_position.x),
      Game::Util::meter_to_pixel(b2_position.y)
    );
    
    target.setPosition(sf_position);
  }
  
  // sync angle
  {
    target.setRotation(
      Game::Util::rad_to_deg(source->GetAngle())
    );
  }
}

}

