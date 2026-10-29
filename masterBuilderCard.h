#ifndef MASTERBUILDERCARD_H
#define MASTERBUILDERCARD_H

#include "cards.h"

#define POINTS_PER_BUILDING 5

/*auteur: Nette Beckers
* klasse masterBuilderCard afgeleid van cards
* houdt bij wanneer de andere speler een gebouw bouwt voor de punten
* en heeft eigen play functie om de kaart te spelen (overschreven van cards)
*/

class masterBuilderCard : public cards
{
    Q_OBJECT
public:
    explicit masterBuilderCard(player *player, building *building, courier *courier);

    virtual void play() override;
    void setHousesBuildEnemy();
    void newHousesEnemy();

private:
    int m_housesBuildEnemy;
};

#endif // MASTERBUILDERCARD_H
