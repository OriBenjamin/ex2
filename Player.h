//
// Created by Ori Dekel and Liel Ferber 02/05/2022
//

#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

#define DEFAULT_FORCE 5
#define DEFAULT_MAX_HP 100

class Player 
{
    const char* name;
    int level;
    int coins;
    int maxHP;
    int hp;
    int force;

    public:
        Player(const char* name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE);
        
        Player(const Player&) = default;
        ~Player() = default;
        Player& operator=(const Player& other) = default;
        
        void printInfo();
        void levelUp();
        int getLevel();
        void buff(int buffAmount);
        void heal(int healAmount);
        void damage(int damageAmount);
        bool isKnockedOut();
        void addCoins(int coinsAmount);
        bool pay(int payAmount);
        int getAttackStrength();


};

#endif //PLAYER_H