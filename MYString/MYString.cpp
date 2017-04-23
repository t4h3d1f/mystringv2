#include "MYString.h"
#include<iostream>

MYString::MYString()
{
	len = 0;
	cap = 20;
	str = new char[20];
	str[0] = '\0';
}

MYString::MYString(const char* in)
{
	while (in[len] != '\0')
	{
		len++;
	}
	len++;
	cap = ((len / 20) + 1) * 20;
	str = new char[cap];
	for (int i = 0; i < len; i++)
	{
		str[i] = in[i];

	}
}

MYString::MYString(const MYString & mstr)
{
	len = mstr.len;
	cap = mstr.cap;
	str = new char[cap];
	for (int i = 0; i < len; i++)
	{
		str[i] = mstr.str[i];
	}
}

int MYString::length()
{
	return len;
};

int MYString::capacity()
{
	return cap;
}

char MYString::operator [] (int index)
{
	char iChar = str[index];
	return iChar;
}

char* MYString::c_str()
{
	return str;
}

void MYString::operator = (const MYString& argStr)
{
	if (&argStr != this)
	{
		delete str;
		len = argStr.len;
		cap = argStr.cap;
		str = new char[cap];
		for (int i = 0; i < len; i++)
		{
			str[i] = argStr.str[i];
		}
	}
}

std::ostream& operator <<(std::ostream& ostr, const MYString& outString)
{
	ostr << outString.str;
	return ostr;
}

std::istream& operator >> (std::istream& istr, MYString& inString)
{
	char* readBuf = new char[100];
	istr >> readBuf;
	inString = MYString(readBuf);
	return istr;
}

bool MYString::operator <(const MYString& argStr)
{

	int sumDiff = 0;
	for (int i = 0; i < len; i++)
	{
		sumDiff = str[i] - argStr.str[i];
		if (sumDiff < 0)
			return true;
		else if (sumDiff > 0)
			return false;
	}
	return false;
}

bool MYString::operator >(const MYString& argStr)
{

	int sumDiff = 0;
	for (int i = 0; i < len; i++)
	{
		sumDiff = str[i] - argStr.str[i];
		if (sumDiff > 0)
			return true;
		else if (sumDiff < 0)
			return false;
	}
	return false;
}

bool MYString::operator ==(const MYString& argStr)
{

	int sumDiff = 0;
	if (len != argStr.len)
		return false;
	for (int i = 0; i < len; i++)
	{
		sumDiff = str[i] - argStr.str[i];
		if ((sumDiff == 0) && (i == len))
			return true;
	}
	return false;
}

MYString MYString::operator +(const MYString &argStr)
{
	int newLen = len + argStr.len;
	int tempCap = ((newLen / 20) + 1) * 20;
	char* tempStr = new char[tempCap];
	for (int i = 0; i < len; i++)
		tempStr[i] = str[i];
	for (int i = len - 1; i < newLen; i++)
		tempStr[i] = argStr.str[i - (len - 1)];
	MYString temp(tempStr);
	return temp;
}


MYString::~MYString()
{
	delete[] str;
}
