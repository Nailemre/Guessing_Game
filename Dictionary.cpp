#include "Dictionary.h"

using namespace std;
Dictionary::Dictionary()
{


}

Dictionary::Dictionary(char * filename)
{
	unordered_map<char, int>freq;
	fstream dataFile;
	string tmp;
	
	string buffer;

	// dosya okunuyor
	dataFile.open(filename, std::fstream::in);
	if (!dataFile)
	{
		cout << "File open error!" << endl;
		exit(0);
	}
	else
	{
		//cout << "File opened successfully!" << endl;

		dataFile >> tmp;
		while (!dataFile.eof())
		{
			words.insert(tmp);
			dataFile >> tmp;
		}
		
	}
	

	//string vectöre çeviriliyor
	wordsvector.assign(words.begin(), words.end());
	// wordsvector içindeki tüm kelimeler filtreden geçirildi geriye kalan kelimeler secrets vectörüne kopyalandý
	string temp;
	
	for (int i = 0; i < wordsvector.size(); i++)
	{

		temp = wordsvector[i];

		for (int j = 0;j < temp.size();j++)
		{
			freq[temp[j]]++;
		}

		if (freq[temp[0]] == 1 && freq[temp[1]] == 1 && freq[temp[2]] == 1 && freq[temp[3]] == 1 && freq[temp[4]] == 1)
		{
			secrets.push_back(temp);
		}
		for (int k = 0;k < 5;k++) 
		{
			freq[temp[k]] = 0;
		}
	}
	
	/*for (int i = 0; i < secrets.size(); i++)
	{
		
		cout << secrets[i] << "\n";
	}*/

	// Filtrelenmiþ kelimelerden random bir kelime seçiliyor
	unsigned srand(time(NULL));
	int randomSelect = rand() % 1629;
	
	RandomWord = secrets[randomSelect];
	
}

Dictionary::~Dictionary()

{

}


string Dictionary::BringValidWord()
{
	
	return RandomWord;
}

bool Dictionary::IsWordValid(string word)
{
	string gizli = "xxxxx";
	for (int i = 0;i < wordsvector.size();i++)
	{
		if (!wordsvector[i].compare(gizli))
		{
			return true;
		}
		if (!wordsvector[i].compare(word))
		{
			//cout << "Kelime Mevcut";
			return true;
		}
		
		
	}
	for (int i = 0;i < wordsvector.size();i++)
	{

		
		if (wordsvector[i].compare(word))
		{
			//cout << "Kelime Mevcut degil";

		}
		return false;
	}
	
}

bool Dictionary::TestLegalSecretWord(string word)
{
	return false;
}
	
