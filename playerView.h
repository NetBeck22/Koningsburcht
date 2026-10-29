#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <QLabel>
#include <QGraphicsScene>

#include "player.h"

/*auteur: Nette Beckers
* klasse playerView
* maakt labels voor players en update ze
*/

class playerView : public QObject
{
    Q_OBJECT
public:
    explicit playerView(QGraphicsScene *scene);
    ~playerView();

    player *getPlayerOne() const;
    player *getPlayerTwo() const;

private slots:
    void firstPlayerLayoutOne();
    void firstPlayerLayoutTwo();
    void setPlayerOne();
    void setPlayerTwo();

private:
    player *m_playerModel;
    player *m_playerModelTwo;
    QLabel *m_playerOne;
    QLabel *m_playerTwo;
};

#endif // PLAYERVIEW_H
