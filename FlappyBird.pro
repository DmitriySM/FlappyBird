TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio
LIBS += -lsfml-graphics
LIBS += -lsfml-network
LIBS += -lsfml-window
LIBS += -lsfml-system

SOURCES += \
    Game/game.cpp \
    Menu/menu.cpp \
    Objects/background.cpp \
    Objects/gameobject.cpp \
    Objects/ground.cpp \
    Objects/obstacle.cpp \
    Objects/penguin.cpp \
    Score/score.cpp \
    main.cpp

HEADERS += \
    Game/game.h \
    Menu/menu.h \
    Objects/background.h \
    Objects/gameobject.h \
    Objects/ground.h \
    Objects/obstacle.h \
    Objects/penguin.h \
    Score/score.h

DISTFILES += \
    Images/bkg1.png \
    Images/bkg2.png \
    Images/gnd1.png \
    Images/gnd2.png \
    Images/main_menu_exit.png \
    Images/main_menu_normal.png \
    Images/main_menu_play.png \
    Images/main_menu_score.png \
    Images/obstacleh.png \
    Images/penguin.png \
    Fonts/Xcelsion.ttf \
    Fonts/Xcelsion.ttf \
    Images/bkg1.png \
    Images/bkg2.png \
    Images/gnd.png \
    Images/gnd1.png \
    Images/gnd2.png \
    Images/main_menu_exit.png \
    Images/main_menu_normal.png \
    Images/main_menu_play.png \
    Images/main_menu_score.png \
    Images/obstacleh.png \
    Images/penguin.png \
    Files/score.txt

SUBDIRS += \
    FlappyBird.pro
