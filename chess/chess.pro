TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle


QT += core gui \
      widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES += images.qrc \
    images.qrc

SOURCES += \
        game.cpp \
        main.cpp \
        mainwindow.cpp \
        piece.cpp \
        pieces/cavalier.cpp \
        pieces/dame.cpp \
        pieces/fou.cpp \
        pieces/pion.cpp \
        pieces/roi.cpp \
        pieces/tour.cpp \
        player.cpp

HEADERS += \
    ChessMovesModel.h \
    enum.h \
    game.h \
    mainwindow.h \
    piece.h \
    pieces/cavalier.h \
    pieces/dame.h \
    pieces/fou.h \
    pieces/pion.h \
    pieces/roi.h \
    pieces/tour.h \
    player.h

FORMS += \
    mainwindow.ui

