#ifndef GAME_H
#define GAME_H

#include <QFile>
#include <QJsonParseError>

#include "helpersBuilding.h"
#include "messengerCard.h"
#include "brickLayerCard.h"
#include "traderCard.h"
#include "masterBuilderCard.h"

#define MESSENGER_NUMBER 1
#define TRADER_NUMBER 2
#define BRICKLAYER_NUMBER 3
#define MASTERBUILDER_NUMBER 6

/*auteur: Nette Beckers
* klasse game
* houdt van alles een model bij en wie aan de beurt is, volgorde van kaarten
* een overkoepelende klassen om nog verbindingen te kunnen maken
* stuurt signaal om gameView te updaten
* functie read om gegevens in te lezen
*/

class game : public QObject
{
    Q_OBJECT
public:
    explicit game(board *boardGame, building *buildingGame, courier *courierGame, helpersBuilding *helpersGame, player *playerOne, player *playerTwo, defenceTower *defenceTowerGame);
    ~game();

    messengerCard *getMessengerOne() const;
    messengerCard *getMessengerTwo() const;
    traderCard *getTraderOne() const;
    traderCard *getTraderTwo() const;
    brickLayerCard *getBrickLayerOne() const;
    brickLayerCard *getBrickLayerTwo() const;
    masterBuilderCard *getmasterBuilderOne() const;
    masterBuilderCard *getmasterBuilderTwo() const;
    player *getTurn() const;
    QColor getColorPlayer() const;
    player *getPlayerOne() const;
    player *getPlayerTwo() const;
    int getNumberOfCardsPlayed() const;

    void setNumberOfCardsPlayed();
    void setTurn();

    void setFirstPlayer();
    void setChosenCharPlayer(int character);
    void playcards();
    void chosenCards();
    void nextRound();
    void buildBrickLayer(int building, int resources[]) const;
    void setForgeSilver() const;
    void setSmid(int resource) const;
    void getResourcesBrickLayer(int resource) const;

signals:
    void giveOutput(QString text);

private:    
    void orderCards();
    void endGame();
    void read();

    player *m_playersTurn;
    board *m_boardGame;
    building *m_buildingGame;
    courier *m_courierGame;
    helpersBuilding *m_helpersGame;
    player *m_playerOneGame;
    player *m_playerTwoGame;
    defenceTower *m_defenceTowerGame;
    messengerCard *m_messenger[NUMBERS_OF_PLAYERS];
    traderCard *m_traderOne;
    traderCard *m_traderTwo;
    brickLayerCard *m_brickLayer[NUMBERS_OF_PLAYERS];
    masterBuilderCard *m_masterbuilder[NUMBERS_OF_PLAYERS];
    cards *m_cardsPlayerOne[NUMBER_OF_CARDS];
    cards *m_cardsPlayerTwo[NUMBER_OF_CARDS];
    int m_numberOfCardsPlayed{0};
    int m_cardOrder[NUMBERS_OF_PLAYERS][2];
};

#endif // GAME_H
