////
//Author: Thoomas Allen
//Section: S
//Program name: Program 3
//Description: Reads in the contents of the entered by the user. Collects words
//into groups of five words. Sorts groups by ascii value and displays result in 
//ascending order. appends length of string and capacity to end of the string's 
//console output.
////

#include "stdafx.h"
#include "MYString.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>

using namespace std;

int main()
{

	vector<MYString> strVec;
	cout << "Enter filename: \n";
	MYString fileStr;
	cin >> fileStr;
	fstream fin;
	fin.open(fileStr.c_str());
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			MYString tempStr;
			fin >> tempStr;
			strVec.push_back(tempStr);
		}
		fin.close();
	}
	else
	{
		cout << "\nInvalid filename\n";
		system("pause");
		return 1;
	}
	int vecLen = strVec.size() - 1;
	int index = 0;
	vector<MYString> compressedStr;
	while (index < (vecLen - 5))
	{
		compressedStr.push_back(strVec[index] + strVec[index + 1] +
			strVec[index + 2] + strVec[index + 3] + strVec[index + 4]);
		index = index + 5;
	}
	switch ((vecLen - index) % 5)
	{
	case 1:
	{
		compressedStr.push_back(strVec[index] + strVec[index + 1]);
		break;
	}
	case 2:
	{
		compressedStr.push_back(strVec[index] + strVec[index + 1] +
			strVec[index + 2]);
		break;
	}
	case 3:
	{
		compressedStr.push_back(strVec[index] + strVec[index + 1] +
			strVec[index + 2] + strVec[index + 3]);
		break;
	}
	case 4:
	{
		compressedStr.push_back(strVec[index] + strVec[index + 1] +
			strVec[index + 2] + strVec[index + 3] + strVec[index + 4]);
		break;
	}
	default:
	{
		compressedStr.push_back(strVec[index]);
		break;
	}
	}
	cout << "\n";
	for (int i = 0; i < compressedStr.size(); i++)
		cout << compressedStr[i] << "\n";
	cout << "\n\n";
	for (int i = 0; i < compressedStr.size(); i++)
	{
		for (int j = 1; j < compressedStr.size(); j++)
		{
			if (compressedStr[j - 1] > compressedStr[j])
			{
				MYString tempStr(compressedStr[j]);
				compressedStr[j] = compressedStr[j - 1];
				compressedStr[j - 1] = tempStr;
			}
		}
	}
	for (int i = 0; i < compressedStr.size(); i++)
		cout << setw(35) << left << compressedStr[i] << compressedStr[i].length() <<
		":" << compressedStr[i].capacity() << "\n";
	system("pause");
}


