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

    // Sector enumeration used for keeping track of
    // where the wheel lands - NOTE: DO NOT CHANGE
    // ORDER, FIXED TO SECTOR ORDER ON WHEEL IMAGE
    enum Sector
    {
        Category1,
        LoseTurn,
        Category2,
        FreeTurn,
        Category3,
        Bankrupt,
        Category4,
        PlayerChoice,
        Category5,
        OpponentChoice,
        Category6,
        SpinAgain
    };
}
