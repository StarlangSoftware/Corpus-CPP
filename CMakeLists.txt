cmake_minimum_required(VERSION 3.12)
project(Corpus)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(data_structure REQUIRED)
find_package(dictionary REQUIRED)
find_package(util REQUIRED)

add_library(Corpus src/WordFormat.h src/LanguageChecker.h src/SentenceSplitter.h src/Sentence.cpp src/Sentence.h src/Paragraph.cpp src/Paragraph.h src/FileDescription.cpp src/FileDescription.h src/TurkishChecker.cpp src/TurkishChecker.h src/TurkishSplitter.cpp src/TurkishSplitter.h src/Corpus.cpp src/Corpus.h src/SentenceSplitter.cpp src/EnglishSplitter.cpp src/EnglishSplitter.h src/CorpusStream.cpp src/CorpusStream.h src/AbstractCorpus.h)
target_link_libraries(Corpus data_structure::data_structure dictionary::dictionary util::util)
add_executable(Test src/WordFormat.h src/LanguageChecker.h src/SentenceSplitter.h src/Sentence.cpp src/Sentence.h src/Paragraph.cpp src/Paragraph.h src/FileDescription.cpp src/FileDescription.h src/TurkishChecker.cpp src/TurkishChecker.h src/TurkishSplitter.cpp src/TurkishSplitter.h src/Corpus.cpp src/Corpus.h Test/SentenceTest.cpp Test/FileDescriptionTest.cpp Test/TurkishSplitterTest.cpp Test/CorpusTest.cpp src/SentenceSplitter.cpp Test/EnglishSplitterTest.cpp src/EnglishSplitter.cpp src/EnglishSplitter.h src/CorpusStream.cpp src/CorpusStream.h Test/CorpusStreamTest.cpp src/AbstractCorpus.h)
target_link_libraries(Test data_structure::data_structure dictionary::dictionary util::util)
