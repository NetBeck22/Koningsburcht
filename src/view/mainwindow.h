#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gameView.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QGraphicsScene;
class QGraphicsView;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    gameView *m_game;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene{};
    QGraphicsView *view{};

};

#endif // MAINWINDOW_H
