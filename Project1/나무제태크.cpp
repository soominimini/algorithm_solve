#include<stdio.h>
#include<algorithm>

#include<deque>
#include<queue>
using namespace std;

int n, m, k;
int origin_nutrient[11][11];
int nutrient[11][11] = {5,};
int death[11][11];
deque<int>map[11][11];

int dx[] = {-1, 0, +1, 0, -1, +1, +1, -1};
int dy[] = {0, -1, 0, +1, -1, -1, +1, +1};

void autumm_spread(int y, int x) {
	int ny, nx;
	for (int i = 0; i < 8; i++) {
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
		
		map[ny][nx].push_front(1);
	}
	return;
}

void spring() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].size() > 0) {
				queue<int> tmp;
				while (map[i][j].size()>0) {
					if (nutrient[i][j] < map[i][j].front()) {
						//양분을 못먹는 경우

						while (map[i][j].size()>0) {
							death[i][j] += map[i][j].front() / 2; 
							map[i][j].pop_front();
						}
						break;
					}
					else {
						nutrient[i][j] -= map[i][j].front();
						tmp.push(map[i][j].front()+1);
						map[i][j].pop_front();
					}
				}
				while (!tmp.empty()) {
					map[i][j].push_back(tmp.front()); tmp.pop();
				}
			}
		}
	}
	return;
}
void summer() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			nutrient[i][j] += death[i][j];
			death[i][j] = 0;
		}
	}
}

void autumm() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].size() > 0) {
				queue<int> tmp;

				while (map[i][j].size()>0) {
					tmp.push(map[i][j].front());
					if (map[i][j].front() % 5 == 0) {
						autumm_spread(i,j);
					}
					map[i][j].pop_front();
				}
				while (!tmp.empty()) {
					map[i][j].push_back(tmp.front());
					tmp.pop();
				}
			}
		}
	}
	return;
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			nutrient[i][j] += origin_nutrient[i][j];
		}
	}
	return;
}
int main() {
	int year = 0; int ret = 0;
	fill(nutrient[0], nutrient[0]+121, 5);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &origin_nutrient[i][j]);
		}
	}
	int x, y, z;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &z);
		map[x - 1][y - 1].push_back(z);
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			nutrient[i][j] += origin_nutrient[i][j];
		}
	}
	*/
	while (year<k) {
		spring();
		summer();
		autumm();
		winter();
		year++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j].size() > 0) {
				ret += map[i][j].size();
			}
		}
	}
	printf("%d", ret);
	return 0;
}