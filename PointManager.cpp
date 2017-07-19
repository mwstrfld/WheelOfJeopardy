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
        m_player1Total += (qint32)points * 200;
        break;
    case Types::Player2:
        m_player2Total += (qint32)points * 200;
        break;
    case Types::Player3:
        m_player3Total += (qint32)points * 200;
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
        m_player1Total += (qint32)points * 400;
        break;
    case Types::Player2:
        m_player2Total += (qint32)points * 400;
        break;
    case Types::Player3:
        m_player3Total += (qint32)points * 400;
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
        m_player1Total -= (qint32)points * 200;
        break;
    case Types::Player2:
        m_player2Total -= (qint32)points * 200;
        break;
    case Types::Player3:
        m_player3Total -= (qint32)points * 200;
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
        m_player1Total -= (qint32)points * 400;
        break;
    case Types::Player2:
        m_player2Total -= (qint32)points * 400;
        break;
    case Types::Player3:
        m_player3Total -= (qint32)points * 400;
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
        if( m_player1Total > 0 )
            m_player1Total = 0;
        break;
    case Types::Player2:
        if( m_player2Total > 0 )
            m_player2Total = 0;
        break;
    case Types::Player3:
        if( m_player3Total > 0 )
            m_player3Total = 0;
        break;
    default:
        break;
    }
}


qint32 PointManager::getPlayerPoints( Types::Player player )
{
    qint32 retVal = 0;

    switch( player )
    {
    case Types::Player1:
        retVal = m_player1Total;
        break;
    case Types::Player2:
        retVal = m_player2Total;
        break;
    case Types::Player3:
        retVal = m_player3Total;
        break;
    default:
        break;
    }

    return retVal;
}

qint32 PointManager::getPlayer1Points()
{
    return m_player1Total;
}

qint32 PointManager::getPlayer2Points()
{
    return m_player2Total;
}

qint32 PointManager::getPlayer3Points()
{
    return m_player3Total;
}


// Hidden members
PointManager::PointManager()
    : m_player1Total( 0 ),
      m_player2Total( 0 ),
      m_player3Total( 0 )
{
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
