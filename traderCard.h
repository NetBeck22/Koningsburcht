#ifndef TRADERCARD_H
#define TRADERCARD_H

#include "cards.h"
#include "courier.h"
#include "defenceTower.h"

#define NUMBER_OF_SAND 3
#define NUMBER_OF_WOOD 2
#define NUMBER_OF_CLAY_STONE_SILVER 1

/*auteur: Nette Beckers
* klasse masterBuilderCard afgeleid van cards
* krijgt courier en defenceTower mee voor nodige functies
* en heeft eigen play functie om de kaart te spelen (overschreven van cards)
*/

class traderCard : public cards
{
    Q_OBJECT
public:
    explicit traderCard(player *player, courier *courier, defenceTower *defenceTower, building *building);
    ~traderCard();

    virtual void play() override;
    void giveResources();

private:
    enum m_NumberOfResourcesForTraders{nSAND = 3, nWOOD = 2,  nCLAY = 1, nSTONE = 1, nSILVER = 1};
    courier *m_courier;
    defenceTower *m_defenceTower;
};

#endif // TRADERCARD_H
