#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// add includes
#include "BracketCheck.h"


TEST_CASE("Check that BracketCheck works", "[BracketCheck]")
{
    // Bracket check object
    BracketCheck check;
    

    // Test the bad vector file
    check.setFileName("./test_data/DSVector_bad.h");
    REQUIRE(check.check_array() == 1);
    REQUIRE(check.check_list() == 1);

    // Test the difficult vector file
    check.setFileName("./test_data/DSVector_difficult.h");
    REQUIRE(check.check_array() == 1);
    REQUIRE(check.check_list() == 1);

    // Test the good vector file
    check.setFileName("./test_data/DSVector_good.h");
    REQUIRE(check.check_array() == 0);
    REQUIRE(check.check_list() == 0);


    // TESTS OF PERSONALLY CREATED FILES

    // Test extra close bracket
    check.setFileName("./test_data/testExtraClose.h");
    REQUIRE(check.check_array() == 1);
    REQUIRE(check.check_list() == 1);

    // Test randomly placed close bracket
    check.setFileName("./test_data/testRandClose.h");
    REQUIRE(check.check_array() == 1);
    REQUIRE(check.check_list() == 1);

    // Test randomly placed open bracket
    check.setFileName("./test_data/testRandOpen.h");
    REQUIRE(check.check_array() == 1);
    REQUIRE(check.check_list() == 1);
}

// you can run the test using Run CTest in the task bar or by running the tests executable. 