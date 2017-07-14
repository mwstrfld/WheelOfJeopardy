#pragma once


#include <QPair>
#include <QVector>

#include <WheelOfJeopardyTypes.h>


class QuestionAndAnswerFacilitator
{
public:
    QuestionAndAnswerFacilitator();
    ~QuestionAndAnswerFacilitator();

    QPair<QString, QString> getNextQuestionAndAnswer( Types::Category category );

protected:
    // Do for each category
    quint8 m_category1CurrentId;
    QVector< QPair<QString, QString> > m_category1QuestionToAnserMap;
};
