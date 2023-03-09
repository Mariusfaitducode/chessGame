TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        game.cpp \
        main.cpp \
        piece.cpp \
        pieces/cavalier.cpp \
        pieces/dame.cpp \
        pieces/fou.cpp \
        pieces/pion.cpp \
        pieces/roi.cpp \
        pieces/tour.cpp \
        player.cpp

HEADERS += \
    enum.h \
    game.h \
    piece.h \
    pieces/cavalier.h \
    pieces/dame.h \
    pieces/fou.h \
    pieces/pion.h \
    pieces/roi.h \
    pieces/tour.h \
    player.h

