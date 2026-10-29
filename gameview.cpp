#include "gameView.h"
/*auteur: Nette Beckers*/

gameView::gameView(QGraphicsScene *scene)
{
    m_defenceTower = new QPushButton;
    m_input = new QSpinBox;
    m_output = new QLabel;
    m_buttonBegin = new QPushButton;
    m_buttonChoose = new QPushButton;
    m_buttonNextRound = new QPushButton;
    m_buttonPlay = new QPushButton;
    m_buttonBuild = new QPushButton;
    m_currentButton = m_buttonBegin;

    addToScene(scene);

    m_boardView = new boardView(scene);
    m_buildingView = new buildingView(scene);
    m_courierView = new courierView(scene);
    m_defenceTowerView = new defenceTowerView(scene);
    m_helpersView = new helpersBuildingView(scene);
    m_playersView = new playerView(scene);
    m_cardsView= new cardsView{scene};
    m_gameModel = new game(m_boardView->getBoard(), m_buildingView->getBuilding(), m_courierView->getCourier(), m_helpersView->getHelper(), m_playersView->getPlayerOne(),m_playersView->getPlayerTwo(), m_defenceTowerView->getdefenceTower());

    m_output->setGeometry(500, 60, 420, 200);
    m_output->setAlignment(Qt::AlignCenter);
    m_output->setStyleSheet("QLabel{font-weight: bold;}");
    m_input->setGeometry(600, 270, 100, 30);
    m_input->setAlignment(Qt::AlignCenter);   
    m_output->setText("hello, let's play!");

    buttonLayout();
    connectGame();
 }

gameView::~gameView()
{
    delete m_input;
    delete m_buttonBegin;
    delete m_output;
    delete m_buttonChoose;
    delete m_buttonPlay;
    delete m_buttonNextRound;
    delete m_defenceTower;
    delete m_buttonBuild;
    delete m_currentButton;
    delete m_gameModel;
    delete m_boardView;
    delete m_buildingView;
    delete m_courierView;
    delete m_defenceTowerView;
    delete m_helpersView;
    delete m_playersView;
    delete m_cardsView;
}

void gameView::buttonLayout()
{
    int xButton{720};
    int yButton{270};
    int widthButton{100};
    int heightButton{30};

    m_buttonBegin->setGeometry(xButton,  yButton, widthButton, heightButton);
    m_defenceTower->setGeometry(xButton,  yButton, widthButton, heightButton);
    m_buttonChoose->setGeometry(xButton,  yButton, widthButton, heightButton);
    m_buttonBuild->setGeometry(xButton,  yButton, widthButton, heightButton);
    m_buttonNextRound->setGeometry(xButton,  yButton, widthButton, heightButton);
    m_buttonPlay->setGeometry(xButton,  yButton, widthButton, heightButton);

    m_buttonBuild->setText("build");
    m_defenceTower->setText("kies res");
    m_buttonPlay->setText("play");
    m_buttonChoose->setText("kies een kaart");
    m_buttonNextRound->setText("volgende ronde");
    m_buttonBegin->setText("start!");

    m_buttonChoose->hide();
    m_buttonNextRound->hide();
    m_buttonPlay->hide();
    m_defenceTower->hide();
    m_buttonBuild->hide();
}

