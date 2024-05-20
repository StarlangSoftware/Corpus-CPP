//
// Created by Olcay Taner Yıldız on 11.01.2019.
//
#include "FileDescription.h"

/**
 * Constructor for the FileDescription object. FileDescription object is used to store sentence or tree file names
 * in a format of path/index.extension such as 'trees/0123.train' or 'sentences/0002.test'. At most 10000 file names
 * can be stored for an extension.
 * @param path Path of the file
 * @param rawFileName Raw file name of the string without path name, including the index of the file and the
 *                    extension. For example 0023.train, 3456.test, 0125.dev, 0000.train etc.
 */
FileDescription::FileDescription(const string& path, const string& rawFileName) {
    this->extension = rawFileName.substr(rawFileName.find_last_of('.') + 1);
    this->index = stoi(rawFileName.substr(0, rawFileName.find_last_of('.')));
    this->path = path;
}

/**
 * Another constructor for the FileDescription object. FileDescription object is used to store sentence or tree
 * file names in a format of path/index.extension such as 'trees/0123.train' or 'sentences/0002.test'. At most 10000
 * file names can be stored for an extension.
 * @param path Path of the file
 * @param extension Extension of the file such as train, test, dev etc.
 * @param index Index of the file, should be larger than or equal to 0 and less than 10000. 123, 0, 9999, etc.
 */
FileDescription::FileDescription(const string& path, const string& extension, int index) {
    this->path = path;
    this->extension = extension;
    this->index = index;
}

/**
 * Accessor for the path attribute.
 * @return Path
 */
string FileDescription::getPath() const{
    return path;
}

/**
 * Accessor for the index attribute.
 * @return Index
 */
int FileDescription::getIndex() const {
    return index;
}

/**
 * Accessor for the extension attribute.
 * @return Extension
 */
string FileDescription::getExtension() const{
    return extension;
}

/**
 * Returns the filename with the original path, such as trees/1234.train
 * @return The filename with the original path
 */
string FileDescription::getFileName() const{
    return getFileName(path);
}

/**
 * Returns the filename with extension replaced with the given extension.
 * @param extension New extension
 * @return The filename with extension replaced with the given extension.
 */
string FileDescription::getFileNameWithExtension(const string& _extension) const{
    return getFileName(path, _extension);
}

/**
 * Returns the filename with path replaced with the given path
 * @param thisPath New path
 * @return The filename with path replaced with the given path
 */
string FileDescription::getFileName(const string& thisPath) const{
    return getFileName(thisPath, index);
}

/**
 * Returns the filename with path and extensions are replaced with the given path and extension.
 * @param thisPath New path
 * @param extension New extension
 * @return The filename with path and extensions are replaced with the given path and extension.
 */
string FileDescription::getFileName(const string& thisPath, const string& _extension) const{
    return getFileName(thisPath, index, _extension);
}

/**
 * Returns the filename with path and index are replaced with the given path and index.
 * @param thisPath New path
 * @param thisIndex New Index
 * @return The filename with path and index are replaced with the given path and index.
 */
string FileDescription::getFileName(const string& thisPath, int thisIndex) const{
    char name[5];
    snprintf(name, 5, "%04d", thisIndex);
    return thisPath + "/" + name + "." + extension;
}

/**
 * Returns the filename with path, index, and extension are replaced with the given path, index, and extension.
 * @param thisPath New path
 * @param thisIndex New Index
 * @param extension New extension
 * @return The filename with path, index, and extension are replaced with the given path, index, and extension.
 */
string FileDescription::getFileName(const string& thisPath, int thisIndex, const string& _extension) const{
    char name[5];
    snprintf(name, 5, "%04d", thisIndex);
    return thisPath + "/" + name + "." + _extension;
}

/**
 * Returns only the filename without path as 'index.extension'.
 * @return File name without path as 'index.extension'.
 */
string FileDescription::getRawFileName() const{
    char name[5];
    snprintf(name, 5, "%04d", index);
    string tmp = name;
    return tmp + "." + extension;
}

/**
 * Increments index by count
 * @param count Count to be incremented
 */
void FileDescription::addToIndex(int count) {
    index += count;
}
