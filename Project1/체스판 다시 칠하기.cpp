/*
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
char map[51][51];
char tmp[8][8];
int ret = 1e6;
int dx[] = { -1, 0, +1, 0 };
int dy[] = { 0, -1, 0, +1 };

int check() {
	int cnt = 0;
	for (int i = 0; i< 8; i++) {
		for (int j = 0; j < 8; j++) {
			int ny, nx;
			if (tmp[i][j] == 'B') {
				for (int k = 0; k < 4; k++) {
					ny = i + dy[k];
					nx = j + dx[k];
					if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8)continue;
					else if (tmp[ny][nx] == 'B') {
						tmp[ny][nx] = 'W';
						cnt++;
					}
				}
			}
			else {
				for (int k = 0; k < 4; k++) {
					ny = i + dy[k];
					nx = j + dx[k];
					if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8)continue;
					else if (tmp[ny][nx] == 'W') {
						tmp[ny][nx] = 'B';
						cnt++;
					}
				}
			}
		}
	}
	return cnt;
}

void make_ches(int y, int x) {
	int x_inx = 0, y_inx = 0;
	for (int i = y; i < y+8; i++) {
		for (int j = x; j < x+8; j++) {
			tmp[y_inx][x_inx++] = map[i][j];
		}
		x_inx = 0;
		y_inx++;
	}

	int tmp_ret = check();
	if ( 64-tmp_ret < tmp_ret) tmp_ret = 64-tmp_ret ;
	ret = min(ret, tmp_ret);
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			make_ches(i,j);
		}
	}
	cout << ret;
	return 0;
}
*/ 