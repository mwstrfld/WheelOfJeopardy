#pragma once


namespace Types
{
    // Player enumeration used for keeping track of
    // whose turn it is within the WoF Board class
    enum Player
    {
        Player1,
        Player2,
        Player3
    };

    // Category enumeration used to pass control to
    // the JeopardyBoard from WheelOfFortuneBoard
    enum Category
    {
        Category1,
        Category2,
        Category3,
        Category4,
        Category5,
        Category6
    };

    // Sector enumeration used for keeping track of
    // where the wheel lands - NOTE: DO NOT CHANGE
    // ORDER, FIXED TO SECTOR ORDER ON WHEEL IMAGE
    enum Sector
    {
        SectorCategory1,
        LoseTurn,
        SectorCategory2,
        FreeTurn,
        SectorCategory3,
        Bankrupt,
        SectorCategory4,
        PlayerChoice,
        SectorCategory5,
        OpponentChoice,
        SectorCategory6,
        SpinAgain
    };
}
