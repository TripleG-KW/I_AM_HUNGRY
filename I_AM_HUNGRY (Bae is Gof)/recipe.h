#ifndef __RECIPE__
#define __RECIPE__

#include "i_am_hungry.h"

class recipe
{
public:
	static void recipe_store(); // 전체 레시피 저장
	int getrecipelist_count(); // recipelist_count 반환
	string getrecipelistname(const int& selected_num); // recipelist에서 선택한 레시피의 이름 가져오기
	void recipelist_print(const string& stuffname); // 선택한 재료의 레시피 리스트 프린트
	string select_recipe(); // 레시피 선택
	void recipe_print(const string& recipename); // 레시피 프린트
	int select_random_recipe(); // 랜덤 레시피 선택
	void recipe_print(const int & recipenum); // 레시피 프린트
	void recipe_bookmark_store(const string& recipename);
	void recipe_bookmark_store(const int & recipenum);
	void history_print();
	void bookmark_print(); // 북마크 레시피 리스트 프린트
private:
	int recipelist_count; // 레시피 리스트 카운트
	vector<string> recipelist; // 레시피 리스트
	static int recipe_count; // 전체 레시피 카운트
	static vector<string> recipe_vector; // 전체 레시피 벡터
};

#endif