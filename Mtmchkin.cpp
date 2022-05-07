#include "Mtmchkin.h"
//using namespace std?/?? why we didnt use it; also- what include and namespaces do we need;


    Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
    {
        //ori what to do if the input is not valid
        //how the fuck i create a default player?!
        this->m_player = new Player //or use it-this->m_player.Player(playerName);
        //ori-do we need name for new array? 
        this->m_cardsArray = new Card* newCardsArray[numOfCards];
        /*or meybe(i think we dont want this way because we were given numOfCards as a parameter and it is weird
        to points to the original cards array):*/

        //this->m_cardsArray = cardsArray
        if(!this->m_cardsArray) //allocation failed
        {
           // ori what to do
        }
        for(int i = 0; i < numOfCards; i++)
        {
            this->m_cardsArray[i] = cardsArray[i];
        }
        this->m_gameStatus = MidGame;
    }


    void Mtmchkin::playNextCard()
    {
        int cardsArraySize = Mtmchkin::getCardsArraySize(this->m_cardsArray); ori- meybe Mtmchkin.getCardsArraySize?
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
        if(this->m_player.level == 10)
        {
            this->m_gameStatus = Win; //ori they didnt tell me to update gmae status...
            return true;
        }
        if(this->m_player.hp == 0)
        {
            this->m_gameStatus = Loss; //ori they didnt tell me to update gmae status...
            return true;
        }
        return false;
    }


    GameStatus Mtmchkin::getGameStatus() const //ori-do we need to remain th const here?
    {
        return this->m_gameStatus;
    }
