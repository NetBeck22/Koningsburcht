#include "building.h"
/*auteur: Nette Beckers*/

building::building(int forge)
    : m_forgeSilver{forge}
{
    m_house = new buildingInfo{10, 8, NUMBER_OF_HOUSES, "Huis"};
    m_tower = new buildingInfo{8, 6, NUMBER_OF_TOWERS, "Toren"};
    m_keep = new buildingInfo{24, 14, 1,"Uitkijkpost"};
    m_tavern = new buildingInfo{22,12,1,"tavern"};
    m_bigGate = new buildingInfo{18,10,1, "Grote Poort"};
    m_smallGate = new buildingInfo{12,6,1, "Kleine Poort"};
    m_stable = new buildingInfo{18,14, 1, "stable"};
    m_servantsHouse = new buildingInfo{18,14, 1, "Bedienden Woning"};
    m_palace = new buildingInfo{30, 18, 1,"palace"};
    m_unselledBuildings = NUMBER_OF_BUILDINGS;
}

building::~building()
{
    delete m_keep;
    delete m_tavern;
    delete m_bigGate;
    delete m_smallGate;
    delete m_stable;
    delete m_servantsHouse;
    delete m_palace;
}

//getters&setters
buildingInfo *building::getBuilding(int building)
{
    buildingInfo *build;
    switch(building)
    {
    case KEEP:
        build = m_keep;
        break;
    case TAVERN:
        build = m_tavern;
        break;
    case BIGGATE:
        build = m_bigGate;
        break;
    case SMALLGATE:
        build = m_smallGate;
        break;
    case STABLE:
        build = m_stable;
        break;
    case SERVANTS:
        build = m_servantsHouse;
        break;
    case PALACE:
        build = m_palace;
        break;
    case HOUSE:
        build = m_house;
        break;
    case TOWER:
        build = m_tower;
        break;
    default:
        build = nullptr;
        break;
    }

    return build;
}

void building::setForgeSilver()
{
    m_forgeSilver ++;
    emit setForge();
}

buildingInfo *building::getHouse() const
{
    return m_house;
}

buildingInfo *building::getTower() const
{
    return m_tower;
}

buildingInfo *building::getKeep() const
{
    return m_keep;
}

buildingInfo *building::getTavern() const
{
    return m_tavern;
}

buildingInfo *building::getBigGate() const
{
    return m_bigGate;
}

buildingInfo *building::getSmallGate() const
{
    return m_smallGate;
}

buildingInfo *building::getStable()  const
{
    return m_stable;
}

buildingInfo *building::getServantsHouse() const
{
    return m_servantsHouse;
}

buildingInfo *building::getPalace() const
{
    return m_palace;
}

int building::getForgeSilver() const
{
    return m_forgeSilver;
}

//als een building gebouwd word
//kijken ze na of ze de nodige resources hebben gegeven
//zo ja, wordt allesgeupdate
bool building::sellBuilding(int building, int resources)
{    
    buildingInfo *build{getBuilding(building)};

    if(build->getResources() != resources)
    {
        return false;
    }
    else
    {
        m_unselledBuildings--;
        build->setAvailable();
        if(build->getAvailable() == 0)
        {
            emit sold(build->getName());
        }
        if(building == 8)
        {
            emit setHouse();
        }
        if(building == 9)
        {
            emit setTower();
        }

        return true;
    }
}

//read functie om gegevens in te lezen
void building::read(QJsonObject json)
{
    m_keep->read(json.value("keep").toObject());
    m_tavern->read(json.value("tavern").toObject());
    m_bigGate->read(json.value("bigGate").toObject());
    m_smallGate->read(json.value("smallGate").toObject());
    m_stable->read(json.value("stable").toObject());
    m_servantsHouse->read(json.value("servants").toObject());
    m_palace->read(json.value("palace").toObject());
    m_house->read(json.value("house").toObject());
    m_tower->read(json.value("tower").toObject());
    m_forgeSilver = json.value("forgeSilver").toInt();

    emit setBuild();
}
