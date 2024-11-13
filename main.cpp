/// ========================= Course 12 Data Structures ===================================
//


/// stack Lib
// push, pop, size, top
/*
#include <stack>
#include <iostream>

using namespace std;

int main(){

    // Create a stack of ints
    stack<int> stkNumbers;

    // push into stack
    stkNumbers.push(10);
    stkNumbers.push(20);
    stkNumbers.push(30);
    stkNumbers.push(40);
    stkNumbers.push(50);

    // we can access the element by getting the top and popping
    // until the stack is empty
    cout << "count = " << stkNumbers.size() << endl;

    cout << "Numbers are:\n";
    while (!stkNumbers.empty()){
        // print top element
        cout << stkNumbers.top() << endl;


        // pop top element from stack
        stkNumbers.pop();
    }

    system("pause>0");
    return 0;
}
 */
// stack swap
/*
#include <iostream>
#include <stack>
using namespace std;

int main(){

    // stack container declaration
    stack<int> myStack1;
    stack<int> myStack2;

    // pushing elements into first stack
    myStack1.push(10);
    myStack1.push(20);
    myStack1.push(30);
    myStack1.push(40);

    // pushing elements into second stack
    myStack2.push(50);
    myStack2.push(60);
    myStack2.push(70);
    myStack2.push(80);

    // using swap() function to swap elements of stack
    myStack1.swap(myStack2);

    // printing the first stack
    cout << "myStack1 = ";
    while (!myStack1.empty()){
        cout << myStack1.top() << " ";
        myStack1.pop();
    }

    // printing the second stack
    cout << "\nmyStack2 = ";
    while (!myStack2.empty()){
        cout << myStack2.top() << " ";
        myStack2.pop();
    }

    system("pause > 0");
    return 0;


}
*/


/// Queue Lib
// push, pop, size, first, back, empty
/*
#include <iostream>
#include <queue>
using namespace std;

int main(){

    // queue container declaration
    queue<int> myQueue;

    // pushing elements into first stack
    cout << "myQueue = ";
    myQueue.push(10);
    cout << myQueue.front() << " ";
    myQueue.push(20);
    cout << myQueue.front() << " ";
    myQueue.push(30);
    cout << myQueue.front() << " ";
    myQueue.push(40);
    cout << myQueue.front() << " ";

    cout << "\nCount: " << myQueue.size();
    cout << "\nFront: " << myQueue.front();
    cout << "\nBack : " << myQueue.back();

    cout << "\nmyQueue = ";
    while (!myQueue.empty()){
        cout << myQueue.front() << " ";
        myQueue.pop();
    }

    system("pause > 0");
    return 0;
}
 */
// queue swap
/*
#include <iostream>
#include <queue>
using namespace std;

int main(){

    // queue container declaration
    queue<int> MyQueue1;
    queue<int> MyQueue2;

    // pushing elements into first queue
    MyQueue1.push(10);
    MyQueue1.push(20);
    MyQueue1.push(30);
    MyQueue1.push(40);

    // pushing elements into 2nd queue
    MyQueue2.push(50);
    MyQueue2.push(60);
    MyQueue2.push(70);
    MyQueue2.push(80);

    // using swap() function to swap elements of queues
    MyQueue1.swap(MyQueue2);

    // printing the first queue
    cout << "MyQueue1 = ";
    while (!MyQueue1.empty()) {
        cout << MyQueue1.front() << " ";
        MyQueue1.pop();
    }

    // printing the second queue
    cout << endl << "MyQueue2 = ";
    while (!MyQueue2.empty()) {
        cout << MyQueue2.front() << " ";
        MyQueue2.pop();
    }

    system("pause>0");

    return 0;
}
 */



