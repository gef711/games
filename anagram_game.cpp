#include <iostream>
#include <unistd.h>//для rand
#include <algorithm>//для random_shuffle
#include <fstream>//для работы с файлами
using namespace std;

void separator()
{
	cout<<"----------"<<endl;
}

int main()
{
	srand(time(NULL));
	string  word[1000];//массив слов из input
	int i=0;//счетчик
	int j;
	int wordscount=0;//количество слов

	ifstream file ("/home/gef711/input_500_words");//открываем файл в конструкторе
	while (getline(file, word[i]) and wordscount<500)//запись данных из файла в массив
	{
		i++;
		wordscount++;
	}
	
	bool nomistakes=true;//отметка отсутствия ошибок
	string originalword;//слово для чтения
        int timestart, timeend;//переменные для времени начала и конца выполнения задания
        int timedifference=0;//переменная для end-start
	string wordanagram;//переменная для слова-анаграммы


	for (j=0; j<5; j++)//переменная i уже используется в теле цикла, поэтому еe не получится использовать в условии цикла :D
	{
		string word2=word[rand()%wordscount];//присвоение случайного слова переменной string word2
	
		string wordletters[word2.size()];
		for (i=0; i<word2.size(); i++)//присвоение массиву букв значений букв слова
			wordletters[i]=(char)word2[i];

		random_shuffle(wordletters, wordletters+word2.size());//смешивание букв wordletters
		
		wordanagram="";
		for (i=0; i<word2.size(); i++)//запись отдельных букв в переменную
		{
			wordanagram+=wordletters[i];
		}
		
		separator();
		cout<<"Anagram: "<<wordanagram<<"."<<endl<<"Enter original word (enter ? to show original word):"<<endl;
		timestart=time(NULL);//время начала выполнения задания
		getline(cin, originalword);//чтение слова
		timeend=time(NULL);//время завершения выполнения задания
		if (originalword!=word2 and originalword!="?")
		{
			cout<<"Incorrect."<<endl;
			nomistakes=false;//ставим метку, что ошибка в серии заданий была
		}
		else if (originalword==word2)
		{
			timedifference+=timeend-timestart;//время, затраченное на выполнение задания
			cout<<"Success!"<<endl;
			cout<<"You did "<<j+1<<" task in "<<timeend-timestart<<" seconds."<<endl;

		}
		else if (originalword=="?")
		{
			cout<<"Original word: "<<word2<<endl;
			nomistakes=false;
		}
	}

		if (nomistakes==true)
		{
			separator();
			cout<<"You did everything right! Your time is "<<timedifference<<" seconds."<<endl;
			separator();
		}
		else if (nomistakes==false)
		{
			separator();
			cout<<"You did at least one mistake. May be another time."<<endl;
			separator();
		}
}
