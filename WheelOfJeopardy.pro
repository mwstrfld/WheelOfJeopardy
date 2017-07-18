QT      += core \
           gui \
           widgets
 
CONFIG  += c++11 

SOURCES  += main.cpp \
            WheelOfFortuneBoard.cpp \
            JeopardyBoard.cpp \
            QuestionAndAnswerFacilitator.cpp \
            PointManager.cpp

HEADERS  += WheelOfJeopardyTypes.h \
            WheelOfFortuneBoard.h \
            JeopardyBoard.h \
            QuestionAndAnswerFacilitator.h \
            PointManager.h

FORMS    += WheelOfFortuneBoard.ui \
            JeopardyBoard.ui

TARGET    = WheelOfJeopardy
TEMPLATE  = app

RESOURCES = WheelOfJeopardy.qrc
