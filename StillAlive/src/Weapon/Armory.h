#pragma once
#include "Weapon/WeaponIntarface.h"

#include <vector>
class Armory
{
public:
	Armory(int size);
	Armory(Weapon* weapon, int size = 1);
	~Armory(); // May be changed in future
	bool PushWeapon(Weapon* weapon);
	Weapon* PopWeapon(int slot);
	Weapon* GetWeapon(int slot);
	bool IsNotFull();

	std::vector<Weapon*>::iterator begin() { return m_Weapons.begin(); }
	std::vector<Weapon*>::iterator end() { return m_Weapons.end(); }
private:
	int m_Size;
	std::vector<Weapon*> m_Weapons;
};

