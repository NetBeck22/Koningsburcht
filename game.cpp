#include "Game.h"
/*auteur: Nette Beckers*/

game::game(board *boardGame, building *buildingGame, courier *courierGame, helpersBuilding *helpersGame, player *playerOne, player *playerTwo, defenceTower *defenceTowerGame)
    : m_boardGame(boardGame), m_buildingGame{buildingGame}, m_courierGame{courierGame}, m_helpersGame{helpersGame}, m_playerOneGame{playerOne}, m_playerTwoGame{playerTwo}, m_defenceTowerGame{defenceTowerGame}
{
    m_messenger[0] = new messengerCard{m_playerOneGame, m_boardGame, m_buildingGame, m_courierGame};
    m_messenger[1] = new messengerCard{m_playerTwoGame, m_boardGame, m_buildingGame, m_courierGame};
    m_traderOne = new traderCard{m_playerOneGame, m_courierGame, m_defenceTowerGame, m_buildingGame};
    m_traderTwo = new traderCard(m_playerTwoGame, m_courierGame, m_defenceTowerGame, m_buildingGame);
    m_brickLayer[0] = new brickLayerCard{m_playerOneGame, m_defenceTowerGame,m_buildingGame, m_courierGame, m_boardGame};
    m_brickLayer[1] = new brickLayerCard{m_playerTwoGame, m_defenceTowerGame,m_buildingGame, m_courierGame, m_boardGame};
    m_masterbuilder[0] = new masterBuilderCard{m_playerOneGame, m_buildingGame, m_courierGame};
    m_masterbuilder[1] = new masterBuilderCard{m_playerTwoGame, m_buildingGame, m_courierGame};    
    m_cardsPlayerOne[0] = m_messenger[0];
    m_cardsPlayerOne[1] = m_traderOne;
    m_cardsPlayerOne[2] = m_brickLayer[0];
    m_cardsPlayerOne[3] = m_masterbuilder[0];
    m_cardsPlayerTwo[0] = m_messenger[1];
    m_cardsPlayerTwo[1] = m_traderTwo;
    m_cardsPlayerTwo[2] = m_brickLayer[1];
    m_cardsPlayerTwo[3] = m_masterbuilder[1];
    read();
}

game::~game()
{
    delete m_playersTurn;
    delete m_boardGame;
    delete m_buildingGame;
    delete m_courierGame;
    delete m_helpersGame;
    delete m_playerOneGame;
    delete m_playerTwoGame;
    delete m_defenceTowerGame;
    delete m_messenger[0];
    delete m_messenger[1];
    delete m_traderOne;
    delete m_traderTwo;
    delete m_brickLayer[0];
    delete m_brickLayer[1];
    delete m_masterbuilder[0];
    delete m_masterbuilder[1];
    delete m_cardsPlayerOne[0];
    delete m_cardsPlayerOne[1];
    delete m_cardsPlayerOne[2];
    delete m_cardsPlayerOne[3];
    delete m_cardsPlayerTwo[0];
    delete m_cardsPlayerTwo[1];
    delete m_cardsPlayerTwo[2];
    delete m_cardsPlayerTwo[3];
}

//Getters&setters
player *game::getTurn() const
{
    return m_playersTurn;
}

messengerCard *game::getMessengerOne() const
{
    return m_messenger[0];
}

messengerCard *game::getMessengerTwo() const
{
    return m_messenger[1];
}

traderCard *game::getTraderOne() const
{
    return m_traderOne;
}

traderCard *game::getTraderTwo() const
{
    return m_traderTwo;
}

brickLayerCard *game::getBrickLayerOne() const
{
    return m_brickLayer[0];
}

masterBuilderCard *game::getmasterBuilderOne() const
{
    return m_masterbuilder[0];
}

brickLayerCard *game::getBrickLayerTwo() const
{
    return m_brickLayer[1];
}

masterBuilderCard *game::getmasterBuilderTwo() const
{
    return m_masterbuilder[1];
}

player *game::getPlayerOne() const
{
    return m_playerOneGame;
}

player *game::getPlayerTwo() const
{
    return m_playerTwoGame;
}

int game::getNumberOfCardsPlayed() const
{
    return m_numberOfCardsPlayed;
}

void game::setNumberOfCardsPlayed()
{
   m_numberOfCardsPlayed ++;
}

QColor game::getColorPlayer() const
{
    QColor playerColor;
    if(m_playersTurn == m_playerOneGame)
    {
        playerColor = m_playerOneGame->getColor();
    }
    else
    {
        playerColor = m_playerTwoGame->getColor();
    }
    return playerColor;
}

