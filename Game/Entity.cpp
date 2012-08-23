/*
  This file is part of the "Buggy Bawkses" Project.

  Copyright (C) 2012 Thomas Trapp; mailto: bawkses@thomastrapp.com

  "Buggy Bawkses" is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, 
  Boston, MA  02110-1301, USA.

  See COPYING for details.
*/

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

