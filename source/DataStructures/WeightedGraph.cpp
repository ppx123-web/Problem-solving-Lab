#include <DataStructures/WeightedGraph.h>


WeightedGraph::WeightedGraph() : Graph() {
    Graph();
    edge_weight.clear();
}

WeightedGraph::~WeightedGraph() {
    Graph::clear();
    edge_weight.clear();
}

bool WeightedGraph::AddVertex(int vertex) {
    return Graph::AddVertex(vertex);
}

bool WeightedGraph::RemoveVertex(int vertex) {
    bool ans =  Graph::RemoveVertex(vertex);
    if(ans) {
        for(auto it:edge_weight) {
            auto temp = it.first;
            if(temp.first == vertex|| temp.second == vertex) {
                edge_weight.erase(temp);
            }
        }
    }
    return ans;
}

bool WeightedGraph::AddEdge(int vertex1, int vertex2, int weight) {
    bool ans = Graph::AddEdge(vertex1,vertex2);
    if(ans) {
        edge_weight[{vertex1,vertex2}] = weight;
        return true;
    } else {
        return false;
    }
}//添加了权重参数；如果添加某条边时图中已经存在了相同起点和终点的边（无论权重是多少），则什么都不做并返回false


bool WeightedGraph::RemoveEdge(int vertex1, int vertex2) {
    if(edge_weight.find({vertex1,vertex2}) == edge_weight.end()) return false;
    else {
        bool ans = Graph::RemoveEdge(vertex1,vertex2);
        if(ans) {
            edge_weight.erase({vertex1,vertex2});
        }
        return ans;
    }
}

int WeightedGraph::CountVertices() const {
    return Graph::CountVertices();

}

int WeightedGraph::CountEdges() const {
    return edge_weight.size();
}

bool WeightedGraph::ContainsVertex(int vertex) const {
    return Graph::ContainsVertex(vertex);
}

bool WeightedGraph::ContainsEdge(int vertex1, int vertex2) const {
    return Graph::ContainsEdge(vertex1,vertex2);
}

int WeightedGraph::GetWeight(int vertex1, int vertex2) const {
    auto it = edge_weight.find({vertex1,vertex2});
    if(it == edge_weight.end())  return 0;
    else return it->second;
}//查询v1指向v2的边的权重，如果这条边不存在则属于UB


std::vector<int> WeightedGraph::GetVertices() const {
    return Graph::GetVertices();
}

std::vector<WeightedEdge> WeightedGraph::GetEdges() const {
    std::vector<WeightedEdge> ans;
    std::vector<Edge> edges = Graph::GetEdges();
    for(const auto& item:edges) {
        auto it = edge_weight.find({item.GetSource(),item.GetDestination()});
        WeightedEdge e(item.GetSource(),item.GetDestination(),it->second);
        ans.push_back(e);
    }
    return ans;
}

std::vector<WeightedEdge> WeightedGraph::GetIncomingEdges(int vertex) const {
    std::vector<WeightedEdge> ans;
    std::vector<Edge> edges = Graph::GetIncomingEdges(vertex);
    for(const auto& item:edges) {
        auto it = edge_weight.find({item.GetSource(),item.GetDestination()});
        WeightedEdge e(item.GetSource(),item.GetDestination(),it->second);
        ans.push_back(e);
    }
    return ans;
}

std::vector<WeightedEdge> WeightedGraph::GetOutgoingEdges(int vertex) const {
    std::vector<WeightedEdge> ans;
    std::vector<Edge> edges = Graph::GetOutgoingEdges(vertex);
    for(const auto& item:edges) {
        auto it = edge_weight.find({item.GetSource(),item.GetDestination()});
        WeightedEdge e(item.GetSource(),item.GetDestination(),it->second);
        ans.push_back(e);
    }
    return ans;
}

int WeightedGraph::GetDegree(int vertex) const {
    return Graph::GetDegree(vertex);
}

std::vector<int> WeightedGraph::GetNeighbors(int vertex) const {
    return Graph::GetNeighbors(vertex);
}