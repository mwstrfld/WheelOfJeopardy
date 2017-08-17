#pragma once


#include <QtGlobal>

#include <WheelOfJeopardyTypes.h>


// Note: This is a singleton class to only have one instance
//       of the PointManager object within the application
class PointManager
{
public:
    // Function call to get the instance
    static PointManager* instance();

    // Add points functions for each round
    void addPoints( Types::Player player, Types::FirstRoundPointValue points );
    void addPoints( Types::Player player, Types::SecondRoundPointValue points );

    // Subtract points functions for each round
    void subtractPoints( Types::Player player, Types::FirstRoundPointValue points );
    void subtractPoints( Types::Player player, Types::SecondRoundPointValue points );

    // Bankrupt a player
    void bankrupt( Types::Player player );

    // Switch rounds
    void switchRounds();

    // Getters for the point totals
    qint32 getPlayerTotalPoints( Types::Player player );
    qint32 getPlayer1TotalPoints();
    qint32 getPlayer2TotalPoints();
    qint32 getPlayer3TotalPoints();
    // Round 1
    qint32 getPlayerRound1Points( Types::Player player );
    qint32 getPlayer1Round1Points();
    qint32 getPlayer2Round1Points();
    qint32 getPlayer3Round1Points();
    // Round 2
    qint32 getPlayerRound2Points( Types::Player player );
    qint32 getPlayer1Round2Points();
    qint32 getPlayer2Round2Points();
    qint32 getPlayer3Round2Points();

    // Getter for the current leader
    Types::Player getCurrentWinner();

protected:
    // Players point totals
    // Round 1
    qint32 m_player1Round1Total;
    qint32 m_player2Round1Total;
    qint32 m_player3Round1Total;
    // Round 2
    qint32 m_player1Round2Total;
    qint32 m_player2Round2Total;
    qint32 m_player3Round2Total;

private:
    // Hidden constructors and equals operator
    PointManager();
    PointManager( const PointManager& );
    PointManager& operator=( const PointManager& );
    ~PointManager();

    // Round indicator
    bool m_firstRound;

    // Actual instance
    static PointManager* m_instance;
};
