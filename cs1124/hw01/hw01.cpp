/*
Program: hw01.cpp
Purpose: Decrypt left shift Caesar ciphers. The first line of the file should be a number
representing the size of the shift. Will not touch capital letters or non-alphabetical characters.
Author: Daniel Wilkins
Date: 01/31/2015
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

char shift(const int& left_shift, char& character);
void decrypt(vector<string>& decrypted);

int main()
{
	vector<string> decrypted;

	decrypt(decrypted);

	for(int i = decrypted.size(); i > 0; i--)
	{
		cout << decrypted[i-1] << endl;
	}

	return 0;
}

char shift(const int& left_shift, char& character) //Returns one shifted character
{
	string alphabet = "abcdefghijklmnopqrstuvwxyz";  //Allows compatibility with any shift

	if(character >= alphabet[-left_shift])
	{
		character = (character + left_shift);	
	}
	else if(character >= alphabet[0] && character < alphabet[-left_shift])
	{
		character = (character + 26 + left_shift);
	}

	return character;
}

void decrypt(vector<string>& decrypted) //Reads file, calls shift() and stores decryped lines
{										//in vector
	ifstream ifs;
	const string encrypted = "encrypted.txt";
	string encrypted_line;
	string decrypted_line;

	ifs.open(encrypted);

	getline(ifs, encrypted_line);

	const int left_shift = -stoi(encrypted_line);		//Converts first line to int

	while(getline(ifs, encrypted_line))
	{
		for(int i = 0; i < encrypted_line.size(); i++)
		{
			decrypted_line += shift(left_shift, encrypted_line[i]);
		}

		decrypted.push_back(decrypted_line);	//Adds line to vector and empties string
		decrypted_line = "";
	}

	ifs.close();
}