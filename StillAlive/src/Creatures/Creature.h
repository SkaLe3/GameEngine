#pragma once

#include "Weapon/Armory.h"


class Creature // : public Engine::Entity
{
public:
	Creature(int health, int velocity, Weapon* weapon, int armSize)
		: m_Health(health), m_Velocity(velocity),
		m_SelectedWeaponSlot(0),m_Armory(weapon, armSize) {};

	bool SelectWeapon(int slot);
	Weapon* GetActiveWeapon();
	Weapon* PickUpWeapon(Weapon* weapon);
	Weapon* DropWeapon();

	void ReloadWeapon();
	void Shoot();
public:

private:
	int m_Health;
	int m_Velocity;

	int m_SelectedWeaponSlot;
	Armory m_Armory;

};