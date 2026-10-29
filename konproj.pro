QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    boardview.cpp \
    brickLayerCard.cpp \
    building.cpp \
    buildingView.cpp \
    buildinginfo.cpp \
    cards.cpp \
    cardsview.cpp \
    courier.cpp \
    courierview.cpp \
    defenceTower.cpp \
    defenceTowerView.cpp \
    game.cpp \
    gameview.cpp \
    helpersBuilding.cpp \
    helpersBuildingView.cpp \
    main.cpp \
    mainwindow.cpp \
    masterBuilderCard.cpp \
    messengercard.cpp \
    player.cpp \
    playerview.cpp \
    resources.cpp \
    traderCard.cpp

HEADERS += \
    BuildingView.h \
    Game.h \
    board.h \
    boardView.h \
    brickLayerCard.h \
    building.h \
    buildingInfo.h \
    cards.h \
    cardsView.h \
    courier.h \
    courierView.h \
    defenceTower.h \
    defenceTowerView.h \
    gameView.h \
    helpersBuilding.h \
    helpersBuildingView.h \
    mainwindow.h \
    masterBuilderCard.h \
    messengerCard.h \
    player.h \
    playerView.h \
    resources.h \
    traderCard.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gameData.qrc


