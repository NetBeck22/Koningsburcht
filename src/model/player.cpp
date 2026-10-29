#include "player.h"
/*auteur: Nette Beckers*/

player::player(QColor color, int number)
{
    m_colorPlayer = color;
    m_numberPlayer = number;
}

player::~player()
{
    delete m_resourcesPlayer;
}

//getters&setters
int player::getCashPlayer() const
{
    return m_cashPlayer;
}

int player::getPointsPlayer() const
{
    return m_pointsPlayer;
}

int player::getHelpersPlayer() const
{
    return m_helpersPlayer;
}

QColor player::getColor() const
{
    return m_colorPlayer;
}

void player::setPointsPlayer(int number)
{
    m_pointsPlayer += number;
    emit setPlayer();
}

void player::setCashPlayer(int number)
{
    m_cashPlayer += number;
    emit setPlayer();
}

void player::setHelpersPlayer()
{
    m_helpersPlayer --;
    emit setPlayer();
}

int player::getCharacter() const
{
    return m_chosenCharPlayer;
}

void player::setCharacter(int number)
{
    m_chosenCharPlayer = number;
}

int player::getNumber() const
{
    return m_numberPlayer;
}

resources *player::getResources() const
{
    return m_resourcesPlayer;
}

void player::setFirst()
{
    if(m_first)
    {
        m_first = false;
    }
    else
    {
        m_first = true;

        if(m_numberPlayer == 1)
        {
            emit setFirstPlayerLayoutOne();
        }
        else
        {
            emit setFirstPlayerLayoutTwo();
        }
    }
}

bool player::getFirst() const
{
    return m_first;
}

void player::setCards(int character)
{
    if(character  == 6)
    {
        m_cards[character-3] = false;

    }
    else
    {
        m_cards[character-1] = false;

    }
}

void player::setResourcePlayer(int number, int resource)
{
    m_resourcesPlayer->setResource(number, resource);
    emit setPlayer();
}


void player::setAllCards()
{
    for(int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        m_cards[i] = true;
    }
}

//heeft despeler genoeg om tebouwen?
bool player::enoughResourcesToBuild()
{
    int total{0};
    if(m_resourcesPlayer->getSand() != 0)
    {
        total ++;
    }
    if(m_resourcesPlayer->getWood() != 0)
    {
        total ++;
    }
    if(m_resourcesPlayer->getClay() != 0)
    {
        total ++;
    }
    if(m_resourcesPlayer->getStone() != 0)
    {
        total ++;
    }
    if(m_resourcesPlayer->getSilver() != 0)
    {
        total ++;
    }

    if(total >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//met welke kaarten kan de speler spelen?
void player::getCardsToPlay(int round)
{
    QString output{QString("Kies een kaart speler %1:\n").arg(QString::number(m_numberPlayer))};
    if(m_cards[0])
    {
        output.append(QString("%1\n").arg(NAME_MESSENGER));
    }
    if(m_cards[1])
    {
        output.append(QString("%1\n").arg(NAME_TRADER));
    }
    if(m_cards[2])
    {
        output.append(QString("%1\n").arg(NAME_BRICKLAYER));
    }
    if(m_cards[3] && round < NUMBER_OF_ROUNDS)
    {
        output.append(QString("%1\n").arg(NAME_MASTERBUILDER));
    }
    emit giveOutput(output);
}

//functie om gegevens in te lezen
void player::read(QJsonObject json)
{
    m_chosenCharPlayer = json.value("character").toInt();
    m_pointsPlayer = json.value("points").toInt();
    m_cashPlayer= json.value("cash").toInt();
    m_helpersPlayer = json.value("helpers").toInt();
    m_resourcesPlayer->read(json.value("resources").toObject());
    m_first = json.value("first").toBool();
    QJsonArray tempList = json.value("cards").toArray();
    m_cards[0] = tempList[0].toBool();
    m_cards[1] = tempList[1].toBool();
    m_cards[2] = tempList[2].toBool();
    m_cards[2] = tempList[3].toBool();
    emit setPlayer();

    if(m_first && m_numberPlayer == 1)
    {
        emit setFirstPlayerLayoutOne();
    }

    if(m_first && m_numberPlayer == 2)
    {
        emit setFirstPlayerLayoutTwo();
    }
}
