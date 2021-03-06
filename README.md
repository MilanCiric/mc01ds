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
    
2. ## QueueAsArray\<T\>

Queue is also auxilary structure for more complex structures where can be inserted object from one side of the queue, but can be taken only from other side, which means first in first out. Functions of this structure are:
- **```long getSize()```**              - return size of the queue
- **```long numberOfElements()```**     - return number of elements inserted into the queue
- **```bool isEmpty()```**              - checks if the queue is empty or not
- **```T getHeadEl()```**               - get head element from the queue but don't remove it from the queue
- **```T dequeue()```**                 - get head element from the queue and remove it from the queue
- **```bool enqueue(T obj)```**         - set new tail element into the queue

For example, creation of queue that consists of 10 ObjType values will be: **```QueueAsArray<ObjType> que(10)```**

3. ## DeckAsArray\<T\>

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
- **SLLNode\<T\> class** - This class is only for representation of nodes in the list. This class is only auxilary class so the SLList class can be made. It's functions are:
    - **```T visit()```** - Function that print node information
    - **```friend ostream& operator<<(ostream& izlaz, SLLNode<T>& obj)```** - overloaded operator <<
    - **```inline bool operator==(const SLLNode& node)```** - overloaded operator == when the right element is SLLNode
    - **```inline bool operator==(const T el)```**  - overloaded operator == when the right element is information as T type
- **SLList\<T\> class** - This class is the representation of the list itself. Functions of this data structure are: 
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

In computing, a hash table (hash map) is a data structure that implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found.
Ideally, the hash function will assign each key to a unique bucket, but most hash table designs employ an imperfect hash function, which might cause hash collisions where the hash function generates the same index for more than one key. Such collisions are always accommodated in some way.
Hash tables are simply lookup table where we have pair of key|value. Simple idea is to make a table where can be inserted some objects (in basic solution), and in an advanced solution to be put more then we have location, making synonyms with the same key in single linked lists of records. Classes that solve this problem are:

- **HashObj\<T,R\> class** - basic auxilary class for hash object where it's remembered key and value information. Functions of this class are:
    - **```void deleteRecord()```** - Function that delete record from the hash table
    - **```HashObj<T, R>& operator= (HashObj<T, R> const& obj)```** - overloaded operator = when on the right side are HashObj
    - **```bool operator==(HashObj<T, R> const& obj)```** - overloaded operator == when on the right side ade HashObj
    - **```T getKey()```** - returns key value of a Hash object
    - **```void setKey(T key)```** - set key value of a Hash object
    - **```R* getRecord()```** - returns record from a Hash object
    - **```void setRecord(R* rec)```** - set record value of a Hash object
    - **```bool isEqualKey(T key)```** - checks is the key are the same, key of the object and passed key
    - **```friend ostream& operator<<(ostream& izlaz, HashObj<T, R>& obj)```** - frined function for operator <<, it means that prints infomration to the output 
- **ScatterObj\<T,R\> class** - this class inherits HashObj class and this class only add status where 0 is free, 1 deleted and 2 occupied location in the hash table. This class only have constructors, and no new functions.
- **ChainedScatterObject\<T,R\> class** - this class inherits ScatterObj class and add next element where it's puts information about next element as synonym.  This class only have constructors, and no new functions.
- **HashTable\<T,R\> class** - Basic structure for Hash table. Function of this data structure are:
    - **```unsigned int h(HashObj<T, R>* obj)```** - hash function, that returns location in hash table as key value
    - **```virtual unsigned int f(int i)```** - primary transformation function if passed integer value
    - **```virtual unsigned int f(double d)```** - primary transformation function if passed double value
    - **```virtual unsigned int f(char *s)```** - primary transformation function if passed array of chars
    - **```virtual unsigned int g(unsigned int i)```** - secondary transformation function
    - **```unsigned int getLength()```** - Function that returns size of the hash table
    - **```virtual double getLoadFactor()```** - Function that returns load factor in percentage value
    
    This class is virtual so it can't have na object reference, so it's only used for inheritance to the other hash type classes
- **ChainedHashTable\<T,R\> class** - this class inherits HastTable class. Functions of this class are:
    - **```void insert(HashObj<T, R>* obj)```** - Function for inserting element into Chained Hash table
    - **```void withdraw(HashObj<T, R>* obj)```** - Function for withdrawing an object from Chained Hash table when object is known
    - **```void withdraw(T key)```** - Function for withdrawsing an object from Chained Hash table when key is known
    - **```HashObj<T, R>* find(T key)```** - returns pointer of hash object if is in the Chained Hash table
    - **```void printAllRecords()```** - prints all records that are in the Chained Hash table
    
    For example, creation of ChainedHashTable that consists of 100 ObjType elements with RecType will be:
