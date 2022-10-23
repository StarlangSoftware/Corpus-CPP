//
// Created by Olcay Taner Yıldız on 11.01.2019.
//

#ifndef CORPUS_FILEDESCRIPTION_H
#define CORPUS_FILEDESCRIPTION_H

#include <string>
using namespace std;

class FileDescription {
private:
    string path, extension;
    int index;
public:
    FileDescription(const string& path, const string& rawFileName);
    FileDescription(const string& path, const string& extension, int index);
    string getPath();
    int getIndex() const;
    string getExtension();
    string getFileName();
    string getFileNameWithExtension(const string& _extension);
    string getFileName(const string& thisPath);
    string getFileName(const string& thisPath, const string& _extension);
    string getFileName(const string& thisPath, int thisIndex);
    string getFileName(const string& thisPath, int thisIndex, const string& _extension);
    string getRawFileName();
    void addToIndex(int count);
};


#endif //CORPUS_FILEDESCRIPTION_H
