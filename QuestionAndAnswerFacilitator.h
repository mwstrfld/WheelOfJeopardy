#pragma once


#include <QPair>
#include <QVector>

#include <WheelOfJeopardyTypes.h>


class QuestionAndAnswerFacilitator
{
public:
    QuestionAndAnswerFacilitator();
    ~QuestionAndAnswerFacilitator();

    // Main function for getting the next question and answer
    QPair<QString, QString> getNextQuestionAndAnswer( Types::Category category );

    // Getter for the category headings
    const QStringList& getCategories() const;

    // Second round reset
    void resetForSecondRound();

protected:
    // Resets indices to zero and clears "maps"
    void reset();

    // Actual categories
    QStringList m_categories;

    // Category Indices and Qustion to Anser "Maps"
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
