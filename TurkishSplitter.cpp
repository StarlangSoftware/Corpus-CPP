//
// Created by Olcay Taner Yıldız on 11.01.2019.
//

#include "TurkishSplitter.h"
#include "TurkishLanguage.h"

/**
 * The contains method takes a String and a char input then check the given String contains the given char.
 *
 * @param s         String input to search for the char.
 * @param character Char input to look for in String.
 * @return true if char is found, false otherwise.
 */
bool TurkishSplitter::contains(string s, char character) {
    return s.find_first_of(character) != -1;
}

/**
 * The listContains method has a String array shortcuts which holds the possible abbreviations that might end with a '.' but not a
 * sentence finisher word. It also takes a String as an input and loops through the shortcuts array and returns
 * true if given String has any matching item in the shortcuts array.
 *
 * @param currentWord String input to check.
 * @return true if contains any abbreviations, false otherwise.
 */
bool TurkishSplitter::listContains(string currentWord) {
    string shortcuts[] = {"alb", "bnb", "bkz", "bşk", "co", "dr", "dç", "der", "em", "gn",
                          "hz", "kd", "kur", "kuv", "ltd", "md", "mr", "mö", "muh", "müh",
                          "no", "öğr", "op", "opr", "org", "sf", "tuğ", "uzm", "vb", "vd",
                          "yön", "yrb", "yrd", "üniv", "fak", "prof", "dz", "yd", "krm", "gen",
                          "pte", "p", "av", "II", "III", "IV", "VI", "VII", "VIII", "IX",
                          "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX",
                          "XX", "tuğa", "plt", "tğm", "tic", "srv", "bl", "dipl", "not", "min",
                          "cul", "san", "rzv", "or", "kor", "tüm", "st", "sn", "fr", "pl",
                          "ka", "tk", "ko", "vs", "yard", "bknz", "doç", "gör", "müz", "oyn",
                          "m", "s", "kr", "ms", "hv", "uz", "re", "ph", "mc", "ed",
                          "km", "yb", "bk", "jr", "bn", "os", "mrs", "bld", "sen", "alm",
                          "sir", "ord", "dir", "yay", "man", "brm", "edt", "dec", "mah", "cad",
                          "vol", "kom", "sok", "apt", "elk", "mad", "ort", "cap", "ste", "exc",
                          "ef"};
    for (const string &shortcut : shortcuts) {
        if (currentWord == shortcut) {
            return true;
        }
    }
    return false;
}

/**
 * The isNextCharUpperCaseOrDigit method takes a String line and an int i as inputs. First it compares each char in
 * the input line with " " and SEPARATORS ({@literal ()[]{}"'״＂՛}) and increment i by one until a mismatch or end of line.
 * <p>
 * When i equals to line length or contains one of the uppercase letters or digits it returns true, false otherwise.
 *
 * @param line String to check.
 * @param i    int defining starting index.
 * @return true if next char is uppercase or digit, false otherwise.
 */
bool TurkishSplitter::isNextCharUpperCaseOrDigit(string line, int i) {
    while (i < line.size() && (line[i] == ' ' || contains(SEPARATORS, line[i]))) {
        i++;
    }
    if (i == line.size() || contains(TurkishLanguage::UPPERCASE_LETTERS + TurkishLanguage::DIGITS + "-", line[i])) {
        return true;
    } else {
        return false;
    }
}

/**
 * The isPreviousWordUpperCase method takes a String line and an int i as inputs. First it compares each char in
 * the input line with " " and checks each char whether they are lowercase letters or one of the qxw. And decrement
 * input i by one till this condition is false.
 * <p>
 * When i equals to -1 or contains one of the uppercase letters or one of the QXW it returns true, false otherwise.
 *
 * @param line String to check.
 * @param i    int defining ending index.
 * @return true if previous char is uppercase or one of the QXW, false otherwise.
 */
bool TurkishSplitter::isPreviousWordUpperCase(string line, int i) {
    while (i >= 0 && (line[i] == ' ' || contains(TurkishLanguage::LOWERCASE_LETTERS + "qxw", line[i]))) {
        i--;
    }
    if (i == -1 || contains(TurkishLanguage::UPPERCASE_LETTERS + "QWX", line[i])) {
        return true;
    } else {
        return false;
    }
}

/**
 * The isNextCharUpperCase method takes a String line and an int i as inputs. First it compares each char in
 * the input line with " " and increment i by one until a mismatch or end of line.
 * <p>
 * When i equals to line length or contains one of the uppercase letters it returns true, false otherwise.
 *
 * @param line String to check.
 * @param i    int defining starting index.
 * @return true if next char is uppercase, false otherwise.
 */
bool TurkishSplitter::isNextCharUpperCase(string line, int i) {
    while (i < line.size() && (line[i] == ' ')) {
        i++;
    }
    if (i == line.length() || contains(TurkishLanguage::UPPERCASE_LETTERS + "\"\'", line[i])) {
        return true;
    } else {
        return false;
    }
}

/**
 * The isNameShortcut method takes a String word as an input. First, if the word length is 1, and currentWord
 * contains UPPERCASE_LETTERS letters than it returns true.
 * <p>
 * Secondly, if the length of the word is 3 (i.e it is a shortcut) and it has a '.' at its 1st index and
 * currentWord's 2nd  index is an uppercase letter it also returns true. (Ex : m.A)
 *
 * @param currentWord String input to check whether it is a shortcut.
 * @return true if given input is a shortcut, false otherwise.
 */
bool TurkishSplitter::isNameShortcut(string currentWord) {
    if (currentWord.size() == 1 && TurkishLanguage::UPPERCASE_LETTERS.find_first_of(currentWord) != -1) {
        return true;
    }
    if (currentWord.size() == 3 && currentWord[1] == '.' && contains(TurkishLanguage::UPPERCASE_LETTERS, currentWord[2])) {
        return true;
    }
    return false;
}
