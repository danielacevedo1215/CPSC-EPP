#include <iostream>
#include <fstream>
using namespace std;

class Number
{
public:
	int intNum;
	double doubleNum;
	Number()
	{}
	~Number()
	{}
};

ostream& operator<<(ostream& OutStream, const Number& Number)
{
	OutStream << "Integer Variable: " << Number.intNum << "\nDouble Variable: " << Number.doubleNum << endl << endl;

	return OutStream;
}

int main()
{
	Number num1;
	Number num2;
	Number num3;
	Number num4;
	Number num5;
	Number readNum;

	ofstream outFile;
	ifstream inFile;
	//Ask user for numbers
	cout << "Enter 1st integer: ";
	cin >> num1.intNum;
	cout << "Enter 1st double: ";
	cin >> num1.doubleNum;


	cout << "Enter 2nd integer: ";
	cin >> num2.intNum;
	cout << "Enter 2nd double: ";
	cin >> num2.doubleNum;

	cout << "Enter 3rd integer: ";
	cin >> num3.intNum;
	cout << "Enter 3rd double: ";
	cin >> num3.doubleNum;

	cout << "Enter 4th integer: ";
	cin >> num4.intNum;
	cout << "Enter 4th double: ";
	cin >> num4.doubleNum;

	cout << "Enter 5th integer: ";
	cin >> num5.intNum;
	cout << "Enter 5th double: ";
	cin >> num5.doubleNum;
	cout << endl;
	//Read and write to a txt file
	outFile.open("Text.txt");
	if (outFile)
	{
		outFile << num1.intNum << endl;
		outFile << num1.doubleNum << endl;
		outFile << num2.intNum << endl;
		outFile << num2.doubleNum << endl;
		outFile << num3.intNum << endl;
		outFile << num3.doubleNum << endl;
		outFile << num4.intNum << endl;
		outFile << num4.doubleNum << endl;
		outFile << num5.intNum << endl;
		outFile << num5.doubleNum << endl;
	}
	else
	{
		cout << "Could not open file to write\n";
	}
	outFile.close();

	inFile.open("Text.txt", ios::binary);
	if (inFile)
	{
		inFile >> num1.intNum;
		inFile >> num1.doubleNum;
		inFile >> num2.intNum;
		inFile >> num2.doubleNum;
		inFile >> num3.intNum;
		inFile >> num3.doubleNum;
		inFile >> num4.intNum;
		inFile >> num4.doubleNum;
		inFile >> num5.intNum;
		inFile >> num5.doubleNum;
		cout << "Text.txt \n";
		cout << num1 << num2 << num3 << num4 << num5;

		inFile.close();
	}
	else
	{
		cout << "Could not open file to read\n";
	}
	//Read and write to a binary file
	outFile.open("Binary.bin", ios::binary);
	if (outFile)
	{

		outFile.write((char*)&num1, sizeof(Number));
		outFile.write((char*)&num2, sizeof(Number));
		outFile.write((char*)&num3, sizeof(Number));
		outFile.write((char*)&num4, sizeof(Number));
		outFile.write((char*)&num5, sizeof(Number));

		outFile.close();
	}
	else
	{
		cout << "Could not open file to write\n";
	}

	inFile.open("Binary.bin", ios::binary);
	if (inFile)
	{
		inFile.read((char*)&num1, sizeof(Number));
		inFile.read((char*)&num2, sizeof(Number));
		inFile.read((char*)&num3, sizeof(Number));
		inFile.read((char*)&num4, sizeof(Number));
		inFile.read((char*)&num5, sizeof(Number));
		cout << "Binary.bin \n";
		cout << num1 << num2 << num3 << num4 << num5;

		inFile.close();
	}
	else
	{
		cout << "Could not open file to read\n";
	}


	inFile.open("Binary.bin", ios::binary);
	if (inFile)
	{
		inFile.seekg(2 * sizeof(Number), inFile.beg);

		inFile.read((char*)&readNum, sizeof(Number));

		cout << "The third object in the file is: \n" << readNum;

		inFile.close();
	}
	else
	{
		cout << "Could not open file to seekg()\n";
	}
	return 0;
}

