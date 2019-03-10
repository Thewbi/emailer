#pragma once

#include "../stdafx.h"

#include <iostream>
#include <vector>
#include <map>

#include "../resource.h"
#include "../component/BaseComponent.h"


LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
ATOM MyRegisterClass(HINSTANCE hInstance, WCHAR szWindowClass[100]);

// TODO: put this into its own namespace em::window::
//
/// https://stackoverflow.com/questions/117792/best-method-for-storing-this-pointer-for-use-in-wndproc
class Window :
	public BaseComponent
{
public:
	HINSTANCE hInstance_;
	std::vector<BaseComponent> childComponents_;
	std::map<int, std::unique_ptr<BaseComponent>> componentMap_;

public:
	Window(HINSTANCE hInstance);
	virtual ~Window();

	HINSTANCE get_hInstance() const { return hInstance_; }
};

