#include "Global.h"

int trigger = 0;

float enemyShotTimer = 0.0f;
float enemyShotDelay = 2.0f;
int max_ammo = 10, ammo = 10;
int player_health = 10, enemy_health = 10;
int enemyspawnTimer = 0;
int maxCharHealth = 200;
int enemyHeathFull = 50;
int enemyMainHeathFull = 500;
int point = 0;
int update = 1;
int score_show = 0;

void reload()
{
	ammo = max_ammo;
}

void reset_game()
{
	enemyShotTimer = 0.0f;
	enemyShotDelay = 2.0f;
	ammo = 10;
	player_health = 10, enemy_health = 10;
	enemyspawnTimer = 0;
	maxCharHealth = 200;
	enemyHeathFull = 50;
	enemyMainHeathFull = 500;
	point = 0;
}
