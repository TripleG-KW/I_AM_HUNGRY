#ifndef __RECIPE__
#define __RECIPE__

#include "i_am_hungry.h"

class recipe
{
public:
	static void recipe_store(); // ��ü ������ ����
	int getrecipelist_count(); // recipelist_count ��ȯ
	string getrecipelistname(const int& selected_num); // recipelist���� ������ �������� �̸� ��������
	void recipelist_print(const string& stuffname); // ������ ����� ������ ����Ʈ ����Ʈ
	string select_recipe(); // ������ ����
	void recipe_print(const string& recipename); // ������ ����Ʈ
	int select_random_recipe(); // ���� ������ ����
	void recipe_print(const int & recipenum); // ������ ����Ʈ
	void recipe_bookmark_store(const string& recipename);
	void recipe_bookmark_store(const int & recipenum);
	void history_print();
	void bookmark_print(); // �ϸ�ũ ������ ����Ʈ ����Ʈ
private:
	int recipelist_count; // ������ ����Ʈ ī��Ʈ
	vector<string> recipelist; // ������ ����Ʈ
	static int recipe_count; // ��ü ������ ī��Ʈ
	static vector<string> recipe_vector; // ��ü ������ ����
};

#endif