#ifndef BRICKLAYERCARD_H
#define BRICKLAYERCARD_H

#include "cards.h"
#include "defenceTower.h"
#include "board.h"

/*auteur: Nette Beckers
* klasse brickLayercard afgeleid van cards
* defencetower en board worden meegegeven voor de nodige functies kunnen uit te voeren
* en heeft eigen play functie om de kaart te spelen (overschreven van cards)
* stuurt nodige signalen naar gameView voor output naar de userinterface
*/

class brickLayerCard : public cards
{
    Q_OBJECT 
public:
    explicit brickLayerCard(player *player, defenceTower *defence, building *building, courier *courier, board *board);
    ~brickLayerCard();

    virtual void play() override;
    void choseResourceDefence(int resource);
    void buildBrickLayer(int building, int resources[4]);

signals:
    void takeResourceDefence();

private:
    defenceTower *m_defenceBirckLayer;
    board *m_boardBrickLayer;
};

#endif // BRICKLAYERCARD_H
