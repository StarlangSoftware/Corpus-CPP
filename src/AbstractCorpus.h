//
// Created by Olcay Taner YILDIZ on 15.11.2022.
//

#ifndef CORPUS_ABSTRACTCORPUS_H
#define CORPUS_ABSTRACTCORPUS_H

#include <string>
#include "Sentence.h"
using namespace std;

class AbstractCorpus{
protected:
    string fileName;
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual Sentence* getSentence() = 0;
};
#endif //CORPUS_ABSTRACTCORPUS_H
