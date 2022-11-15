//
// Created by Olcay Taner YILDIZ on 11.11.2022.
//

#ifndef CORPUS_CORPUSSTREAM_H
#define CORPUS_CORPUSSTREAM_H
#include <fstream>
#include <iostream>
#include "Sentence.h"
#include "AbstractCorpus.h"

using namespace std;

class CorpusStream : public AbstractCorpus{
private:
    ifstream inputStream;
public:
    CorpusStream();
    explicit CorpusStream(const string& fileName);
    void open() override;
    void close() override;
    Sentence* getSentence() override;
    vector<Sentence*> getSentenceBatch(int lineCount);
};


#endif //CORPUS_CORPUSSTREAM_H
