//
// Created by Olcay Taner Yıldız on 11.01.2019.
//

#ifndef CORPUS_TURKISHSPLITTER_H
#define CORPUS_TURKISHSPLITTER_H


#include "SentenceSplitter.h"

class TurkishSplitter : public SentenceSplitter {
private:
    bool contains(string s, char character);
    bool listContains(string currentWord);
    bool isNextCharUpperCaseOrDigit(string line, int i);
    bool isPreviousWordUpperCase(string line, int i);
    bool isNextCharUpperCase(string line, int i);
    bool isNameShortcut(string currentWord);
};


#endif //CORPUS_TURKISHSPLITTER_H
