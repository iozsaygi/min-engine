#include "keycode.h"

namespace min
{
	bool KeyCode::GetIsKeyDown()
	{
		return m_IsKeyDown;
	}

	void KeyCode::UpdateIsKeyDown( bool keyDownStatus )
	{
		m_IsKeyDown = keyDownStatus;
	}
}