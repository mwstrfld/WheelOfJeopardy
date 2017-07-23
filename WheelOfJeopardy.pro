QT      += core \
           gui \
           widgets
 
CONFIG  += c++11 

SOURCES  += main.cpp \
            WheelOfFortuneBoard.cpp \
            JeopardyBoard.cpp \
            QuestionAndAnswerFacilitator.cpp \
            PointManager.cpp \
            QuestionDialog.cpp \
            CategorySelectorDialog.cpp

HEADERS  += WheelOfJeopardyTypes.h \
            WheelOfFortuneBoard.h \
            JeopardyBoard.h \
            QuestionAndAnswerFacilitator.h \
            PointManager.h \
            QuestionDialog.h \
            CategorySelectorDialog.h

FORMS    += WheelOfFortuneBoard.ui \
            JeopardyBoard.ui \
            QuestionDialog.ui \
            CategorySelectorDialog.ui

TARGET    = WheelOfJeopardy
TEMPLATE  = app

RESOURCES = WheelOfJeopardy.qrc
