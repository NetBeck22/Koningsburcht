#ifndef BUILDINGVIEW_H
#define BUILDINGVIEW_H

#include <QGraphicsScene>
#include <QLabel>
#include <QPushButton>

#include "building.h"

/*auteur: Nette Beckers
* klasse buildingview
* maakt alle labels voor de buildings aan
* en knop voor smid, om zilver in te wisselen
* vangt signalen van building op
* stuurt signalen naar buildingView voor updates
*/

class buildingView : public QLabel
{
    Q_OBJECT
public:
    explicit buildingView(QGraphicsScene *scene);
    ~buildingView();

    building *getBuilding() const;
    QPushButton *getButtonSmid();

public slots:
    void notAvailable( QString member);
    void setHouse( );
    void setTower( );
    void setForge();
    void setAllBuildings();

private:
    void setBuilding(QLabel *member, buildingInfo *memberInfo);
    void styleBuilding();
    void addBuildingToScene(QGraphicsScene *scene);

    building *m_buildingModel;
    QLabel *m_towerView;
    QLabel *m_houseView;
    QLabel *m_keepView;
    QLabel *m_tavernView;
    QLabel *m_bigGateView;
    QLabel *m_smallGateView;
    QLabel *m_stableView;
    QLabel *m_servantsHouseView;
    QLabel *m_palaceView;
    QLabel *m_forgeView;
    QLabel *m_marketView;
    QPushButton *m_buttonSmid;
};

#endif // BUILDINGVIEW_H
