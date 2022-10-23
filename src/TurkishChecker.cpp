//
// Created by Olcay Taner Yıldız on 11.01.2019.
//

#include <iostream>
#include <string>
#include "TurkishChecker.h"
#include "Language/TurkishLanguage.h"
#include "SentenceSplitter.h"

/**
 * The isValidWord method takes an input String as a word than define all valid characters as a validCharacters String which has
 * letters (abcçdefgğhıijklmnoöprsştuüvyzABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ),
 * extended language characters (âàáäãèéêëíîòóôûúqwxÂÈÉÊËÌÒÛQWX),
 * digits (0123456789),
 * separators ({@literal ()[]{}"'״＂՛}),
 * sentence enders (.?!…),
 * arithmetic chars (+-/=\*),
 * punctuation chars (,:;),
 * special-meaning chars
 * <p>
 * Then, loops through input word's each char and if a char in word does not in the validCharacters string it returns
 * false, true otherwise.
 *
 * @param word String to check validity.
 * @return true if each char in word is valid, false otherwise.
 */
bool TurkishChecker::isValidWord(const string& word) {
    string specialMeaningCharacters = "$\\_|@%#£§&><";
    string validCharacters =
            TurkishLanguage::LETTERS + TurkishLanguage::EXTENDED_LANGUAGE_CHARACTERS + TurkishLanguage::DIGITS +
            SentenceSplitter::SEPARATORS + SentenceSplitter::SENTENCE_ENDERS + TurkishLanguage::ARITHMETIC_CHARACTERS +
            SentenceSplitter::PUNCTUATION_CHARACTERS + specialMeaningCharacters;
    for (char ch : word) {
        if (validCharacters.find_first_of(ch) == -1) {
            cout << ch;
            return false;
        }
    }
    return true;
}
