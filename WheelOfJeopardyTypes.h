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

    // Point value enumeration used for letting the
    // PM class know the value to subtract or add
    // during the first round of Jeopardy (suffix: 1)
    enum FirstRoundPointValue
    {
        TwoHundred1,
        FourHundred1,
        SixHundred1,
        EightHundred1,
        OneThousand1
    };

    // Point value enumeration used for letting the
    // PM class know the value to subtract or add
    // during the second round of Jeopardy (suffix: 2)
    enum SecondRoundPointValue
    {
        FourHundred2,
        EightHundred2,
        OneThousandTwoHundred2,
        OneThousandSixHundred2,
        TwoThousand2
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
