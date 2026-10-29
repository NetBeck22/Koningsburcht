#ifndef MESSENGERCARD_H
#define MESSENGERCARD_H

#include "cards.h"
#include "board.h"

#define CASH_MESSENGER 8 //aantal munten dat de messenger van de bank krijgt

/*auteur: Nette Beckers
* klasse messengerCard afgeleid van cards
* krijgt een board mee voor de nodige functies uit te voeren
* en heeft eigen play functie om de kaart te spelen (overschreven van cards)
*/

class messengerCard : public cards
{
    Q_OBJECT
public:
    explicit messengerCard(player *player, board *board, building *building, courier *courier);
    ~messengerCard();

    virtual void play() override;

private:
    board *m_board;
};

#endif // MESSENGERCARD_H
