#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>
#include <bits/stdc++.h>
#include <Algorithms/BreadthFirstSearcher.h>
using namespace std;


template<template<typename> class TGraph, typename TValue>
class ShortestPaths {

public:
    ShortestPaths();

    ShortestPaths(const TGraph<TValue> *graph, int source);

    virtual ~ShortestPaths();

public:
    virtual bool HasPathTo(int destination) const;

    virtual std::optional<TValue> TryGetDistanceTo(int destination) const;

    virtual std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const;
};




#endif
