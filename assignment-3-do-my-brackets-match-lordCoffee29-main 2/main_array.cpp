#include <iostream>
#include <algorithm>

#include "DSStack_array.h"
#include "BracketCheck.h"


// file names to check are passed on as command line arguments
int main(int argc, char **argv)
{
    // Start runtime clock
    auto start = std::chrono::high_resolution_clock::now();

    // Run the checker for each file
    for (int i = 1; i < argc; ++i) {
        BracketCheck check;
        check.setFileName(argv[i]);
        check.check_array();
    }

    // End runtime clock
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    // Display runtime in milliseconds
    std::cout << " Checking all the files took " << duration.count() << " milliseconds." << std::endl;

    return 0;
}

// in the terminal type `cd build` and then `./check_brackets_array test_data/*`