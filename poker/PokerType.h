/**
 * @file PokerType.h
 * Created by tdtc-hrb on 2/14/2026 - UTC+8.
 */
#pragma once
class PokerType {
    public:
        enum FrenchSuit {
            Club = 2,    //!< ♣
            Diamond = 3, //!< ♦
            Heart = 5,   //!< ♥
            Spade = 7    //!< ♠
        };
};

/*!
 * @enum FrenchSuit
 * four suits: clubs (♣), diamonds (♦), hearts (♥) and spades (♠)
 * are represented using prime numbers
 */