#ifndef DIJKSTRASHORTESTPATHS_H
#define DIJKSTRASHORTESTPATHS_H

#include <Algorithms/ShortestPaths.h>


template<template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue> {

public:
    DijkstraShortestPaths(TGraph<TValue> *graph, int src);

    ~DijkstraShortestPaths() = default;

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
    ShortestPaths<TGraph,TValue>::vis.clear();
    ShortestPaths<TGraph,TValue>::cost.clear();
    ShortestPaths<TGraph,TValue>::parent.clear();
    ShortestPaths<TGraph,TValue>::source = src;
    priority_queue<pair<int, TValue>, vector<pair<int, TValue>>, cmp> pq;
    ShortestPaths<TGraph,TValue>::cost[src] = TValue();
    pq.emplace(src, ShortestPaths<TGraph,TValue>::cost[src]);
    while (!pq.empty()) {
        const pair<int, TValue> temp = pq.top();
        const int cur_idx = temp.first;
        const TValue cur_cost = temp.second;
        pq.pop();
        if (ShortestPaths<TGraph,TValue>::vis.find(cur_idx) != ShortestPaths<TGraph,TValue>::vis.end()) continue;
        ShortestPaths<TGraph,TValue>::vis[cur_idx] = 1;
        for (auto next:graph->GetOutgoingEdges(cur_idx)) {
            if (next.GetDestination() == cur_idx) continue;
            const int new_idx = next.GetDestination();
            const TValue new_cost = cur_cost + next.GetWeight();
            if (new_cost < ShortestPaths<TGraph,TValue>::cost[new_idx]) {
                pq.emplace(new_idx, new_cost);
                ShortestPaths<TGraph,TValue>::cost[new_idx] = new_cost;
                ShortestPaths<TGraph,TValue>::parent[new_idx] = cur_idx;
            }
        }
    }
}


template<template<typename> class TGraph, typename TValue>
bool DijkstraShortestPaths<TGraph, TValue>::HasPathTo(int destination) const {
    return ShortestPaths<TGraph,TValue>::HasPathTo(destination);
}

template<template<typename> class TGraph, typename TValue>
optional<TValue> DijkstraShortestPaths<TGraph, TValue>::TryGetDistanceTo(int destination) const {
    return ShortestPaths<TGraph,TValue>::TryGetDistanceTo(destination);
}

template<template<typename> class TGraph, typename TValue>
std::optional<std::vector<int>> DijkstraShortestPaths<TGraph, TValue>::TryGetShortestPathTo(int destination) const {
    return ShortestPaths<TGraph,TValue>::TryGetShortestPathTo(destination);
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
