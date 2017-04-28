#ifndef __STUFF__
#define __STUFF__

#include "i_am_hungry.h"

class stuff
{
public:
	static int getstuff_count();
	static string getstuffname(const int& selected_num);
	static void stufflist_store();
	static void stufflist_print();
	static string select_stuff();
private:
	static int stuff_count;
	static vector<string> stuff_vector;
};

#endif