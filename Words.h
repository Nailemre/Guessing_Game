#pragma once
#include<string>
#include<iostream>
#include"Dictionary.h"
using namespace std;
class Words:public Dictionary
{
public:    
	Words() {}; 
	//Default Constructor    
	~Words() {}; 
	//Destructor    
	// public interface to play game of Words   
	//it may call from main() using followings;    
	//main(){    
	//Words W;   
	 //W.playgame(W);    
	 //}    
	void playgame();
	string randomkelime;
private: 
// count functions compare string param with the secret word   
	 // find common letters in any order    
	int countofMatchLetters(string tahmin,string randoma);
	// find common letters in place    
	int countofTruePlaceLetters(string tahmin,string random);
	// track number of guesses used    
	int numguesses;     
	// flag set to true if cheat code is used    
	bool cheated;     
	// word to guess    
	string secret; 
};

