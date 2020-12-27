//
// Created by Olcay Taner YILDIZ on 27.12.2020.
//

#include "catch.hpp"
#include "../Corpus.h"

TEST_CASE("CorpusTest-testNumberOfWords") {
    Corpus corpus = Corpus("corpus.txt");
    Corpus simpleCorpus = Corpus("simplecorpus.txt");
    REQUIRE(826680 == corpus.numberOfWords());
    REQUIRE(24 == simpleCorpus.numberOfWords());
}

TEST_CASE("CorpusTest-testContains") {
    Corpus corpus = Corpus("corpus.txt");
    Corpus simpleCorpus = Corpus("simplecorpus.txt");
    REQUIRE_FALSE(!corpus.contains("atatürk"));
    for (Word word : corpus.getWordList()){
        REQUIRE_FALSE(!corpus.contains(word.getName()));
    }
    REQUIRE_FALSE(!simpleCorpus.contains("mehmet"));
    for (Word word : simpleCorpus.getWordList()){
        REQUIRE_FALSE(!simpleCorpus.contains(word.getName()));
    }
}

TEST_CASE("CorpusTest-testWordCount") {
    Corpus corpus = Corpus("corpus.txt");
    Corpus simpleCorpus = Corpus("simplecorpus.txt");
    REQUIRE(98199 == corpus.wordCount());
    REQUIRE(12 == simpleCorpus.wordCount());
}

TEST_CASE("CorpusTest-testGetCount") {
    Corpus corpus = Corpus("corpus.txt");
    Corpus simpleCorpus = Corpus("simplecorpus.txt");
    REQUIRE(309 == corpus.getCount(Word("mustafa")));
    REQUIRE(109 == corpus.getCount(Word("kemal")));
    REQUIRE(122 == corpus.getCount(Word("atatürk")));
    REQUIRE(4 == simpleCorpus.getCount(Word("ali")));
    REQUIRE(3 == simpleCorpus.getCount(Word("gitti")));
    REQUIRE(4 == simpleCorpus.getCount(Word("at")));
}

TEST_CASE("CorpusTest-testSentenceCount") {
    Corpus corpus = Corpus("corpus.txt");
    Corpus simpleCorpus = Corpus("simplecorpus.txt");
    REQUIRE(50000 == corpus.sentenceCount());
    REQUIRE(5 == simpleCorpus.sentenceCount());
}

TEST_CASE("CorpusTest-testMaxSentenceLength") {
    Corpus corpus = Corpus("corpus.txt");
    Corpus simpleCorpus = Corpus("simplecorpus.txt");
    REQUIRE(1092 == corpus.maxSentenceLength());
    REQUIRE(6 == simpleCorpus.maxSentenceLength());
}