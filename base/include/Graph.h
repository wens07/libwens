//
// Created by wengqiang on 2016/5/17.
//

#ifndef LEARN_TEST_GRAPH_H
#define LEARN_TEST_GRAPH_H
#include <stdio.h>
#include <list>

class Graph
{
    int v_num;
    std::list<int> *adj;

public:
    Graph(int v);
    void addEdge(int v, int w);
    void BFS(int source);

};

#endif //LEARN_TEST_GRAPH_H
