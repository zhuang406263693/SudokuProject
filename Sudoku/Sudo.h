#pragma once
#include <iostream>
using namespace std;
class Sudo {
public:
	int num;
	int co = 0;
	int da[9][9] = { 0 };
	int ju[11][11] = { 0 };
	int num_pic(int row, int l);
	bool judge(int row, int l, int z);
	void output();
	void dfs(int row, int z, int end);
};
int Sudo::num_pic(int row, int l) {
	if (row < 3)
	{
		if (l<3)
		{
			return 1;
		}
		else if (l < 6) {
			return 2;
		}
		else {
			return 3;
		}
	}
	else if (row < 6) {
		if (l < 3)
		{
			return 4;
		}
		else if (l < 6) {
			return 5;
		}
		else {
			return 6;
		}
	}
	else {
		if (l<3)
		{
			return 7;
		}
		else if (l < 6) {
			return 8;
		}
		else {
			return 9;
		}
	}
}

bool Sudo::judge(int row, int l, int z) {
	if (da[row][l] != 0)
	{
		return false;
	}
	for (int i = 0; i < 9; i++)
	{
		if (da[i][l] == z)
		{
			return false;
		}
	}
	return true;
}
void Sudo::output() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) {
			printf("%d ", da[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void Sudo::dfs(int row, int z, int end) {
	if (row == 9)
	{
		//output
		if (z == end)
		{
			//output
			output();
			co++;
			if (co == num)
			{
				exit(0);
			}
			return;
		}
		else {
			int newZ = z + 1;
			if (newZ >= 10)
			{
				newZ -= 9;
			}
			dfs(0, newZ, end);
		}
	}

	for (int i = 0; i < 9; i++) {
		int num = num_pic(row, i);
		if (judge(row, i, z) && ju[z][num] == 0)
		{
			da[row][i] = z;
			ju[z][num] = 1;

			dfs(row + 1, z, end);

			da[row][i] = 0;
			ju[z][num] = 0;
		}
	}
}