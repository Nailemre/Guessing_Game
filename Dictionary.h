#pragma once
#include <iostream>
#include <fstream>
#include<string>
#include<set>
#include<vector>
#include <stdlib.h>
#include<unordered_map>
#include<algorithm>
#include<iterator>
#include<time.h>
using namespace std;
using std::string;

class  Dictionary
{
public:
	
	//Default Constructor    
	Dictionary();    
	//opens file and assign all words into set<string> words;    
	Dictionary(char *filename);    
	//Destructor  
	~Dictionary();   
	// return a random word (without repeated letters)     
	string BringValidWord();
	// check if word is in Dictionary   
bool IsWordValid(string word); 

 string RandomWord;
vector<string>wordsvector;
private:   
	// test if n. word has only unique letters   
	bool TestLegalSecretWord(string word);    
	
	set<string> words;
	vector<string> secrets;
};

