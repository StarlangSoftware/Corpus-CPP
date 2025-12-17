//
// Created by Olcay Taner Yıldız on 12.01.2019.
//

#ifndef CORPUS_CORPUS_H
#define CORPUS_CORPUS_H

#include <vector>
#include "Sentence.h"
#include "CounterHashMap.h"
#include "SentenceSplitter.h"
#include "Paragraph.h"
#include "WordFormat.h"
#include "AbstractCorpus.h"

class Corpus : public AbstractCorpus{
private:
    int sentenceIndex;
protected:
    vector<Sentence*> sentences;
    vector<Paragraph> paragraphs;
    CounterHashMap<Word> wordList;
public:
    Corpus();
    Corpus emptyCopy();
    explicit Corpus(const string& fileName);
    Corpus(const string& fileName, SentenceSplitter* sentenceSplitter);
    Corpus(const string& fileName, LanguageChecker* languageChecker);
    void combine(const Corpus& corpus);
    void addSentence(Sentence* s);
    [[nodiscard]] int numberOfWords() const;
    [[nodiscard]] bool contains(const string& word) const;
    void addParagraph(const Paragraph& p);
    [[nodiscard]] string getFileName() const;
    [[nodiscard]] vector<Word> getWordList() const;
    [[nodiscard]] int wordCount() const;
    [[nodiscard]] int getCount(const Word& word) const;
    [[nodiscard]] int sentenceCount() const;
    [[nodiscard]] Sentence* getSentence(int index) const;
    [[nodiscard]] int paragraphCount() const;
    [[nodiscard]] Paragraph getParagraph(int index) const;
    [[nodiscard]] int maxSentenceLength() const;
    [[nodiscard]] vector<vector<Word*>> getAllWordsAsVector() const;
    void shuffleSentences(int seed);
    Corpus getTrainCorpus(int foldNo, int foldCount);
    Corpus getTestCorpus(int foldNo, int foldCount);
    void writeToFile(const string& _fileName) const;
    [[nodiscard]] string allSubStrings(const Word& word, int k) const;
    void writeToFile(const string& _fileName, WordFormat format) const;
    void open() override;
    void close() override;
    Sentence* getSentence() override;
};


#endif //CORPUS_CORPUS_H
