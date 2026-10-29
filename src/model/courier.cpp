#include "courier.h"
/*auteur: Nette Beckers*/

courier::courier(int sand, int wood, int clay, int stone, int silver)
    : resources{sand, wood, clay, stone, silver}
{

}

//getters&setters
void courier::setResource(int number, int resource)
{
    switch(resource)
    {
    case SAND:
        m_sand += number;
        emit updateResource(SAND);
        break;
    case WOOD:
        m_wood += number;
        emit updateResource(WOOD);
        break;
    case CLAY:
        m_clay += number;
        emit updateResource(CLAY);
        break;
    case STONE:
        m_stone += number;
        emit updateResource(STONE);
        break;
    case SILVER:
        m_silver += number;
        emit updateResource(SILVER);
        break;
    default:
        break;
    }
}

void courier::setPlayer(int resource, int player)
{
    switch(resource)
    {
    case SAND:
        m_playerSand = player;
        break;
    case WOOD:
        m_playerWood = player;
        break;
    case CLAY:
        m_playerClay = player;
        break;
    case STONE:
        m_playerStone = player;
        break;
    case SILVER:
        m_playerSilver = player;
        break;
    default:
        break;
    }
}

int courier::getPlayers(int resource) const
{
    switch(resource)
    {
    case SAND:
        return m_playerSand;
        break;
    case WOOD:
        return m_playerWood;
        break;
    case CLAY:
        return m_playerClay;
        break;
    case STONE:
        return m_playerStone;
        break;
    case SILVER:
        return m_playerSilver;
        break;
    default:
        return  0;
        break;
    }
}

//functie om gegevens in te lezen
void courier::readCourier(QJsonObject json)
{
    m_playerSand = json.value("playerSand").toInt();
    m_playerWood = json.value("playerWood").toInt();
    m_playerClay = json.value("playerClay").toInt();
    m_playerStone = json.value("playerStone").toInt();
    m_playerSilver = json.value("playerSilver").toInt();

    emit updateResource(SAND);
    emit updateResource(WOOD);
    emit updateResource(CLAY);
    emit updateResource(STONE);
    emit updateResource(SILVER);
}
