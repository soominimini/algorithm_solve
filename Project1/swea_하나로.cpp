#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct INFO {
	double  cost;
	int start_node, end_node;
};

vector<INFO> v;
int x_store[1001];
int y_store[1001];
int parent[1001];
double E;
string e;
int N;
double ret_cost = 0;

bool cmp(const INFO &a, const INFO &b) {
	if (a.cost < b.cost)return true;
	else return false;
}

void Union(int p, int c) {
	parent[c] = p;
	return;
}

int  Find(int child) {//부모 찾기
	if (parent[child] != child) {
		int p = Find(parent[child]);
		parent[child] = p;
		return p;
	}
	else return child;
}
double network() {
	double tmp_ret = 0;
	int inx = 0;
	for (int n = 0; n < N; n++) {
		parent[n] = n;
	}

	for (int i = 0; i < v.size(); i++) {
		int find_root_node1 = Find(v[i].start_node);
		int find_root_node2 = Find(v[i].end_node);
		if (find_root_node1 != find_root_node2) {
			inx++;
			Union(find_root_node1, find_root_node2);
			tmp_ret += v.at(i).cost;
		}
		if (inx == N - 1)break;
	}
	return tmp_ret;
}

void cost_put() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j != i) {
				double root = pow(x_store[i] - x_store[j], 2) + pow(y_store[i] - y_store[j], 2);
				//	double root = sqrt(root_tmp); //루트까지 끝남

				INFO inf;
				inf.cost = root;
				inf.start_node = i;
				inf.end_node = j;
				v.push_back(inf);
			}
		}
	}
	return;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int n = 0; n < N; n++) {
			scanf("%d", &x_store[n]);
		}
		for (int n = 0; n < N; n++) {
			scanf("%d", &y_store[n]);
		}
		cin >> e;
		E = atof(e.c_str());
		cost_put();
		sort(v.begin(), v.end(), cmp);
		double tmp_ret = network();// 최솟값
	//	ret_cost = sqrt(tmp_ret);
		long long int ret = round(tmp_ret*E);
		printf("#%d %lld\n", t + 1, ret);

		v.clear(); ret_cost = 0;
		for (int i = 0; i < N; i++) {
			x_store[i] = 0;
			y_store[i] = 0;
		}
	}
	return 0;
}