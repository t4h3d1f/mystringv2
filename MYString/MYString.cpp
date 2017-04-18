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

int MYString::length()
{
	return len;
};

int MYString::capacity()
{
	return cap;
}

char MYString::at(int index)
{
	if ((index > cap) && (index >= 0))
		return '\0';
	char iChar = str[index];
	return iChar;
}
char* MYString::c_str()
{
	return str;
}

void MYString::setEqualTo(const MYString& argStr)
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

void MYString::write(std::ostream& ostr)
{
	for (int i = 0; i < len; i++)
		ostr << str[i];
}

bool MYString::read(std::istream& istr)
{
	char* readBuf = new char[100];
	istr >> readBuf;
	len = 0;
	while (readBuf[len - 1] != '\0')
	{
		len++;
	}
	cap = ((len / 20) + 1) * 20;
	str = new char[cap];
	for (int i = 0; i < len; i++)
	{
		str[i] = readBuf[i];
	}
	delete readBuf;
	return true;
}

int MYString::compareTo(const MYString& argStr)
{

	int sumDiff = 0;
	for (int i = 0; i < len; i++)
	{
		sumDiff = str[i] - argStr.str[i];
		if (sumDiff != 0)
			return sumDiff;
	}
	return 0;
}

MYString::~MYString()
{
	delete[] str;
}
