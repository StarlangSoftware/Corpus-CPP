# Corpus-CPP

Nlptoolkit’in birimlendirici/cümle bölücü bileşeni, bir serbest metnin birimlerini ve/veya cümlelerini saptamak için kullanılabilir. Bu bileşen, kural tabanlı bir bileşen olup girdiyi önceden belirlenmiş bir kural kümesini takip ederek cümlelere ve birimlerine ayırır. Bu kural kümesi, bir sonraki karakterin küçük/büyük harf olması gibi cümle düzeyinde kurallar içerdiği gibi, bir girdinin Türkçe’deki yaygın kısaltmalar arasında olup olmadığını kontrol etmek gibi dil düzeyinde kurallar da içerir. Özetle, birimlendirici/cümle bölücü bileşeni bir girdi olarak serbest metin alır ve çıktı olarak birimlerine ayrılmış bir cümle kümesi verir.

For Developers
============
You can also see either [Python](https://github.com/olcaytaner/Corpus-Py) 
or [Java](https://github.com/olcaytaner/Corpus) repository.
## Requirements

* [C++ Compiler](#cpp)
* [Git](#git)


### CPP
To check if you have compatible C++ Compiler installed,
* Open CLion IDE 
* Preferences >Build,Execution,Deployment > Toolchain  

### Git

Install the [latest version of Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Download Code

In order to work on code, create a fork from GitHub page. 
Use Git for cloning the code to your local or below line for Ubuntu:

	git clone <your-fork-git-link>

A directory called DataStructure will be created. Or you can use below link for exploring the code:

	git clone https://github.com/olcaytaner/Corpus-CPP.git

## Open project with CLion IDE

To import projects from Git with version control:

* Open CLion IDE , select Get From Version Control.

* In the Import window, click URL tab and paste github URL.

* Click open as Project.

Result: The imported project is listed in the Project Explorer view and files are loaded.


## Compile

**From IDE**

After being done with the downloading and opening project, select **Build Project** option from **Build** menu. After compilation process, user can run CorpusTest.cpp .

Detailed Description
============
+ [Corpus](#corpus)
+ [TurkishSplitter](#turkishsplitter)

## Corpus

Bir derlemi hafızaya atmak için

	a = Corpus("derlem.txt");

Bu derlem eğer noktalarla bölünmüş fakat cümlelere bölünmemiş ise

	Corpus(String fileName, SentenceSplitter sentenceSplitter)

Bu derlemin içinde Türkçe dışında cümleler de varsa, onları elimine etmek için

	Corpus(String fileName, LanguageChecker languageChecker)

Derlemdeki cümle sayısı

	int sentenceCount()

Derlemdeki i. cümle ise

	Sentence getSentence(int index)

## TurkishSplitter

Türkçe . kurallarına göre cümlelere ayırmak için TurkishSplitter sınıfı kullanılır.

	ArrayList<Sentence> split(String line);
