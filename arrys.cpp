#include <iostream>
using namespace std;

class Compound
{
public: 
	void getData();
	void makeCompound(char[10], int, char[10] ,int , char[20] ,int );

	char arr1[10];
	char arr2[10];
	char arr3[20];
	int lenghtOfArr1;
	int lenghtOfArr2;
	int lenghtOfArr3;
private:
};

void Compound::makeCompound(char arr1[10], int lenghtOfArr1, char arr2[10], int lenghtOfArr2, char arr3[20], int lenghtOfArr3)
{
	char temp[15];
	cout << "1st word: ";
	for (int i = 0; i <= lenghtOfArr1; i++)
	{
		cout << arr1[i];
	}
	cout << endl;
	cout << "2nd word: ";
	for (int i = 0; i <= lenghtOfArr2; i++)
	{
		cout << arr2[i];
	}
	cout << endl;
	cout << "Compound word: ";
	arr3 =+ arr1;
	arr3 =+ arr2;
	for (int j = 0; j <= lenghtOfArr2; j++)
	{
		cout << arr3[j];
	}
}

void Compound::getData()
{
	cout << "Enter word: ";
	for (int i = 0; i <= 10; i++)
	{
		cin >> arr1[i];
	}
	cout << "Enter 2nd word: ";
	for (int i = 0; i <= 10; i++)
	{
		cin >> arr2[i];
	}
}



int main()
{
	Compound C;
	C.getData();
	C.makeCompound(C.arr1, 10, C.arr2, 10, C.arr3, 20);
	return 0;
}
