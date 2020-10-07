#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
	char traveler; int length, speed;
	cout<<"Be careful, this program will clear terminal once all data are entered!\n";
	cout<<"Enter symbol, which will travel through dots: ";
	cin>>traveler;
	cout<<"Enter length of path: ";
	cin>>length;
	cout<<"Enter speed (sec per dot) of traveling: ";
	cin>>speed;

	system("clear");
	char a[length];
	int i,j;
	for (i=0;i<length;i++) a[i]='.';
	for (i=0;i<length;i++)
	{
		a[i]=traveler;//присвоение значения 'traveler' кажому символу массива по очереди
		for (j=0;j<length;j++)
			cout<<a[j]<<flush;//вывод массива с измененным элементом
		a[i]='.';//присвоение элементу со значением 'traveler' обратно значения '.'
		sleep(speed);
		system("clear");
	}
}
