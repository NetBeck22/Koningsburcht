#include "helpersBuildingView.h"
/*auteur: Nette Beckers*/

helpersBuildingView::helpersBuildingView(QGraphicsScene *scene)
{
    m_helpersModel = new helpersBuilding;
    makeLabels();
    setLabels();
    addLabels(scene);
    layoutLabels();
}

helpersBuildingView::~helpersBuildingView()
{
   delete m_helpersModel;
   delete m_helperKeepBox;
   delete m_helperPalaceBox[0];
   delete m_helperPalaceBox[1];
   delete m_helperSmallGateBox;
   delete m_helperBigGateBox;
   delete m_helperServantsHouseBox[0];
   delete m_helperServantsHouseBox[1];
   delete m_helperServantsHouseBox[2];
   delete m_helperForgeBox[0];
   delete m_helperStableBox[0];
   delete m_helperTavernBox[0];
   delete m_helperMarketBox[0];
   delete m_helperForgeBox[1];
   delete m_helperStableBox[1];
   delete m_helperTavernBox[1];
   delete m_helperMarketBox[1];
}

void helpersBuildingView::makeLabels()
{
    m_helperKeepBox = new QPushButton;
    m_helperPalaceBox[0] = new QPushButton;
    m_helperPalaceBox[1] = new QPushButton;
    m_helperSmallGateBox = new QPushButton;
    m_helperBigGateBox = new QPushButton;
    m_helperServantsHouseBox[0] = new QPushButton;
    m_helperServantsHouseBox[1] = new QPushButton;
    m_helperServantsHouseBox[2] = new QPushButton;
    m_helperForgeBox[0] = new QPushButton;
    m_helperForgeBox[1] = new QPushButton;
    m_helperStableBox[0] = new QPushButton;
    m_helperStableBox[1] = new QPushButton;
    m_helperTavernBox[0] = new QPushButton;
    m_helperTavernBox[1] = new QPushButton;
    m_helperMarketBox[0] = new QPushButton;
    m_helperMarketBox[1] = new QPushButton;

    connect(m_helperKeepBox, SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperPalaceBox[0], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperPalaceBox[1], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperSmallGateBox, SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperBigGateBox, SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperServantsHouseBox[0], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperServantsHouseBox[1], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperServantsHouseBox[2], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperForgeBox[0], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperForgeBox[1], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperStableBox[0], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperStableBox[1], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperTavernBox[0], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperTavernBox[1], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperMarketBox[0], SIGNAL(clicked()), this, SLOT(helperClicked()));
    connect(m_helperMarketBox[1], SIGNAL(clicked()), this, SLOT(helperClicked()));
}

helpersBuilding *helpersBuildingView::getHelper() const
{
    return m_helpersModel;
}

//Ga na welke helpers is aangeklikt en update deze
void helpersBuildingView::helperClicked()
{
    QObject *obj = sender();
    if(obj == m_helperKeepBox)
    {
        m_helperKeepBox->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->KEEP, 0);
    }
    else if(obj == m_helperPalaceBox[0])
    {
        m_helperPalaceBox[0]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->PALACE, 0);
    }
    else if(obj == m_helperPalaceBox[1])
    {
        m_helperPalaceBox[1]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->PALACE, 1);
    }
    else if(obj == m_helperSmallGateBox)
    {
        m_helperSmallGateBox->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->SMALLGATE, 0);
    }
    else if(obj == m_helperBigGateBox)
    {
        m_helperBigGateBox->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->BIGGATE, 0);
    }
    else if(obj == m_helperServantsHouseBox[0])
    {
        m_helperServantsHouseBox[0]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->SERVANTSHOUSE, 0);
    }
    else if(obj == m_helperServantsHouseBox[1])
    {
        m_helperServantsHouseBox[1]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->SERVANTSHOUSE, 1);
    }
    else if(obj == m_helperServantsHouseBox[2])
    {
        m_helperServantsHouseBox[2]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->SERVANTSHOUSE, 2);
    }
    else if(obj == m_helperForgeBox[0])
    {
        m_helperForgeBox[0]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->FORGE, 0);
    }
    else if(obj == m_helperForgeBox[1])
    {
        m_helperForgeBox[1]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->FORGE, 1);
    }
    else if(obj == m_helperStableBox[0])
    {
        m_helperStableBox[0]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->STABLE, 0);
    }
    else if(obj == m_helperStableBox[1])
    {
        m_helperStableBox[1]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->STABLE, 1);
    }
    else if(obj == m_helperTavernBox[0])
    {
        m_helperTavernBox[0]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->TAVERN, 0);
    }
    else if(obj == m_helperTavernBox[1])
    {
        m_helperTavernBox[1]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->TAVERN, 1);
    }
    else if(obj == m_helperMarketBox[0])
    {
        m_helperMarketBox[0]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->MARKET, 0);
    }
    else if(obj == m_helperMarketBox[1])
    {
        m_helperMarketBox[1]->setStyleSheet("QPushButton{background-color: black;}");
        m_helpersModel->setHelper(m_helpersModel->MARKET, 1);
    }

}




