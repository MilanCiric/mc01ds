#include <iostream>
#include "mc01ds.h"
#include <cmath>
using namespace std;
int menu() {
	system("cls");
	int test;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "This window is for test purpose only!!!" << endl;
	cout << "Here we will see results of using data structures such as:" << endl;
	SetConsoleTextAttribute(hConsole, 9);
	cout << "1 - Stack" << endl << "2 - Queue" << endl << "3 - Deck" << endl << "4 - Single link list" << endl;
	cout << "5 - Hash table" << endl << "6 - Binary search tree" << endl << "7 - Graph" << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Enter a choice what to test, and everything else will means end of test program: ";
	cin >> test;
	return test;
	system("cls");
}
void testStack() {
	system("cls");
	//------------------------------------------------------------------------------------------------------------
	//testing stack class//---------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Testing stack class instance!!!" << endl << endl;
	SetConsoleTextAttribute(hConsole, 10);
	stackAsArray<int> s(10);
	s.getTop();
	s.pop();
	for (int i = 1;i < 11;i++)
		s.push(i * 2);
	s.push(10);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Stack is empty: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << (s.isEmpty() ? "true" : "false") << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Number of elements in the stack: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << s.numberOfElements() << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Top element of the stack is: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << s.getTop() << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Stack elements are: ";
	SetConsoleTextAttribute(hConsole, 9);
	for (int i = 1;i < 11;i++)
		cout << s.pop() << " ";
	SetConsoleTextAttribute(hConsole, 10);
	cout << endl << endl;
	system("pause");
	system("cls");
};
void testDeck() {
	system("cls");
	//------------------------------------------------------------------------------------------------------------
	//testing deck class//----------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------
	DeckAsArray<float> d(10);
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Testing deck class instance!!!" << endl << endl;
	d.dequeue();
	d.dequeueTail();
	d.getHeadEl();
	d.getTailEl();
	for (int i = 1;i < 11;i++)
		d.enqueue((float)i * 4);
	d.enqueue((float)100.0);
	d.enqueueHead(100.0);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Head element of deck is: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << d.getHeadEl() << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Tail element of deck is: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << d.getTailEl() << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Is deck empty: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << (d.isEmpty() ? "true" : "false") << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Size of deck: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << d.getSize() << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Number of elements in the deck: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << d.numberOfElements() << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Deck elements are: ";
	SetConsoleTextAttribute(hConsole, 9);
	for (int i = 1;i < 11;i++)
		cout << d.dequeue() << " ";
	cout << endl << endl;
	SetConsoleTextAttribute(hConsole, 10);
	system("pause");
	system("cls");
};
void testQueue() {
	system("cls");
	//------------------------------------------------------------------------------------------------------------
	//testing queue class//---------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Testing queue class instance!!!" << endl << endl;
	QueueAsArray<double> q(10);
	q.getHeadEl();
	q.dequeue();
	for (int i = 1;i < 11;i++)
		q.enqueue((double)i * 3);
	q.enqueue(10.0);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Head element of stack is: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << q.getHeadEl() << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Is queue empty: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << (q.isEmpty() ? "true" : "false") << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Size of queue: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << q.getSize() << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Number of elements in the queue: ";
	SetConsoleTextAttribute(hConsole, 9);
	cout << q.numberOfElements() << endl;
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Queue elements are: ";
	SetConsoleTextAttribute(hConsole, 9);
	for (int i = 1;i < 11;i++)
		cout << q.dequeue() << " ";
	cout << endl << endl;
	SetConsoleTextAttribute(hConsole, 10);
	system("pause");
	system("cls");
};
void testSLList() {
	system("cls");
	//------------------------------------------------------------------------------------------------------------
	//testing sllist class//--------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Testing linked list class instance!!!" << endl << endl;
	SetConsoleTextAttribute(hConsole, 10);
	SLList<int> lista;
	lista.deleteFromHead();
	for (int i = 0;i < 12;i++)
		lista.addToHead((int)pow(-2, i));
	lista.printAll();
	lista.invertionSort();
	lista.printAll();
	lista.selectionSort();
	lista.deleteFromHead();
	lista.printAll();
	lista.invertionSort();
	lista.deleteEl(1);
	lista.printAll();
	lista.swap(64, 16);
	lista.printAll();
	lista.deleteFromHead();
	lista.deleteFromTail();
	lista.printAll();
	system("pause");
	system("cls");
}
void testHashTable() {
	system("cls");
	//------------------------------------------------------------------------------------------------------------
	//testing chained hash table class//--------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Testing chained hash table" << endl << endl;
	SetConsoleTextAttribute(hConsole, 10);
	int r = 9, r1 = 10, r2 = 11, r3 = 12;
	int *rec = &r, *rec1 = &r1, *rec2 = &r2, *rec3 = &r3;
	ChainedHashTable<int, int> cht(10);
	for (int i = 0;i < 10;i++) {
		cht.insert(new HashObj<int, int>(i, rec));
		cht.insert(new HashObj<int, int>(i, rec1));
		cht.insert(new HashObj<int, int>(i, rec2));
		cht.insert(new HashObj<int, int>(i, rec3));
	}
	cht.withdraw(8);
	cht.printAllRecords();
	cout << endl << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Two more" << endl << endl;
	SetConsoleTextAttribute(hConsole, 10);
	system("pause");
	system("cls");
	//------------------------------------------------------------------------------------------------------------
	//testing chained scatter table class//-----------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Testing Chained scatter table" << endl << endl;
	SetConsoleTextAttribute(hConsole, 10);
	ChainedScatterTable<int, int> cht2(10);
	for (int i = 0;i < 11;i++) {
		cht2.insert(ChainedScatterObject<int, int>(i, rec));
	}
	if (cht2.find(2) == NULL) {
	}
	else {
		cout << cht2.find(2) << endl;
		cht2.withdraw(2);
	}
	cht2.printAllRecords();
	cout << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "One more" << endl << endl;
	SetConsoleTextAttribute(hConsole, 10);
	system("pause");
	system("cls");
	//------------------------------------------------------------------------------------------------------------
	//testing open scatter hash table class//---------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Testing Open scatter table" << endl << endl;
	SetConsoleTextAttribute(hConsole, 10);
	OpenScatterTable<int, int> cht3(10);
	for (int i = 0;i < 10;i++) {
		cht3.insert(ScatterObj<int, int>(i, rec));
	}
	cht3.withdraw(11);
	cht3.withdraw(5);
	cht3.printAllRecords();
	system("pause");
	system("cls");
};
void testBSTree() {
	system("cls");
	//------------------------------------------------------------------------------------------------------------
	//testing binary search tree class//--------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Testing BSTree class" << endl << endl;
	SetConsoleTextAttribute(hConsole, 10);
	BSTree<int> stablo;
	if (stablo.isEmpty())
		cout << "It's empty!" << endl;
	for (int i = 0;i < 10;i++)
		stablo.insert(i);
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Preorder traversal of the tree nodes starting from root node: " << endl;
	SetConsoleTextAttribute(hConsole, 10);
	stablo.preorder();
	cout << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Inorder traversal of the tree nodes starting from root node: " << endl;
	SetConsoleTextAttribute(hConsole, 10);
	stablo.inorder();
	cout << endl;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Postorder traversal of the tree nodes  starting from root node: " << endl;
	SetConsoleTextAttribute(hConsole, 10);
	stablo.postorder();
	cout << endl;
	stablo.deleteByMergind(5);
	stablo.iterativePreorder();
	stablo.deleteByCopying(4);
	stablo.iterativeInorder();
	stablo.iterativePostorder();
	stablo.printNode(7);
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Inorder traversal of the tree nodes from specific node: " << endl;
	SetConsoleTextAttribute(hConsole, 10);
	stablo.inorder(stablo.search(6));
	cout << endl;
	stablo.breadthFirst();
	if (stablo.isInTree(5))
		cout << "It's in the tree!" << endl;
	else
		cout << "It's not in the tree!" << endl;
	int data[] = { 4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	BSTree<int> stablo2;
	stablo2.balance(data, 0, 13);
	stablo2.iterativeInorder();
	if (stablo2.isEmpty())
		cout << "It's empty!" << endl;
	else
		cout << "It's not empty!" << endl;
	stablo2.deleteByMergind(5);
	stablo2.iterativePreorder();
	stablo2.deleteByCopying(4);
	stablo2.iterativeInorder();
	system("pause");
	system("cls");
};
void testGraph() {
	system("cls");
	//------------------------------------------------------------------------------------------------------------
	//testing graph class//---------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------------
	GraphAsLists<string, int> graf;
	SetConsoleTextAttribute(hConsole, 6);
	cout << "Testing graph class instance!!!" << endl << endl;
	SetConsoleTextAttribute(hConsole, 10);
	//Inserting all nodes
	graf.insertNode("JFK");
	graf.insertNode("ATL");
	graf.insertNode("ORD");
	graf.insertNode("LAX");
	graf.insertNode("HKG");
	graf.insertNode("SFO");
	graf.insertNode("DFW");
	//Inserting connections, Edges
	graf.insertEdge("DFW", "ATL");
	graf.insertEdge("DFW", "HKG");
	graf.insertEdge("DFW", "SFO");
	graf.insertEdge("SFO", "ATL");
	graf.insertEdge("SFO", "HKG");
	graf.insertEdge("SFO", "DFW");
	graf.insertEdge("JFK", "ATL");
	graf.insertEdge("JFK", "HKG");
	graf.insertEdge("JFK", "LAX");
	graf.insertEdge("JFK", "ORD");
	graf.insertEdge("JFK", "DFW");
	graf.insertEdge("JFK", "SFO");
	graf.insertEdge("HKG", "JFK");
	graf.insertEdge("HKG", "ATL");
	graf.insertEdge("HKG", "ORD");
	graf.insertEdge("HKG", "LAX");
	graf.insertEdge("HKG", "SFO");
	graf.insertEdge("HKG", "DFW");
	graf.insertEdge("ATL", "SFO");
	graf.insertEdge("ATL", "ORD");
	graf.insertEdge("ORD", "LAX");
	graf.insertEdge("LAX", "DFW");
	graf.insertEdge("LAX", "ORD");
	graf.insertEdge("ORD", "ATL");
	graf.insertEdge("ATL", "JFK");
	graf.printGraph();
	graf.deleteNode("LAX");
	graf.deleteEdge("HKG", "ORD");
	cout << endl << "After deleting 'LAX' node:" << endl;
	graf.printGraph();
	long l = graf.breadthTrav("ORD");
	cout << endl << "Number of visited Nodes: " << l << endl;
	l = graf.depthTrav("HKG");
	cout << endl << "Number of visited Nodes: " << l << endl;
	l = graf.topologicalOrderTrav();
	cout << endl << "Number of visited Nodes: " << l << endl;
	LinkedNode<string, int> *e = graf.maxExitingLevel();
	graf.nullEdgeNodes();
	e = graf.maxInputLevel();
	long ll = graf.findPathBreadth("DFW", "JFK", NULL, NULL);
	system("pause");
	system("cls");
};

void main() {
	int test = 0;
	while (true) {
 		test = menu();
		switch (test) {
		case 1: {
			testStack();
		} break;
		case 2: {
			testQueue();
		} break;
		case 3: {
			testDeck();
		} break;
		case 4: {
			testSLList();
		} break;
		case 5: {
			testHashTable();
		} break;
		case 6: {
			testBSTree();
		} break;
		case 7: {
			testGraph();
		} break;
		}
		if (test < 1 || test > 7) {
			SetConsoleTextAttribute(hConsole, 4);
			cout << "You are exiting the test run and terminate the program!!!" << endl;
			SetConsoleTextAttribute(hConsole, 10);
			break;
		}
	}
	system("pause");

}