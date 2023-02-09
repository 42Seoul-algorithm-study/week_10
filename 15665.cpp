// n과 m11

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace	std;

int	n, m;
int	numset[10];
int	arr[10];

void	recur(int depth)
{
	if (depth == m) // 종료조건
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' '; // 수열하나 출력
		cout << '\n';
		return ;
	}
	int	vis = -1;
	for (int i = 0; i < n; i++) // 1부터 n까지 숫자에 대해 반복
	{
		if (vis != numset[i])
		{
			arr[depth] = numset[i]; // depth가 수열의 개수만큼
			vis = numset[i];
			recur(depth + 1); // 한 수열에 대해 나머지 수 넣어주고 출력
		}
	}
}

int	main()
{
	ios::sync_with_stdio(0),cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> numset[i];
	sort(numset, numset + n);
	recur(0);
}
