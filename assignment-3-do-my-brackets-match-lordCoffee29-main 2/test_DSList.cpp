#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "DSList.h"
#include <string.h>

TEST_CASE("Check that DSList works", "[DSList]")
{
    // TESTING USAGE WITH THE COMMON PHRASE "HELLO WORLD"

    // Create string "Hello World" and list object
    std::string helloWorld = "Hello World";
    DSList<char> list;

    // Make a list with push_front
    for(int i = helloWorld.size(); i > 0; i--) {
        list.push_front(helloWorld.at(i - 1));
        CHECK(list.front() == helloWorld.at(i - 1)); // Check that each letter being added corresponds to the input string
    }

    // Test that the front and back of the list are the front and back characters of "Hello World," and that sizes match
    CHECK(list.peek() == 'd');
    CHECK(list.front() == 'H');
    REQUIRE(list.getSize() == helloWorld.size());

    // Empty the list
    list.empty();

    // Test that list is empty
    REQUIRE(list.isEmpty());

    // Make a list with push_back
    for(int i = 0; i < helloWorld.size(); i++) {
        list.push_back(helloWorld.at(i));
        CHECK(list.peek() == helloWorld.at(i)); // Check that each letter being added corresponds to the input string
    }

    // Test that the front and back of the list are the front and back characters of "Hello World," and that sizes match
    CHECK(list.peek() == 'd');
    CHECK(list.front() == 'H');
    REQUIRE(list.getSize() == helloWorld.size());

    // Test display
    // Result should display "Hello World"
    std::cout << "The contents of the list are: ";
    list.display();
    std::cout << std::endl;

    // Test pop_front
    // List should be "ello World"
    list.pop_front();
    
    // Check that the size of the list is one less than the string, and that the first character is 'e'
    CHECK(list.getSize() == (helloWorld.size() - 1));
    REQUIRE(list.front() == 'e');

    // Test pop_front is a loop (loops twice)
    // List should be "lo World"
    for(int i = 0; i < 2; i++) {
        list.pop_front();
    }

    // Check that the size of the list is three less than the string, and that the first character is 'l'
    CHECK(list.getSize() == (helloWorld.size() - 3));
    REQUIRE(list.front() == 'l');

    // Test find: search for 'W' (in list)
    // Result should be at position 3
    REQUIRE(list.find('W') == 3);

    // // Test find: search for 'K' (not in list)
    // // Result should return -1
    REQUIRE(list.find('K') == -1);

    // Test pop_back
    // List should be "lo Worl"
    list.pop_back();

    // Check that the size of the list is four less than the string, and that the last character is 'l'
    CHECK(list.getSize() == (helloWorld.size() - 4));
    REQUIRE(list.peek() == 'l');

    // Test pop_back in a loop (loops twice)
    // List should be "lo Wo"
    for(int i = 0; i < 2; i++) {
        list.pop_back();
    }

    // Check that the size of the list is six less than the string, and that the last character is 'o'
    CHECK(list.getSize() == (helloWorld.size() - 6));
    REQUIRE(list.peek() == 'o');


    // Test empty
    list.empty();

    // Check that the list is empty
    REQUIRE(list.isEmpty());
}

// you can run the test using Run CTest in the task bar or by running the tests executable. 