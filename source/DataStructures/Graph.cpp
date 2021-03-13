#include <DataStructures/Graph.h>

Graph::Graph() {
    Edge e(0,0);
    edges.clear();
    edges.resize(0,e);
    vertex_cnt = 0;

    for(int i = 0;i < MAX_VERTEX;i++) {
        edges_in[i].clear();
        edges_in[i].resize(0,e);
        edges_out[i].clear();
        edges_out[i].resize(0,e);
    }
    for(auto & it : vertexes) {
        it.clear();
        it.resize(0);
    }
    vertex_set.clear();
    vertex_set.resize(0);

}

Graph::~Graph() {
    Edge e(0,0);
    vertex_cnt = 0;
    edges.clear();
    edges.resize(0,e);
    for(int i = 0;i < MAX_VERTEX;i++) {
        edges_in[i].clear();
        edges_in[i].resize(0,e);
        edges_out[i].clear();
        edges_out[i].resize(0,e);
    }
    for(auto & it : vertexes) {
        it.clear();
        it.resize(0);
    }
    vertex_set.clear();
    vertex_set.resize(0);
}

void Graph::clear() {
    Edge e(0,0);
    vertex_cnt = 0;
    edges.clear();
    edges.resize(0,e);
    for(int i = 0;i < MAX_VERTEX;i++) {
        edges_in[i].clear();
        edges_in[i].resize(0,e);
        edges_out[i].clear();
        edges_out[i].resize(0,e);
    }
    for(auto & it : vertexes) {
        it.clear();
        it.resize(0);
    }
    vertex_set.clear();
    vertex_set.resize(0);
}

bool Graph::AddVertex(int vertex) {
    if(vertex_map.find(vertex) == vertex_map.end()) {
        vertex_map[vertex] = ++vertex_cnt;
        vertex_set.push_back(vertex);
        return true;
    } else {
        return false;
    }

}//加入节点

bool Graph::RemoveVertex(int vertex) {
    if(vertex_map.find(vertex) == vertex_map.end()) {
        return false;
    } else {
        vertex_map.erase(vertex);
        vertex_set.erase(std::find(vertex_set.begin(),vertex_set.end(),vertex));
        return true;
    }
}

bool Graph::AddEdge(int vertex1, int vertex2) {
    if(vertex_map.find(vertex1) == vertex_map.end() || vertex_map.find(vertex2) == vertex_map.end())
        return false;
    else {
        Edge e(vertex1,vertex2);
        auto it = find(edges.begin(),edges.end(),e);
        if(it == edges.end()) {
            edges.push_back(e);
            edges_out[vertex_map[vertex1]].push_back(e);
            edges_in[vertex_map[vertex2]].push_back(e);
            vertexes[vertex_map[vertex1]].push_back(vertex2);
            return true;
        } else {
            return false;
        }
    }


}

bool Graph::RemoveEdge(int vertex1, int vertex2) {
    if(vertex_map.find(vertex1) == vertex_map.end() || vertex_map.find(vertex2) == vertex_map.end())
        return false;
    else {
        Edge e(vertex1,vertex2);
        auto it = find(edges.begin(),edges.end(),e);
        if(it == edges.end()) {
            return false;
        } else {
            //auto in = find(edges_in[vertex_map[vertex2]].begin(),edges_in[vertex_map[vertex2]].end(),e);
            //edges_in[vertex_map[vertex2]].erase(in);

            //auto out = find(edges_out[vertex_map[vertex1]].begin(),edges_out[vertex_map[vertex1]].end(),e);
            //edges_out[vertex_map[vertex1]].erase(in);

            edges.erase(it);
            return true;
        }
    }

}




int Graph::CountVertices() const {
    return vertex_set.size();
}

int Graph::CountEdges() const {
    return edges.size();
}

bool Graph::ContainsVertex(int vertex) const {
    return vertex_map.find(vertex) != vertex_map.end();
}

bool Graph::ContainsEdge(int vertex1, int vertex2) const {
    Edge e(vertex1,vertex2);
    return std::find(edges.begin(),edges.end(),e) != edges.end();
}

std::vector<int> Graph::GetVertices() const {
    return vertex_set;
}

std::vector<Edge> Graph::GetEdges() const {
    return edges;
}


std::vector<Edge> Graph::GetIncomingEdges(int vertex) const{
    if(vertex_map.find(vertex) == vertex_map.end()) {
        return  edges_in[0];
    } else {
        int temp = vertex_map.find(vertex)->second;
        return edges_in[temp];
    }

}

std::vector<Edge> Graph::GetOutgoingEdges(int vertex) const{
    if(vertex_map.find(vertex) == vertex_map.end()) {
        return  edges_out[0];
    } else {
        int temp = vertex_map.find(vertex)->second;
        return edges_out[temp];
    }
}

int Graph::GetDegree(int vertex) const{
    if(vertex_map.find(vertex) == vertex_map.end()) {
        return  0;
    } else {
        int temp = vertex_map.find(vertex)->second;
        return edges_out[temp].size();
    }
}

std::vector<int> Graph::GetNeighbors(int vertex) const{
    if(vertex_map.find(vertex) == vertex_map.end()) {
        return  vertexes[0];
    } else {
        int temp = vertex_map.find(vertex)->second;
        return vertexes[temp];
    }
}

