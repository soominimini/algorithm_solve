/*
#include <string>
#include<deque>
#include<algorithm>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	deque<int> dA, dB;

	sort(B.begin(), B.end(), greater<int>());
	sort(A.begin(), A.end(), greater<int>());

	for (int i = 0; i < A.size(); i++) {
		dA.push_back(A.at(i));
		dB.push_back(B.at(i));
	}
	while (!dA.empty() && !dB.empty()) {
		if (dA.front() < dB.front()) {
			answer++;
			dA.pop_front();
			dB.pop_front();
		}
		else {
			dA.pop_front();
			dB.pop_back();
		}
	}
	return answer;
}
int main() {
	vector<int> A = { 5,1, 3,7 };
	vector<int>B = { 8,2,6,2 };
	solution(A,B);

	return 0;
}
*/