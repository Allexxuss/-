// TestC++.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void shorted(vector<int> & ret);

vector<int> sum(const vector<int> & one, const vector<int> & two)
{
	
	int length = max(one.size(), two.size());
    vector<int> x_ext(length, 0 );
	vector<int> y_ext(length, 0);
	vector<int> x;
	x.assign(one.begin(), one.end());
	vector<int> y;
	y.assign(two.begin(), two.end());

	for (int i = 0; i < x.size(); ++i)
	{
		x_ext[i] = x[i];
	}
	for (int i = 0; i < y.size(); ++i)
	{
		y_ext[i] = y[i];
	}
	vector<int> Sum(length + 1 , 0);
	for (int i = 0; i < length; ++i)
	{
		Sum[i] += x_ext[i] + y_ext[i]; // суммируем последние разряды чисел
		Sum[i + 1] += (Sum[i] / 10); // если есть разряд для переноса, переносим его в следующий разряд
		Sum[i] %= 10; // если есть разряд для переноса он отсекается
	}
	shorted(Sum);
	return Sum;
}

vector<int> sub(const vector<int> & one, const vector<int> & two)
{
	vector<int> x;
	x.assign(one.begin(), one.end());
	vector<int> y;
	y.assign(two.begin(), two.end());
	int length = x.size() > y.size() ? x.size() : y.size();
	vector<int> one_ext(length, 0);
	vector<int> two_ext(length, 0);
	for (int i = 0; i < x.size(); ++i)
	{
		one_ext[i] = x[i];
	}
	for (int i = 0; i < y.size(); ++i)
	{
		two_ext[i] = y[i];
	}
	for (int i = 0; i < length; ++i)
	{
		if (one_ext[i] < two_ext[i] && i < length - 1)
		{
			--one_ext[i + 1];
			one_ext[i] += 10;
		}
		one_ext[i] -= two_ext[i];
	}
	return one_ext;
}

void shorted(vector<int> & ret)
{
	int flag = -1;
	for (int i = ret.size() - 1; i >= 0; --i)
	{
		if (ret[i] != 0)
		{
			flag = i;
			break;
		}
	}
	ret.resize(flag + 1);
}

void neg(vector<int> & input)
{
	input[input.size() - 1] = -input[input.size() - 1];
}




vector<int> mult(const vector<int> & one, const vector<int> & two)
{
	int columns = one.size();
	columns += two.size() * 2;
	int rows = two.size() + 1;
	vector<int> row(columns, 0);
	vector<vector<int>> process(rows);
	for (int i = 0; i < rows; ++i)
		process[i] = row;
	for (int i = 0; i < two.size(); ++i)
	{
		for (int j = 0; j < one.size(); ++j)
		{
			int number_last = i + j;
			process[i][number_last] += two[i] * one[j];
			process[i][number_last + 1] += process[i][number_last] / 10;
			process[i][number_last] = process[i][number_last] % 10;
		}
		int  h = 4;
	}
	vector<int> ret(columns);
	for (int i = 0; i < columns - 1; ++i)
	{
		int sum = 0;
		for (int j = 0; j < rows; ++j)
		{
			sum += process[j][i];
		}
		ret[i] += sum;
		ret[i + 1] += ret[i] / 10;
		ret[i] = ret[i] % 10;
	}
	shorted(ret);
	return ret;
}

bool above(const vector<int> & one, const vector<int> & two)
{
	vector<int> ret = sub(one, two);
	bool flag_neg = true;
	for (int i = ret.size() - 1; i >= 0; --i)
	{
		if (ret[i] != 0)
		{
			if (ret[i] < 0)
			{
				flag_neg = false;
			}
			break;
		}
	}
	return flag_neg;
}

vector<int> subtruct(const vector<int> & one, const vector<int> & two)
{
	vector<int> ret;
	if (!above(one, two))
	{
		ret = sub(two, one);
		neg(ret);
	}
	else
		ret = sub(one, two);
	return ret;
}

