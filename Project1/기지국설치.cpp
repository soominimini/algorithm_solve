/*
#include <iostream>
#include <vector>
using namespace std;


//����Ʈ ����, ��ġ�� ������ ��ġ, ���� ����
int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int inx = 0; //stations�� ���� �ε���
	int location = 1; //1~n����


	while (location<=n) {
		//� ��Ȳ���� ������ ����?
		//�����̼��� ������ ����Ʈ�� �Ѱ��� ��
		//�� �˰����� ���� ������ �������� ��ġ�ϰ� ����Ʈ �ε����� �Ѿ�°�

		if ( inx>=stations.size() && location>=stations[inx]-w) {
			//�̹� �� �� �ִ� ������ �ٽ�ų� �������� ���� ���� �ȿ� �ִ� ���̶��
			location = stations[inx] + w + 1;
			inx++; //���� ���������� �̵�
			//���� ������ ���� ��ġ�� �̵�
		}
		else {
			//���� ������ ����Ʈ�� station�� ���� �ȿ� �������� �Ŷ�� ��ġ ����
			//������ ��ġ
			location += w * 2 + 1; //�̷��� ������ �� ������ ��ġ���� ����� ���� �� ������ �� �������� ��ġ�� �ؾ��ϱ� ������
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