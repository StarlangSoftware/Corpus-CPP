//
// Created by Olcay Taner YILDIZ on 11.11.2022.
//

#include "catch.hpp"
#include "../src/CorpusStream.h"

TEST_CASE("CorpusStreamTest-testNumberOfWords1") {
    int wordCount = 0;
    CorpusStream corpus = CorpusStream("corpus.txt");
    corpus.open();
    Sentence* sentence = corpus.getSentence();
    while (sentence != nullptr){
        wordCount += sentence->wordCount();
        sentence = corpus.getSentence();
    }
    corpus.close();
    REQUIRE(826680 == wordCount);
}

TEST_CASE("CorpusStreamTest-testNumberOfWords2") {
    int wordCount = 0;
    CorpusStream corpus = CorpusStream("corpus.txt");
    corpus.open();
    vector<Sentence*> sentenceBatch = corpus.getSentenceBatch(100);
    while (!sentenceBatch.empty()){
        for (Sentence* sentence : sentenceBatch){
            wordCount += sentence->wordCount();
        }
        sentenceBatch = corpus.getSentenceBatch(100);
    }
    corpus.close();
    REQUIRE(826680 == wordCount);
}
