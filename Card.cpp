#include "Player.h"
#include "utilities.h"
#include "Card.h"

//Card constructor- update Cards fields according to the given parameters
Card::Card(CardType type, const CardStats& stats):
m_effect(type),
m_stats(stats)
{}

//applying an encountering of the player with a card
void Card::applyEncounter(Player& player) const
{
    if(this->m_effect == CardType::Battle)
    {
        //the player is strong then the cards character
        if(player.getAttackStrength() >= this->m_stats.force)
        {
            player.levelUp();
            player.addCoins(this->m_stats.loot);
            printBattleResult(true);
        }
        else //the player is weak strong then the cards character
        {
            player.damage(this->m_stats.hpLossOnDefeat);
            printBattleResult(false);
        }
    }
    if(this->m_effect == CardType::Buff)
    {
        //the player has enugh money for buying force points
        if(player.pay(this->m_stats.cost))
        {
            player.buff(this->m_stats.buff);
        }
    }
    if(this->m_effect == CardType::Heal)
    {
        //the player has enugh money for buying heal points
        if(player.pay(this->m_stats.cost))
        {
            player.heal(this->m_stats.heal);
        } 
    }
    if(this->m_effect == CardType::Treasure)
    {
        player.addCoins(this->m_stats.loot);
    }
}

//prints card info according to its type
void Card::printInfo() const
{
    if(this->m_effect == CardType::Battle)
    {
        printBattleCardInfo(this->m_stats);
    }
    if(this->m_effect == CardType::Buff)
    {
        printBuffCardInfo(this->m_stats);
    }
    if(this->m_effect == CardType::Heal)
    {
        printHealCardInfo(this->m_stats);
    }
    if(this->m_effect == CardType::Treasure)
    {
        printTreasureCardInfo(this->m_stats);
    }
}
