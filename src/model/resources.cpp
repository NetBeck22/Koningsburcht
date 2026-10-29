#include "resources.h"
/*auteur: Nette Beckers*/

resources::resources(int sand, int wood, int clay, int stone, int silver)
    : m_sand{sand}, m_wood{wood}, m_clay{clay}, m_stone{stone}, m_silver{silver}
{

}

//getters&setters
void resources::setResource(int number, int resource)
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
}

int resources::getSand() const
{
    return m_sand;
}

int resources::getStone() const
{
    return m_stone;
}

int resources::getClay() const
{
    return m_clay;
}

int resources::getSilver() const
{
    return m_silver;
}

int resources::getWood() const
{
    return m_wood;
}

//gegevens in lezen
void resources::read(QJsonObject json)
{
    m_sand = json.value("sand").toInt();
    m_wood = json.value("wood").toInt();
    m_clay = json.value("clay").toInt();
    m_stone = json.value("stone").toInt();
    m_silver = json.value("silver").toInt();

}
