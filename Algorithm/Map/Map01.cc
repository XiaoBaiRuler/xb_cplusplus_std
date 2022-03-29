#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
/**
 * https://leetcode-cn.com/problems/the-time-when-the-network-becomes-idle/
 * @brief 2039. 网络空闲的时刻
 * 
 * @param edges 
 * @param patience 
 * @return int 
 */
int netWorkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience);

int main(){
    vector<vector<vector<int>>> edgess = {
        {
            {0, 1}, {1, 2}
        },
        {
            {0, 1}, {0, 2}, {1, 2}
        }
    };
    vector<vector<int>> patiences = {
        {0, 2, 1},
        {0, 10, 10}
    };
    int n = edgess.size();
    for (int i = 0; i < n; ++ i){
        cout << netWorkBecomesIdle(edgess[i], patiences[i]) << endl;
    }

    return EXIT_SUCCESS;
}

int netWorkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience){
    int n = patience.size();
    vector<vector<int>> hash(n, vector<int>());
    for (vector<int>& edge : edges){
        hash[edge[0]].push_back(edge[1]);
    }
    vector<int> distance(n, INT_MAX);
    vector<bool> check(n, false);
    distance[0] = 0;
    queue<int> que;
    que.push(0);
    while (!que.empty()){
        int now = que.front();
        que.pop();
        check[now] = true;
        for (int i : hash[now]){
            distance[i] = min(distance[i], distance[now] + 1);
            if (!check[i]){
                que.push(i);
            }
        }   
    }
    for (int i : distance){
        cout << i << " ";
    }
    cout << endl;
    int res = 0;
    for (int i = 1; i < n; ++ i){
        int real = patience[i] * ((2 * distance[i] - 1) / patience[i]) + 2 * distance[i] + 1;
        res = max(real, res);
    }
    return res;
}