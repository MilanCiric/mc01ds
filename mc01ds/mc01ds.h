#pragma once
/*****************************************************************************************************************************
******************************************************************************************************************************
Author:			Milan Ciric				                              ********************************************************
Graduated on:	Faculty of Electronic Engineering, University of Nish ********************************************************
Contact:		thelordofmind@gmail.com                               ********************************************************
Address:		Bulevar Nemanjica 12/66, Nish, Serbia                 ********************************************************
******************************************************************************************************************************
This header file contains vital classes for stack, deck, queue, single linked lists, hash tables, binary search trees and graphs 
data structures. This is version 1.0 but it will be upgrading
during time depending  on needs. They are free to use!
In section beelow we will have coments on every line thet need to be commented.
Every suggestion for changess I will be glad to hear.
******************************************************************************************************************************
*****************************************************************************************************************************/
//----------------------------------------------------------------------------------------------------------------------------
//Start of import section
//Import section for all necesery files needed for functioning properly
//----------------------------------------------------------------------------------------------------------------------------
#include <Windows.h>
#include <iostream>
#include <string>
//----------------------------------------------------------------------------------------------------------------------------
//End of import section
//----------------------------------------------------------------------------------------------------------------------------
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;
//----------------------------------------------------------------------------------------------------------------------------
//StackAsArray class, its representation and complete functions, version 1.0
//----------------------------------------------------------------------------------------------------------------------------
template<class T> class stackAsArray {
private:
	T* arr;		//Array of elements
	long size;	//Maximum size of stack
	long top;	//Index of the top element in the stack
public:
	//Constructor-------------------------------------------------------------------------------------------------------------
	stackAsArray(long size) {
		this->size = size;			//size of stack becomes long size
		this->arr = new T[size];	//reserving memeory for all array members
		this->top = -1;				//top indicator is -1, which means the stack is empty
	}
	//Destructor--------------------------------------------------------------------------------------------------------------
	~stackAsArray() {
		delete[] this->arr;	//deleting array of data
	}
	//Functiont that returns boolean value depends of it empty or not---------------------------------------------------------
	bool isEmpty() {
		return (this->top == -1);	//-1 value of top means that the stack is empty
	}
	//Function that returns number of elements that are in the stack----------------------------------------------------------
	long numberOfElements() {
		return this->top + 1;
	}
	//Function that insert element into stack---------------------------------------------------------------------------------
	void push(T obj) {
		if (this->top == (this->size - 1))			//If stack is full
		{
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Stack overflow!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
		}
		else
			this->arr[++top] = obj;		//otherwise put obj value to the top of the stack
	}
	//Function that removes one element from the top in the stack-------------------------------------------------------------
	T pop() {
		if (this->top == -1)		//if the stack is empty print warning
		{
			SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
			cout << "Stack underflow!" << endl;			//print message
			SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
			return NULL;								//returns NULL, because function needs to returns something
		}
		T result = this->arr[top--];	//removing top element from stack
		return result;					//and return it to the main structure
	}
	//Function that get the top elemet from the stack but dont remove it------------------------------------------------------
	T getTop() {
		if (this->top == -1)		//If stack is empty
		{
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Stack underflow!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return NULL;							//returns NULL
		}
		return this->arr[this->top];				//returns top element without removing it from stack
	}
};
//----------------------------------------------------------------------------------------------------------------------------
//QueueAsArray class, its representation and complete functions, version 1.0
//----------------------------------------------------------------------------------------------------------------------------
template<class T> class QueueAsArray {
private:
	T *arr;					//Array of elements in the queue
	long size;				//Size of Queue
	long head;				//Index of the first element in the queue
	long tail;				//Index of the last element in the queue
	long numOfElements;		//Maximum number of elements that queue can receive in one moment
public:
	//Constructor-------------------------------------------------------------------------------------------------------------
	QueueAsArray(long size) {
		this->size = size;				//size of queue becomes size
		this->arr = new T[size];		//alocating memory for all queue members
		this->head = this->tail = -1;	//making head and tail to value -1, which means the queue is empty
		this->numOfElements = 0;		//seting number of elements to zero
	}
	//Destructor--------------------------------------------------------------------------------------------------------------
	~QueueAsArray() {
		delete[] this->arr;		//deleting memory where was queue members
	}
	//Function that return size of the queue----------------------------------------------------------------------------------
	long getSize() {
		return this->size;	//returns size of the queue
	}
	//Function that returns number of elements--------------------------------------------------------------------------------
	long numberOfElements() {
		return this->numOfElements;		//returns number of elements
	}
	//Function that checks status of the queue, is it empty or not------------------------------------------------------------
	bool isEmpty() {
		return (this->numOfElements == 0);  //checks if the queue is empty and return true or false depends on state of the queue
	}
	//Function that reads only head element and dont remove it----------------------------------------------------------------
	T getHeadEl() {
		if (this->numOfElements == 0)		//If queue is empty
		{
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Queue underflow!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return NULL;							//returns NULL
		}
		return this->arr[this->head];				//returns head element without deleting it
	}
	//Function that reads one element and remove it from the queue------------------------------------------------------------
	T dequeue() {
		if (this->numOfElements == 0)		//if queue is empty
		{
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Queue underflow!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return NULL;							//return NULL
		}
		//otherwise
		T result = this->arr[this->head];							//result becomes head element of queue	
		if (++this->head == this->size) this->head = 0;				//if next element behind the head is equal to siye, head becoms 0
		this->numOfElements--;										//decreasing number of elements
		if (this->numOfElements == 0)this->head = this->tail = -1;	//if number of elements are 0 then head and tail becomes -1
		return result;												//return result
	}
	//Function that puts one element in the queue-----------------------------------------------------------------------------
	bool enqueue(T obj) {
		if (this->numOfElements == this->size)			//If queue is full
		{
			SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
			cout << "Queue overflow!" << endl;			//print message
			SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
			return NULL;								//return NULL
		}
		//otherwise
		if (++this->tail == this->size) this->tail = 0;			//if tail equal to size, tail becomes zero
		this->arr[this->tail] = obj;							//put element on the tail of queue
		if (this->numOfElements == 0)this->head = this->tail;	//if number of elements are zero, head becomes tail
		this->numOfElements++;									//increasing number of elements
		return true;											//return true means that code functioning properly
	}
};
//----------------------------------------------------------------------------------------------------------------------------
//DeckAsArray class, its representation and complete functions, version 1.0
//----------------------------------------------------------------------------------------------------------------------------
template<class T> class DeckAsArray {
private:
	T *arr;					//Array of elements in the deck
	long size;				//Size of deck
	long head;				//Index of the first element in the deck
	long tail;				//Index of the last element in the deck
	long numOfElements;		//Maximum number of elements that deck can receive in one moment
public:
	//Constructor-------------------------------------------------------------------------------------------------------------
	DeckAsArray(long size) {
		this->size = size;				//size of deck takes value of size
		this->arr = new T[size];		//alocating memory for all elements of deck
		this->head = this->tail = -1;	//head and tail are -1, which means the deck is empty
		this->numOfElements = 0;		//number of elements are zero
	}
	//Destructor--------------------------------------------------------------------------------------------------------------
	~DeckAsArray() {
		delete[] this->arr;		//deleting memory where was elements of deck
	}
	//Function that return size of Deck---------------------------------------------------------------------------------------
	long getSize() {
		return this->size;
	}
	//Function that returns number of elements--------------------------------------------------------------------------------
	long numberOfElements() {
		return this->numOfElements;
	}
	//Function that checks status of the Deck, is it empty or not-------------------------------------------------------------
	bool isEmpty() {
		return(this->numOfElements == 0);
	}
	//Function that reads only head element and dont remove it----------------------------------------------------------------
	T getHeadEl() {
		if (this->numOfElements == 0)				//if deck is empty
		{
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Deck underflow!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return NULL;							//return NULL
		}
		return this->arr[this->head];				//return head element without deleting it
	}
	//Function that reads one element and remove it from the Deck-------------------------------------------------------------
	T dequeue() {
		if (this->numOfElements == 0)				//if deck is empty
		{
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Deck underflow!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return NULL;							//return NULL
		}
		//otherwise
		T result = this->arr[this->head];							//result becomes head element of deck
		if (++this->head == this->size) this->head = 0;				//if head is equal to size value, it becomes 0
		this->numOfElements--;										//decreasing number of elements
		if (this->numOfElements == 0)this->head = this->tail = -1;	//if deck is empty, head and tail takes -1
		return result;												//return result
	}
	//Function that puts one element in the Deck------------------------------------------------------------------------------
	bool enqueue(T obj) {
		if (this->numOfElements == this->size)		//if deck is full
		{
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Deck overflow!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return NULL;							//return NULL
		}
		//otherwise
		if (++this->tail == this->size) this->tail = 0;			//if tail is equal to size value, it takes 0
		this->arr[this->tail] = obj;							//put obj on the tail of deck
		if (this->numOfElements == 0)this->head = this->tail;	//if stack is empty, head becomes tail
		this->numOfElements++;									//increasing number of elements
		return true;											//return true means that all completed corectly
	}
	//Put elements in front of head element, which queue is not able to do----------------------------------------------------
	bool enqueueHead(T obj) {
		if (this->numOfElements == this->size)		//if deck are full
		{
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Deck overflow!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return NULL;							//return NULL
		}
		//otherwise
		if (this->numOfElements == 0)		//if deck is empty
			this->head = this->tail = 0;	//head and tail have the same value
		else if (this->head-- == 0)			//otherwise if head decreases value and it's equals to 0
			this->head = this->size - 1;	//then head and size takes -1 as a value
		this->arr[this->head] = obj;		//otherwise obj is put in front of the head
		++this->numOfElements;				//incresing number of elements
		return true;
	}
	//returns tail------------------------------------------------------------------------------------------------------------
	T getTailEl() {
		if (this->numOfElements == 0)				//if deck is empty
		{
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Deck underflow!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return NULL;
		}
		return this->arr[this->tail];				//return tail element without deleting it
	}
	//Function that dequeue element from the tail-----------------------------------------------------------------------------
	T dequeueTail() {
		if (this->numOfElements == 0)				//if deck is empty
		{
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Deck underflow!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return NULL;
		}
		T result = this->arr[this->tail];	//result becomes tail element
		if (this->tail-- == 0)				//if no more elements in the deck 
			this->tail = this->size - 1;	//tail and head takes -1 as value
		--this->numOfElements;				//decreasing number of elements
		return result;						//returning result value
	}
};
//----------------------------------------------------------------------------------------------------------------------------
//Single linked list classes (SLList), its representations and complete functions, version 1.0
//----------------------------------------------------------------------------------------------------------------------------
template<class T> class SLLNode {
public:
	T info;				//Information of node
	SLLNode<T>* next;	//Information of which node is next in line
						//Various constructors
public:
	//Constructor 1, set all data to default value, in most cases to NULL-----------------------------------------------------
	SLLNode() {
		this->info = (T)0;
		this->next = NULL;
	}
	//Constructor 2, set only info data---------------------------------------------------------------------------------------
	SLLNode(T info) {
		this->info = info;
		this->next = NULL;
	}
	//Constructor 3, set complete node----------------------------------------------------------------------------------------
	SLLNode(T info, SLLNode<T>* next) {
		this->info = info;
		this->next = next;
	}
	//Destructor--------------------------------------------------------------------------------------------------------------
	~SLLNode() {}
	//Function that returns information part of the node----------------------------------------------------------------------
	T visit() {
		SetConsoleTextAttribute(hConsole, 9);	//set console text color to blue
		return this->info;						//print info
		SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
	}
	//Friend function, overload output operator <<----------------------------------------------------------------------------
	friend ostream& operator<<(ostream& izlaz, SLLNode<T>& obj) {
		SetConsoleTextAttribute(hConsole, 9);	//set console text color to blue
		izlaz << obj.info;						//get info to ostream
		SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
		return izlaz;							//return everything that need to be printed on console
	}
	//Functions that checks equality of two nodes-----------------------------------------------------------------------------
	//Its overloaded operator == (predefined) when from the right side are node object----------------------------------------
	inline bool operator==(const SLLNode& node) { 
		return this->info == node.info; 
	}
	//Its overloaded operator == (predefined) when from the right side are element of type T----------------------------------
	inline bool operator==(const T el) { 
		return this->info == el; 
	}
};
template<class T> class SLList {
private:
	SLLNode<T> *head, *tail; //Start and end of list
	int numberOfElements;	 //Number of elements on list
public:
	//Constructor-------------------------------------------------------------------------------------------------------------
	SLList() {
		this->head = this->tail = NULL;
		this->numberOfElements = 0;
	}
	//Destructor--------------------------------------------------------------------------------------------------------------
	~SLList() {
		//while list is not empty, deleting one element at the time from head
		while (!isEmpty())	
			T tmp = deleteFromHead();
	}
	//Function that checks if the list is empty-------------------------------------------------------------------------------
	bool isEmpty() {
		return this->head == NULL;
	}
	//Function that insert element in the list and make it as head element----------------------------------------------------
	void addToHead(T el) {
		this->head = new SLLNode<T>(el, head);			 //head beacomes new node
		if (this->tail == NULL) this->tail = this->head; //if tail is NULL, it becomes head
		this->numberOfElements++;						 //uncreasing number of elements
	}
	//Function that insert element in list at the end-------------------------------------------------------------------------
	void addToTail(T el) {
		if (!isEmpty()) {							//if list is not empty
			this->tail->next = new SLLNode<T>(el);	//next of tail becomes new node
			this->tail = tail->next;				//tail becomes it's next element, and also this is new tail
			this->numberOfElements++;				//increasing number of elements
		}
		else {												//otherwise if the list is empty
			this->head = this->tail = new SLLNode<T>(el);	//tail and head are the same
			this->numberOfElements++;						//increasing number of elements
		}
	}
	//Changing the tail after sort--------------------------------------------------------------------------------------------
	void makeNewTail() {
		for (SLLNode<T>* tmp = this->head;tmp != NULL;tmp = tmp->next)	//searching for the last element in the list
			if (tmp->next == NULL)										//when we find it
				this->tail = tmp;										//it becomes a new tail
	}
	//Function that makes new head, where first element was deleted and next become a head------------------------------------
	void makeNewHead() {
		this->head = this->head->next;
	}
	//Function that delete head, and next in line becomes new head------------------------------------------------------------
	T deleteFromHead() {
		if (isEmpty())								//if the list is empty
		{	
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "List is empty!!!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set xonsole text color to green
			return (T)NULL;							
		}
		T el = this->head->info;					//el take information from head element
		SLLNode<T>* tmp = this->head;				//auxilary parameter
		if (this->head == this->tail)				//if the list have one element
			this->head = this->tail = NULL;			//list becomes empty
		else
			this->head = this->head->next;			//otherwise, head becomes it's next element
		SetConsoleTextAttribute(hConsole, 4);		//set console text color to red
		cout << "Element " << tmp->info << " was deleted from head!!!" << endl; //print message
		SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
		delete tmp;									//deleting formal head element
		this->numberOfElements--;					//decreasing number of elements
		return el;									//return information about formal head element
	}
	//Function that delete tail, and previous element becomes new tail--------------------------------------------------------
	T deleteFromTail() {
		if (isEmpty())								//if the list is empty
		{
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "List is empty!!!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return (T)NULL;
		}
		T el = this->tail->info;					//el take tail info
		SLLNode<T>* forDel = this->tail;			//auxilary parameter
		if (this->head == this->tail)				//if the list have one element
			this->head = this->tail = NULL;			//it's become empty
		else										//otherwise
		{
			SLLNode<T>* tmp;						//auxilary parameter
			for (tmp = this->head; tmp->next != this->tail; tmp = tmp->next); //finding the preveous element of tail
			this->tail = tmp;						//tail becomes tmp
			tail->next = NULL;						//next of new tail becomes NULL
		}
		SetConsoleTextAttribute(hConsole, 4);		//set console text color to red
		cout << "Element " << forDel->info << " was deleted from tail!!!" << endl;//print message
		SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
		delete forDel;								//delete formal tail
		this->numberOfElements--;					//decreasing number of elements
		return el;									//return info about formal tail
	}
	//Function for deleteing element from the list----------------------------------------------------------------------------
	void deleteEl(T el) {
		if (isEmpty())								//if the list is empty
		{	
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "List is empty!!!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
		}
		//if we have only one element in the list and that is the searching element
		if (this->head == this->tail && this->head->info == el) 
		{
			SetConsoleTextAttribute(hConsole, 4);	//set console text color to red
			cout << "Element " << this->head->info << " was deleted!!!" << endl;//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			delete this->head;						//deleting the head element
			this->numberOfElements--;				//decreasing number of elements
			this->head = this->tail = NULL;			//tail and head becomes the same, both NULL, and the list is empty
		}
		else if (el == this->head->info)			//otherwise, if the search element is head element, and list have more then one
		{
			SLLNode<T>* tmp = this->head;			//auxilary parameter
			this->head = this->head->next;			//head becomes it's next element
			this->numberOfElements--;				//decreasing number of elements
			SetConsoleTextAttribute(hConsole, 4);	//set console text color to red
			cout << "Element " << tmp->info << " was deleted!!!" << endl; //print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			delete tmp;								//delete formal head
		}
		else {										//otherwise
			SLLNode<T> *prev, *tmp;					//Auxilary parameters
			//finding element
			for (prev = this->head, tmp = this->head->next;tmp != NULL && !(tmp->info == el); prev = prev->next, tmp = tmp->next);
			if (tmp != NULL) {	//if element exists in the list
				prev->next = tmp->next;					//relinking the list
				if (tmp == this->tail)					//if element is tail, then tail becomes previous element of that node
					this->tail = prev;					
				this->numberOfElements--;				//decreasing number of elements
				SetConsoleTextAttribute(hConsole, 4);	//set console text color to red
				cout << "Element " << tmp->info << " was deleted!!!" << endl;//print message
				SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
				delete tmp;								//delete element
			}
		}
	}
	//Function thats returns pointer to the element---------------------------------------------------------------------------
	SLLNode<T>* findNodePtr(T el) {
		for (SLLNode<T>* tmp = this->head;tmp != NULL;tmp = tmp->next) {
			if (tmp->info == el) return tmp;	//if the element in the list, function returns it's pointer
		}
		return NULL;
	}
	//Function that returns pointer of head element---------------------------------------------------------------------------
	SLLNode<T>* getHead() {
		return this->head;
	}
	//Function that returns pointer of tail elemet----------------------------------------------------------------------------
	SLLNode<T>* getTail() {
		return this->tail;
	}
	//Function that check is the currnet element a tail element---------------------------------------------------------------
	bool isTail(T el) {
		if (this->head != NULL) {
			SLLNode<T>* tmp = this->findNodePtr(el);	//finding pointer of the element in the list
			if (tmp->next == NULL)						//it that element is a tail, return true
				return true;
		}
		return false;
	}
	//Function that return number of elements in linked list------------------------------------------------------------------
	int getNumOfEl() {
		return this->numberOfElements;
	}
	//Function that return pointer of next element in the list----------------------------------------------------------------
	SLLNode<T>* getNext(SLLNode<T>* ptr) {
		return ptr->next;
	}
	//Function that get pointer of previous element in the list---------------------------------------------------------------
	SLLNode<T>* getPrev(SLLNode<T>* ptr) {
		SLLNode<T> *prev = this->head;		//auxilary parameter
		for (SLLNode<T>* tmp = this->head; tmp != NULL;tmp = tmp->next) {
			if (tmp->info == ptr->info)		//if we found the node
				return prev;				//return it's previous element
			prev = tmp;						//if it's not the case, get next element in the list and check again
		}
		return NULL;
	}
	//Function that return head element info, not node element of head--------------------------------------------------------
	T getHeadEl() {
		if (this->head != NULL)			//if the list isn't empty
			return this->head->info;	//returns head info
		else
			return (T)NULL;				//otherwise, returns nothing
	}
	//Function that returns tail element, not node element of tail------------------------------------------------------------
	T getTailEl() {
		if (this->head != NULL)			//if the list isn'e empty
			return this->tail->info;	//return tail info
		else
			return (T)NULL;				//otherwise, return nothing
	}
	//Function that return info of next element, not node element of next-----------------------------------------------------
	T getNextEl(T el) {
		if (this->head != NULL)						//if list isn't empty
			return getNext(findNodePtr(el))->info;	//return info of the next element in the list
		else
			return (T)NULL;							//otherwise, return nothing
	}
	//Function that print complete list, it's all elements--------------------------------------------------------------------
	void printAll() {
		SetConsoleTextAttribute(hConsole, 10);								//set console text color to green
		cout << "Linked list have " << this->numberOfElements << " elements, and they are:" << endl;
		for (SLLNode<T>* tmp = this->head; tmp != NULL;tmp = tmp->next)		//traversing the list, one node at the time
		{
			cout << tmp->visit();						//print node info
			if (tmp->next != NULL) {					//if current node have the next element
				SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
				cout << " -> ";							//print message only when it's not a tail element
			}
			SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
		}
		cout << endl;
	}
	//Function that check is element on the list or it's not------------------------------------------------------------------
	bool isInList(T el) {
		for (SLLNode<T>* tmp = this->head;tmp != NULL;tmp = tmp->next) {	//traversing the list
			if (tmp->info == el) return true;								//if element is found, return true
		}
		return false;														//otherwise, return false
	}
	//Function for swaping elements-------------------------------------------------------------------------------------------
	void swap(T a, T b) {
		SLLNode<T> *ptr1 = findNodePtr(a);		//auxilary parameter
		SLLNode<T> *prev1 = getPrev(ptr1);		//auxilary parameter
		SLLNode<T> *ptr2 = findNodePtr(b);		//auxilary parameter
		SLLNode<T> *prev2 = getPrev(ptr2);		//auxilary parameter
		swap(ptr1, prev1, ptr2, prev2);			//calling swap subroutine
		makeNewTail();							//make new tail, because it may be the case that tail may become head or some
												//other memeber in the list that is not the tail
	}
	//Function that exchange two neigbhour elements in the list---------------------------------------------------------------
	void swapNeigbhours(SLLNode<T>* ptr, SLLNode<T>* prev) {
		if (prev == NULL) {					//if previous element dont exists
			this->head = ptr->next;			//head takes value of next element of ptr
			ptr->next = ptr->next->next;	//next element of ptr becoms it's next next element
			this->head->next = ptr;			//next element of head becomes ptr
		}	
		else {								//otherwise
			prev->next = ptr->next;			//next of previouse element becomes next element of ptr
			ptr->next = ptr->next->next;	//next element of ptr becomes it's next next element
			prev->next->next = ptr;			//next next element of previous becomes ptr
		}
	}
	//Function that exchange two elements in the list-------------------------------------------------------------------------
	void swap(SLLNode<T>* ptr1, SLLNode<T>* prev1, SLLNode<T>* ptr2, SLLNode<T>* prev2) {
		if (ptr1 == ptr2)					//if the nodes are the same
			return;							//return doing nothing
		else if (ptr1->next == ptr2)		//if next of ptr1 is equal to ptr2 
			swapNeigbhours(ptr1, prev1);	//then do swap neigbhours of ptr1 and prev1
		else if (ptr2->next == ptr1)		//otherwise if next of ptr2 is equal to ptr1
			swapNeigbhours(ptr2, prev2);	//then do swap neigbhours ptr2 and prev2
		else {								//otherwise
			if (prev1 == NULL)				//if prev1 doesn't exists
				this->head = ptr2;			//head becomes ptr2
			else
				prev1->next = ptr2;			//otherwise next of prev1 becomes ptr2
			if (prev2 == NULL)				//if prev2 doesn't exists
				this->head = ptr1;			//head becomes ptr1
			else
				prev2->next = ptr1;			//otherwise, next of prev2 becomes ptr1
			SLLNode<T>* tmp = ptr1->next;	//auxilary parameters
			ptr1->next = ptr2->next;		//next of ptr1 becomes next element of ptr2
			ptr2->next = tmp;				//next of ptr2 becomes tmp
		}
	}
	//Selcet sort from smalest to largest-------------------------------------------------------------------------------------
	void selectionSort() {
		SLLNode<T> *ptr, *prev, *ptr1, *prev1, *ptr2, *prev2;			//auxilary parameters
		prev1 = NULL;												
		for (ptr1 = this->head;ptr1 != NULL;ptr1 = ptr1->next) {		//traversing the list from head to tail
			ptr = ptr1;							//ptr value becomes ptr1
			prev = prev1;						//prev becomes prev1
			prev2 = ptr1;						//prev2 becomes ptr1
			for (ptr2 = ptr1->next;ptr2 != NULL;ptr2 = ptr2->next) {	//finding where to put the element
				if (ptr->info > ptr2->info) {	//if ptr is equal to ptr2
					ptr = ptr2;					//ptr  becomes ptr2
					prev = prev2;				//prev becomes prev2
				}
				prev2 = ptr2;					//prev2 becomes ptr, so we may continue sort process
			}
			if (ptr1 != ptr) {					//when ptr1 is not equal to ptr
				swap(ptr1, prev1, ptr, prev);	//do swap of ptr1 and ptr
				ptr1 = ptr;						//ptr1 become ptr
			}
			prev1 = ptr1;						//prev1 becomes ptr1
		}
		makeNewTail();				//afeter sorting, we need to declare new tail
	}
	//Invert sort from largest to smalest-------------------------------------------------------------------------------------
	void invertionSort() {
		SLLNode<T> *ptr1, *prev1, *ptr2, *prev2;		//auxilary parameters
		prev1 = head;									//prev1 becomes head element
		for (ptr1 = this->head->next;ptr1 != NULL;) {	//traversing the list starting from the next element of head
			prev2 = NULL;								//prev2 becomes NULL
			ptr2 = this->head;							//ptr2 becomes head
			while (ptr2 != ptr1 && ptr1->info < ptr2->info) { //until the ptr2 is not equla to ptr1 and ptr1 info is maler 
				prev2 = ptr2;							//make prev2 as ptr2
				ptr2 = ptr2->next;						//make ptr2 as next of ptr2
			}
			if (ptr1 != ptr2) {							//if ptr1 isn't equal to ptr2
				if (prev2 != NULL) {					//if prev2 isn't NULL
					prev1->next = ptr1->next;			//next of prev1 becomes next of ptr1
					prev2->next = ptr1;					//next of prev2 becomes ptr1
					ptr1->next = ptr2;					//next of ptr1 becomes ptr2
				}
				else {									//otherwise
					prev1->next = ptr1->next;			//next of prev1 becomes next of ptr1
					this->head = ptr1;					//head becomes ptr1
					ptr1->next = ptr2;					//next of ptr1 becomes ptr2
				}
				ptr1 = prev1->next;						//pt1 becomes next of prev1
			}
			else {					//otherwise
				prev1 = ptr1;		//prev1 becomes ptr1
				ptr1 = ptr1->next;	//ptr1 becomes next of ptr1
			}
		}
		makeNewTail();				//afeter sorting, we need to declare new tail
	}
	//Insert element into sorted list-----------------------------------------------------------------------------------------
	void insertInSorted(SLLNode<T> *ptr) {
		SLLNode<T> *ptr1, *prev1;			//auxilary parameters
		prev1 = NULL;						
		ptr1 = this->head;					//ptr1 becomes head element of the list
		while (ptr1 != NULL && ptr->info < ptr1->info) {	//travesring list until some of conditions becomes false
			prev1 = ptr1;					//prev1 becomes ptr1
			ptr1 = ptr1->next;				//ptr1 becomes next element of ptr1
		}
		if (prev1 != NULL) {				//if prev1 isn't NULL then
			prev1->next = ptr;				//next of prev1 becomes ptr
			ptr->next = ptr1;				//next of ptr becomes ptr1
			this->numberOfElements++;		//increasing number of elements
		}
		else {								//otherwise
			this->head = ptr;				//head element becomes ptr
			ptr->next = ptr1;				//next element of ptr becomes ptr1
			this->numberOfElements++;		//increasing number of elements
		}	
		makeNewTail();						//declaring new tail
	}
	//Insert element into sorted list when its know only value----------------------------------------------------------------
	void insertInSorted(T el) {
		SLLNode<T>* n = new SLLNode<T>(el);	//creating SSLNode element with el value
		InsertInSorted(n);					//calling function for inserting SSLNode element into the list
	}
};
//----------------------------------------------------------------------------------------------------------------------------
//Hash table classes, its representations and complete functions, version 1.0
//----------------------------------------------------------------------------------------------------------------------------
template<class T, class R> class HashObj {
protected:
	T key;		//Key value in the hast table
	R* record;	//some kind of record
public:
	//Constructor 1, set all data to NULL-------------------------------------------------------------------------------------
	HashObj() {
		this->key = (T)0;
		this->record = NULL;
	}
	//Constructor 2, set key to k value---------------------------------------------------------------------------------------
	HashObj(T k) {
		this->key = k;
		this->record = NULL;
	}
	//Constructor 3, set all data to some value-------------------------------------------------------------------------------
	HashObj(T k, R* rec) {
		this->key = k;
		this->record = rec;
	}
	//Destructor--------------------------------------------------------------------------------------------------------------
	~HashObj() {
		if (this->record != NULL)
			this->deleteRecord();		//if record exists, delete it's pointer so memery can be free
	}
	//Function that delete record---------------------------------------------------------------------------------------------
	void deleteRecord() {
		if (this->record != NULL)	//if record exists
		{
			this->record = NULL;	//make record to NULL
			delete this->record;	//delete pointer that points to record

		}
	}
	//predefined operator = for assigning value-------------------------------------------------------------------------------
	HashObj<T, R>& operator= (HashObj<T, R> const& obj) {
		this->key = obj.key;		//key becomes key of the passed object
		this->record = obj.record;	//record becomes record of the passed object
		return *this;				//return this object back and remember it
	}
	//predefined operator == for comparation two HashObj objects--------------------------------------------------------------
	bool operator==(HashObj<T, R> const& obj) {
		return this->record == obj.record;	//if they are the same, return true, otherwise return false
	}
	//Function that get the key value-----------------------------------------------------------------------------------------
	T getKey() {
		return this->key;
	}
	//Function that set the key value-----------------------------------------------------------------------------------------
	void setKey(T key) {
		this->key = key;
	}
	//Function that get the record value--------------------------------------------------------------------------------------
	R* getRecord() {
		return this->record;
	}
	//Function that set the record value--------------------------------------------------------------------------------------
	void setRecord(R* rec) {
		this->record = rec;
	}
	//Function that check is the keys are equal-------------------------------------------------------------------------------
	bool isEqualKey(T key) {
		return this->key == key;
	}
	//Friend function for printing Hash object into ostream-------------------------------------------------------------------
	friend ostream& operator<<(ostream& izlaz, HashObj<T, R>& obj) {
		if (obj.getKey() != NULL)					//if exits in hash table
		{
			SetConsoleTextAttribute(hConsole, 9);	//set console text color to blue
			izlaz << obj.getKey();					//print key
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			izlaz << "|";							//print separator
			SetConsoleTextAttribute(hConsole, 9);	//set console text color to blue
			izlaz << *obj.getRecord();				//print record
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
		}
		return izlaz;
	}
};
template<class T, class R> class ScatterObj : public HashObj<T, R> {
public:
	int status; //value 0 - free, value 1 - deleted, value 2 - ocuppied
public:
	//contructor 1, set default values, mostly to NULL------------------------------------------------------------------------
	ScatterObj() :HashObj<T, R>() {
		this->status = 0;
	}
	//contructor 2, set key value to some value and rest of them to NULL------------------------------------------------------
	ScatterObj(T key) :HashObj<T, R>(key) {
		this->status = 0;
	}
	//contructor 1, set all values to some value except status----------------------------------------------------------------
	ScatterObj(T key, R* record) :HashObj<T, R>(key, record) {
		this->status = 0;
	}
};
template<class T, class R> class ChainedScatterObject :public ScatterObj<T, R> {
public:
	long next;		//parameter that show next synonym
	//Constructor 1, set all data to NULL, and next to -1---------------------------------------------------------------------
	ChainedScatterObject() :ScatterObj<T, R>() {
		this->next = -1;
	}
	//Constructor 1, set key value to some value, and next to -1--------------------------------------------------------------
	ChainedScatterObject(T key) :ScatterObj<T, R>(key) {
		this->next = -1;
	}
	//Constructor 1, set all data to some value, and next to -1---------------------------------------------------------------
	ChainedScatterObject(T key, R* record) : ScatterObj<T, R>(key, record) {
		this->next = -1;
	}
	//Constructor 1, set all data to some value and also the next value-------------------------------------------------------
	ChainedScatterObject(T key, R* record, unsigned int next) : ScatterObj<T, R>() {
		this->next = next;
	}
	//function that make data location as free, that means status = 0---------------------------------------------------------
	bool free() {
		return this->status == 0;
	}
	//Friend function that prints hash object---------------------------------------------------------------------------------
	friend ostream& operator<<(ostream& izlaz, ChainedScatterObject<T, R>& obj) {
		if (obj.getKey() != NULL)					//if object exists into the hash table
		{
			SetConsoleTextAttribute(hConsole, 9);	//set console text color to blue
			izlaz << obj.getKey();					//print key value
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			izlaz << "|";							//print separator
			SetConsoleTextAttribute(hConsole, 9);	//set console text color to blue
			izlaz << *obj.getRecord();				//print record value
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
		}
		return izlaz;
	}
};
template<class T, class R> class HashTable {
protected:
	unsigned int length;		//size of the hash table
	unsigned int count;			//number of members that is in the hash table
	//Hash function that calls primary transformation function for finding free location--------------------------------------
	unsigned int h(HashObj<T, R>* obj) {
		return (this->f(obj->getKey()) % this->length);
	}
	//Primary transformation function for int parameter-----------------------------------------------------------------------
	//Must be virtual so it can be overided-----------------------------------------------------------------------------------
	virtual unsigned int f(int i) {
		return abs(i);			//return absolute value
	}
	//Primary transformation function for double parameter--------------------------------------------------------------------
	//Must be virtual so it can be overided-----------------------------------------------------------------------------------
	virtual unsigned int f(double d) {
		if (d == 0)				//if d is equal to zero
			return 0;			//return zero
		else {					//otherwise
			int exponent;		//exponent value
			double mantisa = frexp(d, &exponent);					//value of mantisa value
			return (unsigned int)((2 * fabs(mantisa) - 1) * ~0U);	//return value of the key
		}
	}
	//Primary transformation function for char parameter----------------------------------------------------------------------
	//Must be virtual so it can be overided-----------------------------------------------------------------------------------
	virtual unsigned int f(char *s) {
		unsigned int res = 0;			//auxilary value
		unsigned int a = 7;				//auxilary value for shifting
		for (int i = 0; s[i] != 0; i++)	//do for every bit
			res = res << a^s[i];		//shift values into res value
		return res;						//return res value
	}
	//Secundary transformation function called g------------------------------------------------------------------------------
	//It can be called when primary function dont have results----------------------------------------------------------------
	virtual unsigned int g(unsigned int i) {
		return (i + 1) % this->length;			//secondary transformation that can be every transformation function
	}
public:
	//Function that get size of the hash table--------------------------------------------------------------------------------
	unsigned int getLength() {
		return this->length;
	}
	//Function that return load factor, which means how many location are occupied in percentage of whole hash table----------
	virtual double getLoadFactor() {
		return (double)this->count / (double)this->length;
	}
};
template<class T, class R> class ChainedHashTable :public HashTable<T, R> {
protected:
	SLList<HashObj<T, R>*> *arr;	//Array of Linked lists
public:
	//Constructor-------------------------------------------------------------------------------------------------------------
	ChainedHashTable(unsigned int len) {
		this->length = len;								//set size of the hash table
		this->count = 0;								//number of elements in the beginning is zero
		this->arr = new SLList<HashObj<T, R>*>[len];	//Define memory for arrays of linked lists of synonyms
	}
	//Destructor--------------------------------------------------------------------------------------------------------------
	~ChainedHashTable() {
		HashObj<T, R>* obj;		//Auxilary parameter
		for (unsigned int i = 0; i < this->length; i++) {	//Traversing complete hash table
			if (this->arr[i].getHead() != NULL) {			//if exists array, delete it
				obj = this->arr[i].getHeadEl();				//take head element of exact array
				while (obj != NULL) {						//while object isn't NULL
					this->arr[i].makeNewHead();				//Delete head from the linked list
					obj->deleteRecord();					//delete record of deleted head
					obj = this->arr[i].getHeadEl();			//take next element as head element
				}
			}
		}
		delete[] this->arr;									//delete pointer of array on the end
	}	
	//Function for inserting one element into the table-----------------------------------------------------------------------
	void insert(HashObj<T, R>* obj) {
		this->arr[this->h(obj)].addToHead(obj);		//if synonyms exists, insert into a list of synonyms
		this->count++;								//increase number of elements
	}
	//Function that witdraw one element from the table when is known pointer of it--------------------------------------------
	void withdraw(HashObj<T, R>* obj) {
		SetConsoleTextAttribute(hConsole, 4);			//set console text color to red
		cout << "Element ";								
		SetConsoleTextAttribute(hConsole, 9);			//set console text color to blue
		cout << this->arr[this->h(obj)].findNodePtr(obj)->info->getKey(); //print key value of synonym
		SetConsoleTextAttribute(hConsole, 6);			//set console text color to yellow
		cout << "|";									//print separator
		SetConsoleTextAttribute(hConsole, 9);			//set console text color to blue
		cout << *this->arr[this->h(obj)].findNodePtr(obj)->info->getRecord(); //print record value of synonym
		SetConsoleTextAttribute(hConsole, 4);			//set console text color to red
		cout << " withdrowned!!!" << endl;
		SetConsoleTextAttribute(hConsole, 10);			//set console text color to green
		this->arr[this->h(obj)].deleteEl(obj);			//delete element from the hash table
		this->count--;									//decreasing number of elements
	}
	//Function that witdraw one element from the table when is known it's value-----------------------------------------------
	void withdraw(T key) {
		HashObj<T, R>* obj = this->find(key);	//make object with key element
		this->withdraw(obj);					//withdraw it
	}
	//Function that find the object into the table based on key value---------------------------------------------------------
	HashObj<T, R>* find(T key) {
		HashObj<T, R>* obj;								//auxilary parameter
		unsigned int i = this->f(key) % this->length;	//find a key value, based on primary transformation
		obj = this->arr[i].getHeadEl();					//obj becomes first element in array of synonyms
		while (!(obj->isEqualKey(key)))					//while obj have the same key
			obj = this->arr[i].getNextEl(obj);			//get next element into the array of synonyms
		return obj;										//return object
	}
	//Print key and record for the all records in the hash table--------------------------------------------------------------
	void printAllRecords() {
		SetConsoleTextAttribute(hConsole, 6);					//set console text color to yellow
		cout << "Chained hash table members are:";
		SetConsoleTextAttribute(hConsole, 10);					//set console text color to green
		for (unsigned int i = 0;i < this->length;i++) {			//traversing via all records
			SetConsoleTextAttribute(hConsole, 6);				//set console text color to yellow
			cout << endl << "Sinonims with the same key: ";
			SetConsoleTextAttribute(hConsole, 9);				//set console text color to blue
			cout << i << endl;									//print key value
			SetConsoleTextAttribute(hConsole, 10);				//set console text color to green
			cout << "Linked list of sinonims have ";
			SetConsoleTextAttribute(hConsole, 9);				//set console text color to blue
			cout << this->arr[i].getNumOfEl();					//print number of synonyms
			SetConsoleTextAttribute(hConsole, 10);				//set console text color to green
			cout << " elements, and they are:" << endl;
			HashObj<T, R>* tmp = this->arr[i].getHeadEl();		//auxilary parameter
			while (tmp != NULL) {								//until tmp is NULL
				SetConsoleTextAttribute(hConsole, 9);			//set console text color to blue
				cout << tmp->getKey();							//print key value
				SetConsoleTextAttribute(hConsole, 6);			//set console text color to yellow
				cout << "|";									//print separator
				SetConsoleTextAttribute(hConsole, 9);			//set console text color to blue
				cout << *tmp->getRecord();						//print record value
				SetConsoleTextAttribute(hConsole, 10);			//set console text color to green
				if (this->arr[i].isTail(tmp) == NULL) {			//print separator of elements until tmp becomes tail
					tmp = this->arr[i].getNextEl(tmp);
					cout << " -> ";
				}
				else
					tmp = NULL;									//tmp becomes NULL, which means that is no more synonyms
			}
			SetConsoleTextAttribute(hConsole, 10);				//set console text color to green
		}
	}
};
template<class T, class R> class ChainedScatterTable : public HashTable<T, R> {
protected:
	ChainedScatterObject<T, R>* arr;			//array of scattered objects
public:
	//Constructor-------------------------------------------------------------------------------------------------------------
	ChainedScatterTable(unsigned int len) {
		this->length = len;			//set size of hash table
		this->count = 0;			//set initial number of elements
		this->arr = new ChainedScatterObject<T, R>[len];	//allocate memory for the hash table members
	}
	//Destructor--------------------------------------------------------------------------------------------------------------
	~ChainedScatterTable() {
		delete[] this->arr;		//delete array of data
	}
	//Predefined hash function------------------------------------------------------------------------------------------------
	unsigned int h(ChainedScatterObject<T, R> obj) {
		return (this->f(obj.getKey()) % this->length);
	}
	//Function that insert element into the hash table------------------------------------------------------------------------
	void insert(ChainedScatterObject<T, R> obj) {
		if (this->count == this->getLength()) {			//is the table is full
			SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
			cout << "The table is full!!!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
		}
		else {											//if the hash table is not full
			long probe = this->h(obj);					//auxilary parameter which is generated via h function
			if (!this->arr[probe].free()) {				//if location in hash table is free
				while (this->arr[probe].next != -1)		//find synonyms
				{
					probe = this->arr[probe].next;		//put on right place with the same synonym
				}
				long tail = probe;						//tail becomes probe value
				probe = this->g(probe);					//probe take value generated from g function
				while (!this->arr[probe].free() && probe != tail)	//while it's not free and it's not a tail
					probe = this->g(probe);				//do one more time g function
				if (probe == tail)						//if probe equal to tail member
				{
					SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
					cout << "Poor secondary transformation!!!";	//print message
					SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
				}
				this->arr[tail].next = probe;			//put element after it's synonyms
			}
			this->arr[probe] = obj;			//put object into hash table
			this->arr[probe].status = 2;	//make it's status to occupied
			this->arr[probe].next = -1;		//make no synonyms
			this->count++;					//increase number of elements
		}
	}
	//Function that find element into hash table based on it's key value------------------------------------------------------
	ChainedScatterObject<T, R> find(T key) {
		long probe = this->f(key) % this->length;	//probe takes value generated from primary f function
		while (probe != -1) {						//until probe is -1
			if (!this->arr[probe].isEqualKey(key))	//if have the same key
				probe = this->arr[probe].next;		//take next element
			else
				return this->arr[probe];			//otherwise return that element
		}
		SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
		cout << "Element wasnt found!" << endl;		//print message
		SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
		return NULL;
	}
	//Function that withdraw one element with the key value-------------------------------------------------------------------
	void withdraw(T key) {
		if (this->count == 0)			//if the hash table is empty
		{		
			SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
			cout << "Table is empty!" << endl;			//print message
			SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
			return;
		}
		else {							//if it's not empty
			long probe = this->f(key) % this->length;		//probe takes value generated from primary function
			long prev = -1;									//previous element is -1, it means it has no one
			while (probe != -1 && !this->arr[probe].isEqualKey(key)) {	//while is equal key and probe is different from -1
				prev = probe;								//previous becomes probe
				probe = this->arr[probe].next;				//probe take next element from the list of synonyms
			}
			if (probe == -1) {								//If probe is -1, no such element in the table 
				SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
				cout << "Element wasnt found!!!" << endl;	//print message
				SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
				return;
			}												//if element exits in the table
			else if (prev != -1) {							//and if previous exists
				//Sinonim will be deleted					
				this->arr[prev].next = this->arr[probe].next;	//relinking synonyms
				SetConsoleTextAttribute(hConsole, 4);		//set console text color to red
				cout << "Element ";				
				SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
				cout << this->arr[probe].getKey();			//print key value
				SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
				cout << "|";								//print separator
				SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
				cout << *this->arr[probe].getRecord();		//print record value
				SetConsoleTextAttribute(hConsole, 4);		//set console text color to red
				cout << " withdrowned!!!" << endl;			//print message
				SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
				this->arr[probe].deleteRecord();			//delete record
				this->arr[probe].status = 1;				//set status to 1, which means deleted
			}
			else if (this->arr[probe].next == -1) {			//if it's nothing from above, and no next element into synonym list
				SetConsoleTextAttribute(hConsole, 4);		//set console text color to red
				cout << "Element ";
				SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
				cout << this->arr[probe].getKey();			//print key value
				SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
				cout << "|";								//print separator
				SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
				cout << *this->arr[probe].getRecord();		//print record value
				SetConsoleTextAttribute(hConsole, 4);		//set console text color to red
				cout << " withdrowned!!!" << endl;
				SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
				this->arr[probe].deleteRecord();			//delete record
				this->arr[probe].status = 1;				//set status to 1, which means deleted
			}
			else {											//otherwise
				long nextEl = this->arr[probe].next;		//take next element
				SetConsoleTextAttribute(hConsole, 4);		//set console text color to red
				cout << "Element ";
				SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
				cout << this->arr[probe].getKey();			//print key value
				SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
				cout << "|";								//print separator
				SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
				cout << *this->arr[probe].getRecord();		//print record value
				SetConsoleTextAttribute(hConsole, 4);		//set console text color to red
				cout << " withdrowned!!!" << endl;
				SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
				this->arr[probe].deleteRecord();			//delete record
				this->arr[probe] = this->arr[nextEl];		//relinking list of synonyms
				this->arr[probe].next = this->arr[nextEl].next;		//relinking list of synonyms
				this->arr[nextEl] = ChainedScatterObject<T, R>();	//make new null reference
				this->arr[nextEl].status = 1;				//object deleted
			}
			this->count--;		//decreasing number of elements					

		}
	}
	//Function that print all records-----------------------------------------------------------------------------------------
	void printAllRecords() {
		SetConsoleTextAttribute(hConsole, 6);				//set console text color to yellow
		cout << "Chained scatter hash table members are:" << endl;
		SetConsoleTextAttribute(hConsole, 10);				//set console text color to green
		for (unsigned int i = 0;i < this->length;i++) {		//get every record from the hash table
			if (this->arr[i].getRecord() != NULL) {			//only place where have record
				SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
				cout << this->arr[i].getKey();				//print key value
				SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
				cout << "|";								//print separator
				SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
				cout << *this->arr[i].getRecord() << endl;	//print record value
			}
		}
		SetConsoleTextAttribute(hConsole, 10);				//set console text color to green
	}
};
template<class T, class R> class OpenScatterTable :public HashTable<T, R> {
protected:
	ScatterObj<T, R>* arr;		//array od scattered objects
public:
	//Constructor-------------------------------------------------------------------------------------------------------------
	OpenScatterTable(unsigned int len) {
		this->length = len;			//set size of table
		this->count = 0;			//set number of elements initialy to zero
		this->arr = new ScatterObj<T, R>[len];	//Allocating memory for table members
	}
	//Destructor--------------------------------------------------------------------------------------------------------------
	~OpenScatterTable() {
		delete[] this->arr;	//deleting array of objects
	}
	//predefined h function---------------------------------------------------------------------------------------------------
	unsigned int h(ScatterObj<T, R> obj) {
		return (this->f(obj.getKey()) % this->length);
	}
	//Function that find unoccupied location----------------------------------------------------------------------------------
	unsigned int findUnoccupied(ScatterObj<T, R> obj) {
		unsigned int hash = this->h(obj);			//hash takes value from h function
		unsigned int probe = hash;					//probe becomes hash, for keeping value
		if (this->arr[probe].status < 2)			//if location is free
			return probe;							//return proble location
		do {
			probe = this->g(probe);					//probe takes value of g function
			if (this->arr[probe].status < 2)		//if location is free
				return probe;						//return probe location
		} while (probe != hash);					//while probe is different from hash
		SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
		cout << "The table is full!!!" << endl;		//print message
		SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
		return -1;									//return -1, which means no free location
	}
	//Function that find match with the key-----------------------------------------------------------------------------------
	long findMatch(T key) {
		unsigned int probe = this->f(key) % this->length;			//probe takes value of f function
		for (unsigned int i = 0;i < this->length;i++)				//traversing via whole table
		{
			if (this->arr[probe].status == 0) return -1;			//if status =0, return -1, no match
			if (this->arr[probe].isEqualKey(key)) return probe;		//if is equal to key, return probe location
			probe = this->g(probe);									//probe takes value of g function
		}
		return -1;													//return -1, no match
	}
	//Function that insert object into the table------------------------------------------------------------------------------
	void insert(ScatterObj<T, R> obj) {
		if (this->count == this->getLength()) {			//if table is full
			SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
			cout << "The table is full!!!" << endl;		//print message
			SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
		}
		unsigned int offset = this->findUnoccupied(obj);	//offset becomes value of free location in the table
		this->arr[offset] = obj;							//put object on that location
		this->arr[offset].status = 2;						//set that location to occupied
		this->count++;										//increase number of elements
	}
	//Function that find element with exact key-------------------------------------------------------------------------------
	ScatterObj<T, R> find(T key) {
		long offset = this->findMatch(key);			//find a match if it has one
		if (offset >= 0)							//if we have a match
			return this->arr[offset];				//return that element
		SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
		cout << "Element wasnt found!!!" << endl;	//print message
		SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
		return NULL;
	}
	//Function for withdrawing element from table based on key value----------------------------------------------------------
	void withdraw(T key) {
		if (this->count == 0) {						//if table is empty
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Table is empty!!!" << endl;	//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return;									//return to the main routine
		}
		long offset = this->findMatch(key);			//find a match if it has one
		if (offset < 0) {							//if no match
			SetConsoleTextAttribute(hConsole, 6);	//set console text color to yellow
			cout << "Object not found!!!" << endl;	//print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			return;									//return to main routine
		}
		SetConsoleTextAttribute(hConsole, 4);		//set console text color to red
		cout << "Element ";	
		SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
		cout << this->arr[offset].getKey();			//print key value
		SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
		cout << "|";								//print seperator
		SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
		cout << *this->arr[offset].getRecord();		//print record value
		SetConsoleTextAttribute(hConsole, 4);		//set console text color to red
		cout << " withdrowned!!!" << endl;
		SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
		this->arr[offset].status = 1;				//set value to deleted
		this->arr[offset].deleteRecord();			//delete object
		count--;									//decreasing number of elements 
	}
	//Function for printing all records---------------------------------------------------------------------------------------
	void printAllRecords() {
		SetConsoleTextAttribute(hConsole, 6);					//set console text color to yellow
		cout << "Open scatter hash table members are:" << endl;
		SetConsoleTextAttribute(hConsole, 10);					//set console text color to green
		for (unsigned int i = 0;i < this->length;i++) {			//traversal via whole table
			if (this->arr[i].getRecord() != NULL) {				//if record exists
				SetConsoleTextAttribute(hConsole, 9);			//set console text color to blue
				cout << this->arr[i].getKey();					//print key value
				SetConsoleTextAttribute(hConsole, 6);			//set console text color to yellow
				cout << "|";									//print separator
				SetConsoleTextAttribute(hConsole, 9);			//set console text color to blue
				cout << *this->arr[i].getRecord() << endl;		//print record value
			}
		}
		SetConsoleTextAttribute(hConsole, 10);					//set console text color to green
	}
};
//----------------------------------------------------------------------------------------------------------------------------
//BSTree class, its representation and complete functions, version 1.0
//----------------------------------------------------------------------------------------------------------------------------
template<class T> class BSTNode {
public:
	T key;						//Value of the BSTNode
	BSTNode<T> *left, *right;	//BSTNode descendants, left and right one, we have only two because it's a binary tree
public:
	//Constructor 1, setting all values to NULL-------------------------------------------------------------------------------
	BSTNode() {
		this->left = this->right = NULL;	//setting left and right descendant initialy to NULL value
		this->key = (T)NULL;				//also setting key value to NULL casted into T type of data
	}
	//Constructor 2, setting key value to el value, and left and right descendant to NULL-------------------------------------
	BSTNode(int el) {
		this->key = el;						//setting key value to el value
		this->left = this->right = NULL;	//setting left and right descendant initialy to NULL value
	}
	//Constructor 3, set all values to desired values passed via list of parameters-------------------------------------------
	BSTNode(int el, BSTNode<T>* left, BSTNode<T>* right) {
		this->key = el;			//setting key value to el value
		this->left = left;		//setting left value for left descendant of current BSTNode 
		this->right = right;	//setting right value for right descendant of current BSTNode
	}
	//Function that checks is it a lower value then current value of BSTNode--------------------------------------------------
	bool isLT(T el) {
		return (this->key < el ? true : false); //if key<el return true otherwise return false
	}
	//Function that checks is it a greater value then current value of BSTNode------------------------------------------------
	bool isGT(T el) {
		return (this->key > el ? true : false);	//if key>el return true otherwise return false
	}
	//Function that checks is it value of current BSTNode equals to value of el parameter-------------------------------------
	bool isEQ(T el) {
		return (this->key == el ? true : false); //if key=el return true otherwise return false
	}
	//Function for seting key value on desired value--------------------------------------------------------------------------
	void setKey(T key) {
		this->key = key;	//Setting key value to el value
	}
	//Function for geting key value-------------------------------------------------------------------------------------------
	T getKey() {
		return this->key;	//Getting key value
	}
	//Function that visit the BSTNode and prints it's value on the screen-----------------------------------------------------
	void visit() {
		SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
		cout << this->key << " ";					//print key value on console
		SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
	}
};
template<class T> class BSTree {
protected:
	BSTNode<T>* root;		//Root node of the tree
	long numOfElements;		//number of elements in the tree
public:
	//Constructor that set all values to default------------------------------------------------------------------------------
	BSTree() {
		this->root = NULL;			//root element is NULL, because on the start tree is empty
		this->numOfElements = 0;	//on start number of elements must be zero
	}
	//Destructor--------------------------------------------------------------------------------------------------------------
	~BSTree() {
		this->deleteTree(root); //Delete tree starts from root node
	}
	//Function that delete complete tree, this function is called from destructor where starting point is root node-----------
	void deleteTree(BSTNode<T>* p) {
		if (p != NULL) {			//If tree is not empty, delete the tree, if not skip delete option
			deleteTree(p->left);	//delete left part of the tree
			deleteTree(p->right);	//delete right part of tree
			delete p;				//After deleting both part of the tree, we can delete start p node
		}
	}
	//Function that deletes complete tree which calls deleteTree function-----------------------------------------------------
	void deleteAll() {
		this->deleteTree(this->root);	//deletes the tree from root node
		this->root = NULL;				//root node takes NULL value
	}
	//Checks is tree empty----------------------------------------------------------------------------------------------------
	bool isEmpty() {
		return root == NULL; //The tree is empty when root node is NULL
	}
	//Function that insert one element into the tree on proper position-------------------------------------------------------
	void insert(T el) {
		//auxiliary parameters, starting point is node p, and we must have previous also
		BSTNode<T>* p = this->root, *prev = NULL;
		while (p != NULL) {		//Finding ending position in the tree
								//Searching for place where we can put our element
			prev = p;			//previous element becomes element p
			if (p->isLT(el))	//if p node value is lower then el value p becomes right descendant of p
				p = p->right;
			else
				p = p->left;	//otherwise p becomes left descendant of p
		}
		//If tree is empty our el value becomes the root
		if (this->root == NULL)
			this->root = new BSTNode<T>(el);	//creating root element as el value
		else if (prev->isLT(el))				//if prev node value is lower the el value
			prev->right = new BSTNode<T>(el);	//right descendant of prev becomes new node with el value
		else
			prev->left = new BSTNode<T>(el);	//otherwise left descendant of prev becomes new node with el value
		this->numOfElements++;					//Number of elements increased by 1
	}
	//Function that checks is the el value is in the tree---------------------------------------------------------------------
	bool isInTree(T el) {
		if (this->root != NULL) {		//if the tree is empty, it's no point of searching element
			return search(el) != NULL;	//if elemenet in the tree return it's position 
		}
		return false;					//if it's not then returns FALSE
	}
	//Function that search for el value in the tree---------------------------------------------------------------------------
	BSTNode<T>* search(T el) {
		//Search calls another search function where parameters are root node and searching value of el
		return search(this->root, el);
	}
	//Function that search for el value in the tree starts from root node-----------------------------------------------------
	BSTNode<T>* search(BSTNode<T>* p, T el) {
		while (p != NULL)			//while p is not NULL means that we still have node to visit
		{
			if (p->isEQ(el))		//if value of p is equal to el then returns p node
				return p;
			else if (p->isGT(el))	//otherwise if p greater then el value, 
				p = p->left;		//p becomes left descendant of p node
			else
				p = p->right;		//otherwise p becomes right descendant of p node
		}
		return NULL;				//If el isn't found function returns NULL value
	}
	//Make balanced binary tree, with sorted array of data--------------------------------------------------------------------
	void balance(int data[], int first, int last) {
		if (first <= last) {					//If value of first is lover or equal to last, function do inserting
			int middle = (first + last) / 2;	//middle value becomes middle member of data in the array 
			insert(data[middle]);				//first will be inserted middle memeber of data
			balance(data, first, middle - 1);	//after that continue to apply this function for the lower part
			balance(data, middle + 1, last);	//also for the upper part of array of data given in the list of arguments
		}
	}
	//Function that delete node with el value if it exists simpy by copying---------------------------------------------------
	void deleteByCopying(T el) {
		if (this->root != NULL) {		//if the tree is not empty we do delete
			BSTNode<T> *node, *p = this->root, *prev = NULL;	//auxilary variables
			while (p != NULL && !p->isEQ(el)) {					//while p is different from NULL and p is not equal to el value	
																//Finding node with desired element value
				prev = p;				//previous value becomes p node
				if (p->isLT(el))		//if p is lowet then el value
					p = p->right;		//p becomes right descendant of p node
				else
					p = p->left;		//otherwise p becomes left descendant of p node
			}
			node = p;								//node value becomes p node
			if (p != NULL && p->isEQ(el)) {			//if p is different from NULL and p is equal to el value
				if (node->right == NULL)			//case 1: Node that dont have right node as descendant
					node = node->left;				//node value becomes left descendant of node
				else if (node->left == NULL)		//case 2: Node that dont have left node as descendant
					node = node->right;				//otherwise node value becomes right descendant of node 
				else {								//case 3: Node have both descendants, if not the case 1 or 2
					BSTNode<T>* tmp = node->left;	//tmp value becomes left descendant of node
					BSTNode<T>* previous = node;	//previous becomes node value
					while (tmp->right != NULL) {	//Finding end right node in left part of the tree
						previous = tmp;				//previous value becomes tmp
						tmp = tmp->right;			//tmp becomes right descendant of tmp node
					}
					node->setKey(tmp->getKey());	//Copying referenc of node to key value
					if (previous == node)			//tmp is first left descendant of node
						previous->left = tmp->left;	//Keeps the same order in the left part of the tree
					else
						previous->right = tmp->left;//left descendant of tmp moving to tmp location
					delete tmp;						//deleting tmp node
					this->numOfElements--;			//decresing number of elements
					return;							//return to the main routine
				}
				if (p == this->root)			//in case 1 and 2 we only move reference
					this->root = node;			//of the node so we need to change link of
				else if (prev->left == p)		//previous node, but in case 3 that is not a case
					prev->left = node;			//left descendant of prev becomes node 
				else
					prev->right = node;			//otherwise right descendant of prev becomes node
				delete p;						//deleting the p node
				this->numOfElements--;			//decresing number of elements
			}
			else if (this->root != NULL) {							//if the tree is empty
				SetConsoleTextAttribute(hConsole, 4);				//setting the text color to red
				cout << "Element is not in the tree!!!" << endl;	//print message
				SetConsoleTextAttribute(hConsole, 10);				//setting the text color to green
			}
			else {
				SetConsoleTextAttribute(hConsole, 4);				//setting the text color to red
				cout << "The tree is empty!!!" << endl;				//print message
				SetConsoleTextAttribute(hConsole, 10);				//setting the text color to green	
			}
		}
	}
	//Function that delete node with el value if it exists simpy by merging---------------------------------------------------
	void deleteByMergind(T el) {
		if (this->root != NULL) {			//if root node is NULL then the tree is empty
			BSTNode<T> *tmp, *node, *p = this->root, *prev = NULL; //Auxilary variables
			while (p != NULL && !p->isEQ(el)) {		//if p is not NULL and value of p is equal to value of el
													//Finding node with desired element value
				prev = p;			//prev value becomes p
				if (p->isLT(el))	//if value of p is lower then value of el
					p = p->right;	//p becomes right descendant of p
				else
					p = p->left;	//otherwise p becomes left descendant of p
			}
			node = p;				//node becomes p
			if (p != NULL && p->isEQ(el)) {		//if p is not NULL and value of p is equal to value of el
				if (node->right == NULL)		//case 1: Node that dont have right node as descendant 
					node = node->left;			//node becomes left descendant of node
				else if (node->left == NULL)	//case 2: Node that dont have left node as descendant
					node = node->right;			//node becomes right descendant of node
				else {							//case 3: Node have both descendants
					tmp = node->left;			//tmp becomes left descendant of node
					while (tmp->right != NULL)	//Finding ending right node in left part
						tmp = tmp->right;		//of the tree and movind right link of node
					tmp->right = node->right;	//in tmp node, and in current position will
					node = node->left;			//be left descendant
				}
				if (p == this->root)			//if p is equal to toot node
					this->root = node;			//then root becomes node
				else if (prev->left == p)		//if left descendant of prev is equal to p
					prev->left = node;			//then that descendant becomes node
				else
					prev->right = node;			//otherwise right descendant of prev becomes node
				delete p;						//at the end we delete p value
				this->numOfElements--;			//and also decrease number of elements
			}
			else if (this->root != NULL)		//if tree is empty
			{
				SetConsoleTextAttribute(hConsole, 4);				//set console text color to red	
				cout << "Element is not in the tree!!!" << endl;	//print message
				SetConsoleTextAttribute(hConsole, 10);				//set console text color to green
			}
			else {
				SetConsoleTextAttribute(hConsole, 4);				//set console text color to red
				cout << "The tree is empty!!!" << endl;				//print message
				SetConsoleTextAttribute(hConsole, 10);				//set console text color to green
			}
		}
	}
	//Preorder traversal of BSTree using recursion technique------------------------------------------------------------------
	void preorder() {
		this->preorder(this->root);		//Calling preorder traversal starting from root node
	}
	//Inorder traversal of BSTree using recursion technique-------------------------------------------------------------------
	void inorder() {
		this->inorder(this->root);		//Calling inorder traversal starting from root node
	}
	//Postorder traversal of BSTree using recursion technique-----------------------------------------------------------------
	void postorder() {
		this->postorder(this->root);	//Calling postorder traversal starting from root node
	}
	//Inorder traversal of BSTree using recursion technique, starting from specifit node--------------------------------------
	void inorder(BSTNode<T>* p) {
		if (p != NULL) {				//If tree is empty it's no meaning to do traversal
			this->inorder(p->left);		//otherwise we use recursion call, where start point is left descendant of p node
			p->visit();					//after that we visit the p node
			this->inorder(p->right);	//and at the end we use recursion call, where start point is right descendant of p node
		}
	}
	//Preorder traversal of BSTree using recursion technique, starting from specifit node-------------------------------------
	void preorder(BSTNode<T>* p) {
		if (p != NULL) {				//If tree is empty it's no meaning to do traversal
			p->visit();					//first we visit the p node
			this->preorder(p->left);	//after that we use recursion call, where start point is left descendant of p node
			this->preorder(p->right);	//and at the end we use recursion call, where start point is right descendant of p node
		}
	}
	//Postorder traversal of BSTree using recursion technique, starting from specifit node------------------------------------
	void postorder(BSTNode<T>* p) {
		if (p != NULL) {				//If tree is empty it's no meaning to do traversal
			this->postorder(p->left);	//First we use recursion call, where start point is left descendant of p node
			this->postorder(p->right);	//after that we use recursion call, where start point is right descendant of p node
			p->visit();					//and at the end we visit the node
		}
	}
	//Breadth traversal of BSTree---------------------------------------------------------------------------------------------
	void breadthFirst() {
		if (this->root != NULL) {		//If the tree is empty it's no meaning to do traversal
			SetConsoleTextAttribute(hConsole, 6);		//set console text color to yellow
			cout << "Breadth first traversal of the tree nodes from start node: " << endl;  //print message
			SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
			BSTNode<T>* p = this->root;								//Auxilary parameters
			QueueAsArray<BSTNode<T>*> queue(this->numOfElements);	//Auxilary que structure
			if (p != NULL) {						//Until p is not NULL we do our traversal
				queue.enqueue(p);					//we enqueue p into the que
				while (!queue.isEmpty()) {			//while que is not empty do traversal
					p = queue.dequeue();			//dequeue p from que
					p->visit();						//visit p node
					if (p->left != NULL)			//if p node have left descendant
						queue.enqueue(p->left);		//enqueue the left descendant of p node
					if (p->right != NULL)			//if p node have right descendant also
						queue.enqueue(p->right);	//enqueue the right descendant of p node as well
				}
			}
			cout << endl;		//Only make one horisontal space on consol printing
		}
	}
	//Iterative preorder traversal of the BSTree, faster method then recursion call of preorder traversal---------------------
	void iterativePreorder() {
		if (root != NULL) {			//If the tree is empty it's no meaning to do traversal
			SetConsoleTextAttribute(hConsole, 6);	//setting console text color to yellow
			cout << "Iterative preorder traversal of the tree nodes  starting from root node: " << endl;  //print message
			SetConsoleTextAttribute(hConsole, 10);	//setting console text color to green
			BSTNode<T>* p = this->root;				//auxilary parameter p becomes pointer of root
			stackAsArray<BSTNode<T>*> stack(this->numOfElements);	//auxilary stack structure 
			if (p != NULL) {				//if p is different then NULL
				stack.push(p);				//p goes into stack
				while (!stack.isEmpty()) {	//while stack is not empty
					p = stack.pop();		//getting p from stack
					p->visit();				//visiting p
											//Left node will put after right node because he must be first to visit
					if (p->right != NULL)		//if p node have right descendant
						stack.push(p->right);	//that descendant goes to stack
					if (p->left != NULL)		//also if p node have right descendant
						stack.push(p->left);	//also that descendant goes to stack as well
				}
			}
			cout << endl;
		}
	}
	//Iterative inorder traversal of the BSTree, faster method then recursion call of inorder traversal-----------------------
	void iterativeInorder() {
		if (root != NULL) {				//If the tree is empty it's no meaning to do traversal
			SetConsoleTextAttribute(hConsole, 6);		//setting console text color to yellow
			cout << "Iterative inorder traversal of the tree nodes starting from root node: " << endl;  //print message
			SetConsoleTextAttribute(hConsole, 10);		//setting console text color to green
			BSTNode<T>* p = this->root;			//auxilary parameter p becomes pointer of root
			stackAsArray<BSTNode<T>*> stack(this->numOfElements);	//auxilary stack structure
			while (p != NULL) {			//while p is different then NULL
				while (p != NULL) {		//second while loop with the same condition
										//We put right nodes into the stack, and after that current node
										//and after that we passes to the left node
					if (p->right != NULL)		//if p have right descendant
						stack.push(p->right);	//we put it onto the stack
					stack.push(p);				//after that we put the p node onto the stack
					p = p->left;				//p becomes left descendant of himself
				}
				p = stack.pop();		//Node without left descendants
				while (!stack.isEmpty() && p->right == NULL) {	//while stack is not empty and right descendant doesn't exists
					p->visit();			//Visiting current node which dont have right nodes
					p = stack.pop();	//get one stack record from stack auxilary structure and put it into p
				}
				p->visit();				//Visiting first node and its right descendants
				if (!stack.isEmpty())	//if stack isn't empty
					p = stack.pop();	//get one stack record from stack structure and put it into p
				else
					p = NULL;			//otherwise p becomes NULL
			}
			cout << endl;
		}
	}
	//Iterative postorder traversal of the BSTree, faster method then recursion call of postorder traversal-------------------
	void iterativePostorder() {
		if (root != NULL) {			//If the tree is empty it's no meaning to do traversal
			SetConsoleTextAttribute(hConsole, 6);	//Setting console text color to yellow
			cout << "Iterative postorder traversal of the tree nodes starting from root node: " << endl; //print message
			SetConsoleTextAttribute(hConsole, 10);	//setting console text color to green
			BSTNode<T> *p = this->root, *q = this->root;			//auxilary parameters
			stackAsArray<BSTNode<T>*> stack(this->numOfElements);	//auxilary stack structure
			while (p != NULL) {						//while p is not NULL
				for (;p->left != NULL;p = p->left)	//loop goes until left descendant is NULL, by left side of descendants
					stack.push(p);					//we put all left descendants into stack
				while (p != NULL && (p->right == NULL || p->right == q)) {
					//while p isn't NULL and right descendant of p is NULL or equal to q parameter
					p->visit();		//visiting p node
					q = p;			//q becomes p
					if (stack.isEmpty()) {	//if stack is empty
						cout << endl;
						return;				//terminate current function and return to main structure
					}
					p = stack.pop();		//if isn't the case, get one record from stack
				}
				stack.push(p);				//push p onto the stack
				p = p->right;				//p becomes right descendant of p
			}
		}
	}
	//Function that prints information of one node, where parameter is it's value---------------------------------------------
	void printNode(T el) {
		if (this->root != NULL) {				//If the tree is empty it's no meaning to do print node
			this->printNode(this->search(el));	//call another printNode function with pointer of element if it exists into tree
		}
	}
	//Function that prints information of one node, where parameter is pointer of the node------------------------------------
	void printNode(BSTNode<T>* p) {
		cout << "Node value: ";
		p->visit();		//visiting the node, which means we print it's value
		cout << endl;
		if (p->left != NULL) {		//if left descendant of p is not NULL, which means it's exists
			cout << "His left descendant: ";
			p->left->visit();		//visit left descendant of p
		}
		else						//otherwise print warning that left descendant don't exists
			cout << "He doesn't nave left descendant!";
		cout << endl;
		if (p->right != NULL) {		//if p have right descendant
			cout << "His right descendant:";
			p->right->visit();		//visit right descendant of p
		}
		else                        //otherwise print warning that right descendant don't exists
			cout << "He doesn't nave right descendant!";
		cout << endl;
	}
};
//----------------------------------------------------------------------------------------------------------------------------
//Graph classes, its representations and complete functions, version 1.0
//----------------------------------------------------------------------------------------------------------------------------
template<class t, class w> class LinkedNode;
template<class t, class w> class Edge
{
public:
	LinkedNode<t, w>* dest;			//point to destination node
	Edge<t, w>* link;				//next edge in linked list
	w weight;						//weight of the edge
	//Constructor 1, set both pointers to NULL--------------------------------------------------------------------------------
	Edge()						
	{
		dest = NULL;
		link = NULL;
	}
	//Constructor 2, set both pointers to some value--------------------------------------------------------------------------
	Edge(LinkedNode<t, w>* a, Edge<t, w>* b)
	{
		dest = a;
		link = b;
	}
};
template <class t, class w> class LinkedNode
{
public:
	t node;						//node information
	Edge<t, w>* adj;			//pointer to linked lists of edges for the specific node
	LinkedNode<t, w>* next;		//next node in the linked list of nodes
	int status;					//information about status, usefull in traversing the graph
	w weightOfNode;				//weight of the node, also usefull in traversing the graph and finding best route
	//Constructor 1, set all to NULL------------------------------------------------------------------------------------------
	LinkedNode()		
	{
		adj = NULL;
		next = NULL;
		status = 0;
		weightOfNode = 0;
	}
	//Constructor 2, set only information of the node-------------------------------------------------------------------------
	LinkedNode(t nodeN)
	{
		node = nodeN;
		adj = NULL;
		next = NULL;
		status = 0;
		wightOfNode = 0;
	}
	//Constructor 3, set every value that node havem except weight------------------------------------------------------------
	LinkedNode(t nodeN, Edge<t, w>* a, LinkedNode<t, w>* b, int c)
	{
		node = nodeN;
		adj = a;
		next = b;
		status = c;
		weightOfNode = 0;
	}
	//Function that print the node value--------------------------------------------------------------------------------------
	void Visit()
	{

		SetConsoleTextAttribute(hConsole, 9);
		cout << node << " ";
		SetConsoleTextAttribute(hConsole, 10);
	}
};
template<class t, class w> class GraphAsLists
{
private:
	LinkedNode<t, w>* start;	//start node in the graph representation
	long nodeNum;				//number of nodes in the graph
	long edgeNum;				//number of the edges in the graph
public:
	//Constructor 1, set all to NULL------------------------------------------------------------------------------------------
	GraphAsLists() {
		this->start = NULL;		//no start node in the beginning, must insert first some node to have start node
		this->nodeNum = 0;		//initialy number of nodes are zero
		this->edgeNum = 0;		//initialy number of edges are zero
	}
	//Function for inserting node into graph----------------------------------------------------------------------------------
	bool insertNode(t pod) {
		LinkedNode<t, w>* newNode = new LinkedNode<t, w>(pod, NULL, start, 0);	//auxilary parameter, that point to start location
		if (newNode == NULL) return false;		//if node isn't created, return false
		this->start = newNode;					//start becomes new node, every node that is inserted becomes start, and rest follow
		this->nodeNum++;						//increasing number of nodes
		return true;
	}
	//Function for deleting node from graph-----------------------------------------------------------------------------------
	bool deleteNode(t pod) {
		LinkedNode<t, w>* ptr;					//auxilary parameter
		if (this->start == NULL) return false;	//if the graph is empty, terminate the function and return false
		if (this->start->node == pod) {			//if the start node is node that need to be deleted
			ptr = this->start;					//remember the pointer
			Edge<t, w>* pot = this->start->adj;	//remember it's links
			while (pot != NULL) {				//while pot is not null, delete one link at the time
				Edge<t, w>* tpot = pot->link;	//get next link in the line
				delete pot;						//delete previous link
				pot = tpot;						//tpot becomes pot
				this->edgeNum--;				//decreasing number of the edges in the graph
			}
			this->start->adj = NULL;			//after deleteing edges, pointer must become NULL
			deleteEdgeToNode(this->start);		//also must be deleted all other edges that points to our node
			ptr = this->start;					//ptr becomes start node
			this->start = this->start->next;	//start becomes it's next element
			delete ptr;							//now ptr can be deleted
			this->nodeNum--;					//decreasing number of nodes in the graph
			return true;
		}
		else {											//if node is not on start possition
			ptr = this->start->next;					//ptr get the next element after start
			LinkedNode<t, w>* par = this->start;		//auxilary parameter
			while (ptr != NULL && ptr->node != pod) {	//while ptr is not NULL and it's info is different then node info which is
				par = ptr;								//needed for deleting
				ptr = ptr->next;						//take next element in the linked list
			}
			if (ptr == NULL) return false;		//if ptr doesn't exists return false
			par->next = ptr->next;				//remember next element in the line
			Edge<t, w>* pot = ptr->adj;			//remember it's list of edges
			while (pot != NULL) {				//until pot is NULL
				Edge<t, w>* tpot = pot->link;	//remember next element in the edges linked list
				delete pot;						//delete pot
				pot = tpot;						//pot value becomes next edge from the list
				this->edgeNum--;				//decreasing number of edges
			}
			ptr->adj = NULL;						//list of edges of specific node are now empty
			deleteEdgeToNode(ptr);					//deleting all other edges that points to that node
			delete ptr;								//delete the node
			SetConsoleTextAttribute(hConsole, 4);	//set console text color to red
			cout << endl << "Node " << pod << " deleted with all his edges!!!" << endl; //print message
			SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
			nodeNum--;								//decreasing number of nodes in the graph
			return true;
		}
	}
	//Function for inserting edge into graph----------------------------------------------------------------------------------
	bool insertEdge(t a, t b) {
		LinkedNode<t, w>* pa = findNode(a);				//auxilary parameter for the first node
		LinkedNode<t, w>* pb = findNode(b);				//auxilary parameter for the second node
		if (pa == NULL || pb == NULL) return false;		//if some of this two nodes don't exists or both don't exists return false
		Edge<t, w>* ptr = new Edge<t, w>(pb, pa->adj);	//ptr becomes a edge from pa to pb
		if (ptr == NULL)return false;					//if ptr is NULL return false
		pa->adj = ptr;									//link from pa must be pointer to pb
		this->edgeNum++;								//increasing number of edges
		return true;
	}
	//Function for deleting edge from graph-----------------------------------------------------------------------------------
	bool deleteEdge(t a, t b) {
		Edge<t, w>* pot = findEdge(a, b);		//first need to find the edge
		if (pot == NULL) return false;			//if dont exists return false
		LinkedNode<t, w>* pa = findNode(a);		//find one node of the edge, and name it pa
		if (pot == pa->adj) {					//if pot in edge links of pa
			pa->adj = pot->link;				//relink the list
			delete pot;							//delete pot
			return true;						
		}
		Edge<t, w>* tpot = pa->adj;				//tpot becomes first element in edge list of pa
		while (tpot->link != pot)				//if next of tpot is different then pot
			tpot = tpot->link;					//get next in line
		tpot->link = pot->link;					//relink the list of edges
		delete pot;								//delete link, pot value
		SetConsoleTextAttribute(hConsole, 4);	//set console text color to red
		cout << endl << "Edge " << a << " -> " << b << " has deleted!!!" << endl;	//print message
		SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
		this->edgeNum--;						//decrease number of edges
		return true;
	}
	//Deletes every edge that leads to exact node-----------------------------------------------------------------------------
	void deleteEdgeToNode(LinkedNode<t, w>* ptr) {
		LinkedNode<t, w>* pa = this->start;				//pa becomes start node in linked lists of nodes
		while (pa != NULL)								//while pa exists, means if it's not end of linked list
		{												//practicaly do for every node
			Edge<t, w> *prev = NULL, *pot = pa->adj;	//pot becomes first element of edges of current node
			while (pot != NULL)							//while pot is not NULL, it means while that node have edges in the list
			{											
				if (pot->dest == ptr)					//if current edge points to ptr
				{
					if (pa->adj == pot)					//if edge is equal to pot
					{	
						pa->adj = pot->link;			//relink the list
						delete pot;						//delte that edge, pot
						this->edgeNum--;				//decrease number of edges
						pot = pa->adj;					//pot becomes first edge in the list of edges
					}
					else
					{									//otherwise
						prev->link = pot->link;			//relink the list
						delete pot;						//delete pot
						this->edgeNum--;				//decrease number of edges
						pot = prev->link;				//pot becomes next element of prev
					}
				}
				else
				{						//otherwise
					prev = pot;			//prev becomes pot
					pot = pot->link;	//pot becomes it's next edge
				}
			}
			pa = pa->next;				//get next node from the list
		}
	}
	//Function that finds specific Node in graph------------------------------------------------------------------------------
	LinkedNode<t, w>* findNode(t pod) {
		LinkedNode<t, w>* ptr = this->start;		//ptr is start node in the list of nodes in the graph
		while (ptr != NULL && ptr->node != pod)		//get next element if it's not end of list and it's not equal to pod
			ptr = ptr->next;
		return ptr;									//return pod
	}
	//Funkction that finds specific edge in graph-----------------------------------------------------------------------------
	Edge<t, w>* findEdge(t a, t b) {
		LinkedNode<t, w>* pa = findNode(a);			//find fist node if exists in graph
		LinkedNode<t, w>* pb = findNode(b);			//find second node if exists in graph
		if (pa == NULL && pb == NULL)return NULL;	//if both not in the list, return NULL
		Edge<t, w>* ptr = pa->adj;					//start edge into list of first node
		while (ptr != NULL && ptr->dest != pb)		//until edge is found or reach the end of list
			ptr = ptr->link;						//take next edge in line
		return ptr;									//return pointer of edge
	}
	//Function that gets node with max exiting level--------------------------------------------------------------------------
	LinkedNode<t, w>* maxExitingLevel() {
		LinkedNode<t, w>* ptr = this->start, *maxNode = NULL; //Auxilary parameters
		int i, max = 0;					//i is value of level of current node, max is maximum of all nodes
		Edge<t, w>* pom;				//auxilary parameter
		while (ptr != NULL)				//until ptr get the end of list of nodes
		{
			pom = ptr->adj;				//get trough the list of edges of current node, start from first element
			i = 0;						//set current index to zero	
			while (pom != NULL)			//until reach the end
			{
				i++;					//increase index for one for each edge
				pom = pom->link;		//get to the next in line
			}
			if (max<i)					//if current index is greater then maximum value
			{	
				max = i;				//new maximum becomes current index
				maxNode = ptr;			//and pointer of maximum level node becomes current node
			}
			ptr = ptr->next;			//if it's not, get next node in line
		}
		cout << endl << "Node with maximum outgoing edges is: ";	//print message
		SetConsoleTextAttribute(hConsole, 9);						//set console text color to blue
		cout << maxNode->node << endl;								//print node
		SetConsoleTextAttribute(hConsole, 10);						//set console text color to green
		return maxNode;												//return pointer of max level node
	}
	//Function that gets node with max exiting level--------------------------------------------------------------------------
	LinkedNode<t, w>* maxInputLevel() {
		SetConsoleTextAttribute(hConsole, 10);					//set console text color to green
		cout << endl << "Node with maximum input edges is: ";	//print message
		bool none = true;										//auxilary parameter
		int maxInput = 0;										//index of max input level
		LinkedNode<t, w>* maxInputNode = NULL;					//pointer of node with max input level
		for (LinkedNode<t, w>* tmp = this->start;tmp != NULL;tmp = tmp->next) {	//traversal of all nodes in the graph
			int maxIn = 0;										//input level for current node
			LinkedNode<t, w>* tmp2 = this->start;				//second traversal of all nodes in the graph
			while (tmp2 != NULL) {								//until tmp2 is NULL
				if (tmp2->adj != NULL) {						//if current node have links
					Edge<t, w>* etmp = tmp2->adj;				//take first edge in the line of edges
					while (etmp != NULL) {						//while reach the end of list of edges
						if (etmp->dest->node == tmp->node)		//if edge points to our node, increase it's input level
							maxIn++;
						etmp = etmp->link;						//if not, get next edge
					}
				}
				tmp2 = tmp2->next;								//get next node
			}
			if (maxIn > maxInput) {								//if current input level is greater then max level
				maxInput = maxIn;								//make max input level as current level
				maxInputNode = tmp;								//and pointer of max input level node to current node
			}
		}
		SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
		cout << maxInputNode->node;					//print node with maximum input level
		cout << endl;			
		SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
		return maxInputNode;						//return node with max input level
	}
	//Function that finds nodes with 0 edges----------------------------------------------------------------------------------
	void nullEdgeNodes() {
		SetConsoleTextAttribute(hConsole, 10);			//set console text color to green
		cout << endl << "Nodes that have no edges: ";	//print message
		SetConsoleTextAttribute(hConsole, 9);			//set console text color to blue
		bool none = true;								//auxilary parameter
		for (LinkedNode<t, w>* tmp = this->start;tmp != NULL;tmp = tmp->next) {	//traversal of all nodes in the graph
			bool find = false;								//if node have links, it's false true
			LinkedNode<t, w>* tmp2 = this->start;			//tmp2 becomes start node
			while (tmp2 != NULL && !find) {					//while tmp2 is not null and isn't founded
				if (tmp2->adj != NULL && !find) {			//if that node isn't in the edge list
					Edge<t, w>* etmp = tmp2->adj;			//etmp becomes first member of edge list
					while (etmp != NULL && !find) {			//while it's not founded and it's not end of the list
						if (etmp->dest->node == tmp->node)	//if link founded that points to current node
							find = true;					//mark that it's founded
						etmp = etmp->link;					//if it's not, get next in line
					}
				}
				tmp2 = tmp2->next;					//get next node in line
			}
			if (!find) {		//if node dont have any links from it, and to it
				tmp->Visit();	//print it 
				none = false;	//reset none parameter
			}
		}
		if (none)											//if graph dont have node with null edges
			cout << "there is no such a node in the graph!";//print message
		cout << endl;
		SetConsoleTextAttribute(hConsole, 10);				//set console text color to green
	}
	//Function that prints the graph------------------------------------------------------------------------------------------
	void printGraph() {
		LinkedNode<t, w>* ptr = this->start;			//start node in the graph
		Edge<t, w>* pom;								//auxilary parameter
		SetConsoleTextAttribute(hConsole, 10);			//set console text color to green
		cout << "Number of nodes: ";					//print message
		SetConsoleTextAttribute(hConsole, 9);			//set console text color to blue
		cout << this->nodeNum << endl;					//print node number
		SetConsoleTextAttribute(hConsole, 10);			//set console text color to green
		cout << "Number of different connection: ";		//print message
		SetConsoleTextAttribute(hConsole, 9);			//set console text color to blue
		cout << this->edgeNum << endl << endl;			//print edge number
		SetConsoleTextAttribute(hConsole, 10);			//set console text color to green
		while (ptr != NULL)								//until ptr reach the end
		{	
			pom = ptr->adj;								//pom starts from first edge in list of edges for current node
			cout << "Node: ";							
			SetConsoleTextAttribute(hConsole, 9);		//set console text color to blue
			cout << ptr->node;							//print node
			SetConsoleTextAttribute(hConsole, 10);		//set console text color to green
			cout << " is connected to";
			while (pom != NULL)							//traversal trough the edges of current node
			{

				cout << " -> ";
				SetConsoleTextAttribute(hConsole, 9);	//set console text color to blue
				cout << pom->dest->node;				//print destination node
				SetConsoleTextAttribute(hConsole, 10);	//set console text color to green
				pom = pom->link;						//get next edge in line of edges
			}
			cout << endl;
			ptr = ptr->next;							//get next node in line of nodes
		}
	}
	//Breadth traversal of nodes in graph-------------------------------------------------------------------------------------
	long breadthTrav(t a) {
		static long retVal = 0;				//auxilary parameter
		LinkedNode<t, w>* ptr = start;		//ptr is start node
		QueueAsArray<LinkedNode<t, w>*> que(this->nodeNum); //auxilary que structure
		while (ptr != NULL) {				//until ptr reach the end of list of nodes
			ptr->status = 1;				//set status of current node to 1
			ptr = ptr->next;				//get next in line
		}
		ptr = findNode(a);					//find node
		if (ptr == NULL) return 0;			//if it's not in the graph, return 0
		que.enqueue(ptr);					//otherwise, put that node into the queue
		ptr->status = 2;					//set it's status to 2, visited
		cout << endl << "Breadth traversal of nodes starting from " << a << " node:" << endl;	//print start node of traversal
		while (!que.isEmpty()) {				//until the queue becomes empty
			ptr = que.dequeue();				//take one element from the queue
			ptr->status = 3;					//set it's status to 3, which means that node will not be visited again
			ptr->Visit();						//visit the node, which means print its info
			if (!que.isEmpty())					//until the queue is empty
				cout << "-> ";					//print corelation mark
			retVal++;							//increase retVal for one
			Edge<t, w>* pot = ptr->adj;			//pot becomes first in line of edges for current node
			while (pot != NULL) {				//until pot get the end of list of edges
				if (pot->dest->status == 1) {	//if pointered node have status 1
					pot->dest->status = 2;		//change it to 2
					que.enqueue(pot->dest);		//and put it into queue
				}
				pot = pot->link;				//get next edge in line of edges
			}
		}
		return retVal;							//return how long is the path
	}
	//Depth traversal of nodes in graph---------------------------------------------------------------------------------------
	long depthTrav(t a) {
		int retVal = 0;					//return value is set to zero, that is the path lenght
		LinkedNode<t, w> *ptr = start;	//start node of traversal
		stackAsArray<LinkedNode<t, w>*> stack(nodeNum);	//auxilary stack structure
		//Setting all nodes status to 1
		while (ptr != NULL)
		{
			ptr->status = 1;		//to every node set status to 1
			ptr = ptr->next;		//get next in line
		}
		//Finding starting node
		ptr = findNode(a);			//find node
		if (ptr == NULL) return 0;	//if don't exists return zero
		stack.push(ptr);			//if exists put it onto stack
		ptr->status = 2;			//set it's status to 2
		//Traversal
		cout << endl << "Depth traversal of graph :" << endl;
		while (!stack.isEmpty())	//until stack is empty
		{
			ptr = stack.pop();				//get one node from stack
			ptr->status = 3;				//set its status to 3, no more visits
			ptr->Visit();					//visit that node, which means print it's info
			if (!stack.isEmpty())			//if stack is not empty, print corelation mark
				cout << "-> ";
			retVal += 1;					//increase return value for 1
			Edge<t, w> *pot = ptr->adj;		//pot is firs edge in list of edges of the current node
			while (pot != NULL)				//until pot get the end of list of edges
			{
				if (pot->dest->status == 1)	//if status of destination node is 1
				{
					pot->dest->status = 2;	//set it to 2
					stack.push(pot->dest);	//and put it onto stack
				}
				pot = pot->link;			//get next edge from list of edges
			}
		}
		return retVal;						//get return value, length of the path
	}
	//Topologiacl traversal of nodes in graph -- need to be checked-----------------------------------------------------------
	long topologicalOrderTrav() {
		int retVal = 0;						//return value, lenght of the path
		LinkedNode<t, w> *ptr;				//auxilary parameter
		ptr = start;						//becomes start node of the graph
		while (ptr != NULL)					//until ptr reach the end of list of nodes
		{
			ptr->status = 0;				//set status of current node to 0
			ptr = ptr->next;				//get next node in line
		}
		ptr = start;						//ptr becomes start node again
		//Calculating levels for all nodes
		while (ptr != NULL)					//until ptr reah the end of list of nodes
		{
			Edge<t, w> *pot = ptr->adj;		//pot becomes first edge in line of edges of current node
			while (pot != NULL)				//until pot reach the end of list
			{
				pot->dest->status += 1;		//status of destination node increase for 1
				pot = pot->link;			//get next edge from list
			}
			ptr = ptr->next;				//get next node from list
		}
		QueueAsArray<LinkedNode<t, w>*> que(nodeNum);	//auxilary queue structure
		ptr = start;						//ptr becomes start node once again
		//counting nodes that not lonely, with level not 0
		while (ptr != NULL)					//until ptr reach the end of list of nodes
		{
			if (ptr->status != 0)			//if status of current node is different then 0
				que.enqueue(ptr);			//put that element into queue
			ptr = ptr->next;				//get next node from list of nodes
		}
		//Visiting nodes in topological order
		cout << endl << "Topological order traversal of graph:" << endl;
		while (!que.isEmpty())				//until queue is empty
		{
			ptr = que.dequeue();			//get one node from queue
			ptr->Visit();					//visit it, print it
			if (!que.isEmpty())				//if queue is not empty, print corelation mark
				cout << "-> ";
			retVal += 1;					//return value increase for 1
			Edge<t, w> *pot = ptr->adj;		//pot become first edge in list of edges of current node
			while (pot != NULL)				//until pot reach the end of list
			{
				pot->dest->status -= 1;		//status of destination node decrease for 1
				if (pot->dest->status == 0)	//if status of destination node is zero
					que.enqueue(pot->dest);	//put it into queue
				pot = pot->link;			//get next edge from list of edges
			}
		}
		return retVal;						//return length of the path
	}
	//Finding path using Breadth search, which is not most eficient way-------------------------------------------------------
	long findPathBreadth(t first, t last, t* arPath, int* lPath) {
		LinkedNode<t, w>* pStart = NULL;		//auxilary parameters
		LinkedNode<t, w>* pEnd = NULL;			//auxilary parameters
		LinkedNode<t, w>* ptr = this->start;	//auxilary parameters, start node of the graph
		while (ptr != NULL) {					//until ptr reach the end of list of nodes
			ptr->status = 0;					//set status of current node to zero
			if (ptr->node == first) {			//if current node is equal to first (starting point of the path)
				pStart = ptr;					//pStart becomes it's pointer
			}
			if (ptr->node == last) {			//if current node is equal to last (ending point of the path)
				pEnd = ptr;						//pEnd becomes it's pointer
			}
			ptr = ptr->next;					//if it's not the case, get next node in line
		}
		cout << endl << "Path determinated by Breadth search from ";
		SetConsoleTextAttribute(hConsole, 9);	//set console color to blue
		cout << first;							//print first (start node of the path) node
		SetConsoleTextAttribute(hConsole, 10);	//set console color to green
		cout << " to ";
		SetConsoleTextAttribute(hConsole, 9);	//set console color to blue
		cout << last;							//print last (end ndoe of the path)
		SetConsoleTextAttribute(hConsole, 10);	//set console color to green
		cout << " is: ";		
		SetConsoleTextAttribute(hConsole, 9);	//set console color to blue
		cout << last;							//start printing from end to start
		SetConsoleTextAttribute(hConsole, 10);	//set console color to green
		cout << " <- ";
		//the same function but only parameters are pointers, not value of nodes, which gives us path
		long n = findPathBreadth(pStart, pEnd, arPath, lPath);
		cout << "\b\b\b\b   " << endl;			//delete last arrow
		return n;								//return lenght of the path
	}
	long findPathBreadth(LinkedNode<t, w>* ptr, LinkedNode<t, w>* pEnd, t* arPath, int* lPath) {
		if (ptr->node == pEnd->node) {			//if first is equal to last node
			if (arPath != NULL)					
				arPath[*lPath++] = ptr->node;	
			return 1;
		}
		int retVal = 0;							//return value is initialy zero
		if (ptr->status != 1) {					//if status not 1
			ptr->status = 1;					//set status to 1
			Edge<t, w>* pot = ptr->adj;			//pot is start edge in list of edges
			while (retVal == 0 && pot != NULL) {	//while retVal is zero and pot is different then NULL
				retVal = findPathBreadth(pot->dest, pEnd, arPath, lPath);	//use recursion call of itself
				pot = pot->link;				//get next edge
			}
			if (retVal != 0 && arPath != NULL)	//if retVal is not zero and arPath is not NULL
				arPath[*lPath++] = ptr->node;	
			ptr->Visit();						//visit the node
			cout << "<- ";
		}
		return retVal;							//return the lenght of the path
	}
}; 
//----------------------------------------------------------------------------------------------------------------------------
//End of header file
//----------------------------------------------------------------------------------------------------------------------------