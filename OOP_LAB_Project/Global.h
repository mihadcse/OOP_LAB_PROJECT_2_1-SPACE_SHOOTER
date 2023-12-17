#pragma once
#include<vector>

using namespace std;

extern int trigger; // declare global variable

extern float enemyShotTimer;
extern float enemyShotDelay;
extern int max_ammo, ammo;
extern int player_health, enemy_health;
extern int enemyspawnTimer;
extern int maxCharHealth;
extern int enemyHeathFull;
extern int enemyMainHeathFull;
extern int point;
extern int update;
extern int score_show;

extern void reload();
extern void reset_game();
