#ifndef DSList_H
#define DSList_H

/**
 * @brief Singly-linked list that uses positions and has a stack interface
 *
 * Implement all described functions and provide a test program using CATCH2
 * 
 * @tparam Object 
 */
template <typename Object>
class DSList
{
private:
   /**
     * @brief The nested Node data structure
     * 
     * struct is in C++ a class with all public members
     */
    struct Node
    {
        Object data;
        Node *next;

        Node(const Object &d = Object{}, Node *n = nullptr)
            : data{d}, next{n} {};
    };
    
    Node *head;

public:

    // Constructor
    DSList<Object>() {
        head = nullptr;
    } 

    // Copy constructor
    DSList<Object>(const DSList<Object> &rhs) {
        head = nullptr;

        Node **prev_next = &head;
        Node *rhs_current = rhs.head;

        // Copy into new list
        while(rhs_current != nullptr) {
            *prev_next = new Node{rhs_current->data, nullptr};
            prev_next = &((*prev_next)->next);
            rhs_current = rhs_current->next;
        }
    } 

    // Destructor
    ~DSList() {
        while(isEmpty() == false) {
            pop_front();
        }
    } 

    // Assignment operator
    DSList &operator=(const DSList &rhs) {
        DSList<Object> copy{rhs}; // call copy constructor
        std::swap(*this, copy);           // exchange this and the copy
        return *this;      
    }

    // Get size of the list
    size_t getSize() const {
        size_t size = 0;
        Node *current = head; // Start iterator at head

        // Keep iterating until the last element, which is a nullptr in a linked list (increase size)
        while(current != nullptr) {
            ++size;
            current = current->next;
        }

        return size;
    } 

    // Check whether the list is empty or not
    bool isEmpty() {
        // List is empty when the head is a nullptr
        if(head == nullptr) {
            return true;
        }
        else {
            return false;
        }
    } 

    // Clear the list
    void empty() {
        // Until the list is empty, remove front element
        while(isEmpty() == false) {
            pop_front();
        }

        // Reset head to nullptr
        head = nullptr;
    } 

    // Search for a character in the list
    int find(Object s) {
        Node *current = head;
        Node *val = new Node(s); // Turn the desired value into a node

        // Iterate through the list
        for(int i = 0; current != nullptr; i++) {
            // If the desired value is found, delete the node and return the position
            if(current->data == val->data) {
                delete val;
                return i;
            }
            // Otherwise keep going
            else {
                current = current->next;
            }

            // If at the end of the list and the desired value is not found...
            if(current == nullptr) {
                // Delete the node and return -1
                delete val;
                return -1;
            }
        }
    }
    
    // Push an element to the front of the list
    void push_front(Object s) {
        // Create a new node to replace the head, transfer everything up a node
        Node *front = new Node(s, head);
        head = front;
    } 

    // Push an element to the back of the list
    void push_back(Object s) {
        Node *current;
        
        // Iterate through the list
        // If the  list is empty...
        if(head == nullptr) {
            // Make the head the value
            head = new Node(s);
            return;
        }
        // Otherwise iterate through the list
        else {
            current = head;
            while((current->next) != nullptr) {
                current = current->next;
            }

            // Attach a new node to the back of the list
            Node *back = new Node(s, nullptr);
            current->next = back;
        }
    }
    
    // Remove an element from the front of the list
    void pop_front() {
        // If the list isn't empty...
        if(isEmpty() == false) {
            // Store head and delete old position of head
            Node *tempNode = head;
            head = head->next;
            delete tempNode;
        }
    } 

    // Remove an element from the back of the list
    void pop_back() {
        // Iterator
        Node *current;
        
        // If the list is not empty...
        if((isEmpty() == false)) {
            // If the head is a nullptr...
            if(head == nullptr) {
                return; // End function
            }
            // If the list has only one element...
            else if(getSize() == 1) {
                head = nullptr; // Make the head a nullptr (makes the size of the list 0)
            }
            // Otherwise go through the list
            else {
                current = head;
                // Iterate until the element two nodes away is a nullptr
                while((current->next->next) != nullptr) {
                    current = current->next;
                }

                // Delete the nullptr node attached to the back node
                delete (current->next->next);
                // Delete the back node and make nullptr
                delete current->next;
                (current->next) = nullptr;
            }
        }
    }

    // Look at the top of the stack (back item in a list)
    Object peek() {
        Node *current;
        
        // Iterate until at the last node as long as the list isn't empty
        if(head != nullptr) {
            current = head;
            while((current->next) != nullptr) {
                current = current->next;
            }

            // Return the back value of the list
            return (current->data);
        }
    }

    // Look at the bottom of the stack (front of the list)
    // This was mostly for testing purposes in the test case
    Object front() {
        // If the list isn't empty...
        if(head != nullptr) {
            // Return the front item of the list
            return (head->data);
        }
    }
    
    // Display the list
    // This was mostly for testing purposes in the test case
    void display() {
        Node *current = head;

        // Iterate through the list and display the contents of each node
        while(current != nullptr) {
            std::cout << current->data;
            current = current->next;
        }
    }
};

#endif
