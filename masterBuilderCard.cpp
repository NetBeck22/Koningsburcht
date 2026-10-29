#include "masterBuilderCard.h"
/*auteur: Nette Beckers*/

masterBuilderCard::masterBuilderCard(player *player, building *building, courier *courier): cards{player, building, courier}
{
    m_cardNumber = 6;
    m_nameCard = "Master Builder";
}

void masterBuilderCard::play()
{
    m_playerCards->setAllCards(); //geef alle kaarten
    m_playerCards->setPointsPlayer(m_housesBuildEnemy); //geef punten voor de gebouwen van de andere speler
    emit giveOutput(QString("speler %1 krijgt alle kaarten terug en %2 punten!").arg(QString::number(m_playerCards->getNumber()), QString::number(m_housesBuildEnemy)));
}

void masterBuilderCard::setHousesBuildEnemy()
{
    m_housesBuildEnemy += POINTS_PER_BUILDING;
}

void masterBuilderCard::newHousesEnemy()
{
    m_housesBuildEnemy= 0;
}
