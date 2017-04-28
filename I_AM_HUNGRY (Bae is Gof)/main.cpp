#include "i_am_hungry.h"
#include "stuff.h"
#include "recipe.h"

int select_menu()
{
	string s;
	for (;;)
	{
		cout << ">>> 메뉴를 선택하세요. (1~4) : ";
		getline(cin, s);
		if (s[0] >= '1' && s[0] <= '4') break;
	}
	cout << endl << endl;

	return s[0] - '0';
}

void recipe_search()
{
	for(;;)
	{
		cout << "[요리법을 찾아볼까요~]" << endl;
		string stuffname = stuff::select_stuff();
		
		recipe* recipelist = new recipe;
		recipelist->recipelist_print(stuffname);

		string recipename = recipelist->select_recipe();
		recipelist->recipe_print(recipename);

		recipelist->recipe_bookmark_store(recipename);

		delete recipelist;
	}
}

void recipe_random()
{
	for (;;)
	{
		cout << "[오늘 뭐 먹지?]" << endl;
		recipe* random = new recipe;
		int recipenum = random->select_random_recipe();
		random->recipe_print(recipenum);

		random->recipe_bookmark_store(recipenum);

		delete random;
	}
}

void recipe_history()
{
	for (;;)
	{
		cout << "[최근 다섯개]" << endl;
		recipe* history = new recipe;
		history->history_print();

		string recipename = history->select_recipe();
		history->recipe_print(recipename);

		history->recipe_bookmark_store(recipename);

		delete history;
	}
}

void recipe_bookmark()
{
	for (;;)
	{
		cout << "[나의 취향♥]" << endl;
		recipe* bookmark = new recipe;
		bookmark->bookmark_print();

		string recipename = bookmark->select_recipe();
		bookmark->recipe_print(recipename);

		delete bookmark;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	stuff::stufflist_store();
	recipe::recipe_store();
	cout << "┌───────────────────────────────────────────────────┐" << endl;
	cout << "│■■■■         ■      ■        ■     ■      ■ ■      ■ ■■    ■  ■■■  ■■■■  ■    ■│" << endl;
	cout << "│   ■           ■■     ■■    ■■     ■      ■ ■      ■ ■ ■   ■ ■       ■     ■  ■  ■ │" << endl;
	cout << "│   ■          ■  ■    ■ ■  ■ ■     ■■■■■ ■      ■ ■  ■  ■ ■  ■■ ■■■■     ■   │" << endl;
	cout << "│   ■         ■■■■   ■  ■■  ■     ■      ■  ■    ■  ■   ■ ■ ■    ■ ■     ■    ■   │" << endl;
	cout << "│■■■■     ■      ■  ■   ■   ■     ■      ■    ■■    ■    ■■  ■■■  ■     ■    ■   │" << endl;
	cout << "│                                                                                                      │" << endl;
	cout << "│                                                                              자취생의 냉장고를 부탁해│" << endl;
	cout << "└───────────────────────────────────────────────────┘" << endl;
	cout << "┌────────────────────────┬──────────────────────────┐" << endl;
	cout << "│                                                │                                                    │" << endl;
	cout << "│                   [메인 메뉴]                  │         [고급 프로그래밍 '배가 고픕니다'조]        │" << endl;
	cout << "│                                                │                                                    │" << endl;
	cout << "│                 <1> 찾아볼까요~                │                   2015726031 임동건                │" << endl;
	cout << "│                 <2> 오늘뭐먹지?                │                   2015726030 박재원                │" << endl;
	cout << "│                 <3> 최근다섯개                 │                   2015726019 이현창                │" << endl;
	cout << "│                 <4> 나의취향♥                 │                   2015726076 김현구                │" << endl;
	cout << "│                                                │                                                    │" << endl;
	cout << "└────────────────────────┴──────────────────────────┘" << endl;

	switch(select_menu())
	{
		case 1:
			recipe_search();
			break;
		case 2:
			recipe_random();
			break;
		case 3:
			recipe_history();
			break;
		case 4:
			recipe_bookmark();
			break;
		default:
			main();
	}

	return 0;
}