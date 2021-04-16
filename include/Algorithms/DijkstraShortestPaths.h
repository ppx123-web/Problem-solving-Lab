#ifndef DIJKSTRASHORTESTPATHS_H
#define DIJKSTRASHORTESTPATHS_H

#include <Algorithms/ShortestPaths.h>


template<template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue> {
private:
    unordered_map<int, TValue> vis;
    unordered_map<int, TValue> cost;
    unordered_map<int, TValue> parent;
    int source;
public:
    DijkstraShortestPaths(TGraph<TValue> *graph, int src);

    ~DijkstraShortestPaths();

public:
    bool HasPathTo(int destination) const;

    std::optional<TValue> TryGetDistanceTo(int destination) const;

    std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const;

    struct cmp {
        bool operator()(pair<int, TValue> ele_1, pair<int, TValue> ele_2) {
            return ele_1.second > ele_2.second;
        }
    };
};


template<template<typename> class TGraph, typename TValue>
DijkstraShortestPaths<TGraph, TValue>::DijkstraShortestPaths(TGraph<TValue> *graph, int src) {
    vis.clear();
    cost.clear();
    parent.clear();
    source = src;
    priority_queue<pair<int, TValue>, vector<pair<int, TValue>>, cmp> pq;
    cost[src] = 0;
    pq.emplace(src, cost[src]);
    while (!pq.empty()) {
        const pair<int, TValue> temp = pq.top();
        const int cur_idx = temp.first;
        const TValue cur_cost = temp.second;
        pq.pop();
        if (vis[cur_idx]) continue;
        vis[cur_idx] = 1;
        for (auto next:graph->GetOutgoingEdges(cur_idx)) {
            if (next.GetDestination() == cur_idx) continue;
            const int new_idx = next.GetDestination();
            const TValue new_cost = cur_cost + next.GetWeight();
            if (new_cost < cost[new_idx]) {
                pq.emplace(new_idx, new_cost);
                cost[new_idx] = new_cost;
                parent[new_idx] = cur_idx;
            }
        }
    }
}

template<template<typename> class TGraph, typename TValue>
DijkstraShortestPaths<TGraph, TValue>::~DijkstraShortestPaths() {

}

template<template<typename> class TGraph, typename TValue>
bool DijkstraShortestPaths<TGraph, TValue>::HasPathTo(int destination) const {
    return vis.find(destination) != vis.end();
}

template<template<typename> class TGraph, typename TValue>
optional<TValue> DijkstraShortestPaths<TGraph, TValue>::TryGetDistanceTo(int destination) const {
    if(vis.find(destination) != vis.end()) {
        return optional<TValue>(cost.find(destination)->second);
    } else return nullopt;
}

template<template<typename> class TGraph, typename TValue>
std::optional<std::vector<int>> DijkstraShortestPaths<TGraph, TValue>::TryGetShortestPathTo(int destination) const {
    vector<int> ans;
    int cur = destination;
    if(vis.find(destination) != vis.end()) {
        while (cur != source) {
            ans.insert(ans.begin(),cur);
            cur = parent.find(cur)->first;
        }
        ans.insert(ans.begin(),cur);
        return ans;
    } else return nullopt;
}

/*template<template<typename> class TGraph, typename TValue>
DijkstraShortestPaths<TGraph, TValue>::DijkstraShortestPaths(TGraph<TValue> *graph, int src) {
    vis.clear();
    cost.clear();
    priority_queue<pair<int, TValue>, vector<pair<int, TValue>>, cmp> pq;
    cost[src] = optional<TValue>();
    pq.emplace(src, cost[src]);
    while (!pq.empty()) {
        const pair<int, TValue> temp = pq.top();
        const int cur_idx = temp.first;
        const TValue cur_cost = temp.second;
        pq.pop();
        if (vis[cur_idx]) continue;
        vis[cur_idx] = 1;
        for (auto next:graph->GetOutgoingEdges(cur_idx)) {
            if (next.first == cur_idx) continue;
            const int new_idx = next.first;
            const int new_cost = cur_cost + next.second;
            if (new_cost < cost[new_idx]) {
                pq.emplace(new_idx, new_cost);
                cost[new_idx] = new_cost;
            }
        }
    }
}*/


#endif
