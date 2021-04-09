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
    static unordered_map<int,int>vis_all;
    static unordered_map<int,int>vis_opt;
public:
    static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action);
    static std::optional<int> FindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate);
};

template <typename TGraph>
unordered_map<int,int> DepthFirstSearcher<TGraph>::vis_all;
template <typename TGraph>
unordered_map<int,int> DepthFirstSearcher<TGraph>::vis_opt;

template<typename TGraph>
void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, const function<void(int)> &action) {
    DepthFirstSearcher<TGraph>::vis_all[start] = 1;
    for(int u:graph->GetNeighbors(start)) {
        if(DepthFirstSearcher<TGraph>::vis_all.find(u) == DepthFirstSearcher<TGraph>::vis_all.end()) {
            action(u);
            VisitAllVertices(graph,u,action);
        }
    }

}

template<typename TGraph>
std::optional<int>
DepthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start, const function<bool(int)> &predicate) {
    DepthFirstSearcher<TGraph>::vis_opt[start] = 1;
    if(predicate(start)) {
        return start;
    }
    for(int u:graph->GetNeighbors(start)) {
        if(DepthFirstSearcher<TGraph>::vis_opt.find(u) == DepthFirstSearcher<TGraph>::vis_opt.end()) {
            return FindFirstVertex(graph,u,predicate);
        }
    }

    return NULL;
}

#endif
