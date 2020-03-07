# mc01ds

mc01ds is a short of Milan Ciric v01 Data Structures. In this header file you can find some solutions for data structures in c++. This is not a final version of this header file, so it will be more in the time. This is LIFO structure, which means, last in first out structure. In this version it can be found structures of:

1. ## stackAsArray\<T\>

Stack structure is based to be a auxilary structure for more complex data structures. If you want to awoid recursion, you will use stack structure as auxilary structure, but that solution is far more complex to develop but it's faster and takes less memory then recursion call methods. Function of this structures are:

- **```bool isEmpty()```**            - check is the stack is empty or not
- **```long numberOfElements()```**   - returns number of elements that is in the stack
- **```void push(T obj)```**          - put one object of T type onto the stack, and increase number of elements
- **```T pop()```**                   - get one object of T type from the stack, and decrease number of elements
- **```T getTop()```**                - get top object of T type from the stack, but don't remove it from the stack

For example, creation of stack that consists of 10 ObjType values will be:   **```stackAsArray<ObjType> stack(10)```**
    
2. ## QueueAsArray

Queue is also auxilary structure for more complex structures where can be inserted object from one side of the queue, but can be taken only from other side, which means first in first out. Functions of this structure are:
- **```long getSize()```**              - return size of the queue
- **```long numberOfElements()```**     - return number of elements inserted into the queue
- **```bool isEmpty()```**              - checks if the queue is empty or not
- **```T getHeadEl()```**               - get head element from the queue but don't remove it from the queue
- **```T dequeue()```**                 - get head element from the queue and remove it from the queue
- **```bool enqueue(T obj)```**         - set new tail element into the queue

For example, creation of queue that consists of 10 ObjType values will be: **```QueueAsArray<ObjType> que(10)```**

3. ## Deck

Deck structure is similar to the queue structure but in this version it can be put element from head and from tail, also it can be taken from both sides as well. This is like two side way queue. Functions of this structure are:
- **```long getSize()```** - return size of the deck
- **```long numberOfElements()```** - return number of inserted elements into the deck
- **```bool isEmpty()```** - checks is the deck is empty or not
- **```T getHeadEl()```** - get head element, but don't remove it from the deck
- **```T dequeue()```** - get head element and remove it from the deck
- **```bool enqueue(T obj)```** - insert new tail element into the deck
- **```bool enqueueHead(T obj)```** - insert new head element into the deck
- **```T getTailEl()```** - get tail element, but don't remove it from the deck
- **```T dequeueTail()```** - get tail element and remove it from the deck

For example, creation of deck that consists of 10 ObjType values will be: **```DeckAsArray<ObjType> deck(10)```**

4. ## Single Linked lists

Single linked lists are structures that is used also as auxilary structures, and they are very good solution, because if it's needed to be add new element into the list, it can be simply put on the right place without realocating memory for it. Just simply create node and put it into the list. The same is when it's needed to be delete some element from the list. Just relink the list and delete the node. So, this structure is consists of 2 classes:
- **SLLNode class** - This class is only for representation of nodes in the list. This class is only auxilary class so the SLList class can be made. It's functions are:
    - **```T visit()```** - Function that print node information
    - **```friend ostream& operator<<(ostream& izlaz, SLLNode<T>& obj)```** - overloaded operator <<
    - **```inline bool operator==(const SLLNode& node)```** - overloaded operator == when the right element is SLLNode
    - **```inline bool operator==(const T el)```**  - overloaded operator == when the right element is information as T type
