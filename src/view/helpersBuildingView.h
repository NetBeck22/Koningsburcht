#ifndef HELPERSBUILDINGVIEW_H
#define HELPERSBUILDINGVIEW_H

#include <QGraphicsScene>
#include <QPushButton>

#include "helpersBuilding.h"

/*auteur: Nette Beckers
* klasse helpersBuilding
* maakt alle buttons voor de helpersPlekjes
* update wanneer ze aangeklikt worden
*/

class helpersBuildingView : public QObject
{
    Q_OBJECT
public:
    explicit helpersBuildingView(QGraphicsScene *scene);
    ~helpersBuildingView();

    helpersBuilding *getHelper() const;

private slots:
    void helperClicked();

private:
    void makeLabels();
    void setLabels();
    void addLabels(QGraphicsScene *scene);
    void layoutLabels();

    helpersBuilding *m_helpersModel;
    QPushButton *m_helperKeepBox;
    QPushButton *m_helperPalaceBox[2];
    QPushButton *m_helperSmallGateBox;
    QPushButton *m_helperBigGateBox;
    QPushButton *m_helperServantsHouseBox[3];
    QPushButton *m_helperForgeBox[2];
    QPushButton *m_helperStableBox[2];
    QPushButton *m_helperTavernBox[2];
    QPushButton *m_helperMarketBox[2];
};

#endif // HELPERSBUILDINGVIEW_H
