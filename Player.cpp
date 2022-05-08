//
// Created by Ori Dekel and Liel Ferber 02/05/2022
//

#include "Player.h"
#include "utilities.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
 
Player::Player(const char* name, int maxHP, int force)
{
    this->m_name = name;
    this->m_level = 1;
    this->m_coins = 0;
    this->m_force = force;
    this->m_maxHP = maxHP;
    if(this->m_maxHP<0)
    {
        this->m_maxHP = DEFAULT_MAX_HP;
    }
    this->m_hp = maxHP;
    if(this->m_force<0)
    {
        this->m_force = DEFAULT_FORCE;
    }
}

void Player::printInfo()
{
    printPlayerInfo(this->m_name,this->m_level,this->m_force,this->m_hp,this->m_coins);
}

void Player::levelUp()
{
    if(this->m_level < 10)
    {
        this->m_level++;
    }
}

int Player::getLevel()
{
    return this->m_level;   
}

void Player::buff(int buffAmount)
{
    if(buffAmount>0)
    {
        this->m_force += buffAmount;   
    }
}

void Player::heal(int healAmount) 
{
    if(healAmount>0)
    {
        this->m_hp += healAmount;   
        if(this->m_hp > this->m_maxHP)
        {
            this->m_hp = this->m_maxHP;
        }
    }
}

void Player::damage(int damageAmount)
{
    if(damageAmount>0)
    {
        this->m_hp -= damageAmount;   
        if(this->m_hp < 0)
        {
            this->m_hp = 0;
        }
    }
}

bool Player::isKnockedOut()
{
    return (this->m_hp == 0);
}

void Player::addCoins(int coinsAmount) 
{
    if(coinsAmount>0)
    {
        this->m_coins += coinsAmount; 
    }  
}

bool Player::pay(int payAmount)
{
    
    if(payAmount < 0 ||this->m_coins < payAmount)
    {
        return false;
    }  
    this->m_coins -= payAmount;
    return true;
}

int Player::getAttackStrength()
{
    return this->m_force + this->m_level;
}
