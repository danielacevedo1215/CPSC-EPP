#pragma once
#include "Header.h"
#include <iostream>


using namespace std;

// Constructor
NodeType::NodeType(int data)
{
	info = data;
	nextPtr = 0;
}

//This Function inserts a node into the linkedlist AT THE END USING RECURSION
void NodeType::insert(NodeType * &node, int value) {

	if (node == NULL) 
	{
		NodeType * currentPtr = new NodeType; //creates new node
		currentPtr->info = value; //Assigns the value inputed by user to currentPtr->info
		node = currentPtr; //Assigns currentPtr to head.
	}

	else
		insert(node->nextPtr, value); //calls function again 
}

//This function print all the nodes in the linked list USING RECURSION
void NodeType::printList(NodeType * node) {
	if (node == NULL) { //prints "list is empty" if the head pointer is empty
		return;
		cout << "list is empty";
	}
	cout << node->info << " "; //prints each node every time the funtion is called
	NodeType::printList(node->nextPtr); //calls the funtion again using nextPtr as the parameter

}

//This function print all the nodes in the linked list REVERSE USING RECURSION
void NodeType::printListReverse(NodeType * node) 
{
	if (node == NULL) { //prints "list is empty" if the head pointer is empty
		return;
		cout << "list is empty";
	}

	NodeType::printListReverse(node->nextPtr); //calls function if node isnt NULL
	cout << node->info << " "; //prints out the node in order of the stack

}

//This function deletes only the LAST node in the linked list USING RECURSION
void NodeType::deleteLast(NodeType * &node)
{
	if (node == NULL) { //checks if node (head) is empty/NULL

	}

	else if (node->nextPtr == NULL) { //if not empty, it checks if the next pointer is NULL
		NodeType * temp = node; //creates a new node called temp and assigns node to it
		node = node->nextPtr; //assigns node->nextPtr to node
		delete temp; //Deletes the node temp was pointing to.

	}
	else if (node->nextPtr->nextPtr == NULL) { //checks if next->next pointer is NULL
		NodeType * temp = node->nextPtr; //creates new node called temp and assigns node-nextptr to it
		node->nextPtr = node->nextPtr->nextPtr; //assigns node->nextptr->nextptr to node->nextptr
		delete temp; //Deletes the node temp was pointing to.
	}

	else {

		NodeType::deleteLast(node->nextPtr); //calls funtion again if all if and else fail and checks node->nextPtr

	}
}




//This function searches for a node to delete then returns if it found the node or not (bool)
//RECURSION
bool NodeType::findAndDelete(NodeType * &node, int num) {
	NodeType * temp = node; //creates new node called temp and assigns node (head) to it

	if (node == NULL) { //checks if the first node is equal to NULL
		return false; //if it is then it returns false
	}

	else if (temp->info == num) { // Checks if the data temp->info is equal to the number inputted by user
		node = node->nextPtr; //node-> nextPtr is assigned to node(head) 
		delete temp; //deletes it
		return true; //returns true
	}
	else if (node->nextPtr == NULL) { //checks if node->nextPtr is equal to Null
		return false; //returns false if node->nextPtr==NULL
	}
	else if (node->nextPtr->info == num) {
		temp = node->nextPtr; //assigns node->next to Temp
		node->nextPtr = node->nextPtr->nextPtr; //assigns node->nextPtr->nextPtr to node->next
		delete temp; //deletes temp
		return true; //returns true
	}


	else {
		findAndDelete(node->nextPtr, num);//calls the function again if the rest failed
	}
}
