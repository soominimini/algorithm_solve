#include<stdio.h>
#include<queue>
using namespace std;

struct INFO {
	bool snake = false;
	bool apple = false;
	int dir;
};
struct DIR {
	int time;
	char direction;
};

int dy[] = { 0, +1, 0, -1 };
int dx[] = { +1, 0, -1, 0 };

INFO map[101][101];
int n, k, l;
queue<DIR>q;
int exit_second = 0;

void move(int beforeTail, int moveHead, int dir, int second) {
	int y = moveHead / 1000;
	int x = moveHead % 1000;

	//방향 바꾸기
	if (!q.empty()) {
		if (q.front().time == second) {
			char chr = q.front().direction;
			if (chr == 'D') {
				if (dir == 3) {
					dir = 0;
				}
				else dir++;
			}
			else {
				if (dir == 0) {
					dir = 3;
				}
				else dir--;
			}
			q.pop();
		}
	}

	if (y < 0 || x < 0 || y >= n || x >= n) {
		exit_second = second;
		return;
	}
	else if (map[y][x].snake == true) {
		exit_second = second;
		return;
	}
	//위는 종료 조건

	else if (map[y][x].apple == true) {
		int ny, nx;
		map[y][x].apple = false;
		map[y][x].snake = true;
		ny = y + dy[dir];
		nx = x + dx[dir];
		map[y][x].dir = dir;
		move(beforeTail, ny * 1000 + nx, dir, second + 1);
	}
	else {
		int tailx, taily;
		tailx = beforeTail % 1000;
		taily = beforeTail / 1000;
		int ny, nx;
		int tail_dir = map[taily][tailx].dir;

		map[y][x].snake = true;
		map[y][x].dir = dir;
		map[taily][tailx].snake = false;

		ny = y + dy[dir];
		nx = x + dx[dir];

		taily += dy[tail_dir];
		tailx += dx[tail_dir];

		move(taily * 1000 + tailx, ny * 1000 + nx, dir, second + 1);
	}
	return;
}

int main() {
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int row, col;
		scanf("%d %d", &row, &col);
		map[row - 1][col - 1].apple = true;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		DIR dir;
		scanf("%d %c", &dir.time, &dir.direction);
		q.push(dir);
	}
	map[0][0].snake = true;
	map[0][0].dir = 0;

	move(0, 1, 0, 1);
	printf("%d", exit_second);
	return 0;
}
