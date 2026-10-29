#include "messengerCard.h"
/*auteur: Nette Beckers*/

messengerCard::messengerCard(player *player, board *board,building *building, courier *courier): cards{player, building, courier}, m_board{board}
{
    m_cardNumber = 1;
    m_nameCard = "Messenger";
}

messengerCard::~messengerCard()
{
    delete m_board;
}

void messengerCard::play()
{
    //aantal munten van de bank die de messenger krijgt
    m_playerCards->setCashPlayer(CASH_MESSENGER); // geef munten uit de bank
    m_board->setCash(CASH_MESSENGER);
    emit giveOutput(QString("speler %1 krijgt 8 munten uit de bank").arg(QString::number(m_playerCards->getNumber())));
}
