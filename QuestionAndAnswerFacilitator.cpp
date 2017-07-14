#include <QuestionAndAnswerFacilitator.h>


QuestionAndAnswerFacilitator::QuestionAndAnswerFacilitator()
    : m_category1CurrentId( 0 ),
      m_category1QuestionToAnserMap()
{
    // TODO: Setup questions here
    // 5 entries within each category map
    m_category1QuestionToAnserMap.push_back( QPair<QString, QString>( "What color is the sky?", "Blue" ) );
}


QuestionAndAnswerFacilitator::~QuestionAndAnswerFacilitator()
{
}


QPair<QString, QString> QuestionAndAnswerFacilitator::getNextQuestionAndAnswer( Types::Category category )
{
    // TODO: Create switch-case statement on Category type (similar to
    //       WheelOfFortuneBoard::actUponNewSector), pick the next item
    //       in the selected category's map, and advance the current
    //       category ID for that particular map.  Something like:
    QPair< QString, QString > retVal;

    switch( category )
    {
    case Types::Category1:
        retVal = m_category1QuestionToAnserMap.at( m_category1CurrentId++ );
        break;
    }

    return retVal;
}
