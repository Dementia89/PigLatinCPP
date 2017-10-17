// PigLatin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

bool IsVowel(char ch);
string Rotate(string str);
string PigLatin(string str);
string PuncuationCheck(string str);

int main()
{
	string str;

	cout << "Enter a string: ";
	getline(cin, str);
	cout << endl;

	cout << "The pig latin form of " << str << " is " << PigLatin(str) << endl;

	cin.clear();
	cin.get();

    return 0;
}

bool IsVowel(char ch)
{
	switch (ch)
	{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'Y':
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
		{
			return true;
		}
		default:
		{
			return false;
		}
	}
}

string Rotate(string str)
{
	string::size_type len = str.length();

	return str.substr(1, len - 1) + str[0];
}

string PigLatin(string str)
{
	string::size_type len;

	bool foundvowel;

	string::size_type counter;

	if (IsVowel(str[0]))
	{
		str += "-way";
	}
	else
	{
		str += '-';
		str = Rotate(str);

		len = str.length();
		foundvowel = false;

		for (counter = 1; counter < len - 1; counter++)
		{
			if (IsVowel(str[0]))
			{
				foundvowel = true;
				break;
			}
			else
			{
				str = Rotate(str);
			}
		}

		if (!foundvowel)
		{
			str = str.substr(1, len) + "-way";
		}
		else
		{
			str += "ay";
		}
	}

	str = PuncuationCheck(str);

	return str;
}

string PuncuationCheck(string str)
{
	string::size_type len;

	len = str.length();

	char a;

	for (int i = 0; i < (int)len - 1; i++)
	{
		switch (str[i])
		{
		case ',':
		case '.':
		case '?':
		case ';':
		case ':':
		case '!':
			a = str[i];
			for (int j = i; j < (int)len - 1; j++)
			{
				str[j] = str[j + 1];
			}
			str[(int)len - 1] = a;
			break;
		default:
			break;
		}
	}

	return str;
}