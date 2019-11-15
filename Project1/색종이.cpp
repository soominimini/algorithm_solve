/*
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

int map[10][10];
bool visited[10][10];
int remain[5];
int ret = 2e9;

void func(int y, int x, int paper_cnt) {
	bool flag = false;
	if (y == 10) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (map[i][j] == 1 && visited[i][j] == false) {
					flag = true; break;
				}
			}
		}
		if (flag == false) {
			ret = min(ret, paper_cnt);
		}
	}

	else if (map[y][x] == 0 || visited[y][x] == true) {
		if (x + 1 < 10)func(y, x+1, paper_cnt);
		else func(y + 1, 0, paper_cnt);
	}
	else {
		for (int i = 1; i <=5; i++) {
			if (i == 1 && remain[0] > 0) {
				if (visited[y][x] == false) {
					visited[y][x] = true;
					remain[0] -= 1;
					
					if (x + 1 < 10) func(y, x+1, paper_cnt+1);
					else func(y + 1, 0, paper_cnt + 1);

					visited[y][x] = false;
					remain[0] += 1;
				}
			}
			else if (i == 2 && remain[1] > 0) {
				bool tmp = false;
				if (y + 2 <= 10 && x + 2 <= 10) {
					for (int k = y; k < y + 2; k++) {
						for (int j = x; j < x + 2; j++) {
							if (map[k][j] == 0 || visited[k][j] == true) {
								tmp = true; break;
							}
						}
					}
				}
				else tmp = true;
				if (tmp == false) {
					for (int k = y; k < y + 2; k++) {
						for (int j = x; j < x + 2; j++) {
							visited[k][j] = true;
						}
					}
					remain[1] -= 1;
					if (x + 2 < 10)func(y, x + 2, paper_cnt + 1);
					else func(y + 1, 0, paper_cnt + 1);
					remain[1] += 1;
					for (int k = y; k < y + 2; k++) {
						for (int j = x; j < x + 2; j++) {
							visited[k][j] = false;
						}
					}
				}
			}
			else if (i == 3 && remain[2] > 0) {
				bool tmp = false;
				if (y + 3 <= 10 && x + 3 <= 10) {
					for (int k = y; k < y + 3; k++) {
						for (int j = x; j < x + 3; j++) {
							if (map[k][j] == 0 || visited[k][j] == true) {
								tmp = true; break;
							}
						}
					}
				}
				else tmp = true;
				if (tmp == false) {
					for (int k = y; k < y + 3; k++) {
						for (int j = x; j < x + 3; j++) {
							visited[k][j] = true;
						}
					}
					remain[2] -= 1;
					if (x + 3 < 10)func(y, x + 3, paper_cnt + 1);
					else func(y + 1, 0, paper_cnt + 1);
					remain[2] += 1;
					for (int k = y; k < y + 3; k++) {
						for (int j = x; j < x + 3; j++) {
							visited[k][j] = false;
						}
					}
				}
			}
			else if (i == 4 && remain[3] > 0) {
				bool tmp = false;
				if (y + 4 <= 10 && x + 4 <= 10) {
					for (int k = y; k < y + 4; k++) {
						for (int j = x; j < x + 4; j++) {
							if (map[k][j] == 0 || visited[k][j] == true) {
								tmp = true; break;
							}
						}
					}
				}
				else tmp = true;
				if (tmp == false) {
					for (int k = y; k < y + 4; k++) {
						for (int j = x; j < x + 4; j++) {
							visited[k][j] = true;
						}
					}
					remain[3] -= 1;
					if (x + 4 < 10)func(y, x + 4, paper_cnt + 1);
					else func(y + 1, 0, paper_cnt + 1);
					remain[3] += 1;
					for (int k = y; k < y + 4; k++) {
						for (int j = x; j < x + 4; j++) {
							visited[k][j] = false;
						}
					}
				}
			}
			else if (i == 5 && remain[4] > 0) {
				bool tmp = false;
				if (y + 5 <= 10 && x + 5 <= 10) {
					for (int k = y; k < y + 5; k++) {
						for (int j = x; j < x + 5; j++) {
							if (map[k][j] == 0 || visited[k][j] == true) {
								tmp = true; break;
							}
						}
					}
				}
				else tmp = true;
				if (tmp == false) {
					for (int k = y; k < y + 5; k++) {
						for (int j = x; j < x + 5; j++) {
							visited[k][j] = true;
						}
					}
					remain[4] -= 1;
					if (x + 5 < 10)func(y, x + 5, paper_cnt + 1);
					else func(y + 1, 0, paper_cnt + 1);
					remain[4] += 1;
					for (int k = y; k < y + 5; k++) {
						for (int j = x; j < x + 5; j++) {
							visited[k][j] = false;
						}
					}
				}
			}
		}
	}
	return;
}
int main() {
	bool empty = true;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)empty = false;
		}
	}


	fill(remain, remain+5, 5);
	if(empty==false)func(0, 0, 0);
	else {
		printf("0\n");
		return 0;
	}

	if (ret == 2e9)printf("-1\n");
	else printf("%d\n", ret);
	return 0;
}
*/