#include "i_am_hungry.h"
#include "stuff.h"
#include "recipe.h"

int select_menu()
{
	string s;
	for (;;)
	{
		cout << ">>> �޴��� �����ϼ���. (1~4) : ";
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
		cout << "[�丮���� ã�ƺ����~]" << endl;
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
		cout << "[���� �� ����?]" << endl;
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
		cout << "[�ֱ� �ټ���]" << endl;
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
		cout << "[���� ���⢾]" << endl;
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
	cout << "����������������������������������������������������������������������������������������������������������" << endl;
	cout << "�������         ��      ��        ��     ��      �� ��      �� ���    ��  ����  �����  ��    �ᦢ" << endl;
	cout << "��   ��           ���     ���    ���     ��      �� ��      �� �� ��   �� ��       ��     ��  ��  �� ��" << endl;
	cout << "��   ��          ��  ��    �� ��  �� ��     ������ ��      �� ��  ��  �� ��  ��� �����     ��   ��" << endl;
	cout << "��   ��         �����   ��  ���  ��     ��      ��  ��    ��  ��   �� �� ��    �� ��     ��    ��   ��" << endl;
	cout << "�������     ��      ��  ��   ��   ��     ��      ��    ���    ��    ���  ����  ��     ��    ��   ��" << endl;
	cout << "��                                                                                                      ��" << endl;
	cout << "��                                                                              ������� ����� ��Ź�ئ�" << endl;
	cout << "����������������������������������������������������������������������������������������������������������" << endl;
	cout << "����������������������������������������������������������������������������������������������������������" << endl;
	cout << "��                                                ��                                                    ��" << endl;
	cout << "��                   [���� �޴�]                  ��         [��� ���α׷��� '�谡 ���Ŵϴ�'��]        ��" << endl;
	cout << "��                                                ��                                                    ��" << endl;
	cout << "��                 <1> ã�ƺ����~                ��                   2015726031 �ӵ���                ��" << endl;
	cout << "��                 <2> ���ù�����?                ��                   2015726030 �����                ��" << endl;
	cout << "��                 <3> �ֱٴټ���                 ��                   2015726019 ����â                ��" << endl;
	cout << "��                 <4> �������⢾                 ��                   2015726076 ������                ��" << endl;
	cout << "��                                                ��                                                    ��" << endl;
	cout << "����������������������������������������������������������������������������������������������������������" << endl;

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