/// Singly Linked List
// Singly Linked List Implementation
/*
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
};

int main() {
    Node* head;

    Node* Node1 = NULL;
    Node* Node2 = NULL;
    Node* Node3 = NULL;

    // allocate 3 nodes in the heap
    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    // Assign value values
    Node1->value = 1;
    Node2->value = 2;
    Node3->value = 3;

    // Connect nodes
    Node1->next = Node2;
    Node2->next = Node3;
    Node3->next = NULL;

    // Print the linked List Value
    head = Node1;
    while (head != NULL) {
        cout << head->value << endl;
        head = head->next;
    }

    system("pause > 0");
    return 0;
}
*/
// Find
/*
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
};

void InsertAtBeginning(Node* &head, int value) {
    // Allocate memory to a node
    Node * new_node = new Node();

    // insert the date
    new_node->value = value;
    new_node->next = head;

    // Move head to new node
    head = new_node;
}

void InsertAfter(Node* prev_node, int Value) {
    Node* new_node = new Node();

    new_node->value = Value;
    new_node->next = prev_node->next;

    prev_node->next = new_node;
}

void InsertAtEnd(Node* &head, int Value) {
    Node* new_node = new Node();

    new_node->value = Value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    Node* LastNode = head;
    while (LastNode->next != NULL) {
        LastNode = LastNode->next;
    }

    LastNode->next = new_node;
}

void DeleteNode(Node* &head, int value){
    Node* Current = head, *Prev = head;

    if (head == NULL){
        return;
    }


    if (Current->value == value){
        head = Current->next;
        delete Current; // free from memory
        return;
    }

    // Find the key to be deleted
    while (Current != NULL && Current->value != value){
        Prev = Current;
        Current = Current->next;
    }

    // If the value is not present
    if (Current == NULL) return;

    // Remove the Node
    Prev->next = Current->next;
    delete Current;
}

void DeleteFirstNode(Node* &head){
    Node* Current = head;

    if (head == NULL){
        return;
    }

    head = Current->next;
    delete Current;// free memory

}

void DeleteLastNode(Node* &head){
    Node* Current = head, *prev = head;

    if (head == NULL) return;
    if (Current->next == NULL){
        head = NULL;
        delete Current; // free from memory
        return;
    }

    // Find the key to be deleted
    while (Current != NULL && Current->next != NULL){
        prev = Current;
        Current = Current->next;
    }

    // Remove the Node
    prev->next = NULL;
    delete Current; // free momory
}

Node *Find (Node* head, int value) {
    while (head != NULL) {
        if (head->value == value) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void PrintList (Node* head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 5);
    InsertAtEnd(head, 0);

    Node* N = Find(head, 4);
    if (N != NULL) {
        cout << "\nValue is : " << N->value << "\n";
        cout << "\nNode Found :-)\n";
    }
    else {
        cout << "\nNode Not Found :-(\n";
    }

    cout << "\n\n";
    PrintList(head);
    cout << "\n";
    InsertAfter(N, 150);

    PrintList(head);
    cout << "\n";

    InsertAtEnd(head, 93);

    PrintList(head);
    cout << "\n";

    DeleteNode(head, 3);

    PrintList(head);
    cout << "\n";

    DeleteFirstNode(head);
    DeleteFirstNode(head);

    PrintList(head);
    cout << "\n";

    system("pause > 0");
    return 0;
}
*/



