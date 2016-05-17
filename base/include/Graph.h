//
// Created by wengqiang on 2016/5/17.
//

#ifndef WENSLIB_GRAPH_H
#define WENSLIB_GRAPH_H
#include <stdio.h>
#include <list>

/**
 * this class is a graph using adjacency list representation
 */
class Graph
{
    int v_num;
    std::list<int> *adj;

public:
    Graph(int v);
    void addEdge(int v, int w);
    void BFS(int source);
    void DFS(int source);

};

/**
 * This class represents a directed graph with weight using adjacency list representation
 */

#define INF 0x3f3f3f3f
// weight and vertex pair for every edge
typedef std::pair<double, int> weightVertexPair;
class GraphWeight
{
    int v_num;
    std::list<weightVertexPair> *adj;

public:
    GraphWeight(int v);
    void addEdge(int u, int v, int weight);
    void shortestPath_by_set(int source);

};

#endif //WENSLIB_GRAPH_H
