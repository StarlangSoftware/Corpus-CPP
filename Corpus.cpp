//
// Created by Olcay Taner Yıldız on 12.01.2019.
//

#include <fstream>
#include <iostream>
#include "Corpus.h"

/**
 * A constructor of {@link Corpus} class which creates new {@link ArrayList} for sentences and a {@link CounterHashMap}
 * for wordList.
 */
Corpus::Corpus() {
}

/**
 * The emptyCopy method returns new Corpus.
 *
 * @return new {@link Corpus}.
 */
Corpus Corpus::emptyCopy() {
    return Corpus();
}

/**
 * Another constructor of {@link Corpus} class which takes a file name as an input. Then reads the input file line by line
 * and calls addSentence method with each read line.
 *
 * @param fileName String file name input that will be read.
 */
Corpus::Corpus(string fileName) {
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    this->fileName = move(fileName);
    string line;
    while (inputStream.good()){
        getline(inputStream, line);
        addSentence(Sentence(line));
    }
}

/**
 * Another constructor of {@link Corpus} class which takes {@link SentenceSplitter}  as an input besides the file name.
 * It reads input file line by line and calls the sentenceSplitter method with each line, then calls addSentence method
 * with each sentence.
 *
 * @param fileName         String file name input that will be read.
 * @param sentenceSplitter {@link SentenceSplitter} type input.
 */
Corpus::Corpus(string fileName, SentenceSplitter sentenceSplitter) {
    vector<Sentence> sentences;
    int count = 0;
    string line;
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    while (inputStream.good()) {
        getline(inputStream, line);
        sentences = sentenceSplitter.split(line);
        for (const Sentence &s : sentences) {
            addSentence(s);
        }
    }
}

/**
 * Another constructor of {@link Corpus} class which also takes languageChecker input besides file name input.
 * It reads input file line by line and add each sentence also by using the languageChecker input which simply checks
 * the validity of the sentence.
 *
 * @param fileName        String file name input that will be read.
 * @param languageChecker {@link LanguageChecker} type input.
 */
Corpus::Corpus(string fileName, LanguageChecker languageChecker) {
    string line;
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    while (inputStream.good()) {
        getline(inputStream, line);
        Sentence s = Sentence(line, languageChecker);
        addSentence(s);
    }
}

/**
 * The combine method takes a {@link Corpus} as an input and adds each sentence of sentences {@link ArrayList}.
 *
 * @param corpus {@link Corpus} type input.
 */
void Corpus::combine(Corpus corpus) {
    for (const Sentence &sentence : corpus.sentences) {
        addSentence(sentence);
    }
}

/**
 * The addSentence method takes a Sentence as an input. It adds given input to sentences {@link ArrayList} and loops
 * through the each word in sentence and puts these words into wordList {@link CounterHashMap}.
 *
 * @param s Sentence type input that will be added to sentences {@link ArrayList} and its words will be added to wordList
 *          {@link CounterHashMap}.
 */
void Corpus::addSentence(Sentence s) {
    Word w;
    sentences.emplace_back(s);
    for (int i = 0; i < s.wordCount(); i++) {
        w = s.getWord(i);
        wordList.put(w);
    }
}
