//
// Created by Ori Dekel and Liel Ferber 02/05/2022
//

#include "Player.h"
#include "utilities.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
 
Player::Player(char* name, int maxHP = DEFAULT_MAX_HP, int force = DEFAULT_FORCE)
{
    this->name = name;
    this->level = 1;
    this->coins = 0;
    this->force = force;
    this->maxHP = maxHP;
    if(this->maxHP<0)
    {
        this->maxHP = DEFAULT_MAX_HP;
    }
    this->hp = maxHP;
    if(this->force<0)
    {
        this->force = DEFAULT_FORCE;
    }
}

void Player::printInfo()
{
    printPlayerInfo(this->name,this->level,this->force,this->hp,this->coins);
}

void Player::levelUp()
{
    if(this->player < 10)
    {
        this->level++;
    }
}

int Player::getLevel()
{
    return this->level;   
}

void Player::buff(int buffAmount)
{
    if(buffAmount>0)
    {
        this->force += buffAmount;   
    }
}

void Player::heal(int healAmount) 
{
    if(healAmount>0)
    {
        this->hp += healAmount;   
        if(this->hp > this->maxHP)
        {
            this->hp = this->maxHP;
        }
    }
}

void Player::damage(int damageAmount)
{
    if(damage>0)
    {
        this->hp -= damageAmount;   
        if(this->hp < 0)
        {
            this->hp = 0;
        }
    }
}

bool Player::isKnockedOut()
{
    return (this->hp == 0);
}

void Player::addCoins(int coinsAmount) 
{
    if(coinsAmount>0)
    {
        this->coins += coinsAmount; 
    }  
}

bool Player::pay(int payAmount)
{
    
    if(payAmount < 0 ||this->coins < payAmount)
    {
        return false;
    }  
    this->coins -= payAmount;
    return true;
}

int Player::getAttackStrength()
{
    return this->force + this->level;
}
