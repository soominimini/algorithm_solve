/*
#include<stdio.h>
#include<algorithm>
using namespace std;

long long int cost = 0;

struct INFO {
	int fir_v, sec_v, edge;
};
int parent[10001];
INFO arr[10001];

int n, e;

int FIND(int child) {
	if (parent[child] == child) return child;
	else {
		int p  = FIND(parent[child]);
		parent[child] = p;
		return p;
	}
}
void Union(int node, int node2) {
	parent[node2] = node;
	return;
}

bool comp(const INFO &a, const INFO &b) {
	if (a.edge < b.edge)return true;
	else return false;
}
int main() {
	scanf("%d %d", &n, &e);

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &arr[i].fir_v, &arr[i].sec_v, &arr[i].edge);
	}
	sort(arr, arr + e, comp);
	for (int i = 0; i < e; i++) {
		//유니온 파인드 코스트 
		int p1 = FIND(arr[i].fir_v);
		int p2 = FIND(arr[i].sec_v);
		if (p1 != p2) {
			Union(p1, p2);
			cost +=arr[i].edge;
		}
	}
	printf("%lld", cost);
	return 0;
}
*/