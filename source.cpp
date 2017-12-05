nclude "Header.h"
#include <iostream>
using namespace std;


int main() 
{
	NodeType * node = NULL;
	NodeType * currentPtr;
	char response;
	int loop = 1;

	do {
		//menu
		cout << endl;
		cout << "Please enter the letter that represents the function you would like to use: " << endl;
		cout << "I: Insert a node into the linked list " << endl;
		cout << "D: Delete the last node from the linked list " << endl;
		cout << "F: Find and Delete a node from the linked list " << endl;
		cout << "P: Print " << endl;
		cout << "R: Print in Reverse" << endl;
		cout << "Q: Quit" << endl;

		cin >> response;
		cout << endl;
		NodeType singlyList;

		//switch for options
		switch (response)
		{
			//This case asks the user to input a node they would like to insert into the linkedlist
		case 'I':
		case 'i': {
			int value;
			cout << "Please enter the digit you would like to enter:  " << endl;
			cin >> value;
			singlyList.insert(node, value);

			break;
		}
				  //This case deletes the last node in the list
		case 'D':
		case 'd': 
		{
			singlyList.deleteLast(node);
			if (node == NULL)
			{
				cout << "List is empty" << endl;//If the function returns false it outputs this
			}
			else 
			{
				singlyList.printList(node); //If the function returns true it will output this
			}
			break;
		}
				  //This case asks the user to input a number they would like to delete in the linked list
		case 'f':
		case 'F': {

			int value;
			cout << "Please enter a digit in the linked list you would like to delete " << endl;
			cin >> value;
			bool val = singlyList.findAndDelete(node, value);
			if (val == 0) {
				cout << "number not found" << endl;  //If the function returns false it outputs this
			}

			else {
				cout << "Number found and deleted:  " << endl; //If the function returns true it will output this
				singlyList.printList(node); //Print the new list with the deleted node
				cout << endl;
			}

			break;
		}
				  //This case asks the user what number they would like to search for
		case 'R':
		case 'r': {
			if (node == NULL) {
				cout << "List is empty" << endl;//If the function returns false it outputs this
			}

			singlyList.printListReverse(node);
			cout << endl << endl;

			break;

		}
				  //This case prints out the linked list
		case 'P':
		case 'p': {
			if (node == NULL) {
				cout << "List is empty" << endl;//If the function returns false it outputs this
			}
			singlyList.printList(node);
			cout << endl << endl;

			break;
		}
				  //This case quits the program
		case 'q':
		case 'Q':
		{
			loop = 0;
			break;
		}
		default:
			cout << "That is not a valid option" << endl;
		}
	} while (loop);
}
