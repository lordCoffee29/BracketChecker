
#include "BracketCheck.h"

// Function to set the name of the file for each file that will be tested for matching brackets
void BracketCheck::setFileName(std::string name) {
    filename = name; // Can be accessed by array and list checking functions
}


// Function to check brackets using a stack array
int BracketCheck::check_array() {
    // File reading object
    std::ifstream file_input(filename);

    // Create a buffer line to read each line of the .h file
    std::string line;

    // Stack array object
    DSStack_array *array = new DSStack_array;

    // Indicate if file is unable to open
    if(!file_input.is_open()) {
        std::cout << "Unable to open file" << std::endl;
    }


    // Counter variables
    int lineCount = 1; // Track line number that the program is reading
    char firstBracket; // Save the first bracket on the stack, for when an error results from an extra open bracket without a matching close
    int locFirstBracket; // Save location of aforementioned bracket
    bool commentFlag = false; // Tracks whether the code is in a multi-line comment or not, default is false

    // Bracket checking
    while(getline(file_input, line)) {
        
        // The stack array is only 1000 units long--stop program if exceeded
        if(array->getSize() == 1000) {
            std::cout << "Stack full!  Program was too large, please try something smaller" << std::endl;
            return 1;
        }

        // Iterate through each character in a line
        for(int i = 0; i < line.size(); i++) {

            // BONUS: don't read brackets from comments
            // Start by detecting a slash
            if((i < (line.size() - 1)) && (line.at(i) == '/')) {
                // Triggers branch for single-line comment
                // If a second slash is detected (//), skip the rest of the line and go to the next line (or iteration of while loop)
                if(line.at(i + 1) == '/') {
                    i = (line.size() - 1);
                    continue;
                }
                // Triggers branch for multi-line comment
                // If an asterick is detected (/*), "flip the switch" to parse through the next few lines until "*/ is detected"
                else if(line.at(i + 1) == '*') {
                    commentFlag = true;
                }
            }

            // For when in multi-line comment mode
            if(commentFlag == true) {
                int pos; // Position in the line string after "*/" is detected

                // Iterate through the line string in search of "*/"
                for(int j = 0; j < (line.size() - 1); j++) {
                    // If found, save the position of the next character and "flip the switch" off, exit the for loop
                    if(((line.at(j)) == '*') && ((line.at(j + 1)) == '/')) {
                        pos = j + 1;
                        commentFlag = false;
                        break;
                    }
                }

                // If "*/" wasn't found in the line string, skip to the end of the line string and start at the next
                if(commentFlag == true) {
                    i = line.size();
                    continue;
                }
                // If "*/" was found, go through the remainder of the line string from the position that multi-line comment mode left off at
                else {
                    i = pos;
                }
            }

            // If an open bracket is detected...
            if((line.at(i) == '(') || (line.at(i) == '[') || (line.at(i) == '{')) {
                // Save the first bracket on the stack and its location
                if(array->isEmpty()) {
                    firstBracket = line.at(i);
                    locFirstBracket = lineCount;
                }
                
                // Add the bracket to the stack
                array->push(line.at(i)); 
            }

            // If a close bracket is detected...
            if((line.at(i) == ')') || (line.at(i) == ']') || (line.at(i) == '}')) {
                // If there is an extraneous close bracket when all other brackets have a match (compare to empty stack)
                if(array->isEmpty()) {
                    std::cout << filename << ": Bracket mismatch detected for " << line.at(i) <<
                    " in line number " << lineCount << std::endl;
                    return 1;
                }

                // When the detected close bracket is '('
                // If the detected close bracket matches the open bracket on the top of the stack...
                if(((array->peek() == '(')) && (line.at(i) == ')')) {
                    array->pop(); // Remove the open bracket from the stack
                }
                // But if the detected close bracket doesn't match the open bracket on the top of the stack...
                else if((line.at(i) == ')') && ((array->peek() == '[') || (array->peek() == '{'))) {
                    // Report the error and end the program
                    std::cout << filename << ": Bracket mismatch detected for " << line.at(i) <<
                    " in line number " << lineCount << std::endl;
                    return 1;
                }
                
                // When the detected close bracket is '['
                // If the detected close bracket matches the open bracket on the top of the stack...
                if(((array->peek() == '[')) && (line.at(i) == ']')) {
                    array->pop();
                }
                // But if the detected close bracket doesn't match the open bracket on the top of the stack...
                else if((line.at(i) == ']') && ((array->peek() == '(') || (array->peek() == '{'))) {
                    // Report the error and end the program
                    std::cout << filename << ": Bracket mismatch detected for " << line.at(i) <<
                    " in line number " << lineCount << std::endl;
                    return 1;
                }
            
                // When the detected close bracket is '{'
                // If the detected close bracket matches the open bracket on the top of the stack...
                if(((array->peek() == '{')) && (line.at(i) == '}')) {
                    array->pop();
                }
                // But if the detected close bracket doesn't match the open bracket on the top of the stack...
                else if((line.at(i) == '}') && ((array->peek() == '(') || (array->peek() == '['))) {
                    // Report the error and end the program
                    std::cout << filename << ": Bracket mismatch detected for " << line.at(i) <<
                    " in line number " << lineCount << std::endl;
                    return 1;
                }
            }
        }
        // Increment the line counter
        lineCount++;
    }

    // Close the file after each line has been read
    file_input.close();

    // If the stack array is empty (meaning every bracket had a match)...
    if(array->isEmpty()) {
        // No errors found and end program
        std::cout << filename << ": OK" << std::endl;
        return 0;
    }
    // If the stack array contains brackets (meaning there was an open bracket without a corresponding close bracket)...
    else {
        // Report the error at the hanging open bracket and end program
        std::cout << filename << ": Bracket mismatch detected for " << firstBracket <<
                    " in line number " << locFirstBracket << std::endl;
        return 1;
    }

    // Delete stack array object
    delete array;
}

