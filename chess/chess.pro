TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        game.cpp \
        main.cpp \
        piece.cpp \
        pieces/pion.cpp \
        player.cpp \
        vector2.cpp

HEADERS += \
    enum.h \
    game.h \
    piece.h \
    pieces/pion.h \
    player.h \
    vector2.h

