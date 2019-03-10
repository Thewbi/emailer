#pragma once

#include "BaseComponent.h"

class ButtonComponent :
	public BaseComponent
{
public:
	ButtonComponent();
	ButtonComponent(const std::string id, const HWND hwnd);
	virtual ~ButtonComponent();
};

