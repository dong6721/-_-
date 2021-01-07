#include <bits/stdc++.h>

using namespace std;

//�ִ�Ÿ� ���� 2���϶�, �׺��� 1������. �ִ�Ÿ����� 3���϶���, ���� �ִ�Ÿ��̹Ƿ� �ִ�Ÿ���.
vector<int> get_dist(vector<vector<int>>& pt, int start, int n)
{
	vector<int> list;
	int dist = 0;
	vector<int> distance(n + 1, -1);
	list.push_back(start);
	distance[start] = dist;
	while (!list.empty())
	{
		dist++;
		vector<int> n_list;
		for (auto t : list)
		{
			for (auto k : pt[t])
			{
				if (distance[k] == -1)
				{
					n_list.push_back(k);
					distance[k] = dist;
				}
			}
		}
		list = n_list;
	}
	return distance;
}


int solution(int n, vector<vector<int>> edges) {
	int answer = 0;
	vector<vector<int>> pt(n + 1, vector<int>());
	for (auto t : edges) {
		pt[t[0]].push_back(t[1]);
		pt[t[1]].push_back(t[0]);
	}

	//���� �� �Ÿ��� �� ������ ���ϱ�
	vector<int> distance = get_dist(pt, 1, n);
	int dist = *max_element(distance.begin(), distance.end());
	int start;
	for (int i = 1; i<distance.size(); i++)
	{
		if (dist == distance[i])
		{
			start = i;
			break;
		}
	}

	//�������� �������� ���� �� �Ÿ� ���ϱ�
	distance = get_dist(pt, start, n);
	dist = *max_element(distance.begin(), distance.end());
	int val = 0;
	int start2;
	for (int i = 1; i<distance.size(); i++)
	{
		if (dist == distance[i])
		{
			start2 = i;
			val++;
		}
	}
	int ans;
	if (val == 1)
	{
		//�ݴ��������� �ٽ��ѹ� calculate
		distance = get_dist(pt, start2, n);
		int val2 = 0;
		for (int i = 1; i<distance.size(); i++)
		{
			if (dist == distance[i])
			{
				val2++;
			}
		}
		if (val2 == 1)
			ans = dist - 1;
		else
			ans = dist;
	}
	else
		ans = dist;


	return ans;
}