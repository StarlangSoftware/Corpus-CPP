//
// Created by Olcay Taner Yıldız on 12.01.2019.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>
#include "Corpus.h"
using namespace std;

/**
 * A constructor of Corpus class which creates new ArrayList for sentences and a CounterHashMap
 * for wordList.
 */
Corpus::Corpus() = default;

/**
 * The emptyCopy method returns new Corpus.
 *
 * @return new Corpus.
 */
Corpus Corpus::emptyCopy() {
    return Corpus();
}

/**
 * Another constructor of Corpus class which takes a file name as an input. Then reads the input file line by line
 * and calls addSentence method with each read line.
 *
 * @param fileName String file name input that will be read.
 */
Corpus::Corpus(const string& fileName) {
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    this->fileName = fileName;
    string line;
    while (inputStream.good()){
        getline(inputStream, line);
        addSentence(new Sentence(line));
    }
    inputStream.close();
}

/**
 * Another constructor of Corpus class which takes SentenceSplitter  as an input besides the file name.
 * It reads input file line by line and calls the sentenceSplitter method with each line, then calls addSentence method
 * with each sentence.
 *
 * @param fileName         String file name input that will be read.
 * @param sentenceSplitter SentenceSplitter type input.
 */
Corpus::Corpus(const string& fileName, SentenceSplitter* sentenceSplitter) {
    vector<Sentence*> _sentences;
    string line;
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    while (inputStream.good()) {
        getline(inputStream, line);
        _sentences = sentenceSplitter->split(line);
        Paragraph paragraph;
        for (Sentence* s : _sentences) {
            paragraph.addSentence(s);
        }
        addParagraph(paragraph);
    }
    inputStream.close();
}

/**
 * Another constructor of Corpus class which also takes languageChecker input besides file name input.
 * It reads input file line by line and add each sentence also by using the languageChecker input which simply checks
 * the validity of the sentence.
 *
 * @param fileName        String file name input that will be read.
 * @param languageChecker LanguageChecker type input.
 */
Corpus::Corpus(const string& fileName, LanguageChecker* languageChecker) {
    string line;
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    while (inputStream.good()) {
        getline(inputStream, line);
        auto* s = new Sentence(line, languageChecker);
        addSentence(s);
    }
    inputStream.close();
}

/**
 * The combine method takes a Corpus as an input and adds each sentence of sentences ArrayList.
 *
 * @param corpus Corpus type input.
 */
void Corpus::combine(const Corpus& corpus) {
    for (Sentence* sentence : corpus.sentences) {
        addSentence(sentence);
    }
}

/**
 * The addSentence method takes a Sentence as an input. It adds given input to sentences ArrayList and loops
 * through the each word in sentence and puts these words into wordList CounterHashMap.
 *
 * @param s Sentence type input that will be added to sentences ArrayList and its words will be added to wordList
 *          CounterHashMap.
 */
void Corpus::addSentence(Sentence* s) {
    sentences.emplace_back(s);
    for (Word* word : s->getWords()) {
        wordList.put(*word);
    }
}

/**
 * The numberOfWords method loops through the sentences ArrayList and accumulates the number of words in sentence.
 *
 * @return size which holds the total number of words.
 */
int Corpus::numberOfWords() const{
    int size = 0;
    for (Sentence* s : sentences) {
        size += s->wordCount();
    }
    return size;
}

/**
 * The contains method takes a String word as an input and checks whether wordList CounterHashMap has the
 * given word and returns true if so, otherwise returns false.
 *
 * @param word String input to check.
 * @return true if wordList has the given word, false otherwise.
 */
bool Corpus::contains(const string& word) const{
    return wordList.containsKey(Word(word));
}

/**
 * The addParagraph method takes a Paragraph type input. It gets the sentences in the given paragraph and
 * add these to the sentences vector and the words in the sentences to the wordList CounterHashMap.
 *
 * @param p Paragraph type input to add sentences and wordList.
 */
