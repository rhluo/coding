//todo leetcode 210
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int>> graph_t;

vector<int> topo(graph_t graph, int num) {
    vector<int> indegree(num, 0);
    queue<int> zeroDegreeNode;
    vector<bool> visited(num, false);

    for(int i  = 0;i < num; i++) {
        for(const auto & to : graph[i]) {
            indegree[to]++;
        }
    }

    for(int i = 0;i < num;i++) {
        if (indegree[i] == 0) {
            zeroDegreeNode.push(i);
            visited[i] = true;
        }
    }

    vector<int> rslt;
    while(zeroDegreeNode.size() > 0) {
        int n = zeroDegreeNode.size();
        for(int i = 0;i < n; i++) {
            auto node = zeroDegreeNode.front();
            zeroDegreeNode.pop();
            rslt.push_back(node);

            for(const auto & to : graph[node]) {
                indegree[to]--;
            }
        }

        for(int i = 0;i < num;i++) {
            if(!visited[i] && indegree[i] == 0) {
                visited[i] = true;
                zeroDegreeNode.push(i);
            }
        }
    }

    if(rslt.size() == num) {
        return rslt;
    }
    return {};
}

int main() {
    int num = 4;
    graph_t graph = {{1,2}, {3}, {3}, {}};

    auto rslt = topo(graph, num);

    for(const auto & i : rslt) {
        cout << i << " ";
    }
    cout << endl;

    return 1;
}