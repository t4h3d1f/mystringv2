#pragma once
#include<iostream>
//Description: MYString performs all the functions of a standard string class.
//This class can: create, read, write, compare, and replace strings.
//the class also has an at() function which returns a character at the index 
//location given in the function call.
class MYString
{
public:
	//Default constructor. will give you an empty string with a 
	//capacity of 20 characters.
	MYString();
	
	//default copy constructor
	MYString::MYString(const MYString& mstr);
	
	//Overloaded constructor, will construct a string by using the character
	//pointer given in the constructor call. 
	MYString(const char*);
	
	//returns the length of the string
	int MYString::length();
	
	//returns the capacity of the string (increases in blocks of 20)
	int MYString::capacity();
	
	//returns the character at the index location given
	char MYString::operator [] (int index);
	
	//returns a pointer to the character array, works with cout
	char* MYString::c_str();
	
	//replace the contents of the string with the contents of the
	//given string
	void MYString::operator = (const MYString &argStr);
	
	//writes the string to the given ostream. can write to console 
	//or file.
	friend std::ostream& operator << (std::ostream& ostr, const MYString& outString);
	
	//reads from the given istream. can read from files or console.
	friend std::istream& operator >>(std::istream& istr, MYString& inString);
	
	//compares this string to the contents of another string. 
	int MYString::compareTo(const MYString& argStr);
	
	//destructor. cleans up after the function is no longer needed.
	MYString MYString::operator +(const MYString &argStr);
	~MYString();
private:
	int len = 0;
	int cap = 20;
	char* str;
};
