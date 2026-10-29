#ifndef CARDS_H
#define CARDS_H

#include "player.h"
#include "building.h"
#include "courier.h"

/*auteur: Nette Beckers
* klasse cards
* krijgt een speler, buildings en courier mee
* om de nodige functies kunnen uit te voeren
* cards kan gebouwen bouwen en helpers zetten
* heeft ook een functie play die door elke kaart zelf overschreven wordt
* stuurt signalen naar gameView
*/

class cards : public QObject
{
    Q_OBJECT
public:
    explicit cards(player *playerCards, building *building, courier *courier);
    ~cards();

    bool getChoseCard() const;
    int getCardNumber() const;
    QString getNameCard()const;

    void setChoseCard();

    virtual void play();
    void build();
    bool buildBuilding(int building, int resourses[4]);

signals:
    void chooseHelper();
    void chooseBuilding(QString buildings);
    void currentSituation();
    void giveOutput(QString text);

protected:
    int m_cardNumber;
    QString m_nameCard;
    player *m_playerCards;
    building *m_building;
    courier *m_courier;
    bool m_choseCard{false};
};

#endif // CARDS_H
