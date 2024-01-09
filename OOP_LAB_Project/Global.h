#pragma once
#include<vector>
#include<string>

using namespace std;

extern int trigger; // declare global variable

extern float enemyShotTimer;
extern float enemyShotDelay;
extern int max_ammo, ammo;
extern int power;
extern int player_health, enemy_health;
extern int enemyspawnTimer;
extern int maxCharHealth;
extern int enemyHeathFull;
extern int enemyMainHeathFull;
extern int point;
extern int update;
extern int score_show;
extern int reset;
extern int level;
extern int new_game_start;

extern string playername;
extern string playername_file;

extern void reload();
extern void reset_game();


//template <class Type>
//class Global
//{
//public:
//	extern Type trigger;
//	extern Type enemyShotTimer;
//	extern Type enemyShotDelay;
//	extern Type max_ammo, ammo;
//	extern Type power;
//	extern Type player_health, enemy_health;
//	extern Type enemyspawnTimer;
//	extern Type maxCharHealth;
//	extern Type enemyHeathFull;
//	extern Type enemyMainHeathFull;
//	extern Type point;
//	extern Type update;
//	extern Type score_show;
//	extern Type reset;
//	extern Type level;
//};
