#include <iostream>
#include <algorithm>
#include <string>
#define SIZE 100001
using namespace std;

int main() {
	int N; cin >> N;
	int A[SIZE];
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);

	int M; cin >> M;
	int m;
	string answer = "";
	for (int i = 0; i < M; i++) {
		cin >> m; //m==1
		if (A[0] > m || A[N - 1] < m) {  //범위 밖
			answer += "0\n";
			continue;
		}
		else { //범위 안
			int left = 0, right = N - 1;
			int mid;
			while (left <= right) {
				mid = (left + right) / 2;
				if (A[mid] == m) {  //맞으면
					answer += "1\n";
					break;
				}
				else if (A[mid] > m) { //왼쪽
					right = mid - 1;
				}
				else { //오른쪽
					left = mid + 1;
				}
			}
			if (left > right)
				answer += "0\n";
		}
	}
	cout << answer;
}