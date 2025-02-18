# Assignment: Do My Brackets Match?

**Objectives:**

* Implement a templated list data structure.
* Developing tests and automated code testing using the catch2 framework.
* Implement a stack interface.


## Time Line 
You have about three weeks to complete the assignment. Start right away! **The lab TA will expect that you already have most of that week's work completed. Come with prepared questions and
be prepared to answer the TA's questions about your code.**

* Week 1: DSStack_array class based on an array with CATCH2 tests and memory leak debugging using `valgrind`. **Deliverables:** `DSStack_array` implementation + test. 
* Week 2: DSStack class based on a linked list with CATCH2 tests and memory leak debugging using `valgrind`. **Deliverables:** `DSList` implementation + test.
* Week 3: Bracket checking function for a single file. CATCH2 tests for the check function. A driver program with command line interface that can check a set of files. Improve the code, comments and the documentation. **Deliverables:** completed project with code, tests and completed answers document.


## Introduction
Writing code is fun... Well, most of the time. Sometimes I mess up
brackets (i.e., `"[]", "()", "{}"`). 
I have a library of hundreds of
source code files and do not want to manually open each one up in VS Code,
so I need a program to do the checking for me.

The program should be called in the following way:

```
check_brackets <input_file> [<input_file> ...]
```

It should produce the following output:

1. If no error is found: `<input file name>: OK` and return 0 (meaning the program executed successfully)
2. If an error is found: `<input file names>: Bracket mismatch detected for [ in line number x` and return 1 (meaning there was a problem).

## The Algorithm
Check code for balanced brackets: push `({[` on the stack and take them off when the corresponding `)`, `}`, or `)` is seen. Any error or a non-empty stack at the end of the code indicates a problem.

## The Data
 You can get some source code (e.g., from the examples in this class) and check them. Then introduce some mistakes and check again. The `data` directory contains example files.

## Implementation Requirements
Write good, well documented code!

You **cannot use STL containers for the stack.** You need to implement two versions of the stack yourself. 

For strings, you can use the STL class`std::string`. Reading STL strings is a 
lot easier than c-strings. See the C++ section of this [IO example](https://github.com/mhahsler/CS2341/blob/main/Chapter1_Programming/io/). 

1. A stack based on an array.
2. A stack based on your own list class implementation. 

Write two programs (add another executable to the `CMakeLists.txt`), one based on a list and one based on a array. Compare the runtime on some larger source code files. Your programs should report the runtime every time. See [the code examples in Chapter2 Algorithm Analysis](https://github.com/mhahsler/CS2341/tree/main/Chapter2_Algorithm_Analysis) for examples of how to measure runtime in C++.


## Additional Work (Bonus; max. 5 points)
* Make sure that unbalanced brackets in comments (`//`, and `/*`) and character or string definitions (i.e., in single and double quotation marks) do not produce an error. This means you also can check `\*` and `*\` and string delimiters `"` and `'` for consistency. [up to +2]
* Check all the `clang` source code from [llvm project](https://github.com/llvm/llvm-project) in the directories `clang/include/` and `clang/lib/` to report timing differences between data different structures. [up to +2]
* How would you check `<>` in C++ since it is used in templates, 
but can also be used as comparison operators? [up to +3]
* Better testing: Can you generate a long text file that randomly nested brackets to a specified depth that you can use to test your code better? [+1]
* Can your program make a recommendation of where to place missing brackets? How would it do that. [up to  +2]
* You could use the function call stack as the "stack" in your program and implement the checker as a recursive program. [up to +3] 

## Grading Rubric

|                             | Points Possible | Points Awarded |
| :------------------         | --------------: | -------------: |
| DSStack_array Class      | 15              |                |
| DSStack_list Class       | 15              |                |
| CATCH2 tests for each class and the checker    |  15              |                |
| Proper Memory Management (valgrind) | 10      |                |
| Runtime comparison          |  5              |                |
| Bracket checker (OK/not OK) | 15              |                |
| Detailed errors for checker | 10              |                |
| Formatting, comments, warnings, etc.  |  5              |                |
| Proper use of GitHub        |  5              |                |
| Answer to questions         |  5              |                |
| Additional Work             | up to +5       |                |
| 48hr early submission bonus |  + 5      |                |

