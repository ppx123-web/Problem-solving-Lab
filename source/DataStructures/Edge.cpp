#include <DataStructures/Edge.h>


Edge::Edge(int source, int destination) {
    from = source;
    to = destination;
}//创建一条边

Edge::~Edge() {
    from = to = NONE_VERTEX;
}//消除一条边

int Edge::GetSource() const {
    //if(from == NONE_VERTEX) assert(0);
    return from;
}//获得边的起始点

int Edge::GetDestination() const {
    //if(to == NONE_VERTEX) assert(0);
    return to;
}//获得边的中点