// Function to check brackets using a stack array
int BracketCheck::check_list() {
    // File reading object
    std::ifstream file_input(filename);

    // Create a buffer line to read each line of the .h file
    std::string line;

    // Stack array object
    DSList<char> list;
    
    // Indicate if file is unable to open
    if(!file_input.is_open()) {
        std::cout << "Unable to open file" << std::endl;
    }


    // Counter variables
    int lineCount = 1; // Track line number that the program is reading
    char firstBracket; // Save the first bracket on the stack, for when an error results from an extra open bracket without a matching close
    int locFirstBracket; // Save location of aforementioned bracket
    bool commentFlag = false; // Tracks whether the code is in a multi-line comment or not, default is false

    // Bracket checking
    while(getline(file_input, line)) {
        
        // The stack array is only 1000 units long--stop program if exceeded
        if(list.getSize() == 1000) {
            std::cout << "Stack full!  Program was too large, please try something smaller" << std::endl;
            return 1;
        }

        // Iterate through each character in a line
        for(int i = 0; i < line.size(); i++) {

            // BONUS: don't read brackets from comments
            // Start by detecting a slash
            if((i < (line.size() - 1)) && (line.at(i) == '/')) {
                // Triggers branch for single-line comment
                // If a second slash is detected (//), skip the rest of the line and go to the next line (or iteration of while loop)
                if(line.at(i + 1) == '/') {
                    i = (line.size() - 1);
                    continue;
                }
                // Triggers branch for multi-line comment
                // If an asterick is detected (/*), "flip the switch" to parse through the next few lines until "*/ is detected"
                else if(line.at(i + 1) == '*') {
                    commentFlag = true;
                }
            }

            // For when in multi-line comment mode
            if(commentFlag == true) {
                int pos; // Position in the line string after "*/" is detected

                // Iterate through the line string in search of "*/"
                for(unsigned int j = 0; j < (line.size() - 1); j++) {
                    // If found, save the position of the next character and "flip the switch" off, exit the for loop
                    if(((line.at(j)) == '*') && ((line.at(j + 1)) == '/')) {
                        pos = j + 1;
                        commentFlag = false;
                        break;
                    }
                }

                // If "*/" wasn't found in the line string, skip to the end of the line string and start at the next
                if(commentFlag == true) {
                    i = line.size();
                    continue;
                }
                // If "*/" was found, go through the remainder of the line string from the position that multi-line comment mode left off at
                else {
                    i = pos;
                }
            }
            
            // If an open bracket is detected...
            if((line.at(i) == '(') || (line.at(i) == '[') || (line.at(i) == '{')) {
                // Save the first bracket on the stack and its location
                if(list.isEmpty()) {
                    firstBracket = line.at(i);
                    locFirstBracket = lineCount;
                }
                
                // Add the bracket to the stack
                list.push_back(line.at(i)); 
            }

            // If a close bracket is detected...
            if((line.at(i) == ')') || (line.at(i) == ']') || (line.at(i) == '}')) {
                // If there is an extraneous close bracket when all other brackets have a match (compare to empty stack)
                if(list.isEmpty()) {
                    std::cout << filename << ": Bracket mismatch detected for " << line.at(i) <<
                    " in line number " << lineCount << std::endl;
                    return 1;
                }

                // When the detected close bracket is '('
                // If the detected close bracket matches the open bracket on the top of the stack...
                if(((list.peek() == '(')) && (line.at(i) == ')')) {
                    list.pop_back(); // Remove the open bracket from the stack
                }
                // But if the detected close bracket doesn't match the open bracket on the top of the stack...
                else if((line.at(i) == ')') && ((list.peek() == '[') || (list.peek() == '{'))) {
                    // Report the error and end the program
                    std::cout << filename << ": Bracket mismatch detected for " << line.at(i) <<
                    " in line number " << lineCount << std::endl;
                    return 1;
                }
                
                // When the detected close bracket is '['
                // If the detected close bracket matches the open bracket on the top of the stack...
                if(((list.peek() == '[')) && (line.at(i) == ']')) {
                    list.pop_back();
                }
                // But if the detected close bracket doesn't match the open bracket on the top of the stack...
                else if((line.at(i) == ']') && ((list.peek() == '(') || (list.peek() == '{'))) {
                    // Report the error and end the program
                    std::cout << filename << ": Bracket mismatch detected for " << line.at(i) <<
                    " in line number " << lineCount << std::endl;
                    return 1;
                }
            
                // When the detected close bracket is '{'
                // If the detected close bracket matches the open bracket on the top of the stack...
                if(((list.peek() == '{')) && (line.at(i) == '}')) {
                    list.pop_back();
                }
                // But if the detected close bracket doesn't match the open bracket on the top of the stack...
                else if((line.at(i) == '}') && ((list.peek() == '(') || (list.peek() == '['))) {
                    // Report the error and end the program
                    std::cout << filename << ": Bracket mismatch detected for " << line.at(i) <<
                    " in line number " << lineCount << std::endl;
                    return 1;
                }
            }
        }
        // Increment the line counter
        lineCount++;
    }

    // Close the file after each line has been read
    file_input.close();

    // If the stack array is empty (meaning every bracket had a match)...
    if(list.isEmpty()) {
        // No errors found and end program
        std::cout << filename << ": OK" << std::endl;
        return 0;
    }
    // If the stack array contains brackets (meaning there was an open bracket without a corresponding close bracket)...
    else {
        // Report the error at the hanging open bracket and end program
        std::cout << filename << ": Bracket mismatch detected for " << firstBracket <<
                    " in line number " << locFirstBracket << std::endl;
        return 1;
    }
}