void Corpus::addParagraph(const Paragraph& p) {
    paragraphs.emplace_back(p);
    for (int i = 0; i < p.sentenceCount(); i++){
        addSentence(p.getSentence(i));
    }
}

/**
 * Getter for the file name.
 *
 * @return file name.
 */
string Corpus::getFileName() const{
    return fileName;
}

/**
 * Getter for the wordList.
 *
 * @return the keySet of wordList.
 */
vector<Word> Corpus::getWordList() const{
    vector<Word> result;
    for (auto &item : wordList) {
        result.emplace_back(item.first);
    }
    return result;
}

/**
 * The wordCount method returns the size of the wordList CounterHashMap.
 *
 * @return the size of the wordList CounterHashMap.
 */
int Corpus::wordCount() const{
    return wordList.size();
}

/**
 * The getCount method returns the count value of given word.
 *
 * @param word Word type input to check.
 * @return the count value of given word.
 */
int Corpus::getCount(const Word& word) const{
    return wordList.count(word);
}

/**
 * The sentenceCount method returns the size of the sentences ArrayList.
 *
 * @return the size of the sentences ArrayList.
 */
int Corpus::sentenceCount() const{
    return sentences.size();
}

/**
 * Getter for getting a sentence at given index.
 *
 * @param index to get sentence from.
 * @return the sentence at given index.
 */
Sentence* Corpus::getSentence(int index) const{
    return sentences.at(index);
}

/**
 * The paragraphCount method returns the size of the paragraphs ArrayList.
 *
 * @return the size of the paragraphs ArrayList.
 */
int Corpus::paragraphCount() const{
    return paragraphs.size();
}

/**
 * Getter for getting a paragraph at given index.
 *
 * @param index to get paragraph from.
 * @return the paragraph at given index.
 */
Paragraph Corpus::getParagraph(int index) const{
    return paragraphs.at(index);
}

/**
 * The maxSentenceLength method finds the sentence with the maximum number of words and returns this number.
 *
 * @return maximum length.
 */
int Corpus::maxSentenceLength() const{
    int maxLength = 0;
    for (Sentence* s : sentences) {
        if (s->wordCount() > maxLength)
            maxLength = s->wordCount();
    }
    return maxLength;
}

/**
 * The getAllWordsAsVector method creates new vector of vectors and adds each word in each sentence of sentences
 * vector into new vector.
 *
 * @return newly created and populated vector.
 */
vector<vector<Word*>> Corpus::getAllWordsAsVector() const{
    vector<vector<Word*>> allWords;
    allWords.reserve(sentenceCount());
    for (int i = 0; i < sentenceCount(); i++) {
        allWords.emplace_back(getSentence(i)->getWords());
    }
    return allWords;
}

/**
 * The shuffleSentences method randomly shuffles sentences ArrayList with given seed value.
 *
 * @param seed value to randomize shuffling.
 */
void Corpus::shuffleSentences(int seed) {
    shuffle(sentences.begin(), sentences.end(), default_random_engine (seed));
}

/**
 * The getTrainCorpus method takes two integer inputs foldNo and foldCount for determining train data size and count of fold respectively.
 * Initially creates a new empty Corpus, then finds the sentenceCount as N. Then, starting from the index 0 it loops through
 * the index (foldNo * N) / foldCount and add each sentence of sentences ArrayList to new Corpus. Later on,
 * starting from the index ((foldNo + 1) * N) / foldCount, it loops through the index N and add each sentence of
 * sentences ArrayList to new Corpus.
 *
 * @param foldNo    Integer input for train set size.
 * @param foldCount Integer input for counting fold.
 * @return the newly created and populated Corpus.
 */
Corpus Corpus::getTrainCorpus(int foldNo, int foldCount){
    Corpus trainCorpus = emptyCopy();
    int N = sentenceCount();
    for (int i = 0; i < (foldNo * N) / foldCount; i++) {
        trainCorpus.addSentence(sentences.at(i));
    }
    for (int i = ((foldNo + 1) * N) / foldCount; i < N; i++) {
        trainCorpus.addSentence(sentences.at(i));
    }
    return trainCorpus;
}

