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

/**
 * The overridden clone method which creates a new sentence and clone words to this sentence.
 *
 * @return Sentence type sentence.
 */
Sentence Sentence::clone() {
    Sentence s = Sentence();
    for (Word w : words)
        s.addWord(w);
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
        words.emplace_back(Word(word));
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
    istringstream iss(sentence);
    vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());
    for (const string &word : results) {
        if (!word.empty()) {
            words.emplace_back(Word(word));
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
Sentence::Sentence(string sentence, LanguageChecker languageChecker) {
    istringstream iss(sentence);
    vector<string> results(istream_iterator<string>{iss}, istream_iterator<string>());
    for (const string &word : results) {
        if (!word.empty() && languageChecker.isValidWord(word)) {
            words.emplace_back(Word(word));
        }
    }
}

/**
 * The getWord method takes an index input and gets the word at that index.
 *
 * @param index is used to get the word.
 * @return the word in given index.
 */
Word Sentence::getWord(int index) {
    return words.at(index);
}

/**
 * The getWords method returns the {@link vector} words.
 *
 * @return words vector.
 */
vector<Word> Sentence::getWords() {
    return words;
}

/**
 * The getStrings method loops through the words {@link vector} and adds each words' names to the newly created
 * {@link vector} result.
 *
 * @return result Vector which holds names of the words.
 */
vector<string> Sentence::getStrings() {
    vector<string> result;
    for (const Word& word : words) {
        result.emplace_back(word.getName());
    }
    return result;
}

/**
 * The getIndex method takes a word as an input and finds the index of that word in the words {@link ArrayList} if it exists.
 *
 * @param word Word type input to search for.
 * @return index of the found input, -1 if not found.
 */
int Sentence::getIndex(Word word) {
    int i = 0;
    for (const Word& w : words) {
        if (w == word)
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
void Sentence::addWord(Word word) {
    words.emplace_back(word);
}

/**
 * The charCount method finds the total number of chars in each word of words {@link vector}.
 *
 * @return sum of the chars.
 */
int Sentence::charCount() {
    int sum = 0;
    for (Word word : words)
        sum += word.charCount();
    return sum;
}
