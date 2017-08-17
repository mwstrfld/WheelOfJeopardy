#include <PointManager.h>


PointManager* PointManager::m_instance = 0;


PointManager* PointManager::instance()
{
    if( !m_instance )
        m_instance = new PointManager();

    return m_instance;
}


void PointManager::addPoints( Types::Player player, Types::FirstRoundPointValue points )
{
    switch( player )
    {
    case Types::Player1:
        if( m_firstRound )
            m_player1Round1Total += (qint32)(points + 1) * 200;
        else
            m_player1Round2Total += (qint32)(points + 1) * 200;
        break;
    case Types::Player2:
        if( m_firstRound )
            m_player2Round1Total += (qint32)(points + 1) * 200;
        else
            m_player2Round2Total += (qint32)(points + 1) * 200;
        break;
    case Types::Player3:
        if( m_firstRound )
            m_player3Round1Total += (qint32)(points + 1) * 200;
        else
            m_player3Round2Total += (qint32)(points + 1) * 200;
        break;
    default:
        break;
    }
}

void PointManager::addPoints( Types::Player player, Types::SecondRoundPointValue points )
{
    switch( player )
    {
    case Types::Player1:
        if( m_firstRound )
            m_player1Round1Total += (qint32)(points + 1) * 400;
        else
            m_player1Round2Total += (qint32)(points + 1) * 400;
        break;
    case Types::Player2:
        if( m_firstRound )
            m_player2Round1Total += (qint32)(points + 1) * 400;
        else
            m_player2Round2Total += (qint32)(points + 1) * 400;
        break;
    case Types::Player3:
        if( m_firstRound )
            m_player3Round1Total += (qint32)(points + 1) * 400;
        else
            m_player3Round2Total += (qint32)(points + 1) * 400;
        break;
    default:
        break;
    }
}


void PointManager::subtractPoints( Types::Player player, Types::FirstRoundPointValue points )
{
    switch( player )
    {
    case Types::Player1:
        if( m_firstRound )
            m_player1Round1Total -= (qint32)(points + 1) * 200;
        else
            m_player1Round2Total -= (qint32)(points + 1) * 200;
        break;
    case Types::Player2:
        if( m_firstRound )
            m_player2Round1Total -= (qint32)(points + 1) * 200;
        else
            m_player2Round2Total -= (qint32)(points + 1) * 200;
        break;
    case Types::Player3:
        if( m_firstRound )
            m_player3Round1Total -= (qint32)(points + 1) * 200;
        else
            m_player3Round2Total -= (qint32)(points + 1) * 200;
        break;
    default:
        break;
    }
}


void PointManager::subtractPoints( Types::Player player, Types::SecondRoundPointValue points )
{
    switch( player )
    {
    case Types::Player1:
        if( m_firstRound )
            m_player1Round1Total -= (qint32)(points + 1) * 400;
        else
            m_player1Round2Total -= (qint32)(points + 1) * 400;
        break;
    case Types::Player2:
        if( m_firstRound )
            m_player2Round1Total -= (qint32)(points + 1) * 400;
        else
            m_player2Round2Total -= (qint32)(points + 1) * 400;
        break;
    case Types::Player3:
        if( m_firstRound )
            m_player3Round1Total -= (qint32)(points + 1) * 400;
        else
            m_player3Round2Total -= (qint32)(points + 1) * 400;
        break;
    default:
        break;
    }
}


void PointManager::bankrupt( Types::Player player )
{
    switch( player )
    {
    case Types::Player1:
        if( m_firstRound )
        {
            if( m_player1Round1Total > 0 )
                m_player1Round1Total = 0;
        }
        else
        {
            if( m_player1Round2Total > 0 )
                m_player1Round2Total = 0;
        }
        break;
    case Types::Player2:
        if( m_firstRound )
        {
            if( m_player2Round1Total > 0 )
                m_player2Round1Total = 0;
        }
        else
        {
            if( m_player2Round2Total > 0 )
                m_player2Round2Total = 0;
        }
        break;
    case Types::Player3:
        if( m_firstRound )
        {
            if( m_player3Round1Total > 0 )
                m_player3Round1Total = 0;
        }
        else
        {
            if( m_player3Round2Total > 0 )
                m_player3Round2Total = 0;
        }
        break;
    default:
        break;
    }
}


