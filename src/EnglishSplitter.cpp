//
// Created by Olcay Taner YILDIZ on 8.02.2022.
//

#include "EnglishSplitter.h"
#include "Language/EnglishLanguage.h"

string EnglishSplitter::upperCaseLetters() {
    return EnglishLanguage::UPPERCASE_LETTERS;
}

string EnglishSplitter::lowerCaseLetters() {
    return EnglishLanguage::LOWERCASE_LETTERS;
}

vector<string> EnglishSplitter::shortCuts(){
    vector<string> shortCuts;
    shortCuts.emplace_back("dr");
    shortCuts.emplace_back("prof");
    shortCuts.emplace_back("org");
    shortCuts.emplace_back("II");
    shortCuts.emplace_back("III");
    shortCuts.emplace_back("IV");
    shortCuts.emplace_back("VI");
    shortCuts.emplace_back("VII");
    shortCuts.emplace_back("VIII");
    shortCuts.emplace_back("IX");
    shortCuts.emplace_back("X");
    shortCuts.emplace_back("XI");
    shortCuts.emplace_back("XII");
    shortCuts.emplace_back("XIII");
    shortCuts.emplace_back("XIV");
    shortCuts.emplace_back("XV");
    shortCuts.emplace_back("XVI");
    shortCuts.emplace_back("XVII");
    shortCuts.emplace_back("XVIII");
    shortCuts.emplace_back("XIX");
    shortCuts.emplace_back("XX");
    shortCuts.emplace_back("min");
    shortCuts.emplace_back("km");
    shortCuts.emplace_back("jr");
    shortCuts.emplace_back("mrs");
    shortCuts.emplace_back("sir");
    return shortCuts;
}