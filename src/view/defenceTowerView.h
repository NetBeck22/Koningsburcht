#ifndef DEFENCETOWERVIEW_H
#define DEFENCETOWERVIEW_H

#include <QGraphicsScene>
#include <QLabel>

#include "defenceTower.h"

/*auteur: Nette Beckers
* klasse defenceTowerView
* afgeleid van resources
* vangt signaal op van defenceTower
* maakt label voor defenceTower
*/

class defenceTowerView : public QObject
{
    Q_OBJECT
public:
    explicit defenceTowerView(QGraphicsScene *scene);
    ~defenceTowerView();

    defenceTower *getdefenceTower() const;

private slots:
    void setDefenceTower();

private:
    defenceTower *m_defenceTowerModel;
    QLabel *m_defenceTower;
};

#endif // DEFENCETOWERVIEW_H
