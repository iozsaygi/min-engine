#include <assert.h>
#include "actor.h"
#include <SDL.h>

namespace min
{
	Actor::Actor( const std::string &name )
	{
		m_Components   = std::vector<Component *>();
		m_ComponentMap = std::map<const std::type_info *, Component *>();
		m_Name         = name;
		m_IsActive     = true;
		m_Transform    = new Transform( this, Vector2D::Zero(), Vector2D::One() );

		AddComponent( m_Transform );
	}

	Actor::~Actor()
	{
		for ( auto component : m_Components )
			delete component;

		m_Components.clear();
		m_ComponentMap.clear();
	}

	void Actor::AddComponent( Component *component )
	{
		assert( component != nullptr );
		m_Components.push_back( component );
		m_ComponentMap[ &typeid( *component ) ] = component;
	}

	std::vector<Component *> Actor::GetComponents()
	{
		return m_Components;
	}

	World *Actor::GetOwnerWorld()
	{
		return m_OwnerWorld;
	}

	void Actor::SetOwnerWorld( World *world )
	{
		assert( world != nullptr );
		m_OwnerWorld = world;
	}

	std::string &Actor::GetName()
	{
		return m_Name;
	}

	bool Actor::GetIsActive()
	{
		return m_IsActive;
	}

	void Actor::SetIsActive( bool isActive )
	{
		m_IsActive = isActive;

		if ( isActive )
		{
			for ( Component *component : m_Components )
				component->OnEnable();
		}
		else
		{
			for ( Component *component : m_Components )
				component->OnDisable();
		}
	}

	Transform *Actor::GetTransform()
	{
		return m_Transform;
	}
}