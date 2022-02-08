//
// Created by Olcay Taner YILDIZ on 8.02.2022.
//

#include "catch.hpp"
#include "../EnglishSplitter.h"

TEST_CASE("EnglishSplitterTest-testSplit") {
    EnglishSplitter splitter = EnglishSplitter();
    REQUIRE(12 == splitter.split("There are some advantages and disadvantages about video games’s effects on teenagers. First of all, people who are especially teenagers are stuck home in these days because of the fact that corona virus. So, they want to killing time in their free time and video games show up in this situation. They are able to play video games with their friends or individually. Secondly, there are various games in the internet, so they are able to find the best ones for themselves. Moreover, games help teenagers to improve their language which they are trying to learn. Consequently, teenagers aren’t bored when they are alone. In the other hand,  teenagers shouldn’t play video games so much if they play, they are going to be addicted. In this situation they are start to gaining more weights and they get disease which name is obesity. Therefore, they are starting to get out less and teenagers loose their sociability. They feel less confident and they can’t communicate with someone easily in real life. To sum up, people need to balance time which they spent on video games.").size());
}