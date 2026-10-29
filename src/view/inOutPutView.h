#ifndef INOUTPUTVIEW_H
#define INOUTPUTVIEW_H

#include <QLabel>
#include <QSpinBox>
#include <QGraphicsScene>
#include <QPushButton>
#include <QObject>

class inOutPutView : public QObject
{
    Q_OBJECT
public:
    inOutPutView(QGraphicsScene *scene);
};


#endif // INOUTPUTVIEW_H
