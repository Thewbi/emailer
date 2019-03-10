#include "stdafx.h"
#include "BaseComponent.h"


BaseComponent::BaseComponent() : hWnd_(NULL)
{
}

BaseComponent::BaseComponent(const std::string id, const HWND hWnd) : id_(id), hWnd_(hWnd)
{
}

BaseComponent::~BaseComponent()
{
	std::cout << id_ << std::endl;

	if (hWnd_)
	{
		::DestroyWindow(hWnd_);
		hWnd_ = NULL;
	}
}

void BaseComponent::handleEvent()
{
	// TODO: add own high level messaging/eventing infrastructure like Qt. 
	// Send message so everybody can consume them.
	//
	// This is where the Win32 event loop is handed over to the 
	// custom messaging/eventing infrastructure
	std::cout << "clickediclick" << std::endl;
}
