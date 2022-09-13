cmake_minimum_required(VERSION 3.12)
project(Corpus)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
set(CONAN_INCLUDE_DIRS_DICTIONARY "/Users/olcay/.conan/data/Dictionary/1.0.0/_/_/package/ace494fb7be9c56def71a38747cca129e2ccda0d/include")

add_library(Corpus src/WordFormat.h src/LanguageChecker.h src/SentenceSplitter.h src/Sentence.cpp src/Sentence.h src/Paragraph.cpp src/Paragraph.h src/FileDescription.cpp src/FileDescription.h src/TurkishChecker.cpp src/TurkishChecker.h src/TurkishSplitter.cpp src/TurkishSplitter.h src/Corpus.cpp src/Corpus.h src/SentenceSplitter.cpp src/EnglishSplitter.cpp src/EnglishSplitter.h)
target_link_libraries(Corpus ${CONAN_LIBS})
add_executable(Test src/WordFormat.h src/LanguageChecker.h src/SentenceSplitter.h src/Sentence.cpp src/Sentence.h src/Paragraph.cpp src/Paragraph.h src/FileDescription.cpp src/FileDescription.h src/TurkishChecker.cpp src/TurkishChecker.h src/TurkishSplitter.cpp src/TurkishSplitter.h src/Corpus.cpp src/Corpus.h Test/SentenceTest.cpp Test/FileDescriptionTest.cpp Test/TurkishSplitterTest.cpp Test/CorpusTest.cpp src/SentenceSplitter.cpp Test/EnglishSplitterTest.cpp src/EnglishSplitter.cpp src/EnglishSplitter.h)
target_link_libraries(Test ${CONAN_LIBS})
