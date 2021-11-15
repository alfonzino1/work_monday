#include <stdio.h>

#include <iostream>
#include <string>
#include <clocale>

using namespace std;

struct student
{
	string NAME;
	int GROUP;
	int SES[5];
};
void zapoln(student* st, int N)
{
	for (int i(0); i < N; ++i)
	{
		cout << "Введите ФИО только на англиском:";
		cin >> st[i].NAME;
		cout << "Введите номер группы только цифрами:";
		cin >> st[i].GROUP;
		cout << "Введите оценки через точку:";
		for (int j(0); j < 5; ++j) { cout << j + 1 << ":"; cin >> st[i].SES[j]; }
	}
}
void sort_group(student* st, int N)
{
	for (int i = N - 1; i >= 1; i--)
		for (int j = 0; j < i; j++)
		{
			if (st[j].GROUP > st[j + 1].GROUP)
			{// меняем местами элементы
				int temp(0);
				temp = st[j].GROUP;
				st[j].GROUP = st[j + 1].GROUP;
				st[j + 1].GROUP = temp;

			}
		}
}

void sred_bal(student* st, int N)
{
	double sred(0);
	cout << "Студент\tНомер группы\n";
	for (int i(0); i < N; ++i)
	{
		for (int j(0); j < 5; ++j)sred += st[i].SES[j];
		if ((sred / 5.0) > 3.7)cout << st[i].NAME << "\t" << st[i].GROUP << "\t\t";
		sred = 0;
	}
	cout << endl;
}

void Show(student* st, int N)
{
	cout << "Студент\tНомер группы\tОценки\n";
	for (int i(0); i < N; ++i)
	{
		cout << st[i].NAME << "\t" << st[i].GROUP << "\t\t";
		for (int j(0); j < 5; ++j)
		{
			cout << st[i].SES[j];
			if (j != 4)cout << ",";
		}
		cout << endl;
	}

}

int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");
	int N;
	cout << "4iclo studentov:";
	cin >> N;

	student* st = new student[N];
	zapoln(st, N);
	sort_group(st, N);
	Show(st, N);
	sred_bal(st, N);
	return 0;
}