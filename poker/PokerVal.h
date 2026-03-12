/**
 * @file PokerVal.h
 * Created by tdtc-hrb on 2/13/2026. - UTC+8
 */
#pragma once
class PokerVal {
    public:
        enum RankEnum {
            Poker02 = 11,
            Poker03 = 13,
            Poker04 = 17,
            Poker05 = 19,
            Poker06 = 23,
            Poker07 = 29,
            Poker08 = 31,
            Poker09 = 37,
            Poker10 = 41,
            Poker11 = 43, //!< Jack
            Poker12 = 47, //!< Queen
            Poker13 = 53, //!< King
            Poker01 = 59  //!< Ace
        };
};

/**
 * @class PokerVal
 * Define 13 rank values
 */
/**
 * @enum RankEnum
 * comprises 13 ranks
 */