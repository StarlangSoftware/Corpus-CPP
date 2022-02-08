//
// Created by Olcay Taner YILDIZ on 8.02.2022.
//

#ifndef DICTIONARY_ENGLISHLANGUAGE_H
#define DICTIONARY_ENGLISHLANGUAGE_H

#include "Language.h"

class EnglishLanguage : public Language {
private:
public:
    static const string LOWERCASE_LETTERS;
    static const string UPPERCASE_LETTERS;
};

const inline string EnglishLanguage::LOWERCASE_LETTERS = "abcdefghijklmnopqrstuvwxyz";
const inline string EnglishLanguage::UPPERCASE_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

#endif //DICTIONARY_ENGLISHLANGUAGE_H
