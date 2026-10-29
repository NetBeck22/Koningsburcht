#include "BuildingView.h"
/*auteur: Nette Beckers*/

buildingView::buildingView(QGraphicsScene *scene)
{
    m_houseView = new QLabel;
    m_towerView = new QLabel;
    m_keepView = new QLabel;
    m_tavernView = new QLabel;
    m_bigGateView = new QLabel;
    m_smallGateView = new QLabel;
    m_stableView = new QLabel;
    m_servantsHouseView = new QLabel;
    m_palaceView = new QLabel;
    m_marketView = new QLabel;
    m_marketView->setText("market");
    m_forgeView = new QLabel;
    m_buttonSmid = new QPushButton;
    m_buildingModel = new building();

    addBuildingToScene(scene);
    styleBuilding();

    connect(m_buildingModel, SIGNAL(setHouse()), this, SLOT(setHouse()));
    connect(m_buildingModel, SIGNAL(setTower()), this, SLOT(setTower()));
    connect(m_buildingModel, SIGNAL(setForge()), this, SLOT(setForge()));
    connect(m_buildingModel, SIGNAL(sold(QString)), this, SLOT(notAvailable(QString)));
    connect(m_buildingModel, SIGNAL(setBuild()), this, SLOT(setAllBuildings()));
}

buildingView::~buildingView()
{
    delete m_buildingModel;
    delete m_towerView;
    delete m_houseView;
    delete m_keepView;
    delete m_tavernView;
    delete m_bigGateView;
    delete m_smallGateView;
    delete m_stableView;
    delete m_servantsHouseView;
    delete m_palaceView;
    delete m_forgeView;
    delete m_marketView;
}

//getters&setters
QPushButton *buildingView::getButtonSmid()
{
    return m_buttonSmid;
}
void buildingView::setForge()
{
    const QString text = QStringLiteral("forge\n zilverstukken: %1").arg(QString::number(m_buildingModel->getForgeSilver()));
    m_forgeView->setText(text);
}

building *buildingView::getBuilding() const
{
    return m_buildingModel;
}

void buildingView::setHouse()
{
    const QString text = QStringLiteral("Huis\nGR: %1  P: %2\naantal beschikbaar: %3").arg(QString::number(m_buildingModel->getHouse()->getResources()), QString::number(m_buildingModel->getHouse()->getPoints()), QString::number(m_buildingModel->getHouse()->getAvailable()));
    m_houseView->setText(text);
}
void buildingView::setTower()
{
    const QString text = QStringLiteral("Toren\nGR: %1  P: %2\naantal beschikbaar: %3").arg(QString::number(m_buildingModel->getTower()->getResources()), QString::number(m_buildingModel->getTower()->getPoints()), QString::number(m_buildingModel->getTower()->getAvailable()));
    m_towerView->setText(text);
}

void buildingView::setBuilding(QLabel *member, buildingInfo *memberInfo)
{
    const QString buildingText = QStringLiteral("%1\nGR: %2  P: %3").arg( memberInfo->getName(), QString::number(memberInfo->getResources()), QString::number(memberInfo->getPoints()));
    member->setText(buildingText);

    if(!memberInfo->getBuildOrNot()) //gebouwd? zet niet beschikbaar
    {
        notAvailable(memberInfo->getName());
    }
}

void buildingView::setAllBuildings()
{
    setHouse();
    setTower();
    setBuilding(m_keepView, m_buildingModel->getKeep());
    setBuilding(m_tavernView, m_buildingModel->getTavern());
    setBuilding(m_bigGateView, m_buildingModel->getBigGate());
    setBuilding(m_smallGateView, m_buildingModel->getSmallGate());
    setBuilding(m_stableView, m_buildingModel->getStable());
    setBuilding(m_servantsHouseView, m_buildingModel->getServantsHouse());
    setBuilding(m_palaceView, m_buildingModel->getPalace());
    setForge();
}

