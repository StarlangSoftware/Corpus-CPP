cmake_minimum_required(VERSION 3.12)
project(Corpus)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(data_structure REQUIRED)
find_package(dictionary REQUIRED)
find_package(util REQUIRED)

add_library(Corpus WordFormat.h LanguageChecker.h SentenceSplitter.h Sentence.cpp Sentence.h Paragraph.cpp Paragraph.h FileDescription.cpp FileDescription.h TurkishChecker.cpp TurkishChecker.h TurkishSplitter.cpp TurkishSplitter.h Corpus.cpp Corpus.h SentenceSplitter.cpp EnglishSplitter.cpp EnglishSplitter.h CorpusStream.cpp CorpusStream.h AbstractCorpus.h)
target_link_libraries(Corpus data_structure::data_structure dictionary::dictionary util::util)
