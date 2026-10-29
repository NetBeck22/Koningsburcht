#include "buildingInfo.h"
/*auteur: Nette Beckers*/

buildingInfo::buildingInfo(int resources, int points, int available, QString name)
    : m_numberOfResources{resources}, m_points{points},m_name{name}, m_available{available}
{

}

//getters&setters
QString buildingInfo::getName() const
{
    return m_name;
}

int buildingInfo::getPoints() const
{
    return m_points;
}

int buildingInfo::getResources() const
{
    return m_numberOfResources;
}

int buildingInfo::getAvailable() const
{
    return m_available;
}

void buildingInfo::setAvailable()
{
    m_available --;
}

bool buildingInfo::getBuildOrNot() const
{
    return m_status;
}

//read functie om gegevens in te lezen
void buildingInfo::read(QJsonObject json)
{
    m_status = json.value("status").toBool();
    m_available = json.value("available").toInt();
}
