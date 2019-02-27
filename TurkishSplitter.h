//
// Created by Olcay Taner Yıldız on 11.01.2019.
//

#ifndef CORPUS_TURKISHSPLITTER_H
#define CORPUS_TURKISHSPLITTER_H


#include "SentenceSplitter.h"

class TurkishSplitter : public SentenceSplitter {
private:
    bool contains(string s, char character);
    bool contains(string s, string character);
    bool listContains(string currentWord);
    bool isNextCharUpperCaseOrDigit(string line, int i);
    bool isPreviousWordUpperCase(string line, int i);
    bool isNextCharUpperCase(string line, int i);
    bool isNameShortcut(string currentWord);
    string repeatControl(string word, bool exceptionMode);
    bool isApostrophe(string line, int i);
    bool numberExistsBeforeAndAfter(string line, int i);
    bool isTime(string line, int i);
    vector<Sentence> split(string line);
};


#endif //CORPUS_TURKISHSPLITTER_H
