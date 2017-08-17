#include <QuestionAndAnswerFacilitator.h>


QuestionAndAnswerFacilitator::QuestionAndAnswerFacilitator()
    : m_categories(),
      m_category1CurrentId( 0 ),
      m_category1QuestionToAnswerMap(),
      m_category2CurrentId( 0 ),
      m_category2QuestionToAnswerMap(),
      m_category3CurrentId( 0 ),
      m_category3QuestionToAnswerMap(),
      m_category4CurrentId( 0 ),
      m_category4QuestionToAnswerMap(),
      m_category5CurrentId( 0 ),
      m_category5QuestionToAnswerMap(),
      m_category6CurrentId( 0 ),
      m_category6QuestionToAnswerMap()
{
    // Category 1: American Presidents
    m_categories << "American\nPresidents";
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the first American President?", "George Washington" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "What are the maximum number of terms a President can serve?", "2" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the first African-American President?", "Barack Obama" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the President during the Civil War?", "Abraham Lincoln" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who was the first President to die in office?", "William Henry Harrison" ) );

    // Category 2: Sports
    m_categories << "Sports";
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "How many players are on a basketball court at once?", "10" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "How many innings are in a baseball game?", "9" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who is the most decorated olympian?", "Michael Phelps" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which Grand Slam tennis tournament is held every January?", "Austrailian Open" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who won the first NFL Super Bowl?", "Green Bay Packers" ) );

    // Category 3: U.S. State Capitals
    m_categories << "U.S. State\nCapitals";
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Texas?", "Austin" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Maryland?", "Annapolis" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of California?", "Sacramento" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Minnesota?", "St. Paul" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the capital of Arizona?", "Phoenix" ) );

    // Category 4: Name that Song
    m_categories << "Name that\nSong";
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"My loneliness is killin' me I must confess I still believe When I'm not with you I lose my mind Give me a sign,\"", "Baby One More Time" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"You may think that I'm a dreamer But I'm not the only one I hope someday you'll join us And the world will live as one\"", "Imagine" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"I hear babies crying, I watch them grow They'll learn much more than I'll ever know And I think to myself,\"", "What a Wonderful World" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"Oh, as long as I know how to love I know I'll stay alive I've got all my life to live and I've got all my love to give\"", "I Will Survive" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Name this song: \"Skies are blue And the dreams that you dare to dream really do come true If happy little bluebirds Beyond the rainbow Why, oh why, can't I?\"", "Somewhere Over the Rainbow" ) );

    // Cateogry 5: Let's Go to the Movies
    m_categories << "Go to\nthe Movies";
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who directed the famous film Jurassic Park?", "Steven Speilberg" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which famous actor played the Termintaor?", "Arnold Schwarzenegger" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "As of 2017, which movie is the highest-grossing film in history?", "Avatar" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "The first movie of the Fast and Furious franchise was released in what year?", "2001" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "In movie ratings, what do the letters PG stand for?", "Parental guidance" ) );

    // Cateogry 6: Months of the Year
    m_categories << "Months\nof Year";
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


const QStringList& QuestionAndAnswerFacilitator::getCategories() const
{
    return m_categories;
}


QPair<QString, QString> QuestionAndAnswerFacilitator::getNextQuestionAndAnswer( Types::Category category )
{
    QPair< QString, QString > retVal;

    switch( category )
    {
    case Types::Category1:
        if( m_category1CurrentId < 5 )
            retVal = m_category1QuestionToAnswerMap.at( m_category1CurrentId++ );
        break;
    case Types::Category2:
        if( m_category2CurrentId < 5 )
            retVal = m_category2QuestionToAnswerMap.at( m_category2CurrentId++ );
        break;
    case Types::Category3:
        if( m_category3CurrentId < 5 )
            retVal = m_category3QuestionToAnswerMap.at( m_category3CurrentId++ );
        break;
    case Types::Category4:
        if( m_category4CurrentId < 5 )
            retVal = m_category4QuestionToAnswerMap.at( m_category4CurrentId++ );
        break;
    case Types::Category5:
        if( m_category5CurrentId < 5 )
            retVal = m_category5QuestionToAnswerMap.at( m_category5CurrentId++ );
        break;
    case Types::Category6:
        if( m_category6CurrentId < 5 )
            retVal = m_category6QuestionToAnswerMap.at( m_category6CurrentId++ );
        break;
    }

    return retVal;
}


