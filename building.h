#ifndef BUILDING_H
#define BUILDING_H

#include "buildingInfo.h"

#define NUMBER_OF_HOUSES 6
#define NUMBER_OF_TOWERS 10
#define NUMBER_OF_BUILDINGS 23

/*auteur: Nette Beckers
* klasse building
* houdt een pointer naar de verschillende buildings bij
* en aantal zilverstukken bij de smid worden
* stuurt signalen naar buildingView voor updates
* functie read om gegevens in te lezen
*/

class building : public QObject
{
    Q_OBJECT   
public:
    enum BuildingOrder{KEEP = 1, TAVERN = 2, BIGGATE = 3, SMALLGATE = 4, STABLE = 5, SERVANTS = 6, PALACE = 7, HOUSE = 8, TOWER = 9};

    explicit building(int forge = 0);
    ~building();

    buildingInfo *getHouse() const;
    buildingInfo *getTower() const;
    buildingInfo *getKeep() const;
    buildingInfo *getTavern() const;
    buildingInfo *getBigGate() const;
    buildingInfo *getSmallGate() const;
    buildingInfo *getStable() const;
    buildingInfo *getServantsHouse() const;
    buildingInfo *getPalace() const;
    int getForgeSilver() const;
    buildingInfo *getBuilding(int building);

    void setForgeSilver();

    bool sellBuilding(int building, int resources);
    void read(QJsonObject json);

signals:
    void setForge();
    void sold(QString buildingName);
    void setHouse();
    void setTower();
    void setBuild();

protected:
    buildingInfo *m_house;
    buildingInfo *m_tower;
    int m_forgeSilver;
    int m_unselledBuildings;

private:
    buildingInfo *m_keep;
    buildingInfo *m_tavern;
    buildingInfo *m_bigGate;
    buildingInfo *m_smallGate;
    buildingInfo *m_stable;
    buildingInfo *m_servantsHouse;
    buildingInfo *m_palace;

};

#endif // BUILDING_H
