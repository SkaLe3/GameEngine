#include "Creature.h"

bool Creature::SelectWeapon(int slot)
{
	if (m_Armory.GetWeapon(slot) == nullptr)
		return false;
	m_SelectedWeaponSlot = slot;
	return true;
}

Weapon* Creature::GetActiveWeapon()
{
	return m_Armory.GetWeapon(m_SelectedWeaponSlot);
}


Weapon* Creature::PickUpWeapon(Weapon* weapon)
{
	bool success = m_Armory.PushWeapon(weapon);
	if (success) return nullptr;
	Weapon* temp = m_Armory.PopWeapon(m_SelectedWeaponSlot);
	if (temp == nullptr) return temp;
	m_Armory.PushWeapon(weapon);
	return temp;
}

Weapon* Creature::DropWeapon()
{
	Weapon* temp = m_Armory.PopWeapon(m_SelectedWeaponSlot);
	if (temp != nullptr) m_SelectedWeaponSlot = 0;
	return temp;
}

void Creature::ReloadWeapon()
{
	Weapon* weapon = m_Armory.GetWeapon(m_SelectedWeaponSlot);
	weapon->Reload();
}

void Creature::Shoot()
{
	Weapon* weapon = m_Armory.GetWeapon(m_SelectedWeaponSlot);
	weapon->Fire();
}