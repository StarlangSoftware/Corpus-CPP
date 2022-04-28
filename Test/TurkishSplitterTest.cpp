//
// Created by Olcay Taner YILDIZ on 27.12.2020.
//

#include "catch.hpp"
#include "../TurkishSplitter.h"

TEST_CASE("TurkishSplitterTest-testSplit") {
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