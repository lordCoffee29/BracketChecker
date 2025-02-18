# Assignment 3: Answers


1. How long did the program take to check all three test files with each version?  Describe what differences in run time you expect for your implementation (use Big-O notation).

   > The stack array version for the three files took 3759 milliseconds.  The list version for the three files took 8948 milliseconds.  The stack array version with the extra files took 7250 milliseconds.  The list version with the extra files took 10724 milliseconds.  I expected them to be similar because the code I wrote for each is pretty much the same but with different functions.  However, I expected the list version to be slower because I used push_back, meaning the list had to iterate through the entire list before adding a value (O(N)).  On the other hand, the array could have items added to it without having to iterate through (O(1)).  Since most of this project was adding onto the stack, it makes sense that it took the linked list slightly longer.

2. Discuss the difference in memory usage based on **your** implementation.

   > The stack array version did not have dynamic memory allocation.  The stack created was of a fixed size (1000), even if the entire stack wasn't full.  This made it memory inefficient.  The space complexity was O(N).  The linked list version did have dynamic memory alllocation due to the nodes.  It could be resized depending on how many items were added or removed from the list.  This made it more memory efficient.

3. Which version would you use in practice. Why?

   > In pracice, I would use the linked list.  It is much more memory efficient and won't eat up unecessary space with slots that aren't filled.  In addition, resizing it would be easy as all that's needed is to add nodes or remove nodes.  This makes sense because it has a space complexity of O(1), whereas an array has a space complexity of O(N).  Though the array was faster (time complexity of O(1) versus the time complexity of a linked list, which was O(N)), it was only marginally so.  As a result, the time difference wouldn't make me prefer an array instead.

4. Make sure that your stack implementations does not have memory leaks.

   ```
   Paste the output of valgrind for running your tests for `DSStack_array` and `DSStack_list` here. 
   ```![Alt text](<Screenshot 2023-10-28 at 4.56.13 AM.png>)
   ```![Alt text](<Screenshot 2023-10-28 at 4.55.45 AM.png>)

   (Outputs also attached as screenshots in repository)

5. Did you attempt any bonuses? If so, please give a brief description of what you did.

   > I implemented code to ensure brackets in single-line comments (//) aren't considered.  To do so, I detected when there was a slash followed by another slash.  Then, I had the program skip the rest of the line of code and move on to the next line.
   > I implemented code to ensure brackets in multi-line comments (/* */) aren't considered.  To do so, I detected when there was a slash followed by an asterisk.  This turned on "multi-comment mode" (switched a boolean value true) and searched lines for "*/".  If a line didn't have that, it was passed and the next line was searched.  When it was found, the program returned to normal (switched the boolean value false) and checked brackets as intended.
   > I added extra test files to make sure my bracket logic worked properly.  These files were only brackets, and I planned where the errors were supposed to be, so I could check my own answer with the answer my code was giving me.
