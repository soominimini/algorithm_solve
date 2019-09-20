/*
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct INFO {
	int x, y;
	int time;
};

int n;
int map[11][11];
vector<INFO> v[2];
vector<INFO> ::iterator iter;
int stair1x, stair1y;
int stair2x, stair2y;


int func() {
	int time = 1;

	while (true) {
		for (int i = 0; i < 2; i++) {
			if (v[i].size() > 0) {
				for (int j = 0; j < v[i].size(); j++) {
					if (j < 3) {
						v[i].at(j).time -= 1;
					}
				}
				//도착
				for (iter = v[i].begin(); iter != v[i].end();) {
					if (iter->time == 0) {
						iter = v[i].erase(iter);
					}
					else
						iter++;
				}
			}
		}//사람 있는지 확인하고 시간 빼기

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 1) {
					if (abs(i - stair1y) + abs(j - stair1x) == time) {
						map[i][j] = 0;
						INFO inf;
						inf.x = j;
						inf.y = i;
						inf.time = map[stair1y][stair1x]+1;
						v[0].push_back(inf);
					}
					else if (abs(i - stair2y) + abs(j - stair2x) == time) {
						map[i][j] = 0;
						INFO inf;
						inf.x = j;
						inf.y = i;
						inf.time = map[stair2y][stair2x]+1;
						v[1].push_back(inf);
					}
				}
			}
		}

		//사람 다 빠져나갔는지 검사
		bool flag = false;
		if (v[0].size() == 0 && v[1].size() == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][j] == 1) {
						//사람 있네
						flag = true;
						break;
					}
				}
				if (flag == true)break;
			}
		}
		if (flag == false) {
			//남은 사람 없음
			return time;
		}
		time++;
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &n);
		bool first = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] > 1 &&first==false) {
					stair1x = j, stair1y = i;
					first = true;
				}
				 if (map[i][j] > 1 && first == true) {
					stair2x = j, stair2y = i;
				}
			}
		}
		func();
	}
}
*/