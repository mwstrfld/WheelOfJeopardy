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

    void reset();
    void resetForSecondRound();

protected:
    // Do for each category
    quint8 m_category1CurrentId;
    QVector< QPair<QString, QString> > m_category1QuestionToAnswerMap;
    quint8 m_category2CurrentId;
    QVector< QPair<QString, QString> > m_category2QuestionToAnswerMap;
    quint8 m_category3CurrentId;
    QVector< QPair<QString, QString> > m_category3QuestionToAnswerMap;
    quint8 m_category4CurrentId;
    QVector< QPair<QString, QString> > m_category4QuestionToAnswerMap;
    quint8 m_category5CurrentId;
    QVector< QPair<QString, QString> > m_category5QuestionToAnswerMap;
    quint8 m_category6CurrentId;
    QVector< QPair<QString, QString> > m_category6QuestionToAnswerMap;
};
