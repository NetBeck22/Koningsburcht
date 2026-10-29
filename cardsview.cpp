#include "cardsView.h"
/*auteur: Nette Beckers*/

cardsView::cardsView(QGraphicsScene *scene)
{   
    m_sandToBuild = new QSpinBox;
    m_woodToBuild = new QSpinBox;
    m_clayToBuild = new QSpinBox;
    m_stoneToBuild = new QSpinBox;
    m_buttonQuitBuild = new QPushButton;
    m_buttonQuitHelper = new QPushButton;

    cardsLayout();

    scene->addWidget(m_buttonQuitBuild);
    scene->addWidget(m_buttonQuitHelper);
    scene->addWidget(m_sandToBuild);
    scene->addWidget(m_woodToBuild);
    scene->addWidget(m_clayToBuild);
    scene->addWidget(m_stoneToBuild);
}

cardsView::~cardsView()
{
    delete m_sandToBuild;
    delete m_woodToBuild;
    delete m_clayToBuild;
    delete m_stoneToBuild;
}

//getters&setters
void cardsView::setHelper()
{
    m_buttonQuitBuild->hide();
    m_buttonQuitHelper->show();
    m_sandToBuild->hide();
    m_woodToBuild->hide();
    m_clayToBuild->hide();
    m_stoneToBuild->hide();
}
void cardsView::getResourcesTobuild(int resources[])
{
    resources[0] = m_sandToBuild->value();
    resources[1] = m_woodToBuild->value();
    resources[2] = m_clayToBuild->value();
    resources[3] = m_stoneToBuild->value();
}

QPushButton*cardsView::getButtonQuitBuild()
{
    return m_buttonQuitBuild;
}

QPushButton *cardsView::getButtonQuitHelper()
{
    return m_buttonQuitHelper;
}

//als de speler clicked moet de knop weg
void cardsView::quitHelper()
{
    m_buttonQuitHelper->hide();
}

//als de speler kan bouwen moeten de spinboxses voor de resources tevoorschijn kmen
void cardsView::chooseBuilding()
{
    m_sandToBuild->show();
    m_woodToBuild->show();
    m_clayToBuild->show();
    m_stoneToBuild->show();
    m_buttonQuitBuild->show();
}

void cardsView::cardsLayout()
{
    int widthSpin{70};
    int heightSpin{20};
    int ySpin{235};
    int xButton{830};
    int yButton{270};
    int widthButton{90};
    int heightButton{30};

    m_sandToBuild->setGeometry(540, ySpin, widthSpin, heightSpin);
    m_woodToBuild->setGeometry(630, ySpin, widthSpin, heightSpin);
    m_clayToBuild->setGeometry(720, ySpin, widthSpin, heightSpin);
    m_stoneToBuild->setGeometry(810, ySpin, widthSpin, heightSpin);
    m_buttonQuitBuild->setGeometry(xButton, yButton, widthButton, heightButton);
    m_buttonQuitHelper->setGeometry(xButton, yButton, widthButton, heightButton);

    m_sandToBuild->setPrefix("sand: ");
    m_woodToBuild->setPrefix("wood: ");
    m_clayToBuild->setPrefix("clay: ");
    m_stoneToBuild->setPrefix("stone: ");
    m_buttonQuitBuild->setText("quit build");
    m_buttonQuitHelper->setText("quit helper");

    m_sandToBuild->setAlignment(Qt::AlignCenter);
    m_woodToBuild->setAlignment(Qt::AlignCenter);
    m_clayToBuild->setAlignment(Qt::AlignCenter);
    m_stoneToBuild->setAlignment(Qt::AlignCenter);

    m_sandToBuild->hide();
    m_woodToBuild->hide();
    m_clayToBuild->hide();
    m_stoneToBuild->hide();
    m_buttonQuitBuild->hide();
    m_buttonQuitHelper->hide();
}
