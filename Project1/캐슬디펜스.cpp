/*
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct ENEMY {
	int dist, row, col;
};

bool comp(const ENEMY &a, const ENEMY &b) {
	if (a.dist < b.dist)return true;
	else if (a.dist == b.dist) {
		if (a.col < b.col) return true;
	}
	return false;
}

ENEMY e;

int N, M, D;
int map[17][16];
int backup[17][16];
bool visited[16];
int arrow_loca[3];

int ret = 0;

bool move() {
	bool flag = true;
	for (int j = 0; j < M; j++) {
		map[N - 1][j] = 0;
	}
	for (int i = N - 2; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				flag = false;
				map[i + 1][j] = map[i][j];
				map[i][j] = 0;
			}
		}
	}
	return flag;
}

void attack() {
	int cur_loca_ret = 0;
	while (true) {
		queue<pair<int, int> > q;

		for (int i = 0; i < 3; i++) {
			vector<ENEMY>v;
			for (int j = N - 1; j >= 0; j--) {
				for (int k = 0; k < M; k++) {
					if (map[j][k] == 1) {
						if (abs(N - j) + abs(arrow_loca[i] - k) <= D) {
							e.dist = abs(N - j) + abs(arrow_loca[i] - k);
							e.col = k;
							e.row = j;
							v.push_back(e);
						}
					}
				}
			}
			if (v.size() > 0) {
				sort(v.begin(), v.end(), comp);
				q.push({ v.begin()->row, v.begin()->col });
			}
			//Á×ÀÏ ¼ö ÀÖ´Â ÀûÀÇ À§Ä¡ ÃÑ 3°³ ´ã±è
		}
		int tmp = 0;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			if (map[y][x] == 1) {
				tmp++;
				map[y][x] = 0;
			}
		}
		cur_loca_ret += tmp;
		bool end = move();
		if (end == true) break;
	}
	ret = max(ret, cur_loca_ret);
	return;
}

void func(int inx, int cnt) {
	if (cnt == 3) {

		attack();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = backup[i][j];
			}
		}
	}
	else {
		for (int i = inx; i < M; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				arrow_loca[cnt] = i;
				func(i+1, cnt+1);
				visited[i] =false;
			}
		}
	}
	return;
}

int main() {
	scanf("%d %d %d", &N, &M, &D);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			backup[i][j] = map[i][j];
		}
	}
	func(0,0);
	printf("%d", ret);
	return 0;
}
*/