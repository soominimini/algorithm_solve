/*
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct INFO {
	int dir, y, x;
};

struct BR {
	int y, x;
};

int dx[] = { -1, 0, +1, 0 };
int dy[] = { 0, -1, 0, +1 };

int map[11][11];
int map_c[11][11];
bool island_visit[7];
bool brdge_visit[7];
int N, M;

vector< INFO>v;
vector< BR>bridge[100];

void making_isalnd() {

	int cnt = 1;
	bool island_custom[11][11];
	fill(island_custom[0], island_custom[0] + 121, false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && island_custom[i][j]==false) {
				queue<int>q;
				q.push(i * 100 + j);
				island_custom[i][j] = true;
				while (!q.empty()) {
					int y = q.front() / 100;
					int x = q.front() % 100;
					q.pop();
					island_custom[y][x] = true;
					map_c[y][x] = cnt;

					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || nx < 0 || ny >= M || nx >= M)continue;
						if (map[ny][nx] != 1)continue;
						else if (island_custom[ny][nx] == true)continue;

						q.push(ny*100+nx);
						island_custom[ny][nx] = true;

					}
				}
				cnt++;
			}
		}
	}

	return;
}
void structure_location() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
					else if (map[ny][nx] == 1)continue;
					else if (map[ny + dy[k]][nx + dx[k]] == 1)continue;

					INFO inf;
					inf.y = ny;
					inf.x = nx;
					inf.dir = k;

					v.push_back(inf);
				}
			}
		}
	}
	return;
}

void bridge_check() {
	queue<pair<int, int> > q;
	for (int i = 0; i < v.size(); i++) {
		bool flag = true;
		int d = v.at(i).dir;
		int cy = v.at(i).y;
		int cx = v.at(i).x;
		q.push({cy, cx});

		int ny, nx;

		while (true) {
			ny = q.front().first + dy[d];
			nx = q.front().second + dx[d];
			q.pop();
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
				flag = false;
				break;
			}
			else if (map[ny][nx] == 1)break;
			q.push({ ny, nx });
		}
		if (flag == true) {
			while (!q.empty()) {
				BR b;
				b.x = q.front().second;
				b.y = q.front().first;
				q.pop();
				bridge[i].push_back(b);
			}
		}
	}
	return;
}

void johab(int depth, int inx, int cnt) {
	if (depth == cnt) {
		cal();
	}
	else {
		for (int i = inx; i < v.size(); i++) {
			if (brdge_visit[i] == false) {
				brdge_visit[i] = true;
				johab(depth, i+1, cnt+1);
				brdge_visit[i] = false;
			}
		}
	}
	return;
}
int cal() {

	for (int i = 0; i < v.size(); i++) {
		if (brdge_visit[i] == true) {
			for (int j = 0; j < bridge[i].size(); j++) {

			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	making_isalnd();
	structure_location();
	bridge_check();
	for (int i = 1; i <= v.size(); i++) {
		//조합 만들기
		johab(i,0,0);
	}
	return 0;
}
*/