void QuestionAndAnswerFacilitator::reset()
{
    // Clear categories
    m_categories.clear();

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

    // Category 1: Automobile Manufacturers
    m_categories << "Automobile\nManufacturers";
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which car company's logo has four silver rings?", "Audi" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which car company has the slogan: 'Zoom, zoom'?", "Mazda" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which young American car company makes only electric vehicles?", "Tesla" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which car company produced the Model T in 1908?", "Ford" ) );
    m_category1QuestionToAnswerMap.push_back( QPair<QString, QString>( "The Carrera is a model produced by which automobile manufacturer?", "Porsche" ) );

    // Category 2: Famous Quotes
    m_categories << "Famouts\nQuotes";
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who said this: \"I have a dream that my four children will one day live in a nation where they will not be judged by the color of their skin, but by the content of their character.\"", "Martin Luther King Jr." ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who said this: \"Mr. Gorbachev, tear down this wall!\"", "Ronald Reagan" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who said this: \"I came. I saw. I conquered.\"", "Julius Caesar" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who authored the character, Prince Hamlet's famous quote: \"To be, or not to be, that is the question\"", "William Shakespeare" ) );
    m_category2QuestionToAnswerMap.push_back( QPair<QString, QString>( "Who said this: \"Anyone who has never made a mistake has never tried anything new.\"", "Albert Einstein" ) );

    // Category 3: College Sports
    m_categories << "College\nSports";
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What men’s NCAA championship did University of Maryland, College Park win in 2017?", "Lacrosse" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the full name of the university that won March Madness in 2015?", "Duke University" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is University of Indiana’s mascot?", "Hoosier" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "How many teams are in the Big 10 Conference?", "14" ) );
    m_category3QuestionToAnswerMap.push_back( QPair<QString, QString>( "What University of Maryland, CP alumni played football in college and went on to start his own sports, footwear, and casual apparel brand?", "Kevin Plank" ) );

    // Category 4: TV Shows
    m_categories << "TV Shows";
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the first name of the character played by Jennifer Anniston in the show Friends?", "Rachel" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the character name of the female protagonist on the show Parks and Recreation?", "Leslie Knope" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which of the following shows is not a Netflix original series: House of Cards, Stranger Things, The Office, or Jessica Jones?", "The Office" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "What show features these 2 family names: Stark and Lannister?", "Game of Thrones" ) );
    m_category4QuestionToAnswerMap.push_back( QPair<QString, QString>( "What year did the first episode of The Big Bang Theory air?", "2007" ) );

    // Cateogry 5: Fast Food
    m_categories << "Fast Food";
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "What fast food restaurant has the slogan \"Eat Mor Chikin\"", "Chick Fil A" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the name of the coffee shop the characters on the show Friends hung out at?", "Central Perk" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "What is the full name of the Mexican fast food restaurant that is known for its burrito, burrito bowl, and 100% recyclable take out bags?", "Chipotle Mexican Grill" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "It is impossible to be more than 115 miles from which fast food restaurant in the continental USA?", "McDonald's" ) );
    m_category5QuestionToAnswerMap.push_back( QPair<QString, QString>( "Which fast food restaurant is called \"Hungry Jack's\" in Australia?", "Burger King" ) );

    // Cateogry 6: Brands
    m_categories << "Brands";
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("What company/brand was founded by Steve Jobs?", "Apple"));
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("What athletic brand logo is known for its three stripes?", "Adidas"));
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("The Pepsi logo has 3 colors: blue, red, and ___?	", "White"));
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("What company has a two-tailed mermaid as its logo?", "Starbucks"));
    m_category6QuestionToAnswerMap.push_back( QPair<QString, QString>("Who is the founder of SpaceX?", "Elon Musk"));
}
