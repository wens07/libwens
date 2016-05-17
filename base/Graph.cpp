//
// Created by wengqiang on 2016/5/17.
//
#include "include/Graph.h"


Graph::Graph(int v)
{
    this->v_num = v;
    adj = new std::list<int>[v];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int source)
{
    //mark all vertices are not visited
    bool *visited = new bool[v_num];
    for (int i = 0; i < v_num; ++i)
        visited[i] = false;

    //queue for BFS
    std::list<int> queue;

    //Mark source vertex visited, and push it to queue
    visited[source] = true;
    queue.push_back(source);

    std::list<int>::iterator iter;
    while (!queue.empty())
    {
        int vertex = queue.front();
        printf("%d\t", vertex);

        queue.pop_front();

        for (iter = std::begin(adj[vertex]); iter != std::end(adj[vertex]); ++iter)
        {
            if (!visited[*iter])
            {
                visited[*iter] = true;
                queue.push_back(*iter);
            }

        }

    }




}