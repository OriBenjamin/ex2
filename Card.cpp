#include "Player.h"
#include "utilities.h"
#include "Card.h"

Card::Card(CardType type, const CardStats& stats)
{
    this->m_effect = type;
    this->m_stats = stats;

    void Card::applyEncounter(Player& player) const
    {
        if(this.m_effect == )
    }
}