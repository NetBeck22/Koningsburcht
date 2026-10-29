#include "boardView.h"
/*auteur: Nette Beckers*/

boardView::boardView(QGraphicsScene *scene)
{
    m_bankView = new QLabel();
    m_roundView = new QLabel();
    m_boardModel = new board();

    makeSummary();
    setBankView();
    setRoundView();

    scene->addWidget(m_summary);
    scene->addWidget(m_bankView);
    scene->addWidget(m_roundView);

    m_bankView->setGeometry(500, 35, 400, 20);
    m_bankView->setStyleSheet("QLabel {background-color : white; color: black; font-weight: bold;}");
    m_roundView->setGeometry(500, 0, 400, 20);
    m_roundView->setStyleSheet("QLabel {background-color : white; color: black; font-weight: bold; font-size : 20pt;}");

    connect(m_boardModel, SIGNAL(updateRound()), this, SLOT(setRoundView()));
    connect(m_boardModel, SIGNAL(updateBank()), this, SLOT(setBankView()));
}

boardView::~boardView()
{
    delete m_boardModel;
    delete m_bankView;
    delete m_roundView;
    delete m_summary;
}

void boardView::makeSummary()
{
    m_summary = new QLabel();
    m_summary->setGeometry(-400,0,400,500);
    m_summary->setStyleSheet("QLabel {background-color : white; color: black; }");
    m_summary->setText("UITLEG\n\n0. VOORBEREIDING: plaats bouwmaterialen op de arbeidskaarten\n\n1. BODE: neemt 8 goudstukken uit de bank\n\n2.HANDELAAR: neemt bouwmaterialen van de ossenkarren \nen de zilverCourier\n\n3. METSELAAR: neemt bouwmaterialen van de wachttoren \n+ bouwt voor goudstukken \n+ zet werklieden in\n\n4. STEENHOUWER:koopt bouwmaterialen van de arbeiders \n+ bouwt voor punten \n+ zet werklieden in\n\n5. ARBEIDER: neemt de bouwmaterialen van de arbeiderskaart \n+ bouwt voor de helft van de punten\n\n6. neemt alle karakterkaarten terug ophand \n+ levert 5 punten per opgericht gebouw\n\nGRONDSTOFFEN\nsilver = ?\nsand = 1\nwood = 2\nclay = 3\nstone = 5");
}

//getters&setters
void boardView::setBankView()
{
    const QString cBank = QString("Er zijn %1 munten in de bank").arg(m_boardModel->getCash());
    m_bankView->setText(cBank);
}

void boardView::setRoundView()
{
    const QString cRound = QString("RONDE %1").arg(m_boardModel->getRound());
    m_roundView->setText(cRound);
}

board *boardView::getBoard()const
{
    return m_boardModel;
}
