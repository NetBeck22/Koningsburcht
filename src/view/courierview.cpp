#include "courierView.h"
/*auteur: Nette Beckers*/

courierView::courierView(QGraphicsScene *scene)
{
    m_silverCourier = new QLabel();
    m_sandCourier = new QLabel();
    m_clayCourier = new QLabel();
    m_stoneCourier = new QLabel();
    m_woodCourier = new QLabel();
    m_courierModel = new courier;
    m_helperSand = new QPushButton;
    m_helperWood = new QPushButton;
    m_helperClay = new QPushButton;
    m_helperStone = new QPushButton;
    m_helperSilver = new QPushButton;

    setResourcesView(SAND);
    setResourcesView(WOOD);
    setResourcesView(CLAY);
    setResourcesView(STONE);
    setResourcesView(SILVER);

    scene->addWidget(m_silverCourier);
    scene->addWidget(m_woodCourier);
    scene->addWidget(m_stoneCourier);
    scene->addWidget(m_clayCourier);
    scene->addWidget(m_sandCourier);
    scene->addWidget(m_helperSand);
    scene->addWidget(m_helperWood);
    scene->addWidget(m_helperClay);
    scene->addWidget(m_helperStone);
    scene->addWidget(m_helperSilver);

    courierLayout();

    connect(m_courierModel, SIGNAL(updateResource(int)), this, SLOT(setResourcesView(int)));
}

//getters&setters
courierView::~courierView()
{
    delete m_courierModel;
    delete m_sandCourier;
    delete m_stoneCourier;
    delete m_woodCourier;
    delete m_silverCourier;
    delete m_clayCourier;
}

QPushButton *courierView::getbuttonSand()
{
    return m_helperSand;
}

QPushButton *courierView::getbuttonWood()
{
    return m_helperWood;
}

QPushButton *courierView::getbuttonClay()
{
    return m_helperClay;
}

QPushButton *courierView::getbuttonStone()
{
    return m_helperStone;
}

QPushButton *courierView::getbuttonSilver()
{
    return m_helperSilver;
}

void courierView::setResourcesView(int resource)
{
    switch(resource)
    {
    case SAND:
        m_sandCourier->setText(QString::number(m_courierModel->getSand()));
        break;
    case WOOD:
        m_woodCourier->setText(QString::number(m_courierModel->getWood()));
        break;
    case CLAY:
        m_clayCourier->setText(QString::number(m_courierModel->getClay()));
        break;
    case STONE:
        m_stoneCourier->setText(QString::number(m_courierModel->getStone()));
        break;
    case SILVER:
        m_silverCourier->setText(QString::number(m_courierModel->getSilver()));
        break;
    default:
        break;
    }
}
courier * courierView::getCourier() const
{
    return m_courierModel;
}

void courierView::clickedResources(int resource, QString text, int player)
{
    switch(resource)
    {
    case SAND:
        m_courierModel->setPlayer(SAND, player);
        m_helperSand->setStyleSheet(text);
        break;
    case WOOD:
        m_courierModel->setPlayer(WOOD, player);
        m_helperWood->setStyleSheet(text);
        break;
    case CLAY:
        m_courierModel->setPlayer(CLAY, player);
        m_helperClay->setStyleSheet(text);
        break;
    case STONE:
        m_courierModel->setPlayer(STONE, player);
        m_helperStone->setStyleSheet(text);
        break;
    case SILVER:
        m_courierModel->setPlayer(SILVER, player);
        m_helperSilver->setStyleSheet(text);
        break;
    default:
        break;
    }
}

void courierView::courierLayout()
{
    int widthHeightCourier{50};
    int yCourier{600};

    m_sandCourier->setGeometry(10, yCourier, widthHeightCourier, widthHeightCourier);
    m_sandCourier->setAlignment(Qt::AlignCenter);
    m_sandCourier->setStyleSheet("QLabel {background-color : #bd962d; color: white; font-weight: bold; font-size : 20pt;}");
    m_woodCourier->setGeometry(102, yCourier, widthHeightCourier, widthHeightCourier);
    m_woodCourier->setAlignment(Qt::AlignCenter);
    m_woodCourier->setStyleSheet("QLabel {background-color : #451116; color: white; font-weight: bold; font-size : 20pt;}");
    m_clayCourier->setGeometry(205, yCourier, widthHeightCourier, widthHeightCourier);
    m_clayCourier->setAlignment(Qt::AlignCenter);
    m_clayCourier->setStyleSheet("QLabel {background-color :#85141b; color: white; font-weight: bold; font-size : 20pt;}");
    m_stoneCourier->setGeometry(307, yCourier, widthHeightCourier, widthHeightCourier);
    m_stoneCourier->setAlignment(Qt::AlignCenter);
    m_stoneCourier->setStyleSheet("QLabel {background-color : black; color: white; font-weight: bold; font-size : 20pt;}");
    m_silverCourier->setGeometry(400, yCourier, widthHeightCourier, widthHeightCourier);
    m_silverCourier->setAlignment(Qt::AlignCenter);
    m_silverCourier->setStyleSheet("QLabel {background-color : silver; color: white; font-weight: bold; font-size : 20pt;}");

    m_helperSand->setGeometry(10, 660, widthHeightCourier, 30);
    m_helperWood->setGeometry(102, 660, widthHeightCourier, 30);
    m_helperClay->setGeometry(205, 660, widthHeightCourier, 30);
    m_helperStone->setGeometry(307, 660, widthHeightCourier, 30);
    m_helperSilver->setGeometry(400, 660, widthHeightCourier, 30);
}
