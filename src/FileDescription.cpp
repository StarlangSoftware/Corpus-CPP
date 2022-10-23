//
// Created by Olcay Taner Yıldız on 11.01.2019.
//
#include "FileDescription.h"

FileDescription::FileDescription(const string& path, const string& rawFileName) {
    this->extension = rawFileName.substr(rawFileName.find_last_of('.') + 1);
    this->index = stoi(rawFileName.substr(0, rawFileName.find_last_of('.')));
    this->path = path;
}

FileDescription::FileDescription(const string& path, const string& extension, int index) {
    this->path = path;
    this->extension = extension;
    this->index = index;
}

string FileDescription::getPath() const{
    return path;
}

int FileDescription::getIndex() const {
    return index;
}

string FileDescription::getExtension() const{
    return extension;
}

string FileDescription::getFileName() const{
    return getFileName(path);
}

string FileDescription::getFileNameWithExtension(const string& _extension) const{
    return getFileName(path, _extension);
}

string FileDescription::getFileName(const string& thisPath) const{
    return getFileName(thisPath, index);
}

string FileDescription::getFileName(const string& thisPath, const string& _extension) const{
    return getFileName(thisPath, index, _extension);
}

string FileDescription::getFileName(const string& thisPath, int thisIndex) const{
    char name[5];
    snprintf(name, 5, "%04d", thisIndex);
    return thisPath + "/" + name + "." + extension;
}

string FileDescription::getFileName(const string& thisPath, int thisIndex, const string& _extension) const{
    char name[5];
    snprintf(name, 5, "%04d", thisIndex);
    return thisPath + "/" + name + "." + _extension;
}

string FileDescription::getRawFileName() const{
    char name[5];
    snprintf(name, 5, "%04d", index);
    string tmp = name;
    return tmp + "." + extension;
}

void FileDescription::addToIndex(int count) {
    index += count;
}
