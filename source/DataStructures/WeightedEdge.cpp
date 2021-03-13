#include <DataStructures/WeightedEdge.h>

WeightedEdge::WeightedEdge(int source, int destination, int w) : Edge(source, destination) {
    Edge(source,destination);
    weight = w;
}

WeightedEdge::~WeightedEdge() {
    Edge::~Edge();
    weight = 0;
}

int WeightedEdge::GetSource() const {
    return Edge::GetSource();
}

int WeightedEdge::GetDestination() const {
    return Edge::GetDestination();
}

int WeightedEdge::GetWeight() const {
    return weight;
}
