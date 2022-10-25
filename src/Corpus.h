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
    Corpus emptyCopy();
    explicit Corpus(const string& fileName);
    Corpus(const string& fileName, SentenceSplitter* sentenceSplitter);
    Corpus(const string& fileName, LanguageChecker* languageChecker);
    void combine(const Corpus& corpus);
    void addSentence(Sentence* s);
    int numberOfWords() const;
    bool contains(const string& word) const;
    void addParagraph(const Paragraph& p);
    string getFileName() const;
    vector<Word> getWordList() const;
    int wordCount() const;
    int getCount(const Word& word) const;
    int sentenceCount() const;
    Sentence* getSentence(int index) const;
    int paragraphCount() const;
    Paragraph getParagraph(int index) const;
    int maxSentenceLength() const;
    vector<vector<Word*>> getAllWordsAsVector() const;
    void shuffleSentences(int seed);
    Corpus getTrainCorpus(int foldNo, int foldCount);
    Corpus getTestCorpus(int foldNo, int foldCount);
    void writeToFile(const string& _fileName);
    string allSubStrings(const Word& word, int k) const;
    void writeToFile(const string& _fileName, WordFormat format);
};


#endif //CORPUS_CORPUS_H
