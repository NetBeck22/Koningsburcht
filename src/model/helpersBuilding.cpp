#include "helpersBuilding.h"
/*auteur: Nette Beckers*/

helpersBuilding::helpersBuilding()
{

}

//getters&setters
void helpersBuilding::setPlayerHelper(int player)
{
    m_playerHelper = player;
}

void helpersBuilding::setHelper(int building, int number)
{
    switch(building)
    {
    case KEEP:
        m_helperKeepPlayer = m_playerHelper;
        break;
    case PALACE:
        m_helperPalacePlayer[number] = m_playerHelper;
        break;
    case SMALLGATE:
        m_helperSmallGatePlayer = m_playerHelper;
        break;
    case BIGGATE:
        m_helperBigGatePlayer = m_playerHelper;
        break;
    case SERVANTSHOUSE:
        m_helperServantsHousePlayer[number] = m_playerHelper;
        break;
    case FORGE:
        m_helperForgePlayer[number] = m_playerHelper;
        break;
    case STABLE:
        m_helperStablePlayer[number] = m_playerHelper;
        break;
    case TAVERN:
        m_helperTavernPlayer[number] = m_playerHelper;
        break;
    case MARKET:
        m_helperMarketPlayer[number] = m_playerHelper;
        break;
    default:
        break;
    }
    m_numberOfHelpers --;
}

//verdeel de eindpunten
int helpersBuilding::endPointsHelpers(int player, int cash)
{
    int points{0};

    keepEndPoints(player, &points);
    palaceEndPoints(player, &points);
    smallGateEndPoints(player, &points);
    bigGateEndPoints(player, &points);
    ServantsEndPoints(player, &points);
    ForgeEndPoints(player, &points);
    stableEndPoints(player, &points);
    marketEndPoints(player, &points, cash);
    tavernEndPoints(player, &points);

    return points;
}

void helpersBuilding::keepEndPoints(int player, int *points)
{
    int pointsKeep{3};
    if(player == m_helperKeepPlayer)
    {
        *points += m_numberOfHelpers*pointsKeep;
    }
}

void helpersBuilding::palaceEndPoints(int player, int *points)
{
    if(player == m_helperPalacePlayer[0] && player == m_helperPalacePlayer[1])
    {
        // //maak nog functie om deze op tevangen en ook door te sturen
    }
    else if(player == m_helperPalacePlayer[0] || player == m_helperPalacePlayer[1])
    {
        //
    }
    *points += 10;
}

void helpersBuilding::ServantsEndPoints(int player, int *points)
{
    if(player == m_helperServantsHousePlayer[0])
    {
        *points += m_unselledBuildings;
    }
    if(player == m_helperServantsHousePlayer[1])
    {
        *points += m_unselledBuildings;
    }
    if(player == m_helperServantsHousePlayer[2])
    {
        *points += m_unselledBuildings;
    }
}

void helpersBuilding::smallGateEndPoints(int player, int *points)
{
    int pointsSmallGate{5};
    if(player == m_helperSmallGatePlayer)
    {
        *points += pointsSmallGate*(NUMBER_OF_TOWERS - m_tower->getAvailable());
    }
}

void helpersBuilding::bigGateEndPoints(int player, int *points)
{
    int pointsBigGate{10};
    if(player == m_helperBigGatePlayer)
    {
        *points += pointsBigGate*(NUMBER_OF_TOWERS - m_tower->getAvailable());
    }
}

void helpersBuilding::ForgeEndPoints(int player, int *points)
{
    if(player == m_helperForgePlayer[0])
    {
        *points +=  m_forgeSilver%2;
    }
    if(player == m_helperForgePlayer[1])
    {
        *points += m_forgeSilver;
    }
}

void helpersBuilding::stableEndPoints(int player, int *points)
{
    int pointsStableLow{2};
    int pointsStableHigh{3};
    if(player == m_helperStablePlayer[0])
    {
        *points += pointsStableLow*(NUMBER_OF_HOUSES - m_house->getAvailable());
    }
    if(player == m_helperStablePlayer[1])
    {
        *points += pointsStableHigh*(NUMBER_OF_HOUSES - m_house->getAvailable());
    }
}

void helpersBuilding::tavernEndPoints(int player, int *points)
{
    if(player == m_helperTavernPlayer[0])
    {
        *points += (NUMBER_OF_HELPERS-m_numberOfHelpers)%2;
    }
    if(player == m_helperTavernPlayer[1])
    {
        *points += NUMBER_OF_HELPERS-m_numberOfHelpers;
    }

}

void helpersBuilding::marketEndPoints(int player, int *points, int cash)
{
    if(player == m_helperMarketPlayer[0] && player == m_helperMarketPlayer[1])
    {
        *points += cash;
    }
    else if(player == m_helperMarketPlayer[0])
    {
        *points += cash%2;
    }
    else if(player == m_helperMarketPlayer[1])
    {
        *points += cash%2;
    }
}

//functie om gegevens in te lezen
void helpersBuilding::read(QJsonObject json)
{
    m_numberOfHelpers = json.value("numberOfHelpers").toInt();
    m_playerHelper = json.value("player").toInt();
    m_helperKeepPlayer = json.value("helperKeep").toInt();
    QJsonArray tempList = json.value("helperPalace").toArray();
    m_helperPalacePlayer[0] = tempList[0].toInt();
    m_helperPalacePlayer[1] = tempList[1].toInt();
    tempList = json.value("helperServants").toArray();
    m_helperServantsHousePlayer[0] = tempList[0].toInt();
    m_helperServantsHousePlayer[1] = tempList[1].toInt();
    m_helperServantsHousePlayer[2] = tempList[2].toInt();
    tempList = json.value("helperForge").toArray();
    m_helperForgePlayer[0] = tempList[0].toInt();
    m_helperForgePlayer[1] = tempList[1].toInt();
    tempList = json.value("helperStable").toArray();
    m_helperStablePlayer[0] = tempList[0].toInt();
    m_helperStablePlayer[1] = tempList[1].toInt();
    tempList = json.value("helperTavern").toArray();
    m_helperTavernPlayer[0] = tempList[0].toInt();
    m_helperTavernPlayer[1] = tempList[1].toInt();
    tempList = json.value("helperMarket").toArray();
    m_helperMarketPlayer[0] = tempList[0].toInt();
    m_helperMarketPlayer[1] = tempList[1].toInt();
    m_helperSmallGatePlayer = json.value("helperSmallGate").toInt();
    m_helperBigGatePlayer = json.value("helperBigGate").toInt();
}
