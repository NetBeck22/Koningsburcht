#include "brickLayerCard.h"
/*auteur: Nette Beckers*/

brickLayerCard::brickLayerCard(player *player, defenceTower *defence, building *building, courier *courier, board *board)
    : cards{player, building, courier}, m_defenceBirckLayer{defence}, m_boardBrickLayer{board}
{
    m_cardNumber = 3;
    m_nameCard = "BrickLayer";
}

brickLayerCard::~brickLayerCard()
{
    delete m_defenceBirckLayer;
}

void brickLayerCard::play()
{
    emit takeResourceDefence();
}

//de speler heeft een resource uit de defenceTower gekozen
//de defenceTower en player worden geupdate
void brickLayerCard::choseResourceDefence(int resource)
{
    int totalResource = m_defenceBirckLayer->getNumberOfReource(resource);
    m_defenceBirckLayer->setResource(-totalResource, resource);
    m_playerCards->setResourcePlayer(totalResource, resource);
}

//als de speler een gebouw bouwt krijgt die de nodige munten uit de bank
void brickLayerCard::buildBrickLayer(int building, int resources[4])
{
    int cash{resources[0]+resources[1]+resources[2]+resources[3]};
    if(buildBuilding(building, resources))
    {
        m_playerCards->setPointsPlayer(cash);
        m_boardBrickLayer->setCash(-cash);
    }
}
