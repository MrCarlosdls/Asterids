#pragma once
#define KEYCOUNT 256
#define _KEY_INVALID -2

namespace Engine
{
	namespace Input
	{
		class InputManager
		{
		public:

			static void Create();
			static void Destroy();
			static InputManager& Instance();

			bool IsKeyDown(unsigned char key);
			bool IsKeyPressed(unsigned char key);
			bool IsKeyReleased(unsigned char key) const;
			void KeyDown(unsigned char key);
			void KeyUp(unsigned char key);
			void ResetInput();
			void Update();

			bool IsAnyKeyPressed() const { return m_isKeyPressed; }

			void SetKeyPressed(bool isKeyPressed) { m_isKeyPressed = isKeyPressed; }

		private:
		
			InputManager();
			InputManager(InputManager const&) : m_isKeyPressed(false) {}

			InputManager& operator=(InputManager const&) {};

			bool m_currentKeys[KEYCOUNT];
			bool m_previousKeys[KEYCOUNT];
			bool m_isKeyPressed;
			static InputManager* s_instance;
		};
	}
}

extern void OnKeyboardDownEvent(unsigned char key);
extern void OnKeyboardReleasedEvent(unsigned char key);
extern void KeyboardPollEvent();