void game::setTurn()
{
    if(m_playersTurn == m_playerOneGame)
    {
        m_playersTurn = m_playerTwoGame;
    }
    else
    {
        m_playersTurn = m_playerOneGame;
    }
}

//functie om de eerste speler aan te duiden
void game::setFirstPlayer()
{
    if(m_boardGame->getRound()%2 == 0)
    {
        if(m_playerTwoGame->getFirst())
        {
            m_playerTwoGame->setFirst();

        }
        m_playerOneGame->setCashPlayer(1);
        m_playerOneGame->setFirst();
        m_playersTurn = m_playerOneGame;
    }
    else
    {
        if(m_playerOneGame->getFirst())
        {
            m_playerOneGame->setFirst();
        }
        m_playerTwoGame->setCashPlayer(1);
        m_playerTwoGame->setFirst();
        m_playersTurn = m_playerTwoGame;
    }
}

//als de speler een kaart heeft gekozen, wordt alles geupdate
void game::setChosenCharPlayer(int  character)
{
    for(int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        if(m_cardsPlayerOne[i]->getCardNumber() == character && getTurn() == m_playerOneGame)
        {
            m_cardsPlayerOne[i]->setChoseCard();
            m_playerOneGame->setCharacter(character);
        }
        else if(m_cardsPlayerTwo[i]->getCardNumber() == character && getTurn() == m_playerTwoGame)
        {
            m_cardsPlayerTwo[i]->setChoseCard();
            m_playerTwoGame->setCharacter(character);
        }
    }
    orderCards();
}

//de kaarten worden in volgorde gezet van wie eerst mag spelen en welke kaart
void game::orderCards()
{
    if((m_playerOneGame->getCharacter() < m_playerTwoGame->getCharacter()) || (m_playerOneGame->getFirst() && m_playerOneGame->getCharacter() == m_playerTwoGame->getCharacter()))
    {
        m_cardOrder[0][0] = m_playerOneGame->getCharacter();
        m_cardOrder[0][1] = m_playerOneGame->getNumber();
        m_cardOrder[1][0] = m_playerTwoGame->getCharacter();
        m_cardOrder[1][1] = m_playerTwoGame->getNumber();
    }
    else if((m_playerTwoGame->getCharacter() < m_playerOneGame->getCharacter()) || (m_playerTwoGame->getFirst() && m_playerOneGame->getCharacter() == m_playerTwoGame->getCharacter()))
    {
        m_cardOrder[0][0] = m_playerTwoGame->getCharacter();
        m_cardOrder[0][1] = m_playerTwoGame->getNumber();
        m_cardOrder[1][0] = m_playerOneGame->getCharacter();
        m_cardOrder[1][1] = m_playerOneGame->getNumber();
    }
}

//de kaarten worden gespeeld op volgorde, uit de ordercards
void game::playcards()
{
    int player{m_cardOrder[m_numberOfCardsPlayed][1]-1};
    int character{m_cardOrder[m_numberOfCardsPlayed][0]};

    if(character == MESSENGER_NUMBER)
    {
        m_messenger[player]->play();
    }
    else if(character == TRADER_NUMBER)
    {
        if(player == m_playerOneGame->getNumber()-1)
        {
            m_playersTurn = m_playerOneGame;
            m_traderOne->play();
        }
        else if(player == m_playerTwoGame->getNumber()-1)
        {
            m_playersTurn = m_playerTwoGame;
            m_traderTwo->play();
        }
    }
    else if(character == BRICKLAYER_NUMBER)
    {
        m_helpersGame->setPlayerHelper(m_playersTurn->getNumber());
        m_brickLayer[player]->play();
    }
    else if(character == MASTERBUILDER_NUMBER)
    {
        m_masterbuilder[player]->play();
    }
}

//de gekozen kaarten worden getoond
void game::chosenCards()
{
    QString charachterPlayerOne, charachterPlayerTwo;
    for(int i = 0; i < NUMBER_OF_CARDS; i++)
    {
        if(m_playerOneGame->getCharacter() == m_cardsPlayerOne[i]->getCardNumber())
        {
            charachterPlayerOne = m_cardsPlayerOne[i]->getNameCard();
        }
        if(m_playerTwoGame->getCharacter() == m_cardsPlayerTwo[i]->getCardNumber())
        {
            charachterPlayerTwo = m_cardsPlayerTwo[i]->getNameCard();
        }
    }

    QString output{QString("speler 1 koos voor %1\nspeler 2 koos voor %2").arg(charachterPlayerOne, charachterPlayerTwo)};
    emit giveOutput(output);
}

