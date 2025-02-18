# Do My Brackets Match?

**Objectives:**

* Implement a templated list data structure.
* Developing tests and automated code testing using the catch2 framework.
* Implement a stack interface.


## Introduction

The program should be called in the following way:

```
check_brackets <input_file> [<input_file> ...]
```

It should produce the following output:

1. If no error is found: `<input file name>: OK` and return 0 (meaning the program executed successfully)
2. If an error is found: `<input file names>: Bracket mismatch detected for [ in line number x` and return 1 (meaning there was a problem).

## The Algorithm
Check code for balanced brackets: push `({[` on the stack and take them off when the corresponding `)`, `}`, or `)` is seen. Any error or a non-empty stack at the end of the code indicates a problem.

## Implementation Requirements

Custom mplementation of the following:
1. A stack based on an array.
2. A stack based on your own list class implementation. 