/**
 * The getTestCorpus method takes two integer inputs foldNo and foldCount for determining test data size and count of
 * fold respectively.. Initially creates a new empty Corpus, then finds the sentenceCount as N.
 * Then, starting from the index (foldNo * N) / foldCount it loops through the index ((foldNo + 1) * N) / foldCount and
 * add each sentence of sentences ArrayList to new Corpus.
 *
 * @param foldNo    Integer input for test size.
 * @param foldCount Integer input counting fold.
 * @return the newly created and populated Corpus.
 */
Corpus Corpus::getTestCorpus(int foldNo, int foldCount) {
    Corpus testCorpus = emptyCopy();
    int N = sentenceCount();
    for (int i = (foldNo * N) / foldCount; i < ((foldNo + 1) * N) / foldCount; i++) {
        testCorpus.addSentence(sentences.at(i));
    }
    return testCorpus;
}

/**
 * The writeToFile method takes a String file name input and writes sentence of sentences ArrayList into this file.
 *
 * @param _fileName file to write the sentences.
 */
void Corpus::writeToFile(const string& _fileName) {
    ofstream output;
    output.open(_fileName, ofstream :: out);
    for (Sentence* sentence : sentences) {
        output << sentence->to_string();
        output << "\n";
    }
    output.close();
}

/**
 * The allSubStrings method takes a Word and an integer as inputs. If the length of the word's name is less than given input k,
 * it concatenates the each word's name with {@literal </s>} and adds to result which starts with {@literal <s>}. Else,  it finds out the
 * substring, concatenates with {@literal </s>} and adds to the String result.
 *
 * @param word Word type input to find substrings.
 * @param k    Integer for substring length.
 * @return String result that has all substrings.
 */
string Corpus::allSubStrings(const Word& word, int k) const{
    string result = "<s> ";
    if (word.getName().length() < k) {
        result += word.getName() + " </s>\n";
    } else {
        result += Word::substring(word.getName(), 0, k);
        for (int j = 1; j < word.charCount() - k + 1; j++) {
            result += " " + Word::substring(word.getName(), j, k);
        }
        result += " </s>\n";
    }
    return result;
}

/**
 * An overloaded writeToFile method takes a String file name and WordFormat type format as inputs.
 * It writes sentence of sentences ArrayList into this file according to given format. There are 4 formats;
 * SURFACE, it directly writes words to file
 * LETTER_2, it writes words to file as 2-Grams.
 * LETTER_3, it writes words to file as 3-Grams.
 * LETTER_4, it writes words to file as 4-Grams.
 *
 * @param _fileName file to write the sentences.
 * @param format WordFormat type input indicates N-Gram output.
 */
void Corpus::writeToFile(const string& _fileName, WordFormat format) {
    string result;
    ofstream output;
    output.open(_fileName, ofstream :: out);
    for (Sentence* sentence : sentences) {
        switch (format) {
            case WordFormat::SURFACE:
                result = "<s> " + sentence->to_string() + " </s>\n";
                break;
            case WordFormat::LETTER_2:
                result = "";
                for (int i = 0; i < sentence->wordCount(); i++) {
                    result += allSubStrings(*sentence->getWord(i), 2);
                }
                break;
            case WordFormat::LETTER_3:
                result = "";
                for (int i = 0; i < sentence->wordCount(); i++) {
                    result += allSubStrings(*sentence->getWord(i), 3);
                }
                break;
            case WordFormat::LETTER_4:
                result = "";
                for (int i = 0; i < sentence->wordCount(); i++) {
                    result += allSubStrings(*sentence->getWord(i), 4);
                }
                break;
        }
        output << result;
    }
    output.close();
}

void Corpus::open() {
    sentenceIndex = 0;
}

void Corpus::close() {
    sentenceIndex = 0;
}

Sentence* Corpus::getSentence() {
    int index = sentenceIndex;
    if (sentenceIndex < sentences.size()){
        sentenceIndex++;
        return sentences[index];
    }
    return nullptr;
}