//fucntie om de gebouwen te updaten als ze gebouwd zijn
void buildingView::notAvailable(QString building)
{
    QLabel *member;

    if(building == m_buildingModel->getHouse()->getName()){ member = m_houseView;}
    else if(building == m_buildingModel->getTower()->getName()){member = m_towerView;}
    else if(building == m_buildingModel->getKeep()->getName()){member = m_keepView;}
    else if(building == m_buildingModel->getTavern()->getName()){member = m_tavernView;}
    else if(building == m_buildingModel->getBigGate()->getName()){member = m_bigGateView;}
    else if(building == m_buildingModel->getSmallGate()->getName()){member = m_smallGateView;}
    else if(building == m_buildingModel->getStable()->getName()){member = m_stableView;}
    else if(building == m_buildingModel->getServantsHouse()->getName()){member = m_servantsHouseView;}
    else if(building == m_buildingModel->getPalace()->getName()){member = m_palaceView;}
    else{member = nullptr;} //geef error terug?

    member->setStyleSheet("QLabel {background-color : black; color: white; font-weight: bold;}");
}


void buildingView::addBuildingToScene(QGraphicsScene *scene)
{
    scene->addWidget(m_houseView);
    scene->addWidget(m_towerView);
    scene->addWidget(m_keepView);
    scene->addWidget(m_tavernView);
    scene->addWidget(m_bigGateView);
    scene->addWidget(m_smallGateView);
    scene->addWidget(m_stableView);
    scene->addWidget(m_servantsHouseView);
    scene->addWidget(m_palaceView);
    scene->addWidget(m_forgeView);
    scene->addWidget(m_marketView);
    scene->addWidget(m_buttonSmid);
}

void buildingView::styleBuilding()
{
    int widthHeightBuilding{140};
    int xOne{10};
    int xyExtra{150};
    int yOne{0};

    m_houseView->setGeometry(xOne, yOne, widthHeightBuilding, widthHeightBuilding);
    m_houseView->setAlignment(Qt::AlignCenter);
    m_towerView->setGeometry(xOne+xyExtra, yOne, widthHeightBuilding, widthHeightBuilding);
    m_towerView->setAlignment(Qt::AlignCenter);
    m_keepView->setGeometry(xOne+xyExtra*2, yOne, widthHeightBuilding, widthHeightBuilding);
    m_keepView->setAlignment(Qt::AlignCenter);
    m_tavernView->setGeometry(xOne, yOne+xyExtra, widthHeightBuilding, widthHeightBuilding);
    m_tavernView->setAlignment(Qt::AlignCenter);
    m_bigGateView->setGeometry(xOne+xyExtra, yOne+xyExtra, widthHeightBuilding, widthHeightBuilding);
    m_bigGateView->setAlignment(Qt::AlignCenter);
    m_smallGateView->setGeometry(xOne+xyExtra*2, yOne+xyExtra, widthHeightBuilding, widthHeightBuilding);
    m_smallGateView->setAlignment(Qt::AlignCenter);
    m_stableView->setGeometry(xOne, yOne+xyExtra*2, widthHeightBuilding, widthHeightBuilding);
    m_stableView->setAlignment(Qt::AlignCenter);
    m_servantsHouseView->setGeometry(xOne+xyExtra, yOne+xyExtra*2, widthHeightBuilding, widthHeightBuilding);
    m_servantsHouseView->setAlignment(Qt::AlignCenter);
    m_palaceView->setGeometry(xOne+xyExtra*2, yOne+xyExtra*2, widthHeightBuilding, widthHeightBuilding);
    m_palaceView->setAlignment(Qt::AlignCenter);
    m_forgeView->setGeometry(xOne+xyExtra, yOne+xyExtra*3,widthHeightBuilding, widthHeightBuilding );
    m_forgeView->setAlignment(Qt::AlignCenter);
    m_marketView->setGeometry(xOne+xyExtra*2, yOne+xyExtra*3, widthHeightBuilding, widthHeightBuilding);
    m_marketView->setAlignment(Qt::AlignCenter);
    m_buttonSmid->setGeometry(500, 270, 50, 30);
    m_buttonSmid->setText("SMID");
}
