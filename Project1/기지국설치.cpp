/*
#include <iostream>
#include <vector>
using namespace std;


//아파트 개수, 설치된 기지국 위치, 전달 범위
int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int inx = 0; //stations를 도는 인덱스
	int location = 1; //1~n까지


	while (location<=n) {
		//어떤 상황에서 종료할 거지?
		//로케이션이 마지막 아파트를 넘겼을 때
		//이 알고리즘은 구역 단위로 기지국을 설치하고 아파트 인덱스를 넘어가는것

		if ( inx>=stations.size() && location>=stations[inx]-w) {
			//이미 쓸 수 있는 기지국 다썼거나 기지국의 서비스 범위 안에 있는 것이라면
			location = stations[inx] + w + 1;
			inx++; //다음 기지국으로 이동
			//서비스 범위가 끝난 위치로 이동
		}
		else {
			//따라서 현재의 아파트가 station의 범위 안에 못들어오는 거라면 설치 가능
			//범위로 설치
			location += w * 2 + 1; //이렇게 따졌을 때 범위가 겹치더라도 상관이 없는 게 어차피 이 구역에는 설치를 해야하기 때문에
			answer++;
		}
	}


	return answer;
}

int main() {
	vector<int>v = {4,11};
	solution(11,v, 1);
	return 0;
}
*/