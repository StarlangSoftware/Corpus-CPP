//
// Created by Olcay Taner YILDIZ on 27.12.2020.
//

#include "catch.hpp"
#include "../FileDescription.h"

TEST_CASE("FileDescriptionTest-testGetIndex") {
    FileDescription fileDescription = FileDescription("mypath", "1234.train");
    REQUIRE(1234 == fileDescription.getIndex());
    fileDescription = FileDescription("mypath", "0000.test");
    REQUIRE(0 == fileDescription.getIndex());
    fileDescription = FileDescription("mypath", "0003.dev");
    REQUIRE(3 == fileDescription.getIndex());
    fileDescription = FileDescription("mypath", "0020.train");
    REQUIRE(20 == fileDescription.getIndex());
    fileDescription = FileDescription("mypath", "0304.dev");
    REQUIRE(304 == fileDescription.getIndex());
}

TEST_CASE("FileDescriptionTest-testGetExtension") {
    FileDescription fileDescription = FileDescription("mypath", "1234.train");
    REQUIRE("train" == fileDescription.getExtension());
    fileDescription = FileDescription("mypath", "0000.test");
    REQUIRE("test" == fileDescription.getExtension());
    fileDescription = FileDescription("mypath", "0003.dev");
    REQUIRE("dev" == fileDescription.getExtension());
}

TEST_CASE("FileDescriptionTest-testGetFileName") {
    FileDescription fileDescription = FileDescription("mypath", "0003.train");
    REQUIRE("mypath/0003.train" == fileDescription.getFileName());
    REQUIRE("newpath/0003.train" == fileDescription.getFileName("newpath"));
    REQUIRE("newpath/0000.train" == fileDescription.getFileName("newpath", 0));
    REQUIRE("newpath/0020.train" == fileDescription.getFileName("newpath", 20));
    REQUIRE("newpath/0103.train" == fileDescription.getFileName("newpath", 103));
    REQUIRE("newpath/0000.dev" == fileDescription.getFileName("newpath", 0, "dev"));
    REQUIRE("newpath/0020.dev" == fileDescription.getFileName("newpath", 20, "dev"));
    REQUIRE("newpath/0103.dev" == fileDescription.getFileName("newpath", 103, "dev"));
}