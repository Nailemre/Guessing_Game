#include "Words.h"
using namespace std;


void Words::playgame()
{
	
	char wordstxt[30] = "words.txt";
	string tahmin;
	Words* p = new Words();
	Dictionary* dic = new Dictionary(wordstxt);
	string randomkelime = dic->BringValidWord();
	numguesses = 1;
	for (;;)
	{
		cout << "Tahmininiz nedir: ";
		getline(cin, tahmin);
		bool flug = dic->IsWordValid(tahmin);
		if (tahmin == "xxxxx")
		{
			dic->wordsvector.push_back("xxxxx");
			cout << "Gizli kelime: " << randomkelime<<endl;
			//numguesses++;
		}
		if (flug == false )
		{
			if(tahmin == "xxxxx"){}
			else{ cout << "Bu kelime sozlukte yok" << endl; }
			
			
		}
		else
		{
			cout << "Eslesen harf sayisi: " << p->countofMatchLetters(tahmin, randomkelime) << endl;
			cout << "Eslesen harflerin dogru konumu: " << p->countofTruePlaceLetters(tahmin, randomkelime) << endl;
		}
		if (p->countofMatchLetters(tahmin, randomkelime) == 5 && p->countofTruePlaceLetters(tahmin, randomkelime) == 5)
		{
			cout << "Bildiniz!" << numguesses << " tahminde dogru sonuca ulastiniz!" << endl;
			exit(0);
		}
		else
		{
			numguesses++;
		}
	}
	
}


int Words::countofMatchLetters(string tahmin,string randoma)
{
	
	string RandomWord = Dictionary::BringValidWord();
	char tahminkýyas[5];
	char random[6];
	unordered_map<char, int>m1;
	for (int i = 0; i < 5; i++)
	{
		m1[tahmin[i]]++;
	}
	int j = 0;
	for (auto it : m1) {
		tahminkýyas[j] = it.first;
		j++;
	}

	strcpy_s(random, randoma.c_str());

	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (tahminkýyas[i] == random[j])
			{
				count++;
			}
		}
	}
	return count;
}

int Words::countofTruePlaceLetters(string tahmin,string random)
{
	//char random[5];
	//strcpy_s(random, RandomWord.c_str());
	int count = 0;
	for (int i = 0;i < 5;i++)
	{
		if (tahmin[i] == random[i])
		{
			count++;
		}
	}
	return count;
}
