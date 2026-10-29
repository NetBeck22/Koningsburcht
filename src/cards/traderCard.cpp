#include "traderCard.h"
/*auteur: Nette Beckers*/

traderCard::traderCard(player *player, courier *courier, defenceTower *defenceTower,building *building): cards{player, building, courier}, m_courier{courier}, m_defenceTower{defenceTower}
{
    m_cardNumber = 2;
    m_nameCard = "Trader";
}

traderCard::~traderCard()
{
    delete m_courier;
    delete m_defenceTower;
}

void traderCard::play()
{
    emit giveOutput(QString("Speler %1 klik op een koerier").arg(QString::number(m_playerCards->getNumber())));
}

//geef resources aan speler, defencetower, uit de courier
void traderCard::giveResources()
{
    int resources[5]{SAND, WOOD, CLAY, STONE, SILVER};
    int numberResources[5]{NUMBER_OF_SAND, NUMBER_OF_WOOD, NUMBER_OF_CLAY_STONE_SILVER, NUMBER_OF_CLAY_STONE_SILVER, NUMBER_OF_CLAY_STONE_SILVER};
    int j{0};
    for(const auto i : resources)
    {
        if(m_courier->getPlayers(i) != 0)
        {
            if(m_courier->getPlayers(i) == m_playerCards->getNumber())
            {
                m_defenceTower->setResource(1, i);
                m_courier->setResource(-numberResources[j], i);
                m_playerCards->setResourcePlayer(numberResources[j], i);
            }
        }
        j++;
    }
}
