//
// Created by Olcay Taner Yıldız on 11.01.2019.
//
#include "FileDescription.h"

FileDescription::FileDescription(string path, string rawFileName) {
    extension = rawFileName.substr(rawFileName.find_last_of('.') + 1);
    index = stoi(rawFileName.substr(0, rawFileName.find_last_of('.')));
    this->path = move(path);
}

FileDescription::FileDescription(string path, string extension, int index) {
    this->path = move(path);
    this->extension = move(extension);
    this->index = index;
}

string FileDescription::getPath() {
    return path;
}

int FileDescription::getIndex() {
    return index;
}

string FileDescription::getExtension() {
    return extension;
}

string FileDescription::getFileName() {
    return getFileName(path);
}

string FileDescription::getFileNameWithExtension(string extension) {
    return getFileName(path, move(extension));
}

string FileDescription::getFileName(string thisPath) {
    return getFileName(move(thisPath), index);
}

string FileDescription::getFileName(string thisPath, string extension) {
    return getFileName(move(thisPath), index, move(extension));
}

string FileDescription::getFileName(string thisPath, int thisIndex) {
    char name[5];
    snprintf(name, 4, "%04d", thisIndex);
    return thisPath + "/" + name + "." + extension;
}

string FileDescription::getFileName(string thisPath, int thisIndex, string extension) {
    char name[5];
    snprintf(name, 4, "%04d", thisIndex);
    return thisPath + "/" + name + "." + extension;
}

string FileDescription::getRawFileName() {
    char name[5];
    snprintf(name, 4, "%04d", index);
    string tmp = name;
    return tmp + "." + extension;
}

void FileDescription::addToIndex(int count) {
    index += count;
}
