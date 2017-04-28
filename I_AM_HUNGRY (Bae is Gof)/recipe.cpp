#include "recipe.h"

int recipe::recipe_count; // 전체 레시피 카운트

vector<string> recipe::recipe_vector; // 전체 레시피 벡터

void recipe::recipelist_print(const string & stuffname)
{
	fstream fin;
	string s, onerecipe;

	cout << "[" << stuffname << "(으)로 만들 수 있는 음식]" << endl;
	fin.open("stuff/" + stuffname + ".txt");

	for (recipelist_count = 0; getline(fin, s); recipelist_count++)
	{
		recipelist.push_back(s);
		onerecipe = "<" + to_string(recipelist_count) + "> " + recipelist.back();
		cout << setw(30) << left << onerecipe;
		if ((recipelist_count + 1) % 6 == 0) cout << endl;
	}
	cout << endl << endl << endl;
	recipelist_count--;
	fin.close();
}

int recipe::getrecipelist_count()
{
	return recipelist_count;
}

string recipe::getrecipelistname(const int & selected_num)
{
	return recipelist[selected_num];
}

string recipe::select_recipe()
{
	fstream fin;
	string s, recipename;
	int i, selected_num;

	cout << ">>> 만들 요리를 입력하세요. (메뉴 - 메인 화면으로 돌아가기) : ";
	for (;;)
	{
		getline(cin, s);
		if (s == "메뉴")
		{
			cout << endl << endl;
			main();
		}
		else if (s[0] >= '0' && s[0] <= '9' && stoi(s) >= 0 && stoi(s) <= getrecipelist_count())
		{
			selected_num = stoi(s);
			recipename = getrecipelistname(selected_num);
			break;
		}
		else
		{
			try
			{
				recipename = s;
				for (i = 0; i <= recipelist_count; i++)
				{
					if (recipelist[i] == recipename) break;
				}
				if (i == recipelist_count + 1) throw recipename;

				fin.open("recipe/" + recipename + ".txt");
				if (fin.fail())	throw recipename;
				else break;
			}
			catch (string e)
			{
				cout << ">>> " << e << "(이)라는 요리가 없습니다. 제대로 입력하세요. (메뉴 - 메인 화면으로 돌아가기) : ";
			}
		}
	}
	fin.close();
	cout << endl << endl;
	return recipename;
}

void recipe::recipe_print(const string & recipename)
{
	fstream fin;
	ofstream fout;
	string s, history[5];

	cout << "[" << recipename << " 요리법" << "]" << endl;
	fin.open("recipe/" + recipename + ".txt");
	while (!fin.eof()) {
		getline(fin, s);
		cout << s << endl;
	}
	fin.close();

	fin.open("history5.txt");
	history[0] = recipename;
	for (int i = 1; i < 5; i++)
		getline(fin, history[i]);
	fin.close();

	fout.open("history5.txt");
	for (int i = 0; i < 5; i++)
		if(history[i] != "")
			fout << history[i] << endl;
	fout.close();
}

void recipe::recipe_print(const int & recipenum)
{
	fstream fin;
	ofstream fout;
	string s, history[5];

	cout << "[" << recipe_vector[recipenum] << " 요리법" << "]" << endl;
	fin.open("recipe/" + recipe_vector[recipenum] + ".txt");
	while (!fin.eof()) {
		getline(fin, s);
		cout << s << endl;
	}
	fin.close();

	fin.open("history5.txt");
	history[0] = recipe_vector[recipenum];
	for (int i = 1; i < 5; i++)
		getline(fin, history[i]);
	fin.close();

	fout.open("history5.txt");
	for (int i = 0; i < 5; i++)
		if (history[i] != "")
			fout << history[i] << endl;
	fout.close();
}

void recipe::recipe_bookmark_store(const string & recipename)
{
	ofstream fout;
	string s, memo;

	cout << ">>> 요리법을 북마크에 저장하시겠습니까? (Y/N) (메뉴 - 메인 화면으로 돌아가기) : ";
	getline(cin, s);
	if (s == "메뉴")
	{
		cout << endl << endl;
		main();
	}
	else if (s[0] == 'Y' || s[0] == 'y')
	{
		cout << ">>> 북마크 메모를 입력해주세요. : ";
		getline(cin, memo);
		fout.open("bookmark.txt", ios_base::app); // 파일에 텍스트 추가하기
		fout << recipename << endl << memo << endl;
		fout.close();
	}
	cout << endl << endl;
}

void recipe::recipe_bookmark_store(const int & recipenum)
{
	ofstream fout;
	string s, memo;

	cout << ">>> 요리법을 북마크에 저장하시겠습니까? (Y/N) (메뉴 - 메인 화면으로 돌아가기) : ";
	getline(cin, s);
	if (s == "메뉴")
	{
		cout << endl << endl;
		main();
	}
	else if (s[0] == 'Y' || s[0] == 'y')
	{
		cout << ">>> 북마크 메모를 입력해주세요. : ";
		getline(cin, memo);
		fout.open("bookmark.txt", ios_base::app); // 파일에 텍스트 추가하기
		fout << recipe_vector[recipenum] << endl << memo << endl;
		fout.close();
	}
	cout << endl << endl;
}

void recipe::history_print()
{
	fstream fin;
	string name, onerecipe;

	fin.open("history5.txt");
	for (recipelist_count = 0;;recipelist_count++)
	{
		getline(fin, name);
		if (fin.eof()) break;
		recipelist.push_back(name);
		onerecipe = "<" + to_string(recipelist_count) + "> " + recipelist[recipelist_count];
		cout << setw(30) << left << onerecipe;
	}
	recipelist_count--;
	fin.close();
	cout << endl << endl << endl;
}

void recipe::bookmark_print()
{
	fstream fin;
	string name, memo;

	fin.open("bookmark.txt");
	for (recipelist_count = 0;;recipelist_count++)
	{
		getline(fin, name);
		if (fin.eof()) break;
		recipelist.push_back(name);
		cout << "<" + to_string(recipelist_count) + "> " << recipelist[recipelist_count];

		getline(fin, memo);
		if (fin.eof()) break;
		cout << " - " << memo << endl;
	}
	recipelist_count--;
	fin.close();
	cout << endl << endl;
}

void recipe::recipe_store()
{
	fstream fin;
	string s;

	fin.open("recipelist.txt");
	for (recipe_count = 0; fin >> s; recipe_count++)
	{
		recipe_vector.push_back(s);
	}
	fin.close();
}

int recipe::select_random_recipe()
{
	fstream fin;
	int recipenum;
	string s;
	cout << ">>> 오늘은 무엇을 만들어 볼까요? 엔터 키를 눌러주세요. (메뉴 - 메인 화면으로 돌아가기) : ";
	getline(cin, s);
	if (s == "메뉴")
	{
		cout << endl << endl;
		main();
	}
	else
	{
		for (;;)
		{
			recipenum = rand() % recipe_count;
			fin.open("recipe/" + recipe_vector[recipenum] + ".txt");
			if (!fin.fail()) break;
		}
	}
	fin.close();
	cout << endl << endl;
	return recipenum;
}