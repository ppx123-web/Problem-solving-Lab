#ifndef BREADTH_FIRST_SEARCHER
#define BREADTH_FIRST_SEARCHER

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
class BreadthFirstSearcher {
 public:
    static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action);
    static std::optional<int> TryFindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate);
};

template<typename TGraph>
void BreadthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start, const function<void(int)> &action) {
    if(!graph->ContainsVertex(start)) return;
    unordered_map<int,int> vis;
    queue<int> q;
    q.push(start);
    action(start);
    vis[start] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int u : graph->GetNeighbors(cur)) {
            if(vis.find(u) == vis.end()) {
                q.push(u);
                vis[u] = 1;
                action(u);
            }
        }
    }
}

template<typename TGraph>
std::optional<int>
BreadthFirstSearcher<TGraph>::TryFindFirstVertex(const TGraph *graph, int start, const function<bool(int)> &predicate) {
    if(!graph->ContainsVertex(start)) return nullopt;
    unordered_map<int,int> vis;
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    if(predicate(start)) return start;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int u : graph->GetNeighbors(cur)) {
            if(vis.find(u) == vis.end()) {
                q.push(u);
                vis[u] = 1;
                if(predicate(u)) return u;
            }
        }
    }
    return nullopt;
}

#endif
