QT      += core \
           gui \
           widgets
 
CONFIG  += c++11 

SOURCES  += main.cpp \
            WheelOfFortuneBoard.cpp \
            JeopardyBoard.cpp \
            QuestionAndAnswerFacilitator.cpp \
            PointManager.cpp \
            QuestionDialog.cpp

HEADERS  += WheelOfJeopardyTypes.h \
            WheelOfFortuneBoard.h \
            JeopardyBoard.h \
            QuestionAndAnswerFacilitator.h \
            PointManager.h \
            QuestionDialog.h

FORMS    += WheelOfFortuneBoard.ui \
            JeopardyBoard.ui \
            QuestionDialog.ui

TARGET    = WheelOfJeopardy
TEMPLATE  = app

RESOURCES = WheelOfJeopardy.qrc
