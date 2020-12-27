//
// Created by Olcay Taner YILDIZ on 27.12.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../Sentence.h"

TEST_CASE("SentenceTest-testGetWord") {
    Sentence sentence = Sentence("ali topu at mehmet ayşeyle gitti");
    REQUIRE(Word("ali") == *sentence.getWord(0));
    REQUIRE(Word("at") == *sentence.getWord(2));
    REQUIRE(Word("gitti") == *sentence.getWord(5));
}

TEST_CASE("SentenceTest-testGetIndex") {
    Sentence sentence = Sentence("ali topu at mehmet ayşeyle gitti");
    REQUIRE(0 == sentence.getIndex(new Word("ali")));
    REQUIRE(2 == sentence.getIndex(new Word("at")));
    REQUIRE(5 == sentence.getIndex(new Word("gitti")));
}

TEST_CASE("SentenceTest-testWordCount") {
    Sentence sentence = Sentence("ali topu at mehmet ayşeyle gitti");
    REQUIRE(6 == sentence.wordCount());
}

TEST_CASE("SentenceTest-testCharCount") {
    Sentence sentence = Sentence("ali topu at mehmet ayşeyle gitti");
    REQUIRE(27 == sentence.charCount());
}