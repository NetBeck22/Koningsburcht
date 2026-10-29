#ifndef COURIER_H
#define COURIER_H

#include "resources.h"
#include "player.h"

/*auteur: Nette Beckers
* klasse courier
* agfeleid van resources
* houdt ook bij welke speler bij welke courier staat
* stuurt signaal om courierView te updaten
* read functie om gegevens in te lezen
*/

class courier : public resources
{
    Q_OBJECT
public:
    explicit courier(int sand = 18, int wood = 16, int clay = 13, int stone = 13, int silver = 13);

    int getPlayers(int resource) const;

    virtual void setResource(int number, int resource) override;
    void setPlayer(int resource, int player);

    void readCourier(QJsonObject json);

signals:
    void updateResource(int resource);

private:
    int m_playerSand{0};
    int m_playerWood{0};
    int m_playerClay{0};
    int m_playerStone{0};
    int m_playerSilver{0};
};

#endif // COURIER_H