void helpersBuildingView::setLabels()
{
    m_helperKeepBox->setText(QString::number(HELPER_POINTS_KEEP));
    m_helperPalaceBox[0]->setText(QString::number(HELPER_POINTS_PALACE));
    m_helperPalaceBox[1]->setText(QString::number(HELPER_POINTS_PALACE));
    m_helperSmallGateBox->setText(QString::number(HELPER_POINTS_SMALL_GATE));
    m_helperBigGateBox->setText(QString::number(HELPER_POINTS_BIG_GATE));
    m_helperServantsHouseBox[0]->setText(QString::number(HELPER_POINTS_SERVANTS_HOUSE_A));
    m_helperServantsHouseBox[1]->setText(QString::number(HELPER_POINTS_SERVANTS_HOUSE_B));
    m_helperServantsHouseBox[2]->setText(QString::number(HELPER_POINTS_SERVANTS_HOUSE_C));
    m_helperForgeBox[0]->setText(QString::number(HELPER_POINTS_FORGE_A));
    m_helperForgeBox[1]->setText(QString::number(HELPER_POINTS_FORGE_B));
    m_helperStableBox[0]->setText(QString::number(HELPER_POINTS_STABLE_A));
    m_helperStableBox[1]->setText(QString::number(HELPER_POINTS_STABLE_B));
    m_helperTavernBox[0]->setText(QString::number(HELPER_POINTS_TAVERN_A));
    m_helperTavernBox[1]->setText(QString::number(HELPER_POINTS_TAVERN_B));
    m_helperMarketBox[0]->setText(QString::number(HELPER_POINTS_MARKET));
    m_helperMarketBox[1]->setText(QString::number(HELPER_POINTS_MARKET));

    int widthHelper{30};
    m_helperKeepBox->setMaximumWidth(widthHelper);
    m_helperPalaceBox[0]->setMaximumWidth(widthHelper);
    m_helperPalaceBox[1]->setMaximumWidth(widthHelper);
    m_helperSmallGateBox->setMaximumWidth(widthHelper);
    m_helperBigGateBox->setMaximumWidth(widthHelper);
    m_helperServantsHouseBox[0]->setMaximumWidth(widthHelper);
    m_helperServantsHouseBox[1]->setMaximumWidth(widthHelper);
    m_helperServantsHouseBox[2]->setMaximumWidth(widthHelper);
    m_helperForgeBox[0]->setMaximumWidth(widthHelper);
    m_helperForgeBox[1]->setMaximumWidth(widthHelper);
    m_helperStableBox[0]->setMaximumWidth(widthHelper);
    m_helperStableBox[1]->setMaximumWidth(widthHelper);
    m_helperTavernBox[0]->setMaximumWidth(widthHelper);
    m_helperTavernBox[1]->setMaximumWidth(widthHelper);
    m_helperMarketBox[0]->setMaximumWidth(widthHelper);
    m_helperMarketBox[1]->setMaximumWidth(widthHelper);
}

void helpersBuildingView::addLabels(QGraphicsScene *scene)
{
    scene->addWidget(m_helperKeepBox);
    scene->addWidget(m_helperPalaceBox[0]);
    scene->addWidget(m_helperPalaceBox[1]);
    scene->addWidget(m_helperSmallGateBox);
    scene->addWidget(m_helperBigGateBox);
    scene->addWidget(m_helperServantsHouseBox[0]);
    scene->addWidget(m_helperServantsHouseBox[1]);
    scene->addWidget(m_helperServantsHouseBox[2]);
    scene->addWidget(m_helperForgeBox[0]);
    scene->addWidget(m_helperForgeBox[1]);
    scene->addWidget(m_helperStableBox[0]);
    scene->addWidget(m_helperStableBox[1]);
    scene->addWidget(m_helperTavernBox[0]);
    scene->addWidget(m_helperTavernBox[1]);
    scene->addWidget(m_helperMarketBox[0]);
    scene->addWidget(m_helperMarketBox[1]);
}

void helpersBuildingView::layoutLabels()
{
    int heightWidthHelper{30};
    m_helperKeepBox->setGeometry(320, 100, heightWidthHelper, heightWidthHelper);
    m_helperPalaceBox[0]->setGeometry(320, 400, heightWidthHelper, heightWidthHelper);
    m_helperPalaceBox[1]->setGeometry(360, 400, heightWidthHelper, heightWidthHelper);
    m_helperSmallGateBox->setGeometry(320, 250, heightWidthHelper, heightWidthHelper);
    m_helperBigGateBox->setGeometry(170, 250, heightWidthHelper, heightWidthHelper);
    m_helperServantsHouseBox[0]->setGeometry(170, 400, heightWidthHelper, heightWidthHelper);
    m_helperServantsHouseBox[1]->setGeometry(210, 400, heightWidthHelper, heightWidthHelper);
    m_helperServantsHouseBox[2]->setGeometry(250, 400, heightWidthHelper, heightWidthHelper);
    m_helperForgeBox[0]->setGeometry(170, 550, heightWidthHelper, heightWidthHelper);
    m_helperForgeBox[1]->setGeometry(210, 550, heightWidthHelper, heightWidthHelper);
    m_helperStableBox[0]->setGeometry(20, 400, heightWidthHelper, heightWidthHelper);
    m_helperStableBox[1]->setGeometry(60, 400, heightWidthHelper, heightWidthHelper);
    m_helperTavernBox[0]->setGeometry(20, 250, heightWidthHelper, heightWidthHelper);
    m_helperTavernBox[1]->setGeometry(60, 250, heightWidthHelper, heightWidthHelper);
    m_helperMarketBox[0]->setGeometry(320, 550, heightWidthHelper, heightWidthHelper);
    m_helperMarketBox[1]->setGeometry(360, 550, heightWidthHelper, heightWidthHelper);
}
