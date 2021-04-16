#include <Algorithms/DijkstraShortestPaths.h>

template<template<typename> class TGraph, typename TValue>
DijkstraShortestPaths<TGraph, TValue>::DijkstraShortestPaths(TGraph<TValue> *graph, int src) {
    vis.clear();
    cost.clear();
    parent.clear();
    source = src;
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
        return optional<TValue>(cost[destination]);
    } else return nullopt;
}

template<template<typename> class TGraph, typename TValue>
std::optional<std::vector<int>> DijkstraShortestPaths<TGraph, TValue>::TryGetShortestPathTo(int destination) const {
    vector<int> ans;
    int cur = destination;
    if(vis.find(destination) != vis.end()) {
        while (cur != source) {
            ans.insert(ans.begin(),cur);
            cur = parent[cur];
        }
        ans.insert(ans.begin(),cur);
        return ans;
    } else return nullopt;
}
