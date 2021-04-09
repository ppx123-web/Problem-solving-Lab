#include <Algorithms/BreadthFirstSearcher.h>

template <typename TGraph>
static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action) {
    unordered_map<int,int> vis;
    queue<int> q;
    q.push(start);
    action(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        vis[cur] = 1;
        for(int u : graph->GetNeighbors(cur)) {
            if(vis.find(u) == vis.end()) {
                q.push(u);
                action(u);
            }
        }
    }
}

template <typename TGraph>
static std::optional<int> FindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate) {
    unordered_map<int,int> vis;
    queue<int> q;
    q.push(start);
    if(predicate(start)) return start;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        vis[cur] = 1;
        for(int u : graph->GetNeighbors(cur)) {
            if(vis.find(u) == vis.end()) {
                q.push(u);
                if(predicate(u)) {
                    return u;
                }
            }
        }
    }
}