void gameView::connectGame()
{
    connect(m_gameModel, SIGNAL(giveOutput(QString)), this, SLOT(setOutput(QString)));
    connect(m_gameModel->getMessengerOne(), SIGNAL(giveOutput(QString)), this, SLOT(setOutput(QString)));
    connect(m_gameModel->getMessengerTwo(), SIGNAL(giveOutput(QString)), this, SLOT(setOutput(QString)));
    connect(m_gameModel->getBrickLayerOne(), SIGNAL(giveOutput(QString)), this, SLOT(setOutput(QString)));
    connect(m_gameModel->getBrickLayerTwo(), SIGNAL(giveOutput(QString)), this, SLOT(setOutput(QString)));
    connect(m_gameModel->getTraderOne(), SIGNAL(giveOutput(QString)), this, SLOT(setOutput(QString)));
    connect(m_gameModel->getTraderTwo(), SIGNAL(giveOutput(QString)), this, SLOT(setOutput(QString)));
    connect(m_gameModel->getmasterBuilderOne(), SIGNAL(giveOutput(QString)), this, SLOT(setOutput(QString)));
    connect(m_gameModel->getmasterBuilderTwo(), SIGNAL(giveOutput(QString)), this, SLOT(setOutput(QString)));
    connect(m_gameModel->getPlayerOne(), SIGNAL(giveOutput(QString)), this, SLOT(setOutput(QString)));
    connect(m_gameModel->getPlayerTwo(), SIGNAL(giveOutput(QString)), this, SLOT(setOutput(QString)));

    connect(m_gameModel->getBrickLayerOne(), SIGNAL(takeResourceDefence()), this, SLOT(chooseResourceDefence()));
    connect(m_gameModel->getBrickLayerOne(), SIGNAL(chooseBuilding(QString)), this, SLOT(chooseBuilding(QString)));
    connect(m_gameModel->getBrickLayerOne(), SIGNAL(currentSituation()), this, SLOT(current()));
    connect(m_gameModel->getBrickLayerTwo(), SIGNAL(takeResourceDefence()), this, SLOT(chooseResourceDefence()));
    connect(m_gameModel->getBrickLayerTwo(), SIGNAL(chooseBuilding(QString)), this, SLOT(chooseBuilding(QString)));
    connect(m_gameModel->getBrickLayerTwo(), SIGNAL(currentSituation()), this, SLOT(current()));

    connect(m_buttonBegin, SIGNAL(clicked()), this, SLOT(begin()));
    connect(m_buttonChoose, SIGNAL(clicked()), this, SLOT(choose()));
    connect(m_buttonNextRound, SIGNAL(clicked()), this, SLOT(next()));
    connect(m_buttonPlay, SIGNAL(clicked()), this, SLOT(playcards()));

    connect(m_defenceTower, SIGNAL(clicked()), this, SLOT(setResourceDefence()));
    connect(m_buttonBuild, SIGNAL(clicked()), this, SLOT(buildBuilding()));
    connect(m_buildingView->getButtonSmid(), SIGNAL(clicked()), this, SLOT(giveSilverToForge()));
    connect(m_cardsView->getButtonQuitBuild(), SIGNAL(clicked()), this, SLOT(setHelper()));
    connect(m_cardsView->getButtonQuitHelper(), SIGNAL(clicked()), this, SLOT(quitHelper()));
    connect(m_courierView->getbuttonSand(), SIGNAL(clicked()), this, SLOT(clickedResource()));
    connect(m_courierView->getbuttonWood(), SIGNAL(clicked()), this, SLOT(clickedResource()));
    connect(m_courierView->getbuttonClay(), SIGNAL(clicked()), this, SLOT(clickedResource()));
    connect(m_courierView->getbuttonStone(), SIGNAL(clicked()), this, SLOT(clickedResource()));
    connect(m_courierView->getbuttonSilver(), SIGNAL(clicked()), this, SLOT(clickedResource()));
}

void gameView::addToScene(QGraphicsScene *scene)
{
    scene->addWidget(m_input);
    scene->addWidget(m_output);
    scene->addWidget(m_buttonBegin);
    scene->addWidget(m_buttonChoose);
    scene->addWidget(m_buttonNextRound);
    scene->addWidget(m_buttonPlay);
    scene->addWidget(m_defenceTower);
    scene->addWidget(m_buttonBuild);
}

//Getters&setters
game *gameView::getGame() const
{
    return m_gameModel;
}

void gameView::setOutput(QString text)
{
    m_output->setText(text);
}

//om situatie bij te houden
void gameView::current()
{
    m_currentButton->hide();
    m_buttonPlay->show();
}

//begin van het spel
void gameView::begin()
{
    m_gameModel->setFirstPlayer();
    m_buttonBegin->hide();
    m_buttonChoose->show();
    m_currentButton = m_buttonChoose;
}

//kies een kaart
void gameView::choose()
{
    m_gameModel->getTurn()->getCardsToPlay(m_boardView->getBoard()->getRound());
    m_input->setPrefix("kaart: ");
    connect(m_buttonChoose, SIGNAL(clicked()), this, SLOT(checkClicked()));
    m_gameModel->setTurn();
}

//kijk na welke kaart is gekozenen of er nog een speler is
void gameView::checkClicked()
{
    m_gameModel->setChosenCharPlayer(m_input->value());
    if(!m_gameModel->getTurn()->getFirst())
    {
        QAbstractButton::disconnect(m_buttonChoose, SIGNAL(clicked()), this, SLOT(checkClicked()));
        m_gameModel->chosenCards();
        m_buttonPlay->show();
        m_currentButton = m_buttonPlay;
        m_buttonChoose->hide();
    }
}

//speel de kaarten
void gameView::playcards()
{
    m_gameModel->setTurn();
    if(m_gameModel->getTurn()->getFirst() && m_gameModel->getNumberOfCardsPlayed() == 0)
    {
        m_gameModel->playcards();
    }
    else if(m_gameModel->getNumberOfCardsPlayed() == 1)
    {
        m_gameModel->playcards();
        m_buttonNextRound->show();
        m_currentButton = m_buttonNextRound;
        m_buttonPlay->hide();
    }
    else
    {
        m_buttonNextRound->show();
        m_currentButton = m_buttonNextRound;
        m_buttonPlay->hide();
    }
    m_gameModel->setNumberOfCardsPlayed();
}

