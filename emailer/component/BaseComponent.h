#pragma once

#include <string>
#include <iostream>

class BaseComponent
{
public:
	HWND hWnd_;
	std::string id_;

public:
	BaseComponent();
	BaseComponent(const std::string id, const HWND hWnd);
	virtual ~BaseComponent();

	virtual void handleEvent();
};

