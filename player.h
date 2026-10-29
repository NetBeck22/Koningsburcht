#ifndef PLAYER_H
#define PLAYER_H

#include <QColor>
#include <QJsonArray>

#include "resources.h"

#define NUMBERS_OF_PLAYERS 2
#define NUMBER_OF_ROUNDS 12
#define NUMBER_OF_CARDS 4
#define NAME_MESSENGER "1. messenger"
#define NAME_TRADER "2. trader"
#define NAME_BRICKLAYER "3. bricklayer"
#define NAME_MASTERBUILDER "6. masterbuilder"

/*auteur: Nette Beckers
* klasse player
* houdt alle informatie van de speler bij
* stuurt signalen om playerView te updaten
* functie read om gegevens in te lezen
*/

class player : public QObject
{
    Q_OBJECT
public:
    explicit player(QColor color, int number);
    ~player();

    int getPointsPlayer() const;
    int getCashPlayer() const;
    int getHelpersPlayer() const;
    QColor getColor() const;
    int getCharacter() const;
    int getNumber() const;
    resources *getResources() const;
    bool getFirst() const;

    void setPointsPlayer(int number);
    void setCashPlayer( int number);
    void setHelpersPlayer();
    void setCharacter(int number);
    void setFirst();
    void setCards(int character);
    void setResourcePlayer(int number, int resource);
    void setAllCards();

    bool enoughResourcesToBuild();
    void getCardsToPlay(int round);
    void setBuildRound();
    void read(QJsonObject json);

signals:
    void setPlayer();
    void setFirstPlayerLayoutOne();
    void setFirstPlayerLayoutTwo();
    void giveOutput(QString text);

private:
    int m_numberPlayer;
    QColor m_colorPlayer;
    int m_chosenCharPlayer{0};
    int m_pointsPlayer{0};
    int m_cashPlayer{3};
    int m_helpersPlayer{6};
    resources *m_resourcesPlayer{new resources{1,1,0,0,0}};
    bool m_first{false};
    bool m_cards[NUMBER_OF_CARDS]{true, true, true, true};
};

#endif // PLAYER_H
