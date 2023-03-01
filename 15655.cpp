/*
 *  15655번: N과 M (6)
 */

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = {0, };
int visited[MAX] = {0, };
vector<int> nums;

void ft_dfs(int num, int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
    for (int i = num; i < n; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            arr[depth] = nums[i];
            ft_dfs(i + 1, depth + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        nums.push_back(input);
    }
    // 사전 순으로 증가해야하므로 오름차순으로 정렬
    sort(nums.begin(), nums.end());
    ft_dfs(0, 0);
}