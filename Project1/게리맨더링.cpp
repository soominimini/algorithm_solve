/*
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int min_ret = 1e6;

int n;
int people[11];
vector<int>map[11];
int combi_ret[10];
int rest_combi[10];
bool combi_visited[11];

void rest_make(int depth) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < depth; j++) {
			if (i == combi_ret[j]) {
				flag = true;
				break;
			}
		}
		if (flag == false) {
			rest_combi[cnt++] = i;
		}
	}
	return;
}

bool combination_check(int depth) {
	queue<int>q;
	bool visited[11] = { false, };
	int cnt = 0;
	q.push(combi_ret[0]);

	if (depth >= 2) {//어차피 노드 하나이면 무조건 연결되어 있는 거니까
		while (!q.empty()) {
			int cur_node = q.front(); q.pop();
			visited[cur_node] = true;
			for (int i = 0; i < map[cur_node].size(); i++) {
				for (int j = 1; j < depth; j++) {//0번은 시작점이니까
					if (map[cur_node].at(i) == combi_ret[j] && visited[map[cur_node].at(i)] == false) {
						q.push(map[cur_node].at(i));
						visited[map[cur_node].at(i)] = true;
					}
				}
			}
		}
	}
	else return true;

	for (int i = 0; i < n; i++) {
		if (visited[i] == true) {
			cnt++;
		}
	}
	if (cnt == depth) return true;
	else return false;
}

bool rest_check(int depth) {
	queue<int>q;
	bool visited[11] = { false, };
	int cnt = 0;
	q.push(rest_combi[0]);

	if (depth >= 2) {//어차피 노드 하나이면 무조건 연결되어 있는 거니까
		while (!q.empty()) {
			int cur_node = q.front(); q.pop();
			visited[cur_node] = true;
			for (int i = 0; i < map[cur_node].size(); i++) {
				for (int j = 1; j < depth; j++) {//0번은 시작점이니까
					if(map[cur_node].at(i)==rest_combi[j] && visited[map[cur_node].at(i)] == false) {
						q.push(map[cur_node].at(i));
						visited[map[cur_node].at(i)] = true;
					}
				}
			}
		}
	}
	else return true;

	for (int i = 0; i < n; i++) {
		if (visited[i] == true) {
			cnt++;
		}
	}
	if (cnt == depth) return true;
	else return false;
}

void people_cal(int depth) {
	int tmp_combi = 0;
	int tmp_rest = 0;
	for(int i=0; i<depth; i++){
		tmp_combi+=people[combi_ret[i]];
	}
	for (int i = 0; i < n - depth; i++) {
		tmp_rest += people[rest_combi[i]];
	}
	min_ret = min(min_ret, abs(tmp_combi - tmp_rest));

	return;
}

void combinationFunc(int depth, int cnt, int inx) {
	if (cnt == depth) {

		//조합 만듦
		rest_make(depth);//조합이랑 나머지 선거구 만듦

		bool comCheck = combination_check(depth);
		bool restCheck = rest_check(n-depth);
		if (comCheck == 1 && restCheck == 1) {
			//둘다 선거구 연결되어 있다면
			people_cal(depth);
		}
	}
	else {
		for (int i = inx; i < n; i++) {
			if (combi_visited[i] == false) {
				combi_visited[i] = true;
				combi_ret[cnt] = i;
				combinationFunc(depth, cnt+1, inx+1);
				combi_visited[i] = false;
			}
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &people[i]);
	}
	for (int i = 0; i < n; i++) {
		int input;
		scanf("%d", &input);
		for (int j = 0; j < input; j++) {
			int node;
			scanf("%d", &node);
			map[i].push_back(node-1);
		}
	}
	for (int i = 1; i < n; i++) {
		combinationFunc(i, 0, 0);
	}

	if (min_ret == 1e6) printf("-1\n");
	else printf("%d\n", min_ret);

	return 0;
}
*/