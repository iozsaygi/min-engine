#ifndef KEYCODE_H
#define KEYCODE_H

namespace min
{
	struct KeyCode
	{
	public:
		bool GetIsKeyDown();
		void UpdateIsKeyDown( bool keyDownStatus );

	private:
		bool m_IsKeyDown = false;
	};
}

#endif // !KEYCODE_H