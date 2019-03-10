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


		HWND ButtonFactory::createButton(HWND hWnd, long button_id)
		{
			return CreateWindow(
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
		}

	}
}
