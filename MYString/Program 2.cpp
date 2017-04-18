////
//Author: Thoomas Allen
//Section: S
//Program name: Program 2
//Description: Reads in the contents of the file "infile2" and sorts the words
//from smallest to largest based on their ascii value. displays the formatted 
//output in blocks of 7 words. Only works with files containing 100 or less
//words. Prints to a file called outfile.txt
////

#include "stdafx.h"
#include "MYString.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>

using namespace std;

vector<MYString> strVec(100);


int main()
{
	ifstream inFile;
	inFile.open("infile2.txt");
	if (inFile.is_open())
	{

		int index = 0;
		while (!inFile.eof())
		{
			strVec[index].read(inFile);
			index++;
		}
		inFile.close();
		strVec.resize(index);
	}
	else
	{
		cout << "Error reading file\n";
		system("pause");
		return 1;
	}
	for (int i = 0; i < strVec.size(); i++)
	{
		for (int j = 1; j < strVec.size(); j++)
		{
			if (strVec[j - 1].compareTo(strVec[j]) > 0)
			{
				MYString tempStr = *new MYString;
				tempStr.setEqualTo(strVec[j]);
				strVec[j].setEqualTo(strVec[j - 1]);
				strVec[j - 1].setEqualTo(tempStr);
			}
		}
	}
	cout << setw(10);
	for (int i = 0; i < strVec.size(); i++)
	{
		strVec[i].write(cout);
		if ((i % 7 == 0) && (i != 0))
			cout << endl;
	}
	cout << endl;
	ofstream outFile("outfile.txt");
	outFile << setw(10);
	for (int i = 0; i < strVec.size(); i++)
	{
		strVec[i].write(outFile);
		if ((i % 7 == 0) && (i != 0))
			outFile << endl;
	}
	outFile << endl;
	outFile.close();
	system("pause");
}

