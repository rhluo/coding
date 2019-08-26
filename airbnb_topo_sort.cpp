#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>


using  namespace std;
using graph_t = vector<vector<int>>;
const int MAXCHAR = 26;

void build(const vector<string> & lines, graph_t & graph, vector<int> & indegree){
    set<pair<char, char>> edges;
    const int line_size = lines.size();
    for(int i = 0; i < line_size; ++i)
        for(int j = i + 1; j < line_size; ++j){
            const string & a = lines[i];
            const string & b = lines[j];
            for(int k = 0; k < a.length(); ++k)
                if(a[k] != b[k]){
                    edges.emplace(a[k], b[k]);
                    break;
                }
            break;
        }
    for(const auto & edge:edges){
        cout<<edge.first<<"->"<<edge.second<<endl;
        int from = edge.first - 'a', to = edge.second - 'a';
        graph[from].push_back(to);
        indegree[to] ++;
    }
}

vector<int> topo_sort(const graph_t & graph, vector<int> & indegree){
    vector<int> result;
    queue<int> que;
    for(int i = 0; i < indegree.size(); ++i)
        if(indegree[i] == 0)
            que.emplace(i);
    while(!que.empty()){
        auto top = que.front(); que.pop();
        result.emplace_back(top);
        for(const auto & next:graph[top]){
            indegree[next]--;
            if(indegree[next] == 0)
                que.emplace(next);
        }
    }
    return result;
}

int main(){
    vector<string> lines = {
        "zy",
        "zx",
    };
    vector<bool> exists(MAXCHAR, false);
    for(const auto & line:lines)
        for(const auto & cha:line)
            exists[cha - 'a'] = true;
    graph_t graph(MAXCHAR);
    vector<int> indegree(MAXCHAR, 0);
    build(lines, graph, indegree);
    auto res = topo_sort(graph, indegree);

    for(const auto & it : res) {
        cout << it << " ";
    }
    cout << endl;

    string ans;
    for(const auto & cha:res)
        if(exists[cha])
            ans.push_back(cha + 'a');
    cout<<ans<<endl;
    return 0;
}
