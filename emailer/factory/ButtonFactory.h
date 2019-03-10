#pragma once

#include "../stdafx.h"

#include <memory>

#include "../resource.h"
#include "../component/ButtonComponent.h"

namespace em
{
	namespace factory
	{
		class ButtonFactory
		{
		public:
			ButtonFactory();
			virtual ~ButtonFactory();

			std::unique_ptr<ButtonComponent> createButton(const std::string id, const HWND hWnd, const long button_id);
		};

	}
}