#include "Mtmchkin.h"
#include <iostream>

    //Mtmchkin Constructor-update Mtmchkins fields according to the given parameters
    Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
    m_player(new Player(playerName)), 
    m_cardsArray(NULL), 
    m_gameStatus(GameStatus::MidGame), 
    m_numOfCards(numOfCards),
    m_currentCard(0)
    {
        //copies the given cards array into a new cards array which m_cardsArray is pointing to
        Card* cards = new Card[numOfCards];
        for(int i = 0; i < numOfCards; i++)
        {
            cards[i] = cardsArray[i];
        }
        this->m_cardsArray = cards;
    }

    //pulls the next card and updates the player's data after card encountering
    void Mtmchkin::playNextCard()
    {   
        int cardsArraySize = this->m_numOfCards;
        //pulling the next card and applying encounter
        this->m_cardsArray[m_currentCard].printInfo();
        this->m_cardsArray[m_currentCard].applyEncounter(*(this->m_player));
        this->m_player->printInfo();
        if(this->m_player->getLevel() == 10)
        {
            this->m_gameStatus = GameStatus::Win; 
        }
        if(this->m_player->isKnockedOut())
        {
            this->m_gameStatus = GameStatus::Loss;
        }
        //if reached the end, return to start of deck
        if(m_currentCard == cardsArraySize-1)
        {
            m_currentCard = -1;
        }
        m_currentCard++;
    }

    //finishes the game when the player has won or lost
    bool Mtmchkin::isOver() 
    {
        return this->m_gameStatus!=GameStatus::MidGame;
    }

    //Mtmchkin destructor
     Mtmchkin::~Mtmchkin()
     {
        //frees game's data
        delete this->m_player;
        delete[] this->m_cardsArray;
     }

    //checks what is the status of the game
    GameStatus Mtmchkin::getGameStatus() const
    {
        return this->m_gameStatus;
    }
