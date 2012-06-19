#include "Game/Entities/FootSensor.h"

namespace Game
{
namespace Entities
{

FootSensor::FootSensor()
: Entity(Game::Entities::Id::FOOT_SENSOR),
  contacts(0)
{
}

void FootSensor::bind_to_body(
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

void FootSensor::begin_collision(b2Contact * /* contact */)
{
  ++this->contacts;
}

void FootSensor::end_collision(b2Contact * /* contact */)
{
  --this->contacts;
}

bool FootSensor::is_on_ground()
{
  return ( this->contacts > 0 );
}

}
}
