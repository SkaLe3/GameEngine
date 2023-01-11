#pragma once
#include "WeaponIntarface.h"
#include <Engine.h>

namespace Engine {
	class Entity{}; // Will be defined in Engine
}

class Glock17 : public Pistol, public Engine::Entity
{

};

class DesertEagle : public Pistol, public Engine::Entity
{

};

class MP5 : public SubMachineGun, public Engine::Entity
{

};

class UMP45 : public SubMachineGun, public Engine::Entity
{

};

class FNScar : public AssaultRifle, public Engine::Entity
{

};

class M4A1 : public AssaultRifle, public Engine::Entity
{

};

class AR15 : public AssaultRifle, public Engine::Entity
{

};

class BarretM82 : public SniperRifle, public Engine::Entity
{

};

class M24 : public SniperRifle, public Engine::Entity
{

};