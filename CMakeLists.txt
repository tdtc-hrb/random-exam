cmake_minimum_required(VERSION 4.1)
project(deal-cards)

set(CMAKE_CXX_STANDARD 20)

add_executable(dealCards main.cpp
        poker/PokerType.h
        poker/PokerVal.h)