- **SLList class** - This class is the representation of the list itself. Functions of this data structure are: 
    - **```bool isEmpty()```** - checks if the list is empty or not
    - **```void addToHead(T el)```** - add one element to the head of the list
    - **```void addToTail(T el)```** - add one element to the tail of the list
    - **```void makeNewTail()```**  - makes new tail, usualy this is needed after sorting
    - **```void makeNewHead()```** - makes new head, usualy this is needed in some situatins of deleting elements   
    - **```T deleteFromHead()```** - function that delete one element from the head of the list
    - **```T deleteFromTail()```** - function that delete one element from the tail of the list
    - **```void deleteEl(T el)```** - function that delete one element if is in the list
    - **```SLLNode<T>* findNodePtr(T el)```** - returns a pointer of node that have searched info
    - **```SLLNode<T>* getHead()```** - returns a pointer of head node of the list
    - **```SLLNode<T>* getTail()```** - returns a pointer of tail of the list
    - **```bool isTail(T el)```** - checks is passed element is a tail element and return true or false
    - **```int getNumOfEl()```** - returns a number of elements that is in the list
    - **```SLLNode<T>* getNext(SLLNode<T>* ptr)```** - returns a pointer of next element in the list, depends on passed element
    - **```SLLNode<T>* getPrev(SLLNode<T>* ptr)```** - returns a pointer of previous element in the list, depends on passed element
    - **```T getHeadEl()```** - returns an information from head element
    - **```T getTailEl()```** - returns an information from tail element 
    - **```T getNextEl(T el)```** - returns an information of next element, depends on passed element
    - **```void printAll()```** - function that prints all members of the list
    - **```bool isInList(T el)```** - checks is element in the list or not and returns true or false
    - **```void swap(T a, T b)```** - swap two elements of the list when only information of that elements are passed
    - **```void swapNeigbhours(SLLNode<T>* ptr, SLLNode<T>* prev)```** - swap neigbhour elements in the list
    - **```void swap(SLLNode<T>* ptr1, SLLNode<T>* prev1, SLLNode<T>* ptr2, SLLNode<T>* prev2)```** - swap to elements in the list when they pointer are known
    - **```void selectionSort()```** - Function for sorting elements
    - **```void invertionSort()```** - Function for sorting elements
    - **```void insertInSorted(SLLNode<T> *ptr)```** - insert a new node into sorted list without destruct order after sort, when it's pointer is passed
    - **```void insertInSorted(T el)```** - insert a new node into sorted list without destruct order after sort, when it's information is passed

For example, creation of single linked list consists of ObjType elements will be: **```SLList<ObjType> list```**
List don't need initial value, beacue, list can exists even if it's empty, so simpy adding one element into the list we get the list, and so on.

5. ## Hash Tables (Chainned, Scattered, OpenScattered)

Hash tables are simply lookup table where we have pair of key|value. Simple idea is to make a table where can be inserted some objects (in basic solution), and in an advanced solution to be put more then we have location, making synonyms with the same key in single linked lists of records. Classes that solve this problem are:

- **HashObj class** - basic auxilary class for hash object where it's remembered key and value information. Functions of this class are:
    - **```void deleteRecord()```**
    - **```HashObj<T, R>& operator= (HashObj<T, R> const& obj)```**
    - **```bool operator==(HashObj<T, R> const& obj)```**
    - **```T getKey()```**
    - **```void setKey(T key)```**
    - **```R* getRecord()```**
    - **```void setRecord(R* rec)```**
    - **```bool isEqualKey(T key)```**
    - **```friend ostream& operator<<(ostream& izlaz, HashObj<T, R>& obj)```**
- **ScatterObj class** - this class inherits HashObj class and this class only add status where 0 is free, 1 deleted and 2 occupied location in the hash table. This class only have constructors, and no new functions.
- **ChainedScatterObject class** - this class inherits ScatterObj class and add next element where it's puts information about next element as synonym.  This class only have constructors, and no new functions.
- **HashTable class** - Basic structure for Hash table. Function of this data structure are:
    - **``````**
- **ChainedHashTable class** - this class inherits HastTable class. Functions of this class are:
    - **``````**
- **ChainedScatterTable** - this class inherits HashTable class. Functions of this class are:
    - **``````**
- **OpenScatterTable** - this class inherits HashTable class. Functions of this class are:
    - **``````**

6. ## Binary Search Tree

- **BSTNode class**
- **BSTree class**

For example, creation of Binary search tree that consist of ObjType elements will be: **```BSTree<ObjType> tree```** Situation is the same as in single liked lists, only here every element have two pointers: left and right element, logic are the same.

7. ## Graph

- **LinkedNode class**
- **Edge class**
- **LinkedNode class**
- **GraphAsLists class**

For example, creation of Graph that consists of ObjType elements with WeightType will be: **```GraphAsLists<ObjType, WeightType> graf```**. Also graph use single linked list as auxilary structure so we dont need initial size.

For more information about how to use these structures look at the cpp file that is test file of these structures.
