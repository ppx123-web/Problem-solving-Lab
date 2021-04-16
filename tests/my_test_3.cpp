#include <DataStructures/WeightedGraph.h>
#include <Algorithms/DijkstraShortestPaths.h>

int main() {
    WeightedGraph<int> *g = new WeightedGraph<int>();
    g->AddVertex(1), g->AddVertex(2);
    g->AddEdge(1, 2, 100);

    ShortestPaths<WeightedGraph, int>
            *p = new DijkstraShortestPaths<WeightedGraph, int>(g, 1);
    delete g; // 注意这里，g被先手动摧毁了
    // 先销毁图的操作不符合对象的生命周期关系
    // 但是你没有办法防止用这个库的人这么写代码

    // 有什么方法能够防止任意实现下一行都不会出错？
    cout << p->TryGetDistanceTo(2).value_or(114514) << endl;
    delete p;
    return 0;
}