#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsScene>
#include <QLabel>

#include "board.h"

/*auteur: Nette Beckers
* klasse boardView maakt de labels voor board
* 1 extra summary label, dat is een vast gegeven
* slots voor de signals van board op te vangen
*/

class boardView : public QObject
{
    Q_OBJECT
public:
    explicit boardView(QGraphicsScene* scene);
    ~boardView();

    board *getBoard() const;

public slots:
    void setRoundView();
    void setBankView();

private:
    void makeSummary();  

    board *m_boardModel;
    QLabel *m_bankView;
    QLabel *m_roundView;
    QLabel *m_summary;
};

#endif // BOARDVIEW_H
