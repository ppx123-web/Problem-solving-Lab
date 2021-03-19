#include <DataStructures/UndirectedGraph.h>

UndirectedGraph::UndirectedGraph():Graph() {

}

UndirectedGraph::~UndirectedGraph() {
}

bool UndirectedGraph::AddVertex(int vertex) {
    return Graph::AddVertex(vertex);
}

bool UndirectedGraph::RemoveVertex(int vertex) {
    return Graph::RemoveVertex(vertex);
}

bool UndirectedGraph::AddEdge(int vertex1, int vertex2) {
    if(Graph::AddEdge(vertex1,vertex2)) {
        bool temp = Graph::AddEdge(vertex2,vertex1);
        return true;
    } else return false;
}

bool UndirectedGraph::RemoveEdge(int vertex1, int vertex2) {
    if(Graph::RemoveEdge(vertex1,vertex2)) {
        bool temp = Graph::RemoveEdge(vertex2,vertex1);
        return true;
    } else return false;
}

int UndirectedGraph::CountVertices() const {
    return Graph::CountVertices();
}

int UndirectedGraph::CountEdges() const {
    int ans = Graph::CountEdges();
    for(auto item:Graph::GetVertices()) {
        if(Graph::ContainsEdge(item,item)) {
            ans++;
        }
    }
    return ans/2;
}

bool UndirectedGraph::ContainsVertex(int vertex) const {
    return Graph::ContainsVertex(vertex);
}

bool UndirectedGraph::ContainsEdge(int vertex1, int vertex2) const {
    return Graph::ContainsEdge(vertex1,vertex2);
}

std::vector<int> UndirectedGraph::GetVertices() const {
    return Graph::GetVertices();
}

std::vector<Edge> UndirectedGraph::GetEdges() const {
    std::vector<Edge> ans = Graph::GetEdges();
    std::map<pair<int,int>,int> s;
    for(auto it = ans.begin();it != ans.end();it++) {
        auto front = s.find({it->GetSource(),it->GetDestination()});
        auto back = s.find({it->GetDestination(),it->GetSource()});
        if(front != s.end()) {
            s.erase(front);
        } else if(back != s.end()) {
            s.erase(back);
        } else {
            s[{it->GetSource(),it->GetDestination()}] = 1;
            ans.erase(it);
        }
    }
    return ans;
}

std::vector<Edge> UndirectedGraph::GetIncomingEdges(int vertex) const {
    return Graph::GetIncomingEdges(vertex);
}

std::vector<Edge> UndirectedGraph::GetOutgoingEdges(int vertex) const {
    return Graph::GetOutgoingEdges(vertex);
}


int UndirectedGraph::GetDegree(int vertex) const {
    vector<int> deg = Graph::GetNeighbors(vertex);
    for(auto it:deg) {
        if(it == vertex) {
            return deg.size() + 1;
        }
    }
    return deg.size();
}

std::vector<int> UndirectedGraph::GetNeighbors(int vertex) const {
    return Graph::GetNeighbors(vertex);
}
