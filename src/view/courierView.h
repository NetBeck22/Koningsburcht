#ifndef COURIERVIEW_H
#define COURIERVIEW_H

#include <QGraphicsScene>
#include <QLabel>
#include <QPushButton>

#include "courier.h"

/*auteur: Nette Beckers
* klasse courierView
* maakt labels en buttons voor de couriers
* en update ze
*/

class courierView : public QObject
{
    Q_OBJECT
public:
    explicit courierView(QGraphicsScene *scene);
    ~courierView();

    courier *getCourier() const;
    QPushButton *getbuttonSand();
    QPushButton *getbuttonWood();
    QPushButton *getbuttonClay();
    QPushButton *getbuttonStone();
    QPushButton *getbuttonSilver();

    void clickedResources(int resource, QString text, int player);

private slots:
    void setResourcesView(int resource);

private:
    void courierLayout();
    courier *m_courierModel;

    QLabel *m_sandCourier;
    QLabel *m_stoneCourier;
    QLabel *m_woodCourier;
    QLabel *m_silverCourier;
    QLabel *m_clayCourier;
    QPushButton *m_helperSand;
    QPushButton *m_helperWood;
    QPushButton *m_helperClay;
    QPushButton *m_helperStone;
    QPushButton *m_helperSilver;
};

#endif // COURIERVIEW_H
