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
    static bool contains(const string& s, char character);
    static bool contains(const string& s, const string& character);
    bool listContains(const string& currentWord);
    bool isNextCharUpperCaseOrDigit(const string& line, int i);
    bool isPreviousWordUpperCase(const string& line, int i);
    bool isNextCharUpperCase(const string& line, int i);
    bool isNameShortcut(const string& currentWord);
    string repeatControl(const string& word, bool exceptionMode);
    bool isApostrophe(const string& line, int i);
    bool numberExistsBeforeAndAfter(const string& line, int i);
    bool isTime(const string& line, int i);
public:
    static const string SEPARATORS;
    static const string SENTENCE_ENDERS;
    static const string PUNCTUATION_CHARACTERS;
    static const string APOSTROPHES;
    vector<Sentence*> split(const string& line);
protected:
    virtual string upperCaseLetters() = 0;
    virtual string lowerCaseLetters() = 0;
    virtual vector<string> shortCuts() = 0;
};

const inline string SentenceSplitter::SEPARATORS = "\n()[]{}\"'\u05F4\uFF02\u055B’”‘“–\u00AD\u200B\t&\u2009\u202F\uFEFF";
const inline string SentenceSplitter::SENTENCE_ENDERS = ".?!…";
const inline string SentenceSplitter::PUNCTUATION_CHARACTERS = ",:;‚";
const inline string SentenceSplitter::APOSTROPHES = "'’‘\u055B";

#endif //CORPUS_SENTENCESPLITTER_H
