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

    // Getters for the point totals
    qint32 getPlayerPoints( Types::Player player );
    qint32 getPlayer1Points();
    qint32 getPlayer2Points();
    qint32 getPlayer3Points();

    // Getter for the current leader
    Types::Player getCurrentWinner();

protected:
    // Players point totals
    qint32 m_player1Total;
    qint32 m_player2Total;
    qint32 m_player3Total;

private:
    // Hidden constructors and equals operator
    PointManager();
    PointManager( const PointManager& );
    PointManager& operator=( const PointManager& );
    ~PointManager();

    // Actual instance
    static PointManager* m_instance;
};
