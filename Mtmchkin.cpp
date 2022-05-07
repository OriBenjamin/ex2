#include "Mtmchkin.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
//using namespace std?/?? why we didnt use it; also- what include and namespaces do we need;


Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
m_player(*(new Player(playerName))), m_cardsArray(cardsArray), m_gameStatus(GameStatus::MidGame),
m_numOfCards(numOfCards)
{
    /*
    //ori what to do if the input is not valid
    //how the fuck i create a default player?!
    Player *player(playerName,0,0) = new Player;
    this->m_player = *player; //or use it-this->m_player.Player(playerName);
    //ori-do we need name for new array? 
    Cards cards = new Cards[numOfCards];
    if(!cards) //allocation failed
    {
       this->numOfCards = 0;
       this->m_cardsArray = NULL;
    } else
    {
        for(int i = 0; i < numOfCards; i++)
        {
            cards[i] = cardsArray[i];
        }
        this->m_cardsArray = cards;
    }


        //this->m_cardsArray = cardsArray
    this->m_gameStatus = MidGame;*/
}


    void Mtmchkin::playNextCard()
    {
        int cardsArraySize = this->m_numOfCards; //ori- meybe Mtmchkin.getCardsArraySize?
        int currentCardIndex = 0;
        while(!Mtmchkin::isOver()) //ori- same as above...
        {
            this->m_cardsArray[currentCardIndex].printInfo();
            this->m_cardsArray[currentCardIndex].applyEncounter(this->m_player);
            this->m_player.printInfo();
            if(currentCardIndex == cardsArraySize-1)
            {
                currentCardIndex = -1;
            }
            currentCardIndex++;
        }
    }

    int Mtmchkin::getCardsArraySize(Card* cardsArray)
    {
        int size = 0;
        while(cardsArray)
        {
            size++;
            cardsArray++;
        }
        return size;
    }

    bool Mtmchkin::isOver()
    {
        if(this->m_player.getLevel() == 10)
        {
            this->m_gameStatus = GameStatus::Win; //ori they didnt tell me to update gmae status...
            return true;
        }
        if(this->m_player.isKnockedOut())
        {
            this->m_gameStatus = GameStatus::Loss; //ori they didnt tell me to update gmae status...
            return true;
        }
        return false;
    }


    GameStatus Mtmchkin::getGameStatus() const //ori-do we need to remain th const here?
    {
        return this->m_gameStatus;
    }
