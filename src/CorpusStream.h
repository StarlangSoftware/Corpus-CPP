//
// Created by Olcay Taner YILDIZ on 11.11.2022.
//

#ifndef CORPUS_CORPUSSTREAM_H
#define CORPUS_CORPUSSTREAM_H
#include <fstream>
#include <iostream>
#include "Sentence.h"

using namespace std;

class CorpusStream {
private:
    ifstream inputStream;
    string fileName;
public:
    CorpusStream();
    explicit CorpusStream(const string& fileName);
    void open();
    void close();
    Sentence* getSentence();
    vector<Sentence*> getSentenceBatch(int lineCount);
};


#endif //CORPUS_CORPUSSTREAM_H
