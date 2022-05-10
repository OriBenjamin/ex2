//
// Created by Ori Dekel and Liel Ferber 02/05/2022
//

#include "Player.h"
#include "utilities.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

/*Player constructor- update Players fields according to the given parameters
or defaults values*/
Player::Player(const char* name, int maxHP, int force):
m_name(name),
m_level(1),
m_coins(0),
m_maxHP(maxHP),
m_hp(maxHP),
m_force(force)
{
    //some of the given parameters are not valid
    if(this->m_maxHP<0)
    {
        this->m_maxHP = DEFAULT_MAX_HP;
        this->m_hp = m_maxHP;
    }
    if(this->m_force<0)
    {
        this->m_force = DEFAULT_FORCE;
    }
}

//prints player info
void Player::printInfo()
{
    printPlayerInfo(this->m_name,this->m_level,this->m_force,this->m_hp,this->m_coins);
}

//increasing players level
void Player::levelUp()
{
    if(this->m_level < 10)
    {
        this->m_level++;
    }
}

//getting players level
int Player::getLevel()
{
    return this->m_level;   
}

//increasing players force
void Player::buff(int buffAmount)
{
    if(buffAmount>0)
    {
        this->m_force += buffAmount;   
    }
}

//increasing players heal points
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

//decreasing players heal points
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

//checks if the player died
bool Player::isKnockedOut()
{
    return (this->m_hp == 0);
}

//increasing players coins
void Player::addCoins(int coinsAmount) 
{
    if(coinsAmount>0)
    {
        this->m_coins += coinsAmount; 
    }  
}

//decreasing players coins depending the payment he made
bool Player::pay(int payAmount)
{
    if(this->m_coins < payAmount)
    {
        return false;
    }  
    if(payAmount <= 0 )
    {
        return true;
    }
    this->m_coins -= payAmount;
    return true;
}

//checks players attack strength
int Player::getAttackStrength()
{
    return this->m_force + this->m_level;
}
