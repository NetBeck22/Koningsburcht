#include "playerView.h"
/*auteur: Nette Beckers*/

playerView::playerView(QGraphicsScene *scene)
{
    m_playerModel = new player(Qt::red, 1);
    m_playerModelTwo = new player(Qt::blue, 2);
    m_playerOne = new QLabel;
    m_playerTwo = new QLabel;

    setPlayerOne();
    setPlayerTwo();

    scene->addWidget(m_playerOne);
    scene->addWidget(m_playerTwo);

    m_playerOne->setGeometry(500, 310, 200, 200);
    m_playerTwo->setGeometry(720, 310, 200, 200);
    m_playerOne->setAlignment(Qt::AlignCenter);
    m_playerTwo->setAlignment(Qt::AlignCenter);
    m_playerOne->setStyleSheet("QLabel{background-color:red; color : white;}");
    m_playerTwo->setStyleSheet("QLabel{background-color:blue; color : white;}");

    connect(m_playerModel, SIGNAL(setPlayer()), this, SLOT(setPlayerOne()));
    connect(m_playerModelTwo, SIGNAL(setPlayer()), this, SLOT(setPlayerTwo()));

    connect(m_playerModel, SIGNAL(setFirstPlayerLayoutOne()), this, SLOT(firstPlayerLayoutOne()));
    connect(m_playerModelTwo, SIGNAL(setFirstPlayerLayoutTwo()), this, SLOT(firstPlayerLayoutTwo()));
}

playerView::~playerView()
{
    delete m_playerModel;
    delete m_playerModelTwo;
    delete m_playerOne;
    delete m_playerTwo;
}

//getters&setters
void playerView::firstPlayerLayoutOne()
{
      m_playerOne->setStyleSheet("QLabel{background-color: black; color: white;}");
      m_playerTwo->setStyleSheet("QLabel{background-color: blue ; color: white;}");
      setPlayerOne();
}

void playerView::firstPlayerLayoutTwo()
{
      m_playerTwo->setStyleSheet("QLabel{background-color: black; color: white;}");
      m_playerOne->setStyleSheet("QLabel{background-color: red ; color: white;}");
      setPlayerTwo();
}

void playerView::setPlayerOne()
{
    const QString playerText{QString("PLAYER ONE\nScore: %1\nMunten: %2\nHelpers: %3\n").arg(QString::number(m_playerModel->getPointsPlayer()), QString::number(m_playerModel->getCashPlayer()), QString::number(m_playerModel->getHelpersPlayer()))
            + QString("Sand: %1\nWood: %2\nClay: %3\n").arg(QString::number(m_playerModel->getResources()->getSand()), QString::number(m_playerModel->getResources()->getWood()), QString::number(m_playerModel->getResources()->getClay()))
            + QString("Stone: %1\nSilver:%2").arg(QString::number(m_playerModel->getResources()->getStone()), QString::number(m_playerModel->getResources()->getSilver()))};
    m_playerOne->setText(playerText);
}

void playerView::setPlayerTwo()
{
    const QString playerText{QString("PLAYER TWO\nScore: %1\nMunten: %2\nHelpers: %3\n").arg(QString::number(m_playerModelTwo->getPointsPlayer()), QString::number(m_playerModelTwo->getCashPlayer()), QString::number(m_playerModelTwo->getHelpersPlayer()))
            + QString("Sand: %1\nWood: %2\nClay: %3\n").arg(QString::number(m_playerModelTwo->getResources()->getSand()), QString::number(m_playerModelTwo->getResources()->getWood()), QString::number(m_playerModelTwo->getResources()->getClay()))
            + QString("Stone: %1\nSilver:%2").arg(QString::number(m_playerModelTwo->getResources()->getStone()), QString::number(m_playerModelTwo->getResources()->getSilver()))};
    m_playerTwo->setText(playerText);
}

player *playerView::getPlayerOne() const
{
    return m_playerModel;
}

player *playerView::getPlayerTwo() const
{
    return m_playerModelTwo;
}
