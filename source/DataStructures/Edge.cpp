#include <DataStructures/Edge.h>


Edge::Edge(int source, int destination) {
    from = source;
    to = destination;
}//创建一条边

Edge::~Edge() {
}//消除一条边

int Edge::GetSource() const {
    return from;
}//获得边的起始点

int Edge::GetDestination() const {
    return to;
}//获得边的中点

