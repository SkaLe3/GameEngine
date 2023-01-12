#include "Player.h"

bool Player::OnLeftMouseButtonPressed()
{
	Shoot();
	return true; // Temporary
}

bool Player::OnKeyRPressed()
{
	ReloadWeapon();
	return true; // Temporary
}