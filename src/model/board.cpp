#include "board.h"
/*auteur: Nette Beckers*/

board::board(int cash, int round)
    :m_cash{cash}, m_round{round}
{

}

//getters&setters
int board::getCash()const
{
    return m_cash;
}

int board::getRound() const
{
    return m_round;
}

void board::setCash( int currentCash)
{
    m_cash -= currentCash;
    emit updateBank();
}

void board::setRound()
{
    m_round --;
    emit updateRound();
}

//read functie om gegevens in te lezen
void board::read(QJsonObject json)
{
    m_round = json.value("round").toInt();
    m_cash = json.value("bank").toInt();
    emit updateBank();
    emit updateRound();
}
