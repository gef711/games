#include <iostream>
using namespace std;

int furbolgshealth=15;
int playershealth=15;
string reaction;
int damage;
int speed;

void combat()//сражение
{
	while (furbolgshealth>0 and playershealth>0)
	{
		cout<<"Furbolg's watching at you angrily. ";
		cout<<"Enter your action (hit): ";
		cin>>reaction;
		if (reaction=="hit")
		{
			cout<<"You hit furbolg."<<endl<<" Furbolg hits you."<<endl;
			damage=rand()%10;
			furbolgshealth-=damage;
			damage=rand()%10;
			playershealth-=damage;
			cout<<"Your health is "<<playershealth<<", furbolg's health is "
				<<furbolgshealth<<'.'<<endl;
		}
		else
		{
			cout<<"You miss furbolg."<<endl;
			damage=rand()%10;
			playershealth-=damage;
		}
	}
	if (playershealth>0) cout<<"Forbolg dies. You won."<<endl;
	else cout<<"You die. Furbolg won."<<endl;
}

void running()//побег, 50:50 или смерть, или удача
{
	speed=rand()%10;
	if (speed>25)
		cout<<"You manage to run away, furbolgs cries behind you."<<endl;
	else cout<<"Furbolg stabs you in the back, you die."<<endl;
}

void begging()//мольба
{
	cout<<"You beg the furbolg not to kill you. It looks at you scornfully."<<endl;
}

int main()
{
	cout<<"You're meet the furbolg."<<endl;
	cout<<"What will you do (fight/run/beg): ";
	getline (cin, reaction);
	if (reaction=="fight")
		combat();
	else if (reaction=="run")
		running();
	else if (reaction=="beg")
		begging();
	else cout<<"Furbolg doesn't understand you."<<endl;

	return 0;
}
