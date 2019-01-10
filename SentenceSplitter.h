//
// Created by LMF319018 on 09/01/2019.
//

#ifndef CORPUS_SENTENCESPLITTER_H
#define CORPUS_SENTENCESPLITTER_H
#include <string>
using namespace std;

class SentenceSplitter {
public:
    static const string SEPARATORS;
    static const string SENTENCE_ENDERS;
    static const string PUNCTUATION_CHARACTERS;
    virtual vector<Sentence> split(string line) = 0;
};

const inline string SEPARATORS = "()[]{}\"'\u05F4\uFF02\u055B";
const inline string SENTENCE_ENDERS = ".?!…";
const inline string PUNCTUATION_CHARACTERS = ",:;";

#endif //CORPUS_SENTENCESPLITTER_H
