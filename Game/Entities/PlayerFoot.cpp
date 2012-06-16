#include "Game/Entities/PlayerFoot.h"

namespace Game
{
namespace Entities
{

PlayerFoot::PlayerFoot()
: Entity(Game::Entities::Id::PLAYER_FOOT),
  foot_contacts(0)
{
}

void PlayerFoot::bind_to_body(
  b2Body * body, 
  const sf::Vector2f body_size
)
{
  if( body == NULL )
  {
    BOOST_THROW_EXCEPTION(Game::Exception());
  }

  b2PolygonShape footShape;
  footShape.SetAsBox(
    Game::Util::pixel_to_meter(body_size.x) / 2.0f,
    Game::Util::pixel_to_meter(body_size.x) / 2.0f,
    b2Vec2(
      0.0f,
      Game::Util::pixel_to_meter(body_size.y)
    ),
    0.0f
  );
  
  b2FixtureDef footFixtureDef;
  footFixtureDef.shape = &footShape;
  footFixtureDef.isSensor = true;
  
  b2Fixture * footSensorFixture = 
    body->CreateFixture(&footFixtureDef);
  
  // We pass a pointer to this Entity, to instruct the CollisionDispatcher 
  // to notify us if we collide with anything
  footSensorFixture->SetUserData(
    Game::Entities::UserData::to_user_data(this)
  );
}

void PlayerFoot::begin_collision(b2Contact * /* contact */)
{
  ++this->foot_contacts;
}

void PlayerFoot::end_collision(b2Contact * /* contact */)
{
  --this->foot_contacts;
}

bool PlayerFoot::is_on_ground()
{
  return ( this->foot_contacts > 0 );
}

}
}
