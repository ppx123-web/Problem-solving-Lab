#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>
#include <bits/stdc++.h>
#include <Algorithms/BreadthFirstSearcher.h>
using namespace std;


template<template<typename> class TGraph, typename TValue>
class ShortestPaths {
protected:
    unordered_map<int, TValue> vis;
    unordered_map<int, TValue> cost;
    unordered_map<int, TValue> parent;
    int source;
public:
    ShortestPaths() {
    }

    ShortestPaths(const TGraph<TValue> *graph, int source) {
    }

    virtual ~ShortestPaths() {
    }

public:
    virtual bool HasPathTo(int destination) const {
        return vis.find(destination) != vis.end();
    }

    virtual std::optional<TValue> TryGetDistanceTo(int destination) const {
        if(vis.find(destination) != vis.end()) {
            return optional<TValue>(cost.find(destination)->second);
        } else return nullopt;
    }

    virtual std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const {
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
};




#endif
