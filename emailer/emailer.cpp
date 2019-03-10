// WindowsProject1.cpp : Definiert den Einstiegspunkt für die Anwendung.
//

#include "stdafx.h"

#include <map>

#include "emailer.h"
#include "window/Window.h"
#include "factory/ButtonFactory.h"
#include "component/ButtonComponent.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	Window window(hInstance);

	// TODO: can this be static?
	em::factory::ButtonFactory buttonFactory;

	// TODO: window manager (linear-vertical, linear-horizontal, border, ...)
	//
	// TODO: Call DestroyWindow on the HWND
	// Therefore build a tree of components on the stack
	// Once the tree goes out of scope, all its nodes will call their destructors
	// The destructors will call DestroyWindow on their components.
	//
	// TODO: devise a way so that when the button is clicked, a button class method gets called
	//
	// map button id to the Buttoncomponent
	//
	// TODO: Make the factory return that button class instead of just a HWND.
	std::unique_ptr<ButtonComponent> buttonPtr = buttonFactory.createButton("btn_close", window.hWnd_, IDB_TEST);

	window.componentMap_.insert(std::make_pair(IDB_TEST, std::move(buttonPtr)));

	//window.childComponents_.push_back(button);

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EMAILER));
	MSG msg;

	// Hauptnachrichtenschleife:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}