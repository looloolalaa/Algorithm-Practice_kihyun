#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 1001
using namespace std;

class Leader {
private:
	int n;
	vector<int> data[5];  //세로줄을 벡터하나에 저장. 한번에 비교해야하는 단위가 세로줄(학년)이기때문에.
	vector<int> answer[SIZE];  //학생수만큼의 정답벡터 선언
public:
	bool init() {
		int now;
		cin >> n;
		if (!(3 <= n && n <= SIZE))
			return false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> now;
				if (!(1 <= now && now <= 9))
					return false;
				data[j].push_back(now);  //학년별저장
			}
		}
		return true;
	}
	void calc() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < n; j++) {
				int now = data[i][j];  //j+1번째 학생과
				for (int k = j + 1; k < n; k++) {
					if (now == data[i][k]) {//k+1번째 학생이 반이 같으면
						append_answer(j, k);//j 번째 학생의 정답 벡터에 k학생추가
						append_answer(k, j);//동시에 k번째학생의 정답벡터에도 j학생추가
					}
				}
			}
		}
	}
	void append_answer(int index,int val) {
		if(!(find(answer[index].begin(), answer[index].end(),val)!= answer[index].end()))//!(이미 넣으려는 값이 있으면)
			answer[index].push_back(val);
	}
	int find_max() { //각 학생의 정답 벡터들중 가장큰 사이즈(여러친구과 같은반이된)를 갖는 녀석이 임시반장 당선 탕탕탕
		int idx=0;
		int max = answer[0].size();
		for (int i = 1; i < n; i++) {
			if (max < answer[i].size()) {
				idx = i;
				max = answer[i].size();
			}
		}
		return idx+1;
	}
	void play() {
		if (init()) {
			calc();
		}
		cout << find_max() << endl;
	}
	void test() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < answer[i].size(); j++) {
				cout << answer[i][j] << " ";
			}
			cout << endl;
			
		}
	}
};

int main() {
	Leader l;
	l.play();
}