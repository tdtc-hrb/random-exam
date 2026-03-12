#include <iostream>
#include <map>
#include <random>
#include <vector>

#include "poker/PokerType.h"
#include "poker/PokerVal.h"

using namespace std;

int getMapKey(map<int, string> myMap ,int index) {
    auto it = myMap.begin();
    //std::advance(it, index);
    auto it2 = std::next(it, index);
    return it2->first;
}

/**
 * Fill in the playing card suit values ​​and descriptions
 * @return map
 */
map<int, string> fillHxMap() {
    map<int, string> result;

    result.insert(make_pair(PokerType::Club, "Clubs"));
    result.insert(make_pair(PokerType::Diamond, "Diamonds"));
    result.insert(make_pair(PokerType::Heart, "Hearts"));
    result.insert(make_pair(PokerType::Spade, "Spades"));

    return result;
}

/**
 * Fill in the playing cards with their rank and description.
 * @return map
 */
map<int, string> fillRankMap() {
    map<int, string> result;

    result.insert(make_pair(PokerVal::Poker01, "A"));
    result.insert(make_pair(PokerVal::Poker02, "2"));
    result.insert(make_pair(PokerVal::Poker03, "3"));
    result.insert(make_pair(PokerVal::Poker04, "4"));
    result.insert(make_pair(PokerVal::Poker05, "5"));
    result.insert(make_pair(PokerVal::Poker06, "6"));
    result.insert(make_pair(PokerVal::Poker07, "7"));
    result.insert(make_pair(PokerVal::Poker08, "8"));
    result.insert(make_pair(PokerVal::Poker09, "9"));
    result.insert(make_pair(PokerVal::Poker10, "10"));
    result.insert(make_pair(PokerVal::Poker11, "J"));
    result.insert(make_pair(PokerVal::Poker12, "Q"));
    result.insert(make_pair(PokerVal::Poker13, "K"));

    return result;
}

/**
 * The standard 52-card deck.
 * @param hxMap
 * @param rankMap
 * @return map
 */
map<int, string> getPokerMap(map<int, string> hxMap, map<int, string> rankMap) {
    map<int, string> result;
    int i = 0;
    int iValue = 0;
    int iValue2 = 0;
    string strPoker = "a";

    for(int n = 0; n < hxMap.size(); n++) {
        for (int j = 0; j < rankMap.size(); j++) {
            iValue = getMapKey(hxMap, n);
            iValue2 = getMapKey(rankMap, j);

            i = iValue * iValue2;

            strPoker = rankMap.at(iValue2)+ " of " + hxMap.at(iValue);

            result.insert(
                make_pair(i,strPoker)
                );
        }
    }

    return result;
}

int main() {
    vector<int> pokerLeft;
    vector<int> pokerRight;

    // playing card suits
    map<int, string> hxMap = fillHxMap();

    // rank of playing cards
    map<int, string> rankMap = fillRankMap();

    map<int, string> pokerMap = getPokerMap(hxMap, rankMap);

    for (int i = 0; i < pokerMap.size(); i++) {
        pokerLeft.push_back(getMapKey(pokerMap, i));
    }

    int iCount = 52;
    for (int i = 0; i < 6; i++) {
        std::random_device rd;  // a seed source for the random number engine
        std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(0, iCount - i);

        int k = pokerLeft[distrib(gen)];
        cout << k << std::endl;

        // move poker to right
        if ( std::erase(pokerLeft, k) ) {
            pokerRight.push_back(k);
        };
    }

    // Check
    for (int i : pokerRight) {
        cout << pokerMap.at(i) << std::endl;
    }

    return 0;
}
