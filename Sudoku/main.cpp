#include <iostream>
#include "Sudo.h"
using namespace std;
int main()
{

	int num;
	cin >> num;
	int begin = (4 + 8) % 9 + 1;
	Sudo s;
	s.num = num;
	s.openFile();
	s.dfs(0, begin, begin - 1);
}
