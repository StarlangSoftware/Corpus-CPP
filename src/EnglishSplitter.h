//
// Created by Olcay Taner YILDIZ on 8.02.2022.
//

#ifndef CORPUS_ENGLISHSPLITTER_H
#define CORPUS_ENGLISHSPLITTER_H

#include "SentenceSplitter.h"

class EnglishSplitter : public SentenceSplitter {
protected:
    string upperCaseLetters();
    string lowerCaseLetters();
    vector<string> shortCuts();
};


#endif //CORPUS_ENGLISHSPLITTER_H
