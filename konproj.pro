QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \
    src/model \
    src/cards \
    src/view

SOURCES += \
    src/model/board.cpp \
    src/model/building.cpp \
    src/model/buildinginfo.cpp \
    src/model/courier.cpp \
    src/model/defenceTower.cpp \
    src/model/game.cpp \
    src/model/helpersBuilding.cpp \
    src/model/player.cpp \
    src/model/resources.cpp \
    src/cards/brickLayerCard.cpp \
    src/cards/cards.cpp \
    src/cards/masterBuilderCard.cpp \
    src/cards/messengercard.cpp \
    src/cards/traderCard.cpp \
    src/view/boardview.cpp \
    src/view/buildingView.cpp \
    src/view/cardsview.cpp \
    src/view/courierview.cpp \
    src/view/defenceTowerView.cpp \
    src/view/gameview.cpp \
    src/view/helpersBuildingView.cpp \
    src/view/inoutputView.cpp \
    src/view/mainwindow.cpp \
    src/view/playerview.cpp \
    src/main.cpp

HEADERS += \
    src/model/Game.h \
    src/model/board.h \
    src/model/building.h \
    src/model/buildingInfo.h \
    src/model/courier.h \
    src/model/defenceTower.h \
    src/model/helpersBuilding.h \
    src/model/player.h \
    src/model/resources.h \
    src/cards/brickLayerCard.h \
    src/cards/cards.h \
    src/cards/masterBuilderCard.h \
    src/cards/messengerCard.h \
    src/cards/traderCard.h \
    src/view/BuildingView.h \
    src/view/boardView.h \
    src/view/cardsView.h \
    src/view/courierView.h \
    src/view/defenceTowerView.h \
    src/view/gameView.h \
    src/view/helpersBuildingView.h \
    src/view/inOutPutView.h \
    src/view/mainwindow.h \
    src/view/playerView.h

FORMS += \
    src/view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    data/gameData.qrc


