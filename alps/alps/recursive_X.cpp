#include <iostream>
using namespace std;

void draw_tree(int row, int left, int right) {
	//printf("%d %d %d\n", row, left, right);
	int length = right - left;
	if (length == 0) return;
	string str = "";
	for (int i = 0; i < length; i++) str += '-';

	if (row == 0) { 
		str[length / 2] = 'X';
		cout << str.c_str();
	}
	else {
		int mid = (left + right) / 2;
		draw_tree(row - 1, left, mid);
		draw_tree(row - 1, mid, right);
	}
	
}

int main() {
	draw_tree(3, 0, 40);
}