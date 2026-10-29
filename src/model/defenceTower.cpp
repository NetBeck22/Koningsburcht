#include "defenceTower.h"
/*auteur: Nette Beckers*/

defenceTower::defenceTower(int sand, int wood, int clay, int stone, int silver)
    : resources{sand, wood, clay, stone, silver}
{

}

//getters&setters
void defenceTower::setResource(int number, int resource)
{
    switch(resource)
    {
    case SAND:
        m_sand += number;
        break;
    case WOOD:
        m_wood += number;
        break;
    case CLAY:
        m_clay += number;
        break;
    case STONE:
        m_stone += number;
        break;
    case SILVER:
        m_silver += number;
        break;
    default:
        break;
    }

    emit updateResources();
}

int defenceTower::getNumberOfReource(int resource) const
{
    switch(resource)
    {
    case SAND:
        return m_sand ;
        break;
    case WOOD:
        return m_wood;
        break;
    case CLAY:
        return m_clay;
        break;
    case STONE:
        return m_stone;
        break;
    case SILVER:
        return m_silver;
        break;
    default:
        return 0;
        break;
    }
}

//read functie om gegevens in te lezen
void defenceTower::read(QJsonObject json)
{
    m_sand = json.value("sand").toInt();
    m_wood = json.value("wood").toInt();
    m_clay = json.value("clay").toInt();
    m_stone = json.value("stone").toInt();
    m_silver = json.value("silver").toInt();
    emit updateResources();
}
