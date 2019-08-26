#include <vector>
#include <queue>
#include <iostream>
#include "algorithm"

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct mycmp{
    bool operator()(pair<int,Interval> &p1,pair<int,Interval> &p2){
        return p1.second.start > p2.second.start;
    }
};
vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
    vector<Interval> result;
    vector<int> index(schedule.size(),1);
    priority_queue<pair<int,Interval>,vector<pair<int,Interval>>,mycmp> pq;
    for(int i = 0;i != schedule.size();++i)
        pq.push(make_pair(i,schedule[i][0]));
    int timestamp = pq.top().second.end;
    cout << timestamp << endl;
    while(!pq.empty()){
        pair<int,Interval> top = pq.top();
        if(top.second.start > timestamp){
            Interval interval(timestamp,top.second.start);
            result.push_back(interval);
            timestamp = top.second.end;
        }
        else{
            timestamp = max(timestamp,top.second.end);
        }
        pq.pop();
        if(index[top.first] != schedule[top.first].size()){
            pq.push(make_pair(top.first,schedule[top.first][index[top.first]]));
            index[top.first]++;
        }

        cout << timestamp << endl;
    }
    return result;
}

int main(){
    vector<vector<Interval>> input;
    vector<Interval> p0;
    p0.push_back(Interval(1,3));
    p0.push_back(Interval(6,7));

    vector<Interval> p1;
    p1.push_back(Interval(1,2));
    p1.push_back(Interval(2,4));

    vector<Interval> p2;
    p2.push_back(Interval(2,5));
    p2.push_back(Interval(9,12));

    input.push_back(p0);
    input.push_back(p1);
    input.push_back(p2);

    auto rslt = employeeFreeTime(input);
    for(const auto & it : rslt) {
        cout << it.start << " " << it.end << endl;
    }
}

/*
 * [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]*/