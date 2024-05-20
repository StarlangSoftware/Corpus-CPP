//
// Created by Olcay Taner YILDIZ on 11.11.2022.
//

#include "CorpusStream.h"

/**
 * Constructor for CorpusStream. CorpusStream is used for reading very large corpora that does not fit in memory as
 * a whole. For that reason, sentences are read one by one.
 * @param fileName File name of the corpus stream.
 */
CorpusStream::CorpusStream(const string& fileName) {
    this->fileName = fileName;
}

/**
 * Implements open method in AbstractCorpus. Initializes file reader.
 */
void CorpusStream::open(){
    inputStream.open(fileName, ifstream::in);
}

/**
 * Implements close method in AbstractCorpus. Closes the file reader.
 */
void CorpusStream::close(){
    inputStream.close();
}

/**
 * Implements getSentence method in AbstractCorpus. Reads from the file buffer next sentence and returns it. If
 * there are no sentences to be read, returns null.
 * @return Next read sentence from file buffer or null.
 */
Sentence *CorpusStream::getSentence(){
    string line;
    if (inputStream.good()){
        getline(inputStream, line);
        return new Sentence(line);
    }
    return nullptr;
}

/**
 * Reads more than one line (lineCount lines) from the buffer, stores them in an array list and returns that
 * array list. If there are no lineCount lines to be read, the method reads only available lines and returns them.
 * @param lineCount Maximum number of lines to read.
 * @return An array list of read lines.
 */
vector<Sentence *> CorpusStream::getSentenceBatch(int lineCount){
    vector<Sentence *> sentences;
    string line;
    for (int i = 0; i < lineCount; i++){
        if (inputStream.good()) {
            getline(inputStream, line);
            sentences.push_back(new Sentence(line));
        } else {
            break;
        }
    }
    return sentences;
}

CorpusStream::CorpusStream() = default;
