#pragma once
#include "Creature.h"
class Player :
    public Creature
{
public:
	// Events
	void OnLeftMouseButtonPressed();
	void OnKeyRPressed();
};

