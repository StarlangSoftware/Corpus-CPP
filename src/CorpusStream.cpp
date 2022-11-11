//
// Created by Olcay Taner YILDIZ on 11.11.2022.
//

#include "CorpusStream.h"

CorpusStream::CorpusStream(const string& fileName) {
    this->fileName = fileName;
}

void CorpusStream::open(){
    inputStream.open(fileName, ifstream::in);
}

void CorpusStream::close(){
    inputStream.close();
}

Sentence *CorpusStream::getSentence(){
    string line;
    if (inputStream.good()){
        getline(inputStream, line);
        return new Sentence(line);
    }
    return nullptr;
}

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
