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

  // Append a square to the bottom of a body.
  // Length of the square is half the body's width.
  // The center of the square is placed on the center of the bottom line of 
  // the body.
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
  
  // Tell Box2D that this fixture is just a sensor, meaning it will not 
  // participate in the physics simulation, but will get notified of
  // collisions.
  footFixtureDef.isSensor = true;
  
  b2Fixture * footSensorFixture = 
    body->CreateFixture(&footFixtureDef);
  
  // We store a pointer to this Entity in the fixture, to let the 
  // CollisionDispatcher be able to notify us
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
