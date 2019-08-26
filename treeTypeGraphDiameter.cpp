#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef int Node;
typedef vector<vector<pair<Node, int>>> graph;

pair<Node, int> bfs(graph& g, int node_number, Node start) {
    queue<pair<Node, int>> q;
    q.push({start, 0});

    vector<bool> visited(node_number, false);
    visited[start] = true;

    int maxv = 0;
    Node maxpoint = start;

    while(q.size() > 0) {
        int n = q.size();
        for(int i = 0; i < n; i++) {
            auto top = q.front();
            q.pop();

            Node node = top.first;
            int cost = top.second;
            for(auto const & next : g[node]) {

                if(visited[next.first]) continue;
                visited[next.first] = true;
                q.push({next.first, cost + next.second});
                if(cost + next.second > maxv) {
                    maxv = cost + next.second;
                    maxpoint = next.first;
                }
            }
        }

    }
    return {maxpoint, maxv};
}

int main() {
    int n = 4;
    graph g = {{{1, 1}}, {{2, 2}, {0, 1}}, {{3, 3}, {1, 2}}, {{2, 3}}};
    Node start = 0;
    auto to = bfs(g, n, start);
    auto rslt = bfs(g, n, to.first);

    cout << to.first << "<->" << rslt.first << " " << rslt.second << endl;
    return 1;
}
