/*
 *  15665번: N과 M (11)
 */

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 8
using namespace std;

int n, m;
int arr[MAX] = {0, };
int visited[MAX] = {0, };
vector<int> nums;

void ft_dfs(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return ;
    }
    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (temp != nums[i]) {
            visited[i] = 1;
            temp = nums[i];
            arr[depth] = nums[i];
            ft_dfs(depth + 1);
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
    sort(nums.begin(), nums.end());
    ft_dfs(0);
}