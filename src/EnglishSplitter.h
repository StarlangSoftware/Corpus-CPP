//
// Created by Olcay Taner YILDIZ on 8.02.2022.
//

#ifndef CORPUS_ENGLISHSPLITTER_H
#define CORPUS_ENGLISHSPLITTER_H

#include "SentenceSplitter.h"

class EnglishSplitter : public SentenceSplitter {
protected:
    string upperCaseLetters() override;
    string lowerCaseLetters() override;
    vector<string> shortCuts() override;
};


#endif //CORPUS_ENGLISHSPLITTER_H
