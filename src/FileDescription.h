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
    [[nodiscard]] string getPath() const;
    [[nodiscard]] int getIndex() const;
    [[nodiscard]] string getExtension() const;
    [[nodiscard]] string getFileName() const;
    [[nodiscard]] string getFileNameWithExtension(const string& _extension) const;
    [[nodiscard]] string getFileName(const string& thisPath) const;
    [[nodiscard]] string getFileName(const string& thisPath, const string& _extension) const;
    [[nodiscard]] string getFileName(const string& thisPath, int thisIndex) const;
    [[nodiscard]] string getFileName(const string& thisPath, int thisIndex, const string& _extension) const;
    [[nodiscard]] string getRawFileName() const;
    void addToIndex(int count);
};


#endif //CORPUS_FILEDESCRIPTION_H