//bij click de volgende ronde
void gameView::next()
{
    m_gameModel->nextRound();
    m_output->setText(QString("RONDE %1").arg(QString::number(m_boardView->getBoard()->getRound())));
    m_buttonNextRound->hide();
    m_buttonBegin->show();
    m_currentButton = m_buttonBegin;
}

//kies een resource uit de defence tower, brickLayer
void gameView::chooseResourceDefence()
{
    m_input->setPrefix("resource: ");
    m_output->setText(QString("Kies een resource uit de defence toren speler %1 \n 1. sand \n 2. wood\n4. clay\n5. stone\n0. silver").arg(QString::number(m_gameModel->getTurn()->getNumber())));
    m_buttonPlay->hide();
    m_defenceTower->show();
    m_currentButton = m_defenceTower;
}

//zet gekozen resource
void gameView::setResourceDefence()
{
    m_gameModel->getResourcesBrickLayer(m_input->value());
    m_defenceTower->hide();
}

//kies een gebouw om te bouwen
void gameView::chooseBuilding(QString buildings)
{
    m_cardsView->chooseBuilding();
    m_input->setPrefix("gebouw: ");
    m_output->setText(buildings);
    m_buttonBuild->show();
    m_currentButton = m_buttonBuild;
}

//bouw het gebouw
void gameView::buildBuilding()
{
    int building = m_input->value();
    int resources[4];
    m_cardsView->getResourcesTobuild(resources);
    m_gameModel->buildBrickLayer(building, resources);
}

//zet een helper
void gameView::setHelper()
{
    m_output->setText("Je kan helpers zetten (max. 2)");
    m_buttonBuild->hide();
    m_buttonPlay->show();
    m_cardsView->setHelper();
}

//stop met helpers zetten, ga voort met het spel
void gameView::quitHelper()
{
    m_buttonPlay->show();
    m_buttonBuild->hide();
    m_cardsView->quitHelper();
}

//een speler wilt een zilverenstaaf inruilen
void gameView::giveSilverToForge()
{
    m_gameModel->setForgeSilver();
    m_output->setText("Kies een resource van de couriers:\n1. sand\n2. wood\n4. clay\n5. stone");
    m_input->setPrefix("resource: ");
    m_buildingView->getButtonSmid()->setText("resource");
    disconnect(m_buildingView->getButtonSmid(), SIGNAL(clicked()), this, SLOT(giveSilverToForge()));
    connect(m_buildingView->getButtonSmid(), SIGNAL(clicked()), this, SLOT(getResourcesSmid()));
}

//gekozen resource voor zilverstaaf
void gameView::getResourcesSmid()
{
    m_gameModel->setSmid(m_input->value());
    m_buildingView->getButtonSmid()->setText("SMID");
    connect(m_buildingView->getButtonSmid(), SIGNAL(clicked()), this, SLOT(giveSilverToForge()));
    disconnect(m_buildingView->getButtonSmid(), SIGNAL(clicked()), this, SLOT(getResourcesSmid()));
}

QString gameView::getColor()
{
    QColor playerColor{m_gameModel->getColorPlayer()};
    QString stylebutton;
    if(playerColor.isValid())
    {
       stylebutton = QString("QPushButton{background-color:%1;}").arg(playerColor.name());
    }
    return stylebutton;
}

//als een courierHelper wordt aangeklikt
void gameView::clickedResource()
{
    QObject *obj = sender();
    QString stylebutton{getColor()};
    if(obj == m_courierView->getbuttonSand())
    {
        m_courierView->clickedResources(SAND, stylebutton, m_gameModel->getTurn()->getNumber());
        m_gameModel->getTurn()->setHelpersPlayer();
    }
    else if (obj == m_courierView->getbuttonWood())
    {
        m_courierView->clickedResources(WOOD, stylebutton, m_gameModel->getTurn()->getNumber());
        m_gameModel->getTurn()->setHelpersPlayer();
    }
    else if (obj == m_courierView->getbuttonClay())
    {
        m_courierView->clickedResources(CLAY, stylebutton, m_gameModel->getTurn()->getNumber());
        m_gameModel->getTurn()->setHelpersPlayer();
    }
    else if (obj == m_courierView->getbuttonStone())
    {
        m_courierView->clickedResources(STONE, stylebutton, m_gameModel->getTurn()->getNumber());
        m_gameModel->getTurn()->setHelpersPlayer();
    }
    else if (obj == m_courierView->getbuttonSilver())
    {
        m_courierView->clickedResources(SILVER, stylebutton, m_gameModel->getTurn()->getNumber());
        m_gameModel->getTurn()->setHelpersPlayer();
    }
}
