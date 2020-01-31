#include <stdio.h>
#include <algorithm>
using namespace std;

struct Point {
	int x;
	int y;
};

bool cmp(Point a, Point b) {
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}
int main() {
	int n;
	Point* p;
	scanf("%d", &n);
	if (1 <= n && n <= 100000)
		p = new Point[n];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	sort(p, p + n, cmp);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", p[i].x, p[i].y);
}