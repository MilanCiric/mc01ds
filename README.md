# mc01ds

mc01ds is a short of Milan Ciric v01 Data Structures. In this header file you can find some solutions for data structures in c++. This is not a final version of this header file, so it will be more in the time. This is LIFO structure, which means, last in first out structure. In this version it can be found structures of:

1. ## stackAsArray

Stack structure is based to be a auxilary structure for more complex data structures. If you want to awoid recursion, you will use stack structure as auxilary structure, but that solution is far more complex to develop but it's faster and takes less memory then recursion call methods. Function of this structures are:

- **```bool isEmpty()```**            - check is the stack is empty or not
- **```long numberOfElements()```**   - returns number of elements that is in the stack
- **```void push(T obj)```**          - put one object of T type onto the stack, and increase number of elements
- **```T pop()```**                   - get one object of T type from the stack, and decrease number of elements
- **```T getTop()```**                - get top object of T type from the stack

For example, creation of stack that contains of 10 ObjType values will be:   **```stackAsArray<ObjType> name(10)```**
    
2. ## QueueAsArray

Queue is also auxilary structure for more complex structures where can be inserted object from one side of the queue, but can be taken only from other side, which means first in first out. Functions of this structure are:
- **```long getSize()```**
- **```long numberOfElements()```**
- **```bool isEmpty()```**
- **```T getHeadEl()```**
- **```T dequeue()```**
- **```bool enqueue(T obj)```**

3. ## Deck
4. ## Single Linked lists
5. ## Hash Tables (Chainned and Scattered)
6. ## Binary Search Tree
7. ## Graph