vector<int> div(const vector<int> & one, const vector<int> & two)
{
	vector<int> ret, temp_ret, res_rev;
	vector<int> dif;
	vector<int> one_combine, one_combine_temp;
	one_combine.assign(one.begin(), one.end());
	int last_number = one_combine.size() - 1;
	while (last_number >= 0)
	{
		int current;
		for (int current = last_number; current >= 0; --current)
		{
			ret.clear();
			for (int i = current; i < one_combine.size(); ++i)
			{
				ret.push_back(one_combine[i]);
			}
			if (above(ret, two))
			{
				int number_div;
				for (number_div = 1; number_div <= 10; ++number_div)
				{
					vector<int> temp_vector = { number_div };
					temp_ret = mult(two, temp_vector);
					if (above(temp_ret, ret))
						break;
				}
				--number_div;
				res_rev.push_back(number_div);
				vector<int> temp_vector = { number_div };
				temp_ret = mult(two, temp_vector);
				dif = sub(ret, temp_ret);
				one_combine_temp.clear();
				for (int i = 0; i < current; ++i)
				{
					one_combine_temp.push_back(one_combine[i]);
				}
				last_number = current - 1;
				for (int i = 0; i < dif.size(); ++i)
				{
					one_combine_temp.push_back(dif[i]);
				}
				shorted(one_combine_temp);
				one_combine.assign(one_combine_temp.begin(), one_combine_temp.end());
				break;
			}
			else
				res_rev.push_back(0);
		}
	}
	reverse(res_rev.begin(), res_rev.end());
	shorted(res_rev);
	return res_rev;
}

vector<int> Enter()
{
	vector<int> x_ext;
	int numb, licznik = 256;
	while (true)
	{
		numb = _getch();
		if (numb > 47 && numb < 58)
		{		
				numb -= 48;
				x_ext.push_back(numb);
				cout << numb;
				licznik--;
		}
		if (numb == 13 || !licznik)
		{
			reverse(x_ext.begin(), x_ext.end());
			break;
		}
	}
	return x_ext;
}

vector<int> Res(vector<int> & res)
{
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i];
	}
	return res;
}

int main()
{
	int number, licz = 1;
	//vector<int> one = { 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//vector<int> two = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//vector<int> res = mult(one, two);
	vector<int> one;
	vector<int> two;
	vector<int> res;

	do
	{
		cin >> number;
	} while (number < 1 && number>200);

	for (int i = 0; i < number; ++i)
	{
		if (licz == 1)
		{
			one = Enter();
			cout << " + ";
			two = Enter();
			res = sum(one, two);
			cout << " = ";
			int i = res.size();
			for (--i; i >= 0; --i)
			{
				cout << res[i];
			}
			cout << endl;
			one.clear();
			two.clear();
		}
		else if(licz == 2)
		{
			one = Enter();
			cout << " * ";
			two = Enter();
			res = mult(one, two);
			cout << " = ";
			int i = res.size();
			for (--i; i >= 0; --i)
			{
				cout << res[i];
			}
			cout << endl;
			one.clear();
			two.clear();
		}
		else if (licz == 3)
		{
			one = Enter();
			cout << " - ";
			two = Enter();

			//two = { 1, 2/* , 3, 4, 5, 6, 7, 8, 9, 1*/ };
			//one = { 1, 2, 3, 4/*, 5, 6, 7, 8, 9, 1*/ };
			res = subtruct(one, two);
			cout << " = ";
			int i = res.size();
			for (--i; i >= 0; --i)
			{
				cout << res[i];
			}
			cout << endl;
			one.clear();
			two.clear();
		}
		else
		{
			one = Enter();
			cout << " / ";
			two = Enter();
			res = div(one, two);
			cout << " = ";
			int i = res.size();
			for (--i; i >= 0; --i)
			{
				cout << res[i];
			}
			cout << endl;
			one.clear();
			two.clear();
			licz = 0;
		}
		licz++;

	}

	/*res = sum(one, two);
	res = subtruct(one, two);
	res = div(one, two);
	res = mult(one, two);*/


		
	return 0;
}




