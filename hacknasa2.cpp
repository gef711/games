#include <iostream>
#include <unistd.h>
using namespace std;

void dots()//dots function
{
	for (int i=0; i<3; i++)
	{
		cout<<'.'<<flush;
		sleep(1);
	}
	cout<<endl;
}


int main()
{
	srand(time(NULL));//random for luck
	cout<<"Do you want to hack NASA (y/n): ";
	char re;//reaction
	cin>>re;
	int luck=rand()%100;//random luck
	if (re=='y' and luck>50)//successful hacking
	{
		for (int perc=0; perc<=100; perc+=25)//full percentage
		{
			cout<<"Hacking NASA "<<perc<<" %"<<flush;
			dots();
		}
		cout<<"Done."<<endl;
	}
	else if (re=='y' and luck<50)//bad luck
	{
		int det_perc=rand()&100;
		for (int perc=0; perc<=det_perc; perc+=25)//hacking till random percentage
		{
			cout<<"Hacking NASA "<<perc<<" %"<<flush;
			dots();
		}
		cout<<"You were detected! FBI helicopter with orcs and trolls is set out to kick your ass."<<endl;
	}
	else if (re=='y' and luck==50) cout<<"God is descended upon your house to tell you that cracking government's sites is bad."<<endl;//luck is 50
	else if (re=='n') cout<<"Quiting..."<<endl;//reaction is no
	else cout<<"Incorrect input, try again."<<endl;//other reaction
}
