#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node * next;
};

int getValue()
{
	int value;
	cin >> value;
	return value;
}

void getData(Node *& head, int size)
{
	Node * temp = new Node;
	cout << "Enter a number ";
	temp->data = getValue();
	temp->next = head;
	head = temp;
}

void print(Node *& head)
{
	Node * temp = new Node;
	temp = head;
	if (head != NULL)
	{
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	else
	{
		cout << "list is empty \n";
	}
	cout << endl;
}

Node moveRight(Node *& head)
{
	Node* temp = head;
	int count = 1;
	//Pointing temp to the kth node
	while (count<1 && temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	//If it is NULL then dont rotate
	if (temp == NULL)
	{
		return *head;
	}
	//point KthNode to temp
	Node* KthNode = temp;
	//Move temp to the last node
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	//point next of temp to the head
	temp->next = head;
	//change head to the next of Kth node
	head = KthNode->next;
	//Point next of KthNode to NULL
	KthNode->next = NULL;
	return *head;
}

void printReverse(Node * head)
{
	if (head == NULL)
	{
		cout << "list is empty \n";
	}
	else
	{
		printReverse(head->next);
		cout << head->data << " ";
	}
	cout << endl;
}

int main()
{
	Node *root = NULL;
	Node headRotated;
	char choice = NULL;
	while (choice != 'q')
	{
		cout << "-----Menu-----\n";
		cout << "a. Add to list\n";
		cout << "b. Print\n";
		cout << "c. Move right\n";
		cout << "d. Print in reverse\n";
		cout << "q. Quit\n";
		cin >> choice;

		switch (choice)
		{
		case 'a': getData(root, 6); break;
		case 'b': print(root); break;
		case 'c': headRotated = moveRight(root); break;
		case 'd': printReverse(root); break;
		default:
			break;
		}
	}
	return 0;
}
