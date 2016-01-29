/*
Program: counter.cpp
Purpose: Count the number of lines, words, and characters in an input file
Author: Daniel Wilkins
Date: 01/28/2015
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int line_count(ifstream& ifs, const string& filename);
int word_count(ifstream& ifs, const string& filename);
int distinct_word_count(ifstream& ifs, const string& filename);
int char_count(ifstream& ifs, const string& filename);


int main()
{
	string filename;
	cout << "Enter filename: ";
	cin >> filename;

	ifstream ifs;

	if(!ifs)
	{
		cerr << "File not found" << endl;
		exit(1);
	}

	cout << "Line count: " << line_count(ifs, filename) << endl;
	cout << "Word count: " << word_count(ifs, filename) << endl;
	cout << "Distinct word count: " << distinct_word_count(ifs, filename) << endl;
	cout << "Character count: " << char_count(ifs, filename) << endl;

	return 0;
}

int line_count(ifstream& ifs, const string& filename)			//Counts number of lines in file
{
	ifs.open(filename);

	string line;
	int line_count = 0;

	while(getline(ifs, line))
	{
		line_count++;
	}

	ifs.close();

	return line_count;
}

int word_count(ifstream& ifs, const string& filename)			//Counts number of words in file
{
	ifs.open(filename);

	string word;
	int word_count = 0;

	while(ifs >> word)
	{
		word_count++;
	}

	ifs.close();

	return word_count;
}

int distinct_word_count(ifstream& ifs, const string& filename)	//Filters repeated words from word count
{
	ifs.open(filename);

	string word;
	vector<string> distinct_words;
	bool distinct;

	while(ifs >> word)
	{	
		distinct = true;

		for(int i = 0; i < distinct_words.size(); i++) 	//Checks if word appeared earlier
		{												
			if(word == distinct_words[i])				//If it did, it is not distinct
			{											
				distinct = false;
			}
		}

		if(distinct == true)
		{
			distinct_words.push_back(word);				//If the word is distinct, adds to list
		}
	}

	ifs.close();

	return distinct_words.size();
}

int char_count(ifstream& ifs,const string& filename)	//Counts number of characters in file
{
	ifs.open(filename);

	char character;
	int char_count = 0;

	while(ifs >> skipws >> character)					//Option to include or skip whitespace chars
	{
		char_count++;
	}

	ifs.close();

	return char_count;
}