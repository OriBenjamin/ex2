//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef MTMCHKIN_H
#define MTMCHKIN_H
#include "Card.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {
public:

    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);

    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() ;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;

    /*
     * D'tor of the game:
     * @result
     *      Object fields are destroyed at Delete function / end of program
    */
    ~Mtmchkin();

private:
    Player* m_player;
    const Card* m_cardsArray;
    GameStatus m_gameStatus;
    int m_numOfCards;
    int m_currentCard;

};


#endif //MTMCHKIN_H
