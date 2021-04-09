#ifndef DEPTH_FIRST_SEARCHER
#define DEPTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <DataStructures/Graph.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <queue>
#include <unordered_map>
using namespace std;


template <typename TGraph>
class DepthFirstSearcher {
public:
    static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action);
    static void dfs_vis_all(const TGraph *graph, int start, const function<void(int)> &action,unordered_map<int,int>&vis_all);
    static std::optional<int> FindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate);
    static std::optional<int> dfs_vis_opt(const TGraph *graph, int start, const std::function<bool(int)> &predicate,unordered_map<int,int>&vis_opt);
};


template<typename TGraph>
void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, const function<void(int)> &action) {
    unordered_map<int,int> vis;
    dfs_vis_all(graph,start,action,vis);
}

template<typename TGraph>
void DepthFirstSearcher<TGraph>::dfs_vis_all(const TGraph *graph, int start, const function<void(int)> &action,unordered_map<int,int>&vis_all) {
    vis_all[start] = 1;
    action(start);
    for(int u:graph->GetNeighbors(start)) {
        if(vis_all.find(u) == vis_all.end()) {
            dfs_vis_all(graph,u,action,vis_all);
        }
    }
}

template<typename TGraph>
std::optional<int>
DepthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, const function<bool(int)> &predicate) {
    unordered_map<int,int> vis;
    return dfs_vis_opt(graph,start,predicate,vis);
}

template<typename TGraph>
std::optional<int>
DepthFirstSearcher<TGraph>::dfs_vis_opt(const TGraph *graph, int start, const function<bool(int)> &predicate,unordered_map<int, int> &vis_opt) {
    vis_opt[start] = 1;
    if(predicate(start)) {
        return start;
    }
    for(int u:graph->GetNeighbors(start)) {
        if(vis_opt.find(u) == vis_opt.end()) {
            std::optional<int> ret;
            if((ret = FindFirstVertex(graph,u,predicate,vis_opt))) {
                return ret;
            }
        }
    }
    return nullopt;
}

#endif
