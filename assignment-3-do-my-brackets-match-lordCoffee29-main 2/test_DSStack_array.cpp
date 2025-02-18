#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// add includes
#include "DSStack_array.h"
#include <string.h>


TEST_CASE("Check that DSStack_array works", "[DSStack_array]")
{
    // add test cases (create lists and specify what the expected output is)

    // TESTING USAGE WITH THE COMMON PHRASE "HELLO WORLD"

    // Create string "Hello World" and create stack array object
    std::string testString = "Hello World";
    DSStack_array *testStack = new DSStack_array();

    // Test push
    for(unsigned int i = 0; i < testString.size(); i++) {
        testStack->push(testString.at(i));
        CHECK(testStack->peek() == testString.at(i)); // Check that characters in the stack correspond to characters in the string
    }

    // Test "display" 
    // The stack should be "Hello World"
    std::cout << "The stack contains: ";
    testStack->display();
    std::cout << std::endl;

    // Test getSize
    // The size of "Hello World" should be 11
    REQUIRE(testStack->getSize() == testString.size());

    // Test peek
    // The result of peek should be 'd'
    REQUIRE(testStack->peek() == 'd');

    // Test pop
    // The result of pop should be a stack with size of 10 and "Hello Worl", and peek should return 'l'
    testStack->pop();
    
    CHECK(testStack->getSize() == 10);
    REQUIRE(testStack->peek() == 'l');

    // Test pop in a loop (to make sure multiple pops work)
    // For 2 iterations of a loop, the result should be a stack with size of 8 and "Hello Wo", and peek should return 'o'
    for(int i = 0; i < 2; i++) {
        testStack->pop();
    }
    
    CHECK(testStack->getSize() == 8);
    REQUIRE(testStack->peek() == 'o');

    // Test isEmpty when the stack is not empty
    // Since the testStack is not empty, the result should be 0, or false
    REQUIRE_FALSE(testStack->isEmpty());
    
    // Test empty
    // The result should be a size of 0
    testStack->empty();
    
    REQUIRE(testStack->isEmpty());

    

    delete testStack;
}

// you can run the test using Run CTest in the task bar or by running the tests executable. 