**```ChainedHashTable<ObjType, RecType> hash(100)```**
- **ChainedScatterTable\<T,R\> class** - this class inherits HashTable class. Functions of this class are:
    - **```unsigned int h(ChainedScatterObject<T, R> obj)```** - overloaded hash function for ChainedScatterObject  
    - **```void insert(ChainedScatterObject<T, R> obj)```** - function for inserting element into Chained Scatter Table
    - **```ChainedScatterObject<T, R> find(T key)```** - Function that finds Hash object if exists in Chained Scatter Table
    - **```void withdraw(T key)```** - Function for withdrawing hash object if key is known
    - **```void printAllRecords()```** - prints all records in the Chained Scatter Table
    
    For example, creation of ChainedScatterTable that consists of 100 ObjType elements with RecType will be:
**```ChainedScatterTable<ObjType, RecType> hash(100)```**
- **OpenScatterTable\<T,R\> class** - this class inherits HashTable class. Functions of this class are:
    - **```unsigned int h(ScatterObj<T, R> obj)```** - overloaded hash function for ScatterObj
    - **```unsigned int findUnoccupied(ScatterObj<T, R> obj```** - Function that finds unoccupied loacion in the Open Scatter Table
    - **```long findMatch(T key)```** - Function that find exact match if exists in Open Scatter Table based on key value
    - **```void insert(ScatterObj<T, R> obj)```** - Function for inserting element into Open Scatter Table
    - **```ScatterObj<T, R> find(T key)```** - Function for finding Hash object in Open Scatter Table based on the key value
    - **```void withdraw(T key)```** - Function for withdrawing the hash object from Open Scatter Table
    - **```void printAllRecords()```** - prints all records of Open Scatter Table
    
    For example, creation of OpenScatterTable that consists of 100 ObjType elements with RecType will be: 
**```OpenScatterTable<ObjType, RecType> hash(100)```**

6. ## Binary Search Tree

In computer science, binary search trees (BST), sometimes called ordered or sorted binary trees, are a particular type of container: a data structure that stores "items" (such as numbers, names etc.) in memory. They allow fast lookup, addition and removal of items, and can be used to implement either dynamic sets of items, or lookup tables that allow finding an item by its key (e.g., finding the phone number of a person by name).
Binary search trees are very usefull and complex data structures. They usualy can be used for searching, but this is not only use of this data structures. It can be weighted, also grouped, and so on, depends on what is needed. Two classes that make this data structures are:

- **BSTNode\<T\> class** - This class is only an euxilary one for later creation of Binary search tree structure. Here it's remembered only key value, and also left and righ descendant of the node. Functions of this class are:
    - **```bool isLT(T el)```** - Checks if the el value is lover then key value
    - **```bool isGT(T el)```** - Checks if the el value is greater then key value
    - **```bool isEQ(T el)```** - Checks if the el value is equal to the key value
    - **```void setKey(T key)```** - Function that set key value to the passed value
    - **```T getKey()```** - Function that returns key value of the node
    - **```void visit()```** - Function that print information of the node
