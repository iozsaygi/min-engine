#include <assert.h>
#include "box_collider_2D.h"

namespace min
{
	void BoxCollider2D::Birth()
	{
		assert( GetOwner() != nullptr );
		m_OwnerTransform		= GetOwner()->GetTransform();
		m_ColliderRectangle.w	= m_OwnerTransform->GetScale().GetX();
		m_ColliderRectangle.h	= m_OwnerTransform->GetScale().GetY();
	}

	void BoxCollider2D::OnTick( float deltaTime )
	{
		m_ColliderRectangle.x = m_OwnerTransform->GetPosition().GetX();
		m_ColliderRectangle.y = m_OwnerTransform->GetPosition().GetY();
	}

	SDL_Rect &BoxCollider2D::GetColliderRectangle()
	{
		return m_ColliderRectangle;
	}
}