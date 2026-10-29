#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include<QHBoxLayout>

#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    ui->setupUi(this);
    this->setWindowTitle("Koningsburcht");
    scene = new QGraphicsScene{this};
    view = new QGraphicsView{scene, this};
    setCentralWidget(view);

    m_game = new gameView{scene};

}

MainWindow::~MainWindow()
{
    delete ui;
    delete view;
    delete scene;
}

