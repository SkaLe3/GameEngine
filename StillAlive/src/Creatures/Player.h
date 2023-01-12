#pragma once
#include "Creature.h"
class Player :
    public Creature
{
public:
	// Events
	bool OnLeftMouseButtonPressed();
	bool OnKeyRPressed();
};

