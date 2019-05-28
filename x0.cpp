#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;
void main()
{
	int ar[3][3], xod=0;
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
		ar[i][j]=0;
	COORD start,cord;
	HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
	start.X=0;cord.X=1;
	start.Y=0;cord.Y=1;
	     while(1)
		 {
		   SetConsoleCursorPosition(hout,start);

		   for(int y=0;y<7;y++)
		   {
			   for(int x=0;x<7;x++)
			   {
				   if(y==0&&x==0)
					   cout<<(char)218;
				   else if(y==0&&x==6)
					   cout<<(char)191;
				   else if(y==6&&x==0)
					   cout<<(char)192;
				   else if(y==6&&x==6)
					   cout<<(char)217;
				   else if(y%2==0&&x==0)
					   cout<<(char)195;
				   else if(y==0&&x%2==0)
					   cout<<(char)194;
				   else if(y==6&&x%2==0)
					   cout<<(char)193;
				   else if(y%2==0&&x==6)
					   cout<<(char)180;
				   else if(y%2==0&&x%2==0)
					   cout<<(char)197;
				   else if(x%2==0)
					   cout<<(char)179;
				   else if(y%2==0)
					   cout<<(char)196;
				   else
				   {
					   int t=ar[y/2][x/2];
					   if (t==0)cout<<" ";
					   else if (t==1)cout<<"X";
					   else if (t==2)cout<<"O";
				   }
			   }
			   cout<<"\n";
		   }
		   SetConsoleCursorPosition(hout,cord);
		   
		   int a=_getch();
		    if(a=224)
				a=_getch();
			if(a==75&&cord.X>2)
				cord.X-=2;
			else if(a==77&cord.X<5)
				cord.X+=2;
			else if(a==75&&cord.Y>2)
				cord.Y-=2;
			else if(a==77&cord.Y<5)
				cord.Y+=2;
			if(a==13)
			{
				if(ar[cord.Y/2][cord.X/2]==0)
				{
					if(xod%2==0)
						ar[cord.Y/2][cord.X/2]=1;
					else
						ar[cord.Y/2][cord.X/2]=2;
					xod++;
					system("cls");
					//proverka
				}
			}
		 }
}