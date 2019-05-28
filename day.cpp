// day.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
# include <iostream>
#include <conio.h>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	// дата рождения отца
	int iDayF, iMonthF, iYearF;
	// дата рождения сына
	int iDayS, iMonthS, iYearS;

	int difDay = 0;

	iDayF = iMonthF = iYearF = 0;
	iDayS = iMonthS = iYearS = 0;

	// ввод даты рождения
	cout << "\tEnter date of father birth (dd mm yyyy):\n\n\t";
	cin >> iDayF >> iMonthF >> iYearF;

	// проверка даты рождения на корректность (начало)
	if (iYearF < 1900)
	{
		cout << "\n\n\tError! Wrong year of birth!!\n\n";
		_getch();
		return 13;
	}
	else if (iMonthF < 1 || iMonthF > 12)
	{
		cout << "\n\n\tError! Wrong month of birth!!\n\n";
		_getch();
		return 13;
	}
	else if (iDayF < 1 || iDayF > 31)
	{
		cout << "\n\n\tError! Wrong day of birth!!\n\n";
		_getch();
		return 13;
	}

	// ввод даты рождения
	cout << "\tEnter date of son birth (dd mm yyyy):\n\n\t";
	cin >> iDayS >> iMonthS >> iYearS;

	// проверка даты рождения на корректность (начало)
	if (iYearS < 1900)
	{
		cout << "\n\n\tError! Wrong year of birth!!\n\n";
		_getch();
		return 13;
	}
	else if (iMonthS < 1 || iMonthS > 12)
	{
		cout << "\n\n\tError! Wrong month of birth!!\n\n";
		_getch();
		return 13;
	}
	else if (iDayS < 1 || iDayS > 31)
	{
		cout << "\n\n\tError! Wrong day of birth!!\n\n";
		_getch();
		return 13;
	}

	int iDayYear = 0;

		bool lYear = false;
		if (iYearF % 4 ==0 && iYearF % 100 !=0 && iYearF % 400 !=0)
			lYear = true;
		else if (iYearF % 4 ==0 && iYearF % 100 ==0 && iYearF % 400 ==0)
			lYear = true;

		int shift = 0;
		if (lYear == true )
		{
			if ( (iMonthF == 1)  || (iMonthF == 2 && iDayF < 29))
			  shift = 1;
		}

		for (int i  = iYearF + 1 ; i <= iYearS  ; i++)
		{
			bool lYear = false;
			if (i % 4 == 0 && i % 100 !=0 && i % 400 !=0)
				lYear = true;
			else if (i % 4 ==0 && i % 100 ==0 && i % 400 ==0)
				lYear = true;

            if (lYear  && (i == iYearS) &&( (iMonthF > 2)  || (iMonthF == 2 && iDayF > 28)))
			{
               iDayYear += 366;
			}
			else if ((shift == 1) && (i == iYearF + 1) )
			{
				 iDayYear += 366;
			}
			if (lYear  && (i == iYearS) &&( (iMonthF < 2)  || (iMonthF == 2 && iDayF < 29)))
			{
               iDayYear += 365;
			}
			else if (lYear == true)
				iDayYear += 366;
			else
				iDayYear += 365;
		}

    iDayYear += shift;
	int difDays = 0;
	bool lYearS = false;

	if (iYearS % 4 ==0 && iYearS % 100 !=0 && iYearS % 400 !=0)
		lYearS = true;
	else if (iYearS % 4 ==0 && iYearS % 100 ==0 && iYearS % 400 ==0)
		lYearS = true;

	if ( iMonthS > iMonthF || (iMonthS == iMonthF && iDayS >= iDayF))
		{
			if (iMonthS - iMonthF > 1)
			{
				for (int i = iMonthF ; i < iMonthS; i++ )
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
						difDays += 31;
					else if (i == 4 || i == 6 || i == 9 || i == 11)
						difDays += 30;
					else if (i == 2 )
					{
						if (lYearS == true)
							difDays += 29;
						else
							difDays += 28;
					}
				}
				difDays += iDayS - iDayF;
			}
			else if (iMonthS > iMonthF )
			{
				if (iMonthF == 1 || iMonthF == 3 || iMonthF == 5 || iMonthF == 7 || iMonthF == 8 || iMonthF == 10 || iMonthF == 12)
					difDays += 31 - iDayF;
				else if (iMonthF == 4 || iMonthF == 6 || iMonthF == 9 || iMonthF == 11)
					difDays += 30 - iDayF;
				else if (iMonthF == 2)
				{
					if (lYearS == true)
						difDays += 29 - iDayF;
					else 
						difDays += 28 - iDayF;
				}
				difDays += iDayS;
			}
			else if (iMonthS == iMonthF)
			{
			   difDays += iDayS - iDayF;
			}
		}
		else if ( iMonthS < iMonthF || (iMonthS == iMonthF && iDayS <= iDayF))
		{
			if (iMonthF - iMonthS > 1)
			{
				for (int i = iMonthS ; i < iMonthF; i++ )
				{
					if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
						difDays += 31;
					else if (i == 4 || i == 6 || i == 9 || i == 11)
						difDays += 30;
					else if (i == 2 )
					{
						if (lYearS == true)
							difDays += 29;
						else
							difDays += 28;
					}
				}
				difDays += iDayF - iDayS;
			}
			else if (iMonthF > iMonthS )
			{
				if (iMonthS == 1 || iMonthS == 3 || iMonthS == 5 || iMonthS == 7 || iMonthS == 8 || iMonthS == 10 || iMonthS == 12)
					difDays += 31 - iDayS;
				else if (iMonthS == 4 || iMonthS == 6 || iMonthS == 9 || iMonthS == 11)
					difDays += 30 - iDayS;
				else if (iMonthF == 2)
				{
					if (lYearS ==  true)
						difDays += 29 - iDayS;
					else 
						difDays += 28 - iDayS;
				}
				difDays += iDayF;
			}
			
			else if (iMonthS == iMonthF)
			{
			   difDays += iDayF - iDayS;
			}
		}
		difDays += iDayYear;
		cout << "\n\n\t Difference days is " << difDays << "\n";
		_getch();
		return 0;

}

