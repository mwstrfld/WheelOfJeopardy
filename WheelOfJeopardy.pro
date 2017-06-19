QT      += core \
           gui \
           widgets
 
CONFIG  += c++11 

SOURCES += main.cpp \
           WheelOfFortuneBoard.cpp

HEADERS += WheelOfFortuneBoard.h

FORMS   += WheelOfFortuneBoard.ui

TARGET   = WheelOfJeopardy
TEMPLATE = app

Release: DESTDIR     = build/release
Release: OBJECTS_DIR = build/release/.o
Release: MOC_DIR     = build/release/.moc
Release: RCC_DIR     = build/release/.rcc
Release: UI_DIR      = build/release/.ui

Debug: DESTDIR     = build/debug
Debug: OBJECTS_DIR = build/debug/.o
Debug: MOC_DIR     = build/debug/.moc
Debug: RCC_DIR     = build/debug/.rcc
Debug: UI_DIR      = build/debug/.ui
