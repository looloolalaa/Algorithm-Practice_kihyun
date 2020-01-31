#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

struct Person {
	int age;
	char name[101];
};
void show(Person* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d %s\n", arr[i].age, arr[i].name);
		//cout << arr[i].age << " " << arr[i].name << endl;
	}
}
bool cmp(Person a, Person b) {
	return a.age < b.age;
}

int main() {
	int n;
	int age;
	char name[101];
	Person* arr;
	scanf("%d", &n);
	//cin >> n;

	if (1 <= n && n <= 100000) {
		arr = new Person[n];
		for (int i = 0; i < n; i++) {
			scanf("%d ", &age);
			scanf("%s", name);
			//cin >> age >> name;
			if (1 <= age && age <= 200) {
				arr[i].age = age;
				strcpy(arr[i].name, name);
			}
		}
	}
	stable_sort(arr, arr + n, cmp);
	show(arr, n);

}