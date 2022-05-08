#include "Mtmchkin.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;


    Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
    m_player(new Player(playerName)), 
    m_cardsArray(NULL), 
    m_gameStatus(GameStatus::MidGame), 
    m_numOfCards(numOfCards)
    {
        Card* cards = new Card[numOfCards];
        for(int i = 0; i < numOfCards; i++)
        {
            cards[i] = cardsArray[i];
        }
        this->m_cardsArray = cards;
    }


    void Mtmchkin::playNextCard()
    {
        int cardsArraySize = this->m_numOfCards;
        int currentCardIndex = 0;
        while(!Mtmchkin::isOver())
        {
            this->m_cardsArray[currentCardIndex].printInfo();
            this->m_cardsArray[currentCardIndex].applyEncounter(*(this->m_player));
            this->m_player->printInfo();
            if(currentCardIndex == cardsArraySize-1)
            {
                currentCardIndex = -1;
            }
            currentCardIndex++;
        }
    }

    bool Mtmchkin::isOver()
    {
        if(this->m_player->getLevel() == 10)
        {
            this->m_gameStatus = GameStatus::Win; 
            return true;
        }
        if(this->m_player->isKnockedOut())
        {
            this->m_gameStatus = GameStatus::Loss;
            return true;
        }
        return false;
    }

     Mtmchkin::~Mtmchkin()
     {
        delete this->m_player;
        delete[] this->m_cardsArray;
     }


    GameStatus Mtmchkin::getGameStatus() const
    {
        return this->m_gameStatus;
    }
