#include <DataStructures/WeightedGraph.h>


WeightedGraph::WeightedGraph() : Graph() {
    Graph();
    edge_weight.clear();
}

WeightedGraph::~WeightedGraph() {
    Graph::clear();
    edge_weight.clear();
    vertex_in.clear();
    vertex_out.clear();
}

bool WeightedGraph::AddVertex(int vertex) {
    return Graph::AddVertex(vertex);
}

bool WeightedGraph::RemoveVertex(int vertex) {
    return Graph::RemoveVertex(vertex);
}

bool WeightedGraph::AddEdge(int vertex1, int vertex2, int weight) {
    bool ans = Graph::AddEdge(vertex1,vertex2);
    if(ans) {
        edge_weight[{vertex1,vertex2}] = weight;
        WeightedEdge e(vertex1,vertex2,weight);
        if(vertex_in.find(vertex2) != vertex_in.end()) {
            vertex_in[vertex2].push_back(e);
        } else {
            std::vector<WeightedEdge> temp1;
            temp1.push_back(e);
            vertex_in[vertex2] = temp1;
        }

        if(vertex_out.find(vertex1) != vertex_in.end()) {
            vertex_in[vertex1].push_back(e);
        } else {
            std::vector<WeightedEdge> temp2;
            temp2.push_back(e);
            vertex_out[vertex1] = temp2;
        }
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
    return Graph::CountEdges();

}

int WeightedGraph::CountEdges() const {
    return Graph::CountEdges();
}

bool WeightedGraph::ContainsVertex(int vertex) const {
    return Graph::ContainsVertex(vertex);
}

bool WeightedGraph::ContainsEdge(int vertex1, int vertex2) const {
    return Graph::ContainsEdge(vertex1,vertex2);
}

int WeightedGraph::GetWeight(int vertex1, int vertex2) const {
    auto it = edge_weight.find({vertex1,vertex2});
    if(it == edge_weight.end())  return -1;
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