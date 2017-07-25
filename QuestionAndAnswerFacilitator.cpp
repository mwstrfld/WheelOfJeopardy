#include <QuestionAndAnswerFacilitator.h>


QuestionAndAnswerFacilitator::QuestionAndAnswerFacilitator()
    : m_category1CurrentId( 0 ),
      m_category1QuestionToAnswerMap(),
      m_category2CurrentId( 0 ),
      m_category2QuestionToAnswerMap(),
      m_category3CurrentId( 0 ),
      m_category3QuestionToAnswerMap(),
      m_category4CurrentId( 0 ),
      m_category4QuestionToAnswerMap(),
      m_category5CurrentId( 0 ),
      m_category5QuestionToAnswerMap()
{
    // Category 1: American Presidents
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the first American President?", "George Washington" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "What are the maximum number of terms a President can serve?", "2" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the first African-American President?", "Barack Obama" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the President during the Civil War?", "Abraham Lincoln" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the first President to die in office?", "William Henry Harrison" ) );

    // Category 2: Sports
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "How many players are on a basketball court at once?", "10" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "How many innings are in a baseball game?", "9" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who is the most decorated olympian?", "Michael Phelps" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which Grand Slam tennis tournament is held every January?", "Austrailian Open" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who won the first NFL Super Bowl?", "Green Bay Packers" ) );

    // Category 3: U.S. State Capitals
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Texas?", "Austin" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Maryland?", "Annapolis" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of California?", "Sacramento" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Minnesota?", "St. Paul" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Arizona?", "Phoenix" ) );

    // Category 4: Name that Song
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"My loneliness is killin' me I must confess I still believe When I'm not with you I lose my mind Give me a sign,\"", "Baby One More Time" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"You may think that I'm a dreamer But I'm not the only one I hope someday you'll join us And the world will live as one\"", "Imagine" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"I hear babies crying, I watch them grow They'll learn much more than I'll ever know And I think to myself,\"", "What a Wonderful World" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"Oh, as long as I know how to love I know I'll stay alive I've got all my life to live and I've got all my love to give\"", "I Will Survive" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"Skies are blue And the dreams that you dare to dream really do come true If happy little bluebirds Beyond the rainbow Why, oh why, can't I?\"", "Somewhere Over the Rainbow" ) );

    // Cateogry 5: Let's Go to the Movies
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who directed the famous film Jurassic Park?", "Steven Speilberg" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which famous actor played the Termintaor?", "Arnold Schwarzenegger" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "As of 2017, which movie is the highest-grossing film in history?", "Avatar" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "The first movie of the Fast and Furious franchise was released in what year?", "2001" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "In movie ratings, what do the letters PG stand for?", "Parental guidance" ) );

    // Cateogry 6: Months of the Year
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("In which month is the shortest day of the year?", "December"));
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("In which month is Columbus Day?", "October"));
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("Black Friday is a popular day for businesses and is in this month.", "November"));
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("This month has the shortest number of days.", "February"));
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("In which month did the United States of America obtain its independence?", "July"));
}


QuestionAndAnswerFacilitator::~QuestionAndAnswerFacilitator()
{
    reset();
}


QPair<QString, QString> QuestionAndAnswerFacilitator::getNextQuestionAndAnswer( Types::Category category )
{
    QPair< QString, QString > retVal;

    switch( category )
    {
    case Types::Category1:
        if( m_category1CurrentId < 6 )
            retVal = m_category1QuestionToAnswerMap.at( m_category1CurrentId++ );
        break;
    case Types::Category2:
        if( m_category2CurrentId < 6 )
            retVal = m_category2QuestionToAnswerMap.at( m_category2CurrentId++ );
        break;
    case Types::Category3:
        if( m_category3CurrentId < 6 )
            retVal = m_category3QuestionToAnswerMap.at( m_category3CurrentId++ );
        break;
    case Types::Category4:
        if( m_category4CurrentId < 6 )
            retVal = m_category4QuestionToAnswerMap.at( m_category4CurrentId++ );
        break;
    case Types::Category5:
        if( m_category5CurrentId < 6 )
            retVal = m_category5QuestionToAnswerMap.at( m_category5CurrentId++ );
        break;
    case Types::Category6:
        if( m_category6CurrentId < 6 )
            retVal = m_category6QuestionToAnswerMap.at( m_category6CurrentId++ );
        break;
    }

    return retVal;
}


void QuestionAndAnswerFacilitator::reset()
{
    // Reset indices
    m_category1CurrentId = 0;
    m_category2CurrentId = 0;
    m_category3CurrentId = 0;
    m_category4CurrentId = 0;
    m_category5CurrentId = 0;
    m_category6CurrentId = 0;

    // Clear maps
    m_category1QuestionToAnswerMap.clear();
    m_category2QuestionToAnswerMap.clear();
    m_category3QuestionToAnswerMap.clear();
    m_category4QuestionToAnswerMap.clear();
    m_category5QuestionToAnswerMap.clear();
    m_category6QuestionToAnswerMap.clear();
}


void QuestionAndAnswerFacilitator::resetForSecondRound()
{
    // Call main reset
    reset();

    // TODO: Add new questions
    /*
    // Category 1: American Presidents
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the first American President?", "George Washington" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "What are the maximum number of terms a President can serve?", "2" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the first African-American President?", "Barack Obama" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the President during the Civil War?", "Abraham Lincoln" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the first President to die in office?", "William Henry Harrison" ) );

    // Category 2: Sports
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "How many players are on a basketball court at once?", "10" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "How many innings are in a baseball game?", "9" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who is the most decorated olympian?", "Michael Phelps" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which Grand Slam tennis tournament is held every January?", "Austrailian Open" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who won the first NFL Super Bowl?", "Green Bay Packers" ) );

    // Category 3: U.S. State Capitals
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Texas?", "Austin" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Maryland?", "Annapolis" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of California?", "Sacramento" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Minnesota?", "St. Paul" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Arizona?", "Phoenix" ) );

    // Category 4: Name that Song
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"My loneliness is killin' me I must confess I still believe When I'm not with you I lose my mind Give me a sign,\"", "Baby One More Time" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"You may think that I'm a dreamer But I'm not the only one I hope someday you'll join us And the world will live as one\"", "Imagine" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"I hear babies crying, I watch them grow They'll learn much more than I'll ever know And I think to myself,\"", "What a Wonderful World" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"Oh, as long as I know how to love I know I'll stay alive I've got all my life to live and I've got all my love to give\"", "I Will Survive" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"Skies are blue And the dreams that you dare to dream really do come true If happy little bluebirds Beyond the rainbow Why, oh why, can't I?\"", "Somewhere Over the Rainbow" ) );

    // Cateogry 5: Let's Go to the Movies
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who directed the famous film Jurassic Park?", "Steven Speilberg" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which famous actor played the Termintaor?", "Arnold Schwarzenegger" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "As of 2017, which movie is the highest-grossing film in history?", "Avatar" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "The first movie of the Fast and Furious franchise was released in what year?", "2001" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "In movie ratings, what do the letters PG stand for?", "Parental guidance" ) );

    // Cateogry 6: Months of the Year
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("In which month is the shortest day of the year?", "December"));
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("In which month is Columbus Day?", "October"));
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("Black Friday is a popular day for businesses and is in this month.", "November"));
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("This month has the shortest number of days.", "February"));
    */
}
