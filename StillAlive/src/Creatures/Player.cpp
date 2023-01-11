#include "Player.h"

void Player::OnLeftMouseButtonPressed()
{
	Shoot();
}

void Player::OnKeyRPressed()
{
	ReloadWeapon();
}