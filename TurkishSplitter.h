//
// Created by Olcay Taner Yıldız on 11.01.2019.
//

#ifndef CORPUS_TURKISHSPLITTER_H
#define CORPUS_TURKISHSPLITTER_H


#include "SentenceSplitter.h"

class TurkishSplitter : public SentenceSplitter {
protected:
    string upperCaseLetters();
    string lowerCaseLetters();
    vector<string> shortCuts();
};


#endif //CORPUS_TURKISHSPLITTER_H
