#include "Armory.h"

Armory::~Armory()
{
	for (Weapon* weapon : m_Weapons)
		weapon = nullptr;
	// Only scene controlls enities memory
}

Armory::Armory(int size) : m_Size(size) {};

Armory::Armory(Weapon* weapon, int size) : Armory(size)
{
	m_Weapons[0] = weapon;
}

bool Armory::PushWeapon(Weapon* weapon)
{
	if (m_Size == m_Weapons.size())
		return false;
	int slot = 1;
	while (m_Size <= slot && m_Weapons[slot] != nullptr)
		slot++;
	if (m_Size <= slot) 
		return false;
	m_Weapons[slot] = weapon;
	return true;
}

Weapon* Armory::PopWeapon(int slot)
{
	if (m_Size <= slot || slot < 1)
		return nullptr;
	if (m_Weapons[slot] == nullptr)
		return nullptr;
	Weapon* tempWeapon = m_Weapons[slot];
	m_Weapons[slot] = nullptr;
	return tempWeapon;
}

Weapon* Armory::GetWeapon(int slot)
{
	if (m_Size <= slot || slot < 0)
		return nullptr;
	if (m_Weapons[slot] == nullptr)
		return nullptr;
	return m_Weapons[slot];
}

bool Armory::IsNotFull()
{
	for (int i = 0; i < m_Size; i++)
		if (m_Weapons[i] == nullptr)
			return true;
	return false;
}