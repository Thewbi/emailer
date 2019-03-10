#include "stdafx.h"
#include "ButtonFactory.h"

namespace em
{
	namespace factory
	{

		ButtonFactory::ButtonFactory()
		{
		}

		ButtonFactory::~ButtonFactory()
		{
		}

		std::unique_ptr<ButtonComponent> ButtonFactory::createButton(const std::string id, const HWND hWnd, const long button_id)
		{
			HWND buttonHWnd = CreateWindow(
				L"BUTTON",  // Predefined class; Unicode assumed 
				L"OK",      // Button text 
				WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
				10,         // x position 
				10,         // y position 
				100,        // Button width
				100,        // Button height
				hWnd,     // Parent window
				(HMENU)button_id,       // button id.
				(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
				NULL);      // Pointer not needed.

			return std::make_unique<ButtonComponent>(id, buttonHWnd);
		}

	}
}
