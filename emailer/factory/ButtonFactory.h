#pragma once

#include "../stdafx.h"
#include "../resource.h"

namespace em
{
	namespace factory
	{
		class ButtonFactory
		{
		public:
			ButtonFactory();
			virtual ~ButtonFactory();

			HWND createButton(HWND hWnd, long button_id);
		};

	}
}