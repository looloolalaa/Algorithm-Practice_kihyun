#include <iostream>
using namespace std;
#define MAX 10000

int main() {
	int x;
	cin >> x;

	int before = 0, after = 0, sum=0;
	int up = 0, down = 0;
	for (int i = 0; i < MAX; i++) { //i==0
		before = (i) * (i + 1) / 2; //0
		after = (i + 1) * (i + 2) / 2; //1
		if (before < x && x <= after) {
			int th = x - before;  //1
			if ((i+1) % 2) {  
				down = th;  //°Å²Ù·Î
				up = (i+2) - down;
			}
			else {
				up = th;
				down = (i + 2) - up;
			}
			break;
		}
	}
	cout << up << "/" << down << endl;
}