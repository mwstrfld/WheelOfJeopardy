QT      += core \
           gui \
           widgets
 
CONFIG  += c++11 

SOURCES  += main.cpp \
            WheelOfFortuneBoard.cpp \
            JeopardyBoard.cpp

HEADERS  += WheelOfFortuneBoard.h \
            JeopardyBoard.h

FORMS    += WheelOfFortuneBoard.ui \
            JeopardyBoard.ui

TARGET    = WheelOfJeopardy
TEMPLATE  = app

RESOURCES = WheelOfJeopardy.qrc
