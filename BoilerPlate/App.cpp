#include "App.hpp"
#include <iostream>
#include <algorithm>
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>
#include <fstream>
#include <sstream>
#include <string>
//#include "irrKlang.h"
#include "config.h"
#include "manager.h" 

using namespace std;

namespace Application
{
	const float DESIRED_FRAME_RATE = 60.0f;
	const float DESIRED_FRAME_TIME = 1.0f / DESIRED_FRAME_RATE;

	App::App(const string& title, const int width, const int height)
		: m_title(title)
		, m_width(width)
		, m_height(height)
		, m_nUpdates(0)
		, m_timer(new Engine::TimeManager)
		, m_mainWindow(nullptr)
		, m_game(nullptr)
		, m_context(nullptr)
		, m_deltaTime(0.0f)
	{
		m_state = AppState::UNINITIALIZED;
		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();
		m_deltaTime = static_cast<double>(DESIRED_FRAME_TIME);
		m_game = new Asteroids::Game(width, height);
	}


	App::~App()
	{
		delete m_game;
		m_timer->Stop();
		delete m_timer;
		Engine::Input::InputManager::Instance().Destroy();

		CleanupSDL();
	}

	void App::Execute()
	{
		if (m_state != AppState::INIT_SUCCESSFUL)
		{
			cerr << "Game INIT was not successful." << endl;
			return;
		}

		m_state = AppState::RUNNING;
		//PlaySound(TEXT("text.wav"), NULL, SND_SYNC);
		SDL_Event event;
		while (m_state == AppState::RUNNING)
		{
			// Input polling
			//
			while (SDL_PollEvent(&event))
			{
				OnEvent(&event);
			}

			//
			Update();
			Render();

			KeyboardPollEvent();
		}
	}

	bool App::Init()
	{
		// Init the external dependencies
		//
		bool success = SDLInit() && GlewInit();
		if (!success)
		{
			m_state = AppState::INIT_FAILED;
			return false;
		}

		// Setup the viewport
		//
		SetupViewport();

		// Change game state
		//
		m_state = AppState::INIT_SUCCESSFUL;

		//Addin sound

		m_game->Init();

		return true;
	}

	void App::OnKeyDown(SDL_KeyboardEvent keyBoardEvent)
	{
		OnKeyboardDownEvent(keyBoardEvent.keysym.sym);
	}

	void App::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
	{
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_ESCAPE:
			OnExit();
			break;
		default:
			OnKeyboardReleasedEvent(keyBoardEvent.keysym.sym);
			break;
		}
	}

	void App::Update()
	{
		double startTime = m_timer->GetElapsedTimeInSeconds();
		m_game->Update(m_deltaTime);

		double endTime = m_timer->GetElapsedTimeInSeconds();
		double nextTimeFrame = startTime + DESIRED_FRAME_TIME;

		while (endTime < nextTimeFrame)
		{
			endTime = m_timer->GetElapsedTimeInSeconds();
		}

		//double elapsedTime = endTime - startTime;        
		m_deltaTime = endTime - startTime;
		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();
		m_nUpdates++;
	}

	void App::Render() const
	{
		m_game->Render();

		SDL_GL_SwapWindow(m_mainWindow);
	}

	bool App::SDLInit()
	{
		// Initialize SDL's Video subsystem
		//
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			cerr << "Failed to init SDL" << endl;
			return false;
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		Uint32 flags = SDL_WINDOW_OPENGL |
			SDL_WINDOW_SHOWN |
			SDL_WINDOW_RESIZABLE;

		m_mainWindow = SDL_CreateWindow(
			m_title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			m_width,
			m_height,
			flags
		);

		if (!m_mainWindow)
		{
			cerr << "Failed to create window!" << endl;
			SDL_Quit();
			return false;
		}

		m_context = SDL_GL_CreateContext(m_mainWindow);
		SDL_GL_MakeCurrent(m_mainWindow, m_context);

		// Make double buffer interval synced with vertical scanline refresh
		SDL_GL_SetSwapInterval(0);

		return true;
	}

	void App::SetupViewport() const
	{
		// Defining ortho values
		//
		float halfWidth = m_width * 0.5f;
		float halfHeight = m_height * 0.5f;

		// Set viewport to match window
		//
		glViewport(0, 0, m_width, m_height);

		// Set Mode to GL_PROJECTION
		//
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// Set projection MATRIX to ORTHO
		//
		glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1, 1);

		// Setting Mode to GL_MODELVIEW
		//
		glMatrixMode(GL_MODELVIEW);
	}

	bool App::GlewInit()
	{
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			cerr << "Error: " << glewGetErrorString(err) << endl;
			return false;
		}

		return true;
	}

	void App::CleanupSDL() const
	{
		// Cleanup
		//

		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_mainWindow);

		SDL_Quit();
	}

	void App::OnResize(int width, int height)
	{
		m_width = width;
		m_height = height;

		SetupViewport();
	}

	void App::OnExit()
	{
		m_state = AppState::QUIT;

	}
}