void PointManager::switchRounds()
{
    m_firstRound = false;
}


qint32 PointManager::getPlayerTotalPoints( Types::Player player )
{
    qint32 retVal = 0;

    switch( player )
    {
    case Types::Player1:
        retVal = m_player1Round1Total + m_player1Round2Total;
        break;
    case Types::Player2:
        retVal = m_player2Round1Total + m_player2Round2Total;
        break;
    case Types::Player3:
        retVal = m_player3Round1Total + m_player3Round2Total;
        break;
    default:
        break;
    }

    return retVal;
}

qint32 PointManager::getPlayer1TotalPoints()
{
    return m_player1Round1Total + m_player1Round2Total;
}

qint32 PointManager::getPlayer2TotalPoints()
{
    return m_player2Round1Total + m_player2Round2Total;
}

qint32 PointManager::getPlayer3TotalPoints()
{
    return m_player3Round1Total + m_player3Round2Total;
}

qint32 PointManager::getPlayerRound1Points( Types::Player player )
{
    qint32 retVal = 0;

    switch( player )
    {
    case Types::Player1:
        retVal = m_player1Round1Total;
        break;
    case Types::Player2:
        retVal = m_player2Round1Total;
        break;
    case Types::Player3:
        retVal = m_player3Round1Total;
        break;
    default:
        break;
    }

    return retVal;
}

qint32 PointManager::getPlayer1Round1Points()
{
    return m_player1Round1Total;
}

qint32 PointManager::getPlayer2Round1Points()
{
    return m_player2Round1Total;
}

qint32 PointManager::getPlayer3Round1Points()
{
    return m_player3Round1Total;
}

qint32 PointManager::getPlayerRound2Points( Types::Player player )
{
    qint32 retVal = 0;

    switch( player )
    {
    case Types::Player1:
        retVal = m_player1Round2Total;
        break;
    case Types::Player2:
        retVal = m_player2Round2Total;
        break;
    case Types::Player3:
        retVal = m_player3Round2Total;
        break;
    default:
        break;
    }

    return retVal;
}

qint32 PointManager::getPlayer1Round2Points()
{
    return m_player1Round2Total;
}

qint32 PointManager::getPlayer2Round2Points()
{
    return m_player2Round2Total;
}

qint32 PointManager::getPlayer3Round2Points()
{
    return m_player3Round2Total;
}

// Hidden members
PointManager::PointManager()
    : m_player1Round1Total( 0 ),
      m_player2Round1Total( 0 ),
      m_player3Round1Total( 0 ),
      m_player1Round2Total( 0 ),
      m_player2Round2Total( 0 ),
      m_player3Round2Total( 0 ),
      m_firstRound( true )
{
}


// Getter for the current leader
Types::Player PointManager::getCurrentWinner()
{
    // Get totals
    qint32 player1Total = m_player1Round1Total + m_player1Round2Total;
    qint32 player2Total = m_player2Round1Total + m_player2Round2Total;
    qint32 player3Total = m_player3Round1Total + m_player3Round2Total;

    // Assume Player 1 is winning now
    qint32 max = player1Total;
    Types::Player retVal = Types::Player1;

    if( player2Total > max )
    {
        // Player 2 has highest now
        max = player2Total;
        retVal = Types::Player2;
    }

    if( player3Total > max )
    {
        // Player 3 has highest point total
        retVal = Types::Player3;
    }

    return retVal;
}


PointManager::PointManager( const PointManager& )
{
}

PointManager& PointManager::operator=( const PointManager& )
{
    return *this;
}

PointManager::~PointManager()
{
}
