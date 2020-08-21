#include "Dictionary.h"
#include "Words.h"

using namespace std;

int main()
{
	cout << "Bil Bakalim Oyununa Hosgeldiniz:" << endl;
	cout << "5 harften olusan bir kelime tuttum." << endl;
	
	Words*play=new Words();

	play->playgame();

	system("pause");
	return 0;
}