/// doubly Linked List
// doubly Linked List Implementation
/*
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;
};

int main() {

    Node* head;

    Node* Node1 = NULL;
    Node* Node2 = NULL;
    Node* Node3 = NULL;

    // allocate 3 nodes in the heap
    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    // Assign value values
    Node1->value = 1;
    Node2->value = 2;
    Node3->value = 3;

    // Connect nodes
    Node1->next = Node2;
    Node1->prev = NULL;

    Node2->next = Node3;
    Node2->prev = Node1;

    Node3->next = NULL;
    Node3->prev = Node2;

    // print the linked list value
    head = Node1;
    while (head != NULL) {
        cout << head->value << endl;
        head = head->next;
    }
}
*/
// Find
/*
#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;
};

void InsertAtBeginning(Node*& head, int value) {

    // 1-Create a new node with the desired value.
    // 2-Set the next pointer of the new node to the current head of the list.
    // 3-Set the previous pointer of the current head to the new node.
    // 4-Set the new node as the new head of the list

     Node* new_node = new Node();

    new_node->value = value;
    new_node->next = head;
    new_node->prev = NULL;

    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
}

Node* Find(Node* head, int value) {
    while (head != NULL) {
        if (head->value == value) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

void InsertAfter(Node* Current, int value) {

    // 1- Create a new node with the desired value.
    // 2- set the next pointer of the new node to the next node of the current node.
    // 3- set the previous pointer of the new node to the current node.
    // 4- set the next pointer of the current node to the new node.
    // 5- set the previous pointer of the next node to the new node ( if it exists ).

    Node* new_node = new Node();

    new_node->value = value;
    new_node->next = Current->next;
    new_node->prev = Current;

    if (Current->next != NULL) {
        Current->next->prev = new_node;
    }
    Current->next = new_node;
}

void InsertAtEnd(Node*& head, int value) {

    // 1-Create a new node with the desired value.
    // 2-Traverse the list to find the last node.
    // 3-Set the next pointer of the last node to the new node.
    // 4-Set the previous pointer of the new node to the last node.

    Node* new_node = new Node();

    new_node->value = value;
    new_node->next = NULL;
    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
    }
    else {
        Node* Current = head;
        while (Current->next != NULL) {
            Current = Current->next;
        }
        Current->next = new_node;
        new_node->prev = Current;
    }
}

void DeleteNode(Node*& head, Node*& NodeToDelete) {

    // 1-Set the next pointer of the previous node to the next pointer of the current node.
    // 2-Set the previous pointer of the next node to the previous pointer of the current node.
    // 3-Delete the current node.

    if (head == NULL || NodeToDelete == NULL) {
        return;
    }

    if (head == NodeToDelete) {
        head = NodeToDelete->next;
    }

    if (NodeToDelete->next != NULL) {
        NodeToDelete->next->prev = NodeToDelete->prev;
    }

    if (NodeToDelete->prev != NULL) {
        NodeToDelete->prev->next = NodeToDelete->next;
    }
    delete NodeToDelete;
}

void DeleteFirstNode(Node*& head) {


    if (head == NULL) {
        return;
    }

    Node* First = head;
    head = head->next;
    head->prev = NULL;
    delete First;

}

void DeleteLastNode(Node*& head) {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* Current = head;
    while (Current->next->next != NULL) {
        Current = Current->next;
    }

    Node* Temp = Current->next;
    Current->next = NULL;
    delete Temp;
}

void PrintNodeDetails(Node* head) {

    if (head->prev != NULL) {
        cout << head->prev->value;
    } else {
        cout << "NULL";
    }

    cout << " <--> " << head->value << " <--> ";

    if (head->next != NULL) {
        cout << head->next->value << endl;
    } else {
        cout << "NULL";
    }

}

void PrintListDetails(Node* head) {

    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->next;
    }

}

void PrintList(Node* head) {
    cout << "NULL <--> ";
    while(head != NULL) {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";
}

int main() {

    Node* head = NULL;

    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);

    cout << "\nLinked List Contenet:\n";
    PrintList(head);
    PrintListDetails(head);

    Node *N1 = Find(head, 2);
    InsertAfter(N1, 123);
    cout << "\n\nLinked List Content after InsertAfter: \n";
    PrintList(head);
    PrintListDetails(head);

    InsertAtEnd(head, 6);
    cout << "\n\nLinked List Content after InsertAtEnd: \n";
    PrintList(head);
    PrintListDetails(head);

    Node* N2 = Find(head, 123);
    DeleteNode(head, N2);
    cout << "\n\nLinked List Content after DeleteNode: \n";
    PrintList(head);
    PrintListDetails(head);

    DeleteFirstNode(head);
    cout << "\n\nLinked List Content after DeleteFirstNode: \n";
    PrintList(head);
    PrintListDetails(head);

    DeleteLastNode(head);
    cout << "\n\nLinked List Content after DeleteLastNode: \n";
    PrintList(head);
    PrintListDetails(head);

    Node* N = Find(head, 5);
    if (N != NULL) {
        cout << "\n\n Node " << N->value <<  " Found :-) \n";
    } else {
        cout << "\n\n Node Is not Found :-(\n";
    }

    system("pause>0");

}
*/



/// Circular Linked List
/*

 */



/// Map Data Type
/*
#include <iostream>
#include <map>
using namespace std;

int main() {
    // Declare a map with string keys and int values
    map<string, int> studentGrades;

    // Inserting Grades for three students
    studentGrades["Ali"] = 77;
    studentGrades["Ahmed"] = 85;
    studentGrades["Fadi"] = 95;

    // Printing all map values
    cout << "\nPrinting all map values..\n\n";

    // Iterating over the map
    for (const auto& pair : studentGrades) {
        cout << "Student: " << pair.first << ", Grade: " << pair.second << endl;
    }

    // Finding the grade for a specific student
    string FirstName = "Fadi";
    if (studentGrades.find(FirstName) != studentGrades.end()) {
        cout << FirstName << "'s grade: " << studentGrades[FirstName] << endl;
    }
    else {
        cout << "Grade not found for " << FirstName << endl;
    }

    return 0;
}
*/



/// Union Data Type
/*
#include <iostream>
using namespace std;

union myUnion {
    int intValue;
    float floatValue;
    char charValue;
};

int main() {
    myUnion Union;

    Union.intValue = 42;
    cout << "Integar value: " << Union.intValue << endl;

    Union.floatValue = 3.14f;
    cout << "Float Value: " << Union.floatValue << endl;

    Union.charValue = 'A';
    cout << "Char Value: " << Union.charValue << endl;

    return 0;
}
*/



