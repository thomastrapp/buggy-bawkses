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
  config(conf),
  physics(NULL),
  visible(rect_def.size),
  height(
    Game::Util::pixel_to_meter(rect_def.size.y)
  )
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

Bar::~Bar()
{
  this->physics->GetWorld()->DestroyBody(this->physics);
}

void Bar::pre_solve_collision(
  b2Contact * contact, 
  const b2Manifold * /* old_manifold */
)
{
  static const float player_height = Game::Util::pixel_to_meter(
    this->config->get<float>("player-height")
  );
  
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
    const float passer_bottom = passer_position.y + player_height / 2.0f;
    const float bar_top       = this->physics->GetPosition().y - this->height;
    
    // be a little fuzzy
    const float padding = 3.0f * b2_linearSlop;
    
    // If the passer is completely over the bar
    if( passer_bottom > bar_top - padding )
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

bool Bar::is_in_view(const sf::View& view)
{
  const float bar_top = this->physics->GetPosition().y - this->height / 2.0f;
  const float view_bottom = Game::Util::pixel_to_meter(
    view.getCenter().y + view.getSize().y / 2.0f
  );
  
  return ( bar_top < view_bottom );
}


}
}

