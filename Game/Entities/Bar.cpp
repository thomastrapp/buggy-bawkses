#include "Game/Entities/Bar.h"

// solve circular dependencies
#include "Game/World.h"

namespace Game
{
namespace Entities
{

Bar::Bar(
  boost::shared_ptr<Game::Config> conf, 
  Game::World& game_world,
  const RectangleDef& rect_def
)
: Entity(Game::Entities::Id::BAR),
  physics(NULL),
  visible(rect_def.size)
{
  // setup the body
  {
    b2BodyDef barDef;
    barDef.type = b2_staticBody;
    barDef.position.Set(
      Game::Util::pixel_to_meter(rect_def.pos.x),
      Game::Util::pixel_to_meter(rect_def.pos.y)
    );
    
    this->physics = game_world.b2world()->CreateBody(&barDef);
  }
  
  {
    b2PolygonShape blockBox;
    blockBox.SetAsBox(
      Game::Util::pixel_to_meter(rect_def.size.x / 2.0f),
      Game::Util::pixel_to_meter(rect_def.size.y / 2.0f)
    );
    
    b2FixtureDef fixtureDef;
    fixtureDef.density = 0.0f;
    fixtureDef.shape = &blockBox;
    
    b2Fixture * barFixture = this->physics->CreateFixture(&fixtureDef);
    barFixture->SetUserData(Game::Entities::UserData::to_user_data(this));
  }
  
  {
    this->visible.setFillColor(sf::Color(255, 255, 0));
    this->visible.setOrigin(rect_def.size / 2.0f);
    this->visible.setPosition(rect_def.pos);
  }
}

void Bar::pre_solve_collision(
  b2Contact * contact, 
  const b2Manifold * /* old_manifold */
)
{
  if( contact->GetFixtureA()->GetUserData() == NULL || 
      contact->GetFixtureB()->GetUserData() == NULL    )
  {
    return;
  }

  b2Vec2 passer_position(0, 0);
  Game::Entity * passer = NULL;
  
  Game::Entity * entityA = Game::Entities::UserData::to_entity(
    contact->GetFixtureA()->GetUserData()
  );
  Game::Entity * entityB = Game::Entities::UserData::to_entity(
    contact->GetFixtureB()->GetUserData()
  );

  // Determine which Entity is the passing Entity
  if( entityA == this )
  {
    passer = entityB;
    passer_position = contact->GetFixtureB()->GetBody()->GetPosition();
  }
  else if( entityB == this )
  {
    passer = entityA;
    passer_position = contact->GetFixtureA()->GetBody()->GetPosition();
  }
  else
  {
    // If an Entity is notifed of a collision it must be a participant
    // "This shouldn't happen"
    BOOST_THROW_EXCEPTION(Game::Exception());
  }

  assert(passer != NULL);
  
  // Only allow Game::Entities::Player to pass
  if( passer->get_entity_id() == Game::Entities::Id::PLAYER )
  {
    // If the Player's center is positioned under the center of this bar
    // Allow imprecisions: 3.0f * b2_linearSlop
    if( passer_position.y >  
            this->physics->GetPosition().y - 3.0f * b2_linearSlop )
    {
      // Let the Player through this bar by disabling this collision
      contact->SetEnabled(false);
    }
  }
}

void Bar::render(sf::RenderTarget& renderer)
{
  renderer.draw(this->visible);
}


}
}

