#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "Game.h"
#include "cardsView.h"
#include "boardView.h"
#include "BuildingView.h"
#include "defenceTowerView.h"
#include "courierView.h"
#include "helpersBuildingView.h"
#include "playerView.h"

/*auteur: Nette Beckers
* klasse gameView
* mmaakt alle buttons aan om te spelen, die telkens vervangen worden
* heeft van alle views een model om zo ook dejuiste verbingen te maken en doorte geven aan game
*/

class gameView : public QObject
{
    Q_OBJECT
public:
    explicit gameView(QGraphicsScene *scene);
    ~gameView();

    game *getGame() const;

public slots:
    void checkClicked();
    void clickedResource();
    void begin();
    void choose();
    void next();
    void playcards();
    void setHelper();
    void chooseBuilding(QString buildings);
    void buildBuilding();
    void chooseResourceDefence();
    void setResourceDefence();
    void giveSilverToForge();
    void getResourcesSmid();
    void quitHelper();
    void current();
    void setOutput(QString text);

private:
    void buttonLayout();
    void connectGame();
    void addToScene(QGraphicsScene *scene);

    QString getColor();
    QSpinBox *m_input;
    QPushButton *m_buttonBegin;
    QLabel *m_output;
    QPushButton *m_buttonChoose;
    QPushButton *m_buttonPlay;
    QPushButton *m_buttonNextRound;
    QPushButton *m_defenceTower;
    QPushButton *m_buttonBuild;
    QPushButton *m_currentButton;

    game *m_gameModel;
    boardView *m_boardView;
    buildingView *m_buildingView;
    courierView *m_courierView;
    defenceTowerView *m_defenceTowerView;
    helpersBuildingView *m_helpersView;
    playerView *m_playersView;
    cardsView *m_cardsView;
};

#endif // GAMEVIEW_H
