#include "defenceTowerView.h"
/*auteur: Nette Beckers*/

defenceTowerView::defenceTowerView(QGraphicsScene *scene)
{
    m_defenceTower = new QLabel;
    m_defenceTowerModel = new defenceTower;
    setDefenceTower();
    scene->addWidget(m_defenceTower);
    m_defenceTower->setGeometry(10, 450, 140, 140);
    m_defenceTower->setAlignment(Qt::AlignCenter);

    connect(m_defenceTowerModel, SIGNAL(updateResources()), this, SLOT(setDefenceTower()));
}

defenceTowerView::~defenceTowerView()
{
    delete m_defenceTowerModel;
    delete m_defenceTower;
}

//getters&setters
void defenceTowerView::setDefenceTower()
{
    const QString text{QString("defenceTower\nSand: %1\nWood: %2\nClay: %3\n").arg(QString::number(m_defenceTowerModel->getSand()),QString::number(m_defenceTowerModel->getWood()),QString::number(m_defenceTowerModel->getClay()))
            + QString("Stone: %1\nSilver: %2").arg(QString::number(m_defenceTowerModel->getStone()), QString::number(m_defenceTowerModel->getSilver()))};
    m_defenceTower->setText(text);
}

defenceTower *defenceTowerView::getdefenceTower() const
{
    return m_defenceTowerModel;
}