- **BSTree\<T\> class** - This class is representation of the Binary search tree itself, where the auxilary structure is BSTNode as basic element. Functions of this class are:
    - **```void deleteTree(BSTNode<T>* p)```** - Function that deletes subtree from node p
    - **```void deleteAll()```** - Function that deltes complete tree, starts from root node
    - **```bool isEmpty()```** - Function that checks is the tree is empty or not
    - **```void insert(T el)```** - Function for inserting element into the Binary Search Tree
    - **```bool isInTree(T el)```** - Function that checks is the passed element with the key value in the tree or not
    - **```BSTNode<T>* search(T el)```** - Function that find a node based on passed key value if exists in the Binary Search Tree
    - **```BSTNode<T>* search(BSTNode<T>* p, T el)```** - Function that find a node based on pointer value of the node if exists in the Binary Search Tree 
    - **```void balance(int data[], int first, int last)```** - Make from sorted array a sorted Binary Search Tree
    - **```void deleteByCopying(T el)```** - Delete a node with copying a subtree
    - **```void deleteByMergind(T el)```** - Delete a node with merging subtree
    - **```void preorder()```** - Function for preorder traversal of Binary Search Tree, recursive way
    - **```void inorder()```** - Function for inorder traversal of Binary Search Tree, recursive way
    - **```void postorder()```** - Function for postorder traversal of Binary Search Tree, recursive way
    - **```void inorder(BSTNode<T>* p)```**  - Function for inorder traversal of Binary Search Tree, recursive way
    - **```void preorder(BSTNode<T>* p)```** - Function for preorder traversal of Binary Search Tree, recursive way
    - **```void postorder(BSTNode<T>* p)```** - Function for postorder traversal of Binary Search Tree, recursive way
    - **```void breadthFirst()```** - Function for Bradth first traversal of Binary Search Tree
    - **```void iterativePreorder()```** - Function for iterative preorder traversal of Binary Search Tree
    - **```void iterativeInorder()```** - Function for iterative inorder traversal of Binary Search Tree
    - **```void iterativePostorder()```** - Function for iterative postorder traversal of Binary Search Tree
    - **```void printNode(T el)```** - Function that print node with it's left and right descendant, based on passed key
    - **```void printNode(BSTNode<T>* p)```** - Function that print node with it's left and right descendant, based on passed pointer of the node

For example, creation of Binary search tree that consist of ObjType elements will be: **```BSTree<ObjType> tree```** Situation is the same as in single liked lists, only here every element have two pointers: left and right element, logic are the same.

7. ## Graph

In mathematics, and more specifically in graph theory, a graph is a structure amounting to a set of objects in which some pairs of the objects are in some sense "related". The objects correspond to mathematical abstractions called vertices (also called nodes or points) and each of the related pairs of vertices is called an edge (also called link or line).Typically, a graph is depicted in diagrammatic form as a set of dots or circles for the vertices, joined by lines or curves for the edges. Graphs are one of the objects of study in discrete mathematics. Because of these reasons, it's needed to have a graph as data structure for better solving some of these problems.
Classes that are make our graph are:

- **LinkedNode\<T,W\> class** - This class is representation of a node in the graph, and it stores all needed data, and have one function more then constructore and that function is:
    - **```void Visit()```** - Function that print information about node
- **Edge\<T,W\> class** - This class is representation of an edge in the graph. It stores all needed data and dont have any additional functions.
- **GraphAsLists\<T,W\> class** - This class is the graph itself. It consists of Linked nodes as primary elements and from edges that linkes two node per edge. Funciton of this class are:
    - **```bool insertNode(t pod)```** - Function that insert one node into the graph
    - **```bool deleteNode(t pod)```** - funtion that delete one node from the graph if exists
    - **```bool insertEdge(t a, t b)```** - Function that insert one edge into the graph if is possible 
    - **```bool deleteEdge(t a, t b)```** - Function that delete the edge from the graph if exists
    - **```void deleteEdgeToNode(LinkedNode<t, w>* ptr)```** - Function that delete every edge that lead to the some node. This is important function when we delete the node, also all his corelated edges must be deleted as well.
    - **```LinkedNode<t, w>* findNode(t pod)```** - Function that find node and return it's pointer, if exists in the graph
    - **```Edge<t, w>* findEdge(t a, t b)```** - Function that find an edge and return it's pointer, if exists in the graph
    - **```LinkedNode<t, w>* maxExitingLevel()```** - Function that's calculating maximum edge number that exits from one node
    - **```LinkedNode<t, w>* maxInputLevel()```** - Function that's calculating maximum edge number that get in one node 
    - **```void nullEdgeNodes()```** - Function that prints all nodes that dont have any edges
    - **```void printGraph()```** - Function that print complete graph
    - **```long breadthTrav(t a)```** - Function for Breadth taversing of the graph
    - **```long depthTrav(t a)```** - Function for Depth traversing of the graph
    - **```long topologicalOrderTrav()```** - Function for traversing of the graph based on topological order
    - **```long findPathBreadth(t first, t last, t* arPath, int* lPath)```** - Function that finds the path, based on info values of nodes
    - **```long findPathBreadth(LinkedNode<t, w>* ptr, LinkedNode<t, w>* pEnd, t* arPath, int* lPath)```** - Function that finds the path, based on pointer values of nodes
    

For example, creation of Graph that consists of ObjType elements with WeightType will be: 
**```GraphAsLists<ObjType, WeightType> graf```**. 
Also graph use single linked list as auxilary structure so we dont need initial size.

For more information about how to use these structures look at the cpp file that is test file of these structures.
