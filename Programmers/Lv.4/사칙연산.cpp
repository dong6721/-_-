#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//dp로 풀것
int solution(vector<string> arr)
{
	int answer = 1;
	vector<vector<int>> dpmax(500, vector<int>(500, -123456789));
	vector<vector<int>> dpmin(500, vector<int>(500, 123456789));
	for (int i = 0; i < arr.size(); i+=2)
	{
		dpmax[i][i] = atoi(arr[i].c_str());
		dpmin[i][i] = atoi(arr[i].c_str());		
	}

	for (int c = 2; c < arr.size(); c += 2)
	{
		for (int i = 0; i < arr.size(); i += 2)
		{
			for (int j = i + 1; j < i + c; j += 2)
			{
				if (j >= arr.size())
					break;
				if (arr[j] == "+")
				{
					dpmax[i][i + c] = max(dpmax[i][i + c], dpmax[i][j - 1] + dpmax[j + 1][i + c]);
					dpmin[i][i + c] = min(dpmin[i][i + c], dpmin[i][j - 1] + dpmin[j + 1][i + c]);
				}
				else if (arr[j] == "-")
				{
					dpmax[i][i + c] = max(dpmax[i][i + c], dpmax[i][j - 1] - dpmin[j + 1][i + c]);
					dpmin[i][i + c] = min(dpmin[i][i + c], dpmin[i][j - 1] - dpmax[j + 1][i + c]);
				}
			}
		}
	}
	return dpmax[0][arr.size() - 1];
}