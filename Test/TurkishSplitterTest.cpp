//
// Created by Olcay Taner YILDIZ on 27.12.2020.
//

#include "catch.hpp"
#include "../src/TurkishSplitter.h"

TEST_CASE("TurkishSplitterTest-testSplit1") {
    TurkishSplitter splitter = TurkishSplitter();
    REQUIRE(14 == splitter.split(":Cin Ali, bak! At. "
                                    "Bak, Cin Ali, bak. "
                                    "Bu at. "
                                    "Baba, o atı bana al. "
                                    "Cin Ali, bu at. "
                                    "O da ot. "
                                    "Baba, bu ata ot al. "
                                    "Cin Ali, bu ot, o da at. "
                                    "Otu al, ata ver. "
                                    "Bak, Suna! "
                                    "Cin Ali, ata ot verdi. "
                                    "Su verdi. "
                                    "Cin Ali, ata bir kova da su verdi.").size());
}

TEST_CASE("TurkishSplitterTest-testSplit2") {
    TurkishSplitter splitter = TurkishSplitter();
    REQUIRE(1 == splitter.split("WWW.GOOGLE.COM").size());
}

TEST_CASE("TurkishSplitterTest-testSplit3") {
    TurkishSplitter splitter = TurkishSplitter();
    REQUIRE(1 == splitter.split("www.google.com").size());
}

TEST_CASE("TurkishSplitterTest-testSplit4") {
    TurkishSplitter splitter = TurkishSplitter();
    REQUIRE(1 == splitter.split("1. adımda ve 2. adımda ne yaptın").size());
    REQUIRE(7 == splitter.split("1. adımda ve 2. adımda ne yaptın")[0]->wordCount());
}

TEST_CASE("TurkishSplitterTest-testSplit5") {
    TurkishSplitter splitter = TurkishSplitter();
    REQUIRE(1 == splitter.split("1.adımda ve 2.adımda ne yaptın").size());
    REQUIRE(7 == splitter.split("1.adımda ve 2.adımda ne yaptın")[0]->wordCount());
}

TEST_CASE("TurkishSplitterTest-testSplit6") {
    TurkishSplitter splitter = TurkishSplitter();
    REQUIRE(1 == splitter.split("Burada II. Murat ve I. Ahmet oyun oynadı").size());
    REQUIRE(8 == splitter.split("Burada II. Murat ve I. Ahmet oyun oynadı")[0]->wordCount());
}