//als de speler het gebouw wilt bouwen, wordt build aan geroepen
void game::buildBrickLayer(int building, int resources[4]) const
{
    m_brickLayer[m_playersTurn->getNumber()-1]->buildBrickLayer(building, resources);
    m_masterbuilder[2-m_playersTurn->getNumber()]->setHousesBuildEnemy();
}

//de speler geeft een zilverenstaaf aan de smid
void game::setForgeSilver() const
{
    m_playersTurn->setResourcePlayer(-1, SILVER);
    m_buildingGame->setForgeSilver();
}

//als de speler gekozen heeft welke resource ze wilt krijgen van de zilverstaaf aan de smid
void game::setSmid(int resource) const
{
    m_courierGame->setResource(-1, resource);
    m_playersTurn->setResourcePlayer(1, resource);
}

//de speler heeft een resource gekozen van de defenceTower, met de kaart brickLayer
void game::getResourcesBrickLayer(int resource) const
{
   m_brickLayer[m_playersTurn->getNumber()-1]->choseResourceDefence(resource);
   m_brickLayer[m_playersTurn->getNumber()-1]->build();
}

void game::nextRound()
{   
    m_masterbuilder[0]->newHousesEnemy(); //zet op 0
    m_masterbuilder[1]->newHousesEnemy();

    if(m_traderOne->getChoseCard() || m_traderTwo->getChoseCard()) //was er een trader, geef resources
    {
        m_traderOne->giveResources();
        m_traderTwo->giveResources();
    }

    if(!m_masterbuilder[0]->getChoseCard()) //als ze geen masterbuilder hadden, zet de gekozen kaart false
    {
        m_playerOneGame->setCards(m_playerOneGame->getCharacter());
    }

    if(!m_masterbuilder[1]->getChoseCard())
    {
        m_playerTwoGame->setCards(m_playerTwoGame->getCharacter());
    }

    for(int i = 0; i < NUMBER_OF_CARDS; i++) //zet de gekozen kaart weer af
    {
        if(m_playerOneGame->getCharacter() == m_cardsPlayerOne[i]->getCardNumber())
        {
            m_cardsPlayerOne[i]->setChoseCard();
        }
        if(m_playerTwoGame->getCharacter() == m_cardsPlayerTwo[i]->getCardNumber())
        {
            m_cardsPlayerTwo[i]->setChoseCard();
        }
    }

    if(m_boardGame->getRound() == 0) //als het einde is, verdeel de punten
    {
        endGame();
    }

    m_numberOfCardsPlayed = 0;
    m_boardGame->setRound();
    emit giveOutput(QString("RONDE %1").arg(QString::number(m_boardGame->getRound())));
}

//verdeel punten, kijk wie gewonnen is
void game::endGame()
{
    m_playerOneGame->setPointsPlayer(m_helpersGame->endPointsHelpers(m_playerOneGame->getNumber(), m_playerOneGame->getCashPlayer()));
    m_playerTwoGame->setPointsPlayer(m_helpersGame->endPointsHelpers(m_playerTwoGame->getNumber(), m_playerTwoGame->getCashPlayer()));

    if(m_playerOneGame->getPointsPlayer() > m_playerTwoGame->getPointsPlayer())
    {
        emit giveOutput(QString("Speler %1 is gewonnen!").arg(QString::number(m_playerOneGame->getNumber())));
    }
    else
    {
        emit giveOutput(QString("Speler %1 is gewonnen!").arg(QString::number(m_playerTwoGame->getNumber())));
    }
}

//read fucntie om gegevens in te lezen
void game::read()
{
    QFile koningsBurcht("C:/Users/nette/Documents/konproj/files/koningsBurchtFile.json");
    if(!koningsBurcht.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        EXIT_FAILURE;
    }
    else
    {
        QByteArray data = koningsBurcht.readAll();
        koningsBurcht.close();
        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson( data, &jsonError );
        QJsonObject koningsBurchtObject = document.object();
        QJsonObject courier = koningsBurchtObject.value("courier").toObject();
        QJsonObject board = koningsBurchtObject.value("board").toObject();
        QJsonObject building = koningsBurchtObject.value("building").toObject();
        QJsonObject helpers = koningsBurchtObject.value("helpers").toObject();
        QJsonObject playerOne = koningsBurchtObject.value("playerOne").toObject();
        QJsonObject playerTwo = koningsBurchtObject.value("playerTwo").toObject();
        QJsonObject defence = koningsBurchtObject.value("defenceTower").toObject();

        m_boardGame->read(board);
        m_buildingGame->read(building);
        m_courierGame->read(courier);
        m_courierGame->readCourier(courier);
        m_helpersGame->read(helpers);
        m_playerOneGame->read(playerOne);
        m_playerTwoGame->read(playerTwo);
        m_defenceTowerGame->read(defence);
    }
}
