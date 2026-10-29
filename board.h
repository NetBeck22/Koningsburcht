#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QJsonObject>

/*auteur: Nette Beckers
* klasse board houdt de bank en de ronde bij
* functie read om gegevens in te lezen
* signals voor boardView
*/

class board : public QObject
{
    Q_OBJECT
public:
     explicit board(int cash = 82, int round = 12);

    int getCash() const;
     int getRound() const;

     void setCash( int currentCash);
     void setRound();

     void read(QJsonObject json);

signals:
    void updateBank();
    void updateRound();

private:
    int m_cash;
    int m_round;
};

#endif // BOARD_H
