#pragma once
class NodeType
{

public:
	NodeType(int = 0);  		// constructor with default value for
								// info field
	int info;                 	// data
	NodeType * nextPtr; 		// pointer to next node in the list

								//All the functions
	void insert(NodeType * &head, int value);
	void deleteLast(NodeType *&head);
	void printList(NodeType * head);
	bool findAndDelete(NodeType * &head, int num);
	void printListReverse(NodeType * node);
};
