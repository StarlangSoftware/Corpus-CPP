//
// Created by Olcay Taner Yıldız on 12.01.2019.
//

#ifndef CORPUS_CORPUS_H
#define CORPUS_CORPUS_H

#include <vector>
#include <unordered_set>
#include "Sentence.h"
#include "CounterHashMap.h"
#include "SentenceSplitter.h"
#include "Paragraph.h"
#include "WordFormat.h"

class Corpus {
protected:
    vector<Sentence*> sentences;
    vector<Paragraph> paragraphs;
    CounterHashMap<Word> wordList;
    string fileName;
public:
    Corpus();
    ~Corpus();
    Corpus emptyCopy();
    explicit Corpus(const string& fileName);
    Corpus(const string& fileName, SentenceSplitter* sentenceSplitter);
    Corpus(const string& fileName, LanguageChecker* languageChecker);
    void combine(const Corpus& corpus);
    void addSentence(Sentence* s);
    int numberOfWords();
    bool contains(const string& word);
    void addParagraph(const Paragraph& p);
    string getFileName();
    vector<Word> getWordList();
    int wordCount();
    int getCount(const Word& word);
    int sentenceCount();
    Sentence* getSentence(int index);
    int paragraphCount();
    Paragraph getParagraph(int index);
    int maxSentenceLength();
    vector<vector<Word*>> getAllWordsAsVector();
    void shuffleSentences(int seed);
    Corpus getTrainCorpus(int foldNo, int foldCount);
    Corpus getTestCorpus(int foldNo, int foldCount);
    void writeToFile(const string& _fileName);
    string allSubStrings(const Word& word, int k);
    void writeToFile(const string& _fileName, WordFormat format);
};


#endif //CORPUS_CORPUS_H
