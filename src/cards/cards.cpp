#include "cards.h"
/*auteur: Nette Beckers*/

cards::cards(player *playerCards, building *building, courier *courier)
    : m_playerCards{playerCards}, m_building{building}, m_courier{courier}
{

}

cards::~cards()
{
    delete m_playerCards;
    delete m_building;
    delete m_courier;
}

int cards::getCardNumber() const
{
    return m_cardNumber;
}

QString cards::getNameCard() const
{
    return m_nameCard;
}

void cards::play()
{
    emit giveOutput("play");
}

void cards::setChoseCard()
{
    if(m_choseCard)
    {
        m_choseCard = false;
    }
    else
    {
        m_choseCard = true;
    }
}

bool cards::getChoseCard() const
{
    return m_choseCard;
}

//functie om te bouwen
//als de speler genoeg verschillende resources heeft
//worden de beschikbare gebouwen getoond
//anders gaat het spel door
void cards::build()
{
    if(m_playerCards->enoughResourcesToBuild())
    {
        QString buildings{QString("Deze gebouwen kan je nog bouwen speler %1 (max. 2)\n").arg(QString::number(m_playerCards->getNumber()))};
        QString keep{QString("%1. %2\n").arg(QString::number(m_building->KEEP), m_building->getKeep()->getName())};
        QString tavern{QString("%1. %2\n").arg(QString::number(m_building->TAVERN), m_building->getTavern()->getName())};
        QString  bigGate{QString("%1. %2\n").arg(QString::number(m_building->BIGGATE), m_building->getBigGate()->getName())};
        QString smallGate{QString("%1. %2\n").arg(QString::number(m_building->SMALLGATE), m_building->getSmallGate()->getName())};
        QString stable{QString("%1. %2\n").arg(QString::number(m_building->STABLE), m_building->getStable()->getName())};
        QString servants{QString("%1. %2\n").arg(QString::number(m_building->SERVANTS), m_building->getServantsHouse()->getName())};
        QString palace{QString("%1. %2\n").arg(QString::number(m_building->PALACE), m_building->getPalace()->getName())};
        QString house{QString("%1. %2\n").arg(QString::number(m_building->HOUSE), m_building->getHouse()->getName())};
        QString tower{QString("%1. %2\n").arg(QString::number(m_building->TOWER), m_building->getTower()->getName())};
        if(m_building->getKeep()->getBuildOrNot())
        {
            buildings.append(keep);
        }
        if(m_building->getTavern()->getBuildOrNot())
        {
            buildings.append(tavern);
        }
        if(m_building->getBigGate()->getBuildOrNot())
        {
            buildings.append(bigGate);
        }
        if(m_building->getSmallGate()->getBuildOrNot())
        {
            buildings.append(smallGate);
        }
        if(m_building->getStable()->getBuildOrNot())
        {
            buildings.append(stable);
        }
        if(m_building->getServantsHouse()->getBuildOrNot())
        {
            buildings.append(servants);
        }
        if(m_building->getPalace()->getBuildOrNot())
        {
            buildings.append(palace);
        }
        if(m_building->getHouse()->getBuildOrNot())
        {
            buildings.append(house);
        }
        if(m_building->getTower()->getBuildOrNot())
        {
            buildings.append(tower);
        }

        emit chooseBuilding(buildings);
    }
    else
    {
        emit currentSituation();
        emit giveOutput("Niet genoeg verschillende resources om te bouwen!");
    }
}

//functie als de speler wilt bouwen, returnt of de speler kan bouwen ja of nee
bool cards::buildBuilding(int building, int resources[4])
{
    int total = resources[0]*SAND + resources[1]*WOOD + resources[2]*CLAY + resources[3]*STONE;

    if(m_building->sellBuilding(building, total))
    {
        m_playerCards->setResourcePlayer(-resources[0], SAND);
        m_courier->setResource(resources[0], SAND);
        m_playerCards->setResourcePlayer(-resources[1], WOOD);
        m_courier->setResource(resources[1], WOOD);
        m_playerCards->setResourcePlayer(-resources[2], CLAY);
        m_courier->setResource(resources[2], CLAY);
        m_playerCards->setResourcePlayer(-resources[3], STONE);
        m_courier->setResource(resources[3], STONE);

        return true;
    }
    else
    {
        emit giveOutput("Foute resources!");
        return false;
    }
}
