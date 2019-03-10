#pragma once

#include "../stdafx.h"

#include <iostream>

#include "../resource.h"


LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
ATOM MyRegisterClass(HINSTANCE hInstance, WCHAR szWindowClass[100]);

// TODO: put this into its own namespace em::window::
//
/// https://stackoverflow.com/questions/117792/best-method-for-storing-this-pointer-for-use-in-wndproc
class Window
{
private:
	HINSTANCE hInstance;
	HWND hWnd;

public:
	Window(HINSTANCE hInstance);
	virtual ~Window();
	void lol();

	HINSTANCE get_hInstance() const { return hInstance; }
	HWND get_hWnd() const { return hWnd; }
};

