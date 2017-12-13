#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class File
{
public: 
	const int ARR_SIZE = 5;
	const char * filename = "numbers.txt";
	int val[5] = { 0 };

	void writeToFile()
	{
		ifstream inFile(filename);
		// Can also do inFile.open(filename);

		if (inFile.is_open())
		{
			string get_val;
			for (int i = 0; i < ARR_SIZE; i++)
			{
				inFile >> get_val;
				val[i] = stoi(get_val); // Convert string to int

			}
		}

		for (int i = 0; i < ARR_SIZE; i++)
		{
			cout << val[i] << endl;
			val[i] += val[i] / 2;

		}

		inFile.close();
	}
	void readInFile()
	{
		ofstream outFile(filename);
		if (outFile.is_open())
		{
			for (int i = 0; i < ARR_SIZE; i++)
			{
				outFile << val[i] << endl;

			}
			outFile.close();
		}
	}
};



int main()
{
	File test;
	test.writeToFile();
	test.readInFile();
	return 0;
}

