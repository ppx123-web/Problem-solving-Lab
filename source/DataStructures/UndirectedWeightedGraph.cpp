#include <DataStructures/UndirectedWeightedGraph.h>

UndirectedWeightedGraph::UndirectedWeightedGraph():WeightedGraph() {
}

UndirectedWeightedGraph::~UndirectedWeightedGraph() {
}

bool UndirectedWeightedGraph::AddVertex(int vertex) {
    return WeightedGraph::AddVertex(vertex);
}

bool UndirectedWeightedGraph::RemoveVertex(int vertex) {
    return WeightedGraph::RemoveVertex(vertex);
}

bool UndirectedWeightedGraph::AddEdge(int vertex1, int vertex2, int weight) {
    if(WeightedGraph::AddEdge(vertex1,vertex2,weight)) {
        bool temp = WeightedGraph::AddEdge(vertex2,vertex1,weight);
        return true;
    } else return false;
}

bool UndirectedWeightedGraph::RemoveEdge(int vertex1, int vertex2) {
    if(WeightedGraph::RemoveEdge(vertex1,vertex2)) {
        bool temp = WeightedGraph::RemoveEdge(vertex2,vertex1);
        return true;
    } else {
        return false;
    }
}

bool UndirectedWeightedGraph::ContainsVertex(int vertex) const {
    return WeightedGraph::ContainsVertex(vertex);
}

bool UndirectedWeightedGraph::ContainsEdge(int vertex1, int vertex2) const {
    return WeightedGraph::ContainsEdge(vertex1,vertex2);
}

int UndirectedWeightedGraph::GetWeight(int vertex1, int vertex2) const {
    return WeightedGraph::GetWeight(vertex1,vertex2);
}

std::vector<int> UndirectedWeightedGraph::GetVertices() const {
    return WeightedGraph::GetVertices();
}

std::vector<WeightedEdge> UndirectedWeightedGraph::GetEdges() const {
    std::vector<WeightedEdge> ans = WeightedGraph::GetEdges();
    std::map<pair<pair<int,int>,int>,int> s;
    for(auto it = ans.begin();it != ans.end();it++) {
        pair<pair<int,int>,int> e1,e2;
        e1.first.first = it->GetSource(); e1.first.second = it->GetDestination(); e1.second = it->GetWeight();
        e2.first.first = it->GetDestination(); e2.first.second = it->GetSource(); e2.second = it->GetWeight();
        auto front = s.find(e1);
        auto back = s.find(e2);
        if(front != s.end()) {
            s.erase(front);
        } else if(back != s.end()) {
            s.erase(back);
        } else {
            s[e1] = 1;
            ans.erase(it);
        }
    }
    return ans;
}