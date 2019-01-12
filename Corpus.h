//
// Created by Olcay Taner Yıldız on 12.01.2019.
//

#ifndef CORPUS_CORPUS_H
#define CORPUS_CORPUS_H

#include <vector>
#include "Sentence.h"
#include "CounterHashMap.h"
#include "SentenceSplitter.h"

class Corpus {
protected:
    vector<Sentence> sentences;
    CounterHashMap<Word> wordList;
    string fileName;
public:
    Corpus();
    Corpus emptyCopy();
    Corpus(string fileName);
    Corpus(string fileName, SentenceSplitter sentenceSplitter);
    Corpus(string fileName, LanguageChecker languageChecker);
    void combine(Corpus corpus);
    void addSentence(Sentence s);
};


#endif //CORPUS_CORPUS_H
