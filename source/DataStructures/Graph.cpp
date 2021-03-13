#include <DataStructures/Graph.h>

Graph::Graph() {
    vertex_cnt = 0;
}

Graph::~Graph() {
    Graph::clear();
}

void Graph::clear() {
    vertex_in.clear();
    vertex_out.clear();
    vertex_set.clear();
    vertex_set.resize(0);
    edge_in.clear();
    edge_out.clear();
}


bool Graph::AddVertex(int vertex) {
    if (vertex_map.find(vertex) == vertex_map.end()) {
        vertex_map[vertex] = ++vertex_cnt;
        vertex_set.push_back(vertex);
        return true;
    } else {
        return false;
    }

}//加入节点

bool Graph::RemoveVertex(int vertex) {
    if (vertex_map.find(vertex) == vertex_map.end()) {
        return false;
    } else {
        vertex_map.erase(vertex);
        vertex_set.erase(std::find(vertex_set.begin(), vertex_set.end(), vertex));
        return true;
    }
}

template<class T>
void add(int v1, int v2, T x, unordered_map<int, vector<T>> *vec) {
    if (vec->find(v1) != vec->end()) {
        (*vec)[v1].push_back(x);
    } else {
        vector<T> temp;
        temp.push_back(x);
        (*vec)[v1] = temp;
    }
}

template<class T>
bool is_exit(int v1, int v2, T x, const unordered_map<int, vector<T>> *vec) {
    if (vec->find(v1) == vec->end()) {
        return false;
    } else {
        auto f = vec->find(v1)->second;
        auto it = find(f.begin(),f.end(),x);
        if(it == f.end()) {
            return false;
        } else {
            return true;
        }
    }
}

template<class T>
void delete_x(int v1, int v2, T x, unordered_map<int, vector<T>> *vec) {
    auto it = find((*vec)[v1].begin(),(*vec)[v1].end(),x);
    (*vec)[v1].erase(it);
}


bool Graph::AddEdge(int vertex1, int vertex2) {
    if (vertex_map.find(vertex1) == vertex_map.end() || vertex_map.find(vertex2) == vertex_map.end())
        return false;
    else {
        if(is_exit(vertex1,vertex2,vertex2,&vertex_out)) {
            return false;
        }
        add(vertex1, vertex2, vertex2, &vertex_out);
        add(vertex2, vertex1, vertex1, &vertex_in);
        Edge e(vertex1, vertex2);
        add(vertex1, vertex2, e, &edge_out);
        add(vertex2, vertex1, e, &edge_in);
        return true;
    }
}


bool Graph::RemoveEdge(int vertex1, int vertex2) {
    if (vertex_map.find(vertex1) == vertex_map.end() || vertex_map.find(vertex2) == vertex_map.end())
        return false;
    else {
        if(!is_exit(vertex1,vertex2,vertex2,&vertex_out)) {
            return false;
        }
        delete_x(vertex1, vertex2, vertex2, &vertex_out);
        delete_x(vertex2, vertex1, vertex1, &vertex_in);
        Edge e(vertex1, vertex2);
        delete_x(vertex1, vertex2, e, &edge_out);
        delete_x(vertex2, vertex1, e, &edge_in);
        return true;
    }

}


int Graph::CountVertices() const {
    return vertex_set.size();
}

int Graph::CountEdges() const {
    int ans = 0;
    for(const auto& item:edge_out) {
        ans += item.second.size();
    }
    return ans;
}

bool Graph::ContainsVertex(int vertex) const {
    return vertex_map.find(vertex) != vertex_map.end();
}

bool Graph::ContainsEdge(int vertex1, int vertex2) const {
    Edge e(vertex1, vertex2);
    return is_exit(vertex1,vertex2,e,&edge_out);
}

std::vector<int> Graph::GetVertices() const {
    return vertex_set;
}

std::vector<Edge> Graph::GetEdges() const {
    vector<Edge> ans;
    for(const auto& item:edge_out) {
        auto it = item.second;
        ans.insert(ans.end(),it.begin(),it.end());
    }
    return ans;
}


std::vector<Edge> Graph::GetIncomingEdges(int vertex) const {
    vector<Edge> temp;
    if (vertex_map.find(vertex) == vertex_map.end()) {
        return temp;
    } else {
        auto it = edge_in.find(vertex);
        if(it == edge_in.end()) {
            return temp;
        }
        return edge_in.find(vertex)->second;
    }
}

std::vector<Edge> Graph::GetOutgoingEdges(int vertex) const {
    vector<Edge> temp;
    if (vertex_map.find(vertex) == vertex_map.end()) {
        return temp;
    } else {
        if(edge_out.find(vertex) == edge_out.end()) return temp;
        return edge_out.find(vertex)->second;
    }
}

int Graph::GetDegree(int vertex) const {
    if (vertex_map.find(vertex) == vertex_map.end()) {
        return 0;
    } else {
        return edge_out.find(vertex)->second.size();
    }
}

std::vector<int> Graph::GetNeighbors(int vertex) const {
    if (vertex_map.find(vertex) == vertex_map.end()) {
        vector<int> temp;
        return temp;
    } else {
        return vertex_out.find(vertex)->second;
    }
}




/*
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
    vertex_set.resize(0);}



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
            edges_in[vertex_map[vertex2]].erase(find(edges_in[vertex_map[vertex2]].begin(),edges_in[vertex_map[vertex2]].end(),e));
            edges_out[vertex_map[vertex1]].erase(find(edges_out[vertex_map[vertex1]].begin(),edges_out[vertex_map[vertex1]].end(),e));
            vertexes[vertex_map[vertex1]].erase(find(vertexes[vertex_map[vertex1]].begin(),vertexes[vertex_map[vertex1]].end(),vertex2));

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

*/
