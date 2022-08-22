//
// Created by LMF319018 on 09/01/2019.
//

#ifndef CORPUS_SENTENCESPLITTER_H
#define CORPUS_SENTENCESPLITTER_H
#include <string>
#include "Sentence.h"

using namespace std;

class SentenceSplitter {
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
public:
    static const string SEPARATORS;
    static const string SENTENCE_ENDERS;
    static const string PUNCTUATION_CHARACTERS;
    vector<Sentence*> split(string line);
protected:
    virtual string upperCaseLetters() = 0;
    virtual string lowerCaseLetters() = 0;
    virtual vector<string> shortCuts() = 0;
};

const inline string SentenceSplitter::SEPARATORS = "\n()[]{}\"'\u05F4\uFF02\u055B";
const inline string SentenceSplitter::SENTENCE_ENDERS = ".?!…";
const inline string SentenceSplitter::PUNCTUATION_CHARACTERS = ",:;";

#endif //CORPUS_SENTENCESPLITTER_H
