#include "stuff.h"

int stuff::stuff_count;

vector<string> stuff::stuff_vector;

int stuff::getstuff_count()
{
	return stuff_count;
}

void stuff::stufflist_print()
{
	string onestuff;

	for (int i = 0; i <= stuff_count; i++)
	{
		onestuff = "<" + to_string(i) + "> " + stuff_vector[i];
		cout << setw(30) << left << onestuff;
		if ((i + 1) % 6 == 0) cout << endl;
	}
	cout << endl << endl << endl;
}

string stuff::select_stuff()
{
	fstream fin;
	string s, stuffname;
	int selected_num;

	cout << ">>> 재료의 번호나 이름을 입력하세요. (목록 - 전체 음식재료 보기, 메뉴 - 메인 화면으로 돌아가기) : ";
	for (;;)
	{
		getline(cin, s);
		if (s == "목록")
		{
			cout << endl << endl;
			stufflist_print();
			cout << ">>> 재료의 번호나 이름을 입력하세요. (목록 - 전체 음식재료 보기, 메뉴 - 메인 화면으로 돌아가기) : ";
		}
		else if (s == "메뉴")
		{
			cout << endl << endl;
			main();
		}
		else if (s[0] >= '0' && s[0] <= '9' && stoi(s) >= 0 && stoi(s) <= getstuff_count())
		{
			selected_num = stoi(s);
			stuffname = getstuffname(selected_num);
			break;
		}
		else
		{
			try
			{
				stuffname = s;
				fin.open("stuff/" + stuffname + ".txt");
				if (fin.fail())	throw stuffname;
				else break;
			}
			catch (string e)
			{
				cout << ">>> " << e << "이라는 재료가 없습니다. 제대로 입력하세요. (목록 - 전체 음식재료 보기, 메뉴 - 메인 화면으로 돌아가기) : ";
			}
		}
	}
	fin.close();
	cout << endl << endl;
	return stuffname;
}

string stuff::getstuffname(const int& selected_num)
{
	return stuff_vector[selected_num];
}

void stuff::stufflist_store()
{
	fstream fin;
	string s;

	fin.open("stufflist.txt");
	for (stuff_count = 0; fin >> s; stuff_count++)
	{
		stuff_vector.push_back(s);
	}
	stuff_count--;
	fin.close();
}