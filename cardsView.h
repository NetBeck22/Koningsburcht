#ifndef CARDSVIEW_H
#define CARDSVIEW_H

#include "messengerCard.h"
#include "traderCard.h"
#include "brickLayerCard.h"
#include "masterBuilderCard.h"

#include <QSpinBox>
#include <QPushButton>
#include <QGraphicsScene>

/*auteur: Nette Beckers
* klasse cardsView
* maakt de spinBoxen aan voor de resources
* als de speler gaat bouwen
* en quitbuttons om te stoppen met bouwen of helpers zetten
*/

class cardsView : public QObject
{
    Q_OBJECT
public:
    explicit cardsView(QGraphicsScene *scene);
    ~cardsView();

    QPushButton *getButtonQuitBuild();
    QPushButton *getButtonQuitHelper();

    void setHelper();

    void quitHelper();
    void chooseBuilding();
    void getResourcesTobuild(int resources[]);


private:  
    void cardsLayout();

    QSpinBox *m_sandToBuild;
    QSpinBox *m_woodToBuild;
    QSpinBox *m_clayToBuild;
    QSpinBox *m_stoneToBuild;
    QPushButton *m_buttonQuitBuild;
    QPushButton *m_buttonQuitHelper;
};

#endif // CARDSVIEW_H
