//
// Created by LMF319018 on 09/01/2019.
//

#include <fstream>
#include <sstream>
#include "Sentence.h"

/**
 * An empty constructor of {@link Sentence} class. Creates an {@link vector} of words.
 */
Sentence::Sentence() {
}

Sentence::~Sentence(){
    for (auto& word : words){
        delete word;
    }
}
/**
 * The overridden clone method which creates a new sentence and clone words to this sentence.
 *
 * @return Sentence type sentence.
 */
Sentence Sentence::clone() {
    Sentence s = Sentence();
    for (Word* w : words)
        s.addWord(new Word(w->getName()));
    return s;
}

/**
 * Another constructor of {@link Sentence} class which takes a file as an input. It reads each word in the file
 * and adds to words {@link vector}.
 *
 * @param file input file to read words from.
 */
Sentence::Sentence(ifstream file) {
    while (file.good()) {
        string word;
        file >> word;
        words.emplace_back(new Word(word));
    }
    file.close();
}

/**
 * Another constructor of {@link Sentence} class which takes a sentence String as an input. It parses the sentence by
 * " " and adds each word to the newly created {@link vector} words.
 *
 * @param sentence String input to parse.
 */
Sentence::Sentence(string sentence) {
    vector<string> results = Word::split(sentence);
    for (const string &word : results) {
        if (!word.empty()) {
            words.emplace_back(new Word(word));
        }
    }
}

/**
 * Another constructor of {@link Sentence} class with two inputs; a String sentence and a {@link LanguageChecker}
 * languageChecker. It parses a sentence by " " and then check the language considerations. If it is a valid word,
 * it adds this word to the newly created {@link vector} words.
 *
 * @param sentence        String input.
 * @param languageChecker {@link LanguageChecker} type input.
 */
Sentence::Sentence(string sentence, LanguageChecker* languageChecker) {
    vector<string> results = Word::split(sentence);
    for (const string &word : results) {
        if (!word.empty() && languageChecker->isValidWord(word)) {
            words.emplace_back(new Word(word));
        }
    }
}

/**
 * The getWord method takes an index input and gets the word at that index.
 *
 * @param index is used to get the word.
 * @return the word in given index.
 */
Word* Sentence::getWord(int index) {
    return words.at(index);
}

/**
 * The getWords method returns the {@link vector} words.
 *
 * @return words vector.
 */
vector<Word*> Sentence::getWords() {
    return words;
}

vector<Word> Sentence::getWordList() {
    vector<Word> wordList;
    for (Word* word : words) {
        wordList.push_back(*word);
    }
    return wordList;
}

/**
 * The getStrings method loops through the words {@link vector} and adds each words' names to the newly created
 * {@link vector} result.
 *
 * @return result Vector which holds names of the words.
 */
vector<string> Sentence::getStrings() {
    vector<string> result;
    for (Word* word : words) {
        result.emplace_back(word->getName());
    }
    return result;
}

/**
 * The getIndex method takes a word as an input and finds the index of that word in the words {@link ArrayList} if it exists.
 *
 * @param word Word type input to search for.
 * @return index of the found input, -1 if not found.
 */
int Sentence::getIndex(Word* word) {
    int i = 0;
    for (Word* w : words) {
        if (w->getName() == word->getName())
            return i;
        i++;
    }
    return -1;
}

/**
 * The wordCount method finds the size of the words {@link vector}.
 *
 * @return the size of the words {@link vector}.
 */
unsigned long Sentence::wordCount() {
    return words.size();
}

/**
 * The addWord method takes a word as an input and adds this word to the words {@link vector}.
 *
 * @param word Word to add words {@link vector}.
 */
void Sentence::addWord(Word* word) {
    words.emplace_back(word);
}

/**
 * The charCount method finds the total number of chars in each word of words {@link vector}.
 *
 * @return sum of the chars.
 */
int Sentence::charCount() {
    int sum = 0;
    for (Word* word : words)
        sum += word->charCount();
    return sum;
}

/**
 * The replaceWord method takes an index and a word as inputs. It removes the word at given index from words
 * {@link vector} and then adds the given word to given index of words.
 *
 * @param i       index.
 * @param newWord to add the words {@link vector}.
 */
void Sentence::replaceWord(int i, Word* newWord) {
    words.erase(words.begin() + i);
    words.insert(words.begin() + i, newWord);
}

/**
 * The insertWord method takes an index and a word as inputs. It inserts the word at given index to words
 * {@link ArrayList}.
 *
 * @param i       index.
 * @param newWord to add the words {@link ArrayList}.
 */
void Sentence::insertWord(int i, Word *newWord) {
    words.insert(words.begin() + i, newWord);
}

/**
 * The safeIndex method takes an index as an input and checks whether this index is between 0 and the size of the words.
 *
 * @param index is used to check the safety.
 * @return true if an index is safe, false otherwise.
 */
bool Sentence::safeIndex(int index) {
    return index >= 0 && index < words.size();
}

/**
 * The overridden toString method returns an accumulated string of each word in words {@link ArrayList}.
 *
 * @return String result which has all the word in words {@link ArrayList}.
 */
string Sentence::to_string() {
    if (!words.empty()) {
        string result = words.at(0)->to_string();
        for (int i = 1; i < words.size(); i++) {
            result += " ";
            result += words.at(i)->to_string();
        }
        return result;
    } else {
        return "";
    }
}

/**
 * The toWords method returns an accumulated string of each word's names in words {@link ArrayList}.
 *
 * @return String result which has all the names of each item in words {@link ArrayList}.
 */
string Sentence::toWords(){
    if (!words.empty()) {
        string result = words.at(0)->getName();
        for (int i = 1; i < words.size(); i++) {
            result += " ";
            result += words.at(i)->getName();
        }
        return result;
    } else {
        return "";
    }
}

/**
 * The writeToFile method writes the given file by using toString method.
 *
 * @param file to write in.
 */
void Sentence::writeToFile(ofstream file){
    file << to_string();
    file.close();
}