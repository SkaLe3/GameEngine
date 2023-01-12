#pragma once

enum class FIRE_MODE
{
	AUTO, SINGLE, BURST
};
class Weapon
{
	Weapon() = delete;
public:
	virtual ~Weapon() = default;
	virtual void Fire() = 0;
	virtual void Reload() = 0;
protected:
	FIRE_MODE m_FiringMode;
	double m_Damage;
	double m_FireRate;
	double m_Accuracy;
	int m_MagazineCapacity;
	int	m_MaxAmmo;
	double m_ReloadTime;

};	


class Pistol : public Weapon
{

};

class SubMachineGun : public Weapon
{

};

class AssaultRifle : public Weapon
{

};

class SniperRifle : public Weapon
{

};

class SpecialWeapon : public Weapon
{

};