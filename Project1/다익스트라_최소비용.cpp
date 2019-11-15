/*
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

struct INFO {
	int s, e, d;
};

int n, m;
int start_point, end_point;
vector<pair<int, int> > map[1002];
int dist[1002];
bool visited[1002];

int main() {
	scanf("%d %d", &n, &m);
	int s, e, d;
	INFO inf;
	fill(dist, dist + 1001, 2e9);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &e, &d);
		map[s].push_back({e,d});
	}
	scanf("%d %d", &start_point, &end_point);

	//시작 
	dist[start_point] = 0;
	visited[start_point] = true;
	for (int i = 0; i < map[start_point].size(); i++) {
		dist[map[start_point].at(i).first] = min(dist[map[start_point].at(i).first], map[start_point].at(i).second + 0);
	}
	int cnt = 1;
	while (cnt<n) {
		int min_val = 2e9, min_inx = n + 1;
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false && dist[i] != 2e9) {
				//시작 지점 제외
				if (dist[i] < min_val) {
					min_val = dist[i];
					min_inx = i;
				}
				else if (dist[i] == min_val) {
					if (i < min_inx) {
						min_val = dist[i];
						min_inx = i;
					}
				}
			}

		}
		//현재 가장 최솟값
		for (int i = 0; i < map[min_inx].size(); i++) {
			dist[map[min_inx].at(i).first] = min(dist[map[min_inx].at(i).first], map[min_inx].at(i).second + dist[min_inx]);
		}
		visited[min_inx] = true;
		cnt++;
	}
	printf("%d\n", dist[end_point]);
	return 0;
}
*/