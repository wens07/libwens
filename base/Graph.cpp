//
// Copyright (c) 2016. All rights reserved.
// http://github.com/wens07
//
// Author: wengqiang (wens at qiangweng dot site)
// Date: 2016/5/18
//
// Use of this source code is governed by a BSD-style license
// that can be found in the License file.
//
//


#include <stack>
#include <queue>
#include <set>
#include "include/Graph.h"

/**
 *  following is for Graph class
 */
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
        printf("%.1d\t", vertex);

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

    printf("\n");



}

void  Graph::DFS_NO_RECUR(int source)
{
    //mark all vertices are not visited
    bool *visited = new bool[v_num];
    for (int i = 0; i < v_num; ++i)
        visited[i] = false;

    //queue for BFS
    std::stack<int> st;

    //Mark source vertex visited, and push it to queue
    visited[source] = true;
    st.push(source);

    std::list<int>::iterator iter;
    while (!st.empty())
    {
        int vertex = st.top();
        printf("%.1d\t", vertex);

        st.pop();

        for (iter = std::begin(adj[vertex]); iter != std::end(adj[vertex]); ++iter)
        {
            if (!visited[*iter])
            {
                visited[*iter] = true;
                st.push(*iter);
            }

        }

    }

    printf("\n");


}

void Graph::DFS_RECUR_UTIL(int source, bool visited[])
{
    // if not visited, set it visited
    if (!visited[source])
        visited[source] = true;
    printf("%.1d\t", source);

    // visit adjacent vertex recursively
    std::list<int>::iterator iter;
    for (iter = std::begin(adj[source]); iter != std::end(adj[source]); ++iter)
    {
        if (!visited[*iter])
            DFS_RECUR_UTIL(*iter, visited);
    }
}

void Graph::DFS_RECUR(int source)
{
    bool *visited = new bool[v_num];
    for (int i = 0; i < v_num; ++i)
        visited[i] = false;

    DFS_RECUR_UTIL(source, visited);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool instack[])
{
    //set whether visited and instack
    visited[v] = true;
    instack[v] = true;

    // transfer all vertex that adjacent to v
    std::list<int>::iterator iter;
    for (iter = std::begin(adj[v]); iter != std::end(adj[v]); ++iter)
    {
        if (!visited[*iter] && isCyclicUtil(*iter, visited, instack))
            return true;
        else if(instack[*iter])
            return true;
    }

    //get out of recursive stack
    instack[v] = false;
    return  false;
}
bool Graph::isCyclic()
{
    // mark all vertex unvisited and not included in recursive stack
    bool *visited = new bool[v_num];
    bool *instack = new  bool[v_num];

    for (int i = 0; i < v_num; ++i)
    {
        visited[i] = false;
        instack[i] = false;
    }

    for (int i = 0; i < v_num; ++i)
    {
        if (isCyclicUtil(i, visited, instack))
            return true;
    }

    return false;
}

/**
 *  following is GraphWeight class
 */
GraphWeight::GraphWeight(int v)
{
    this->v_num = v;
    this->adj = new std::list<weightVertexPair>[v];
}

void GraphWeight::addEdge(int u, int v, int weight)
{
    adj[u].push_back(std::make_pair(weight, v));
    adj[v].push_back(std::make_pair(weight, u));
}

void GraphWeight::shortestPath_by_set(int source)
{
    //set to store pair<distance, vertex>
    std::set<weightVertexPair> ds_set;
    //vector to store  distances from vertex to source
    std::vector<double> ds_vec(v_num, INF);

    //initialize set and vector
    ds_set.insert(std::make_pair(0, source));
    ds_vec[source] = 0;

    while (!ds_set.empty())
    {
        weightVertexPair p = *(ds_set.begin());
        ds_set.erase(ds_set.begin());
        int u = p.second;

        std::list<weightVertexPair>::iterator iter;
        for (iter = std::begin(adj[u]); iter != std::end(adj[u]); ++iter)
        {
            int v = (*iter).second;
            int dis = (*iter).first;

            if (ds_vec[v] > ds_vec[u] + dis)
            {
                if (ds_vec[v] != INF)
                    ds_set.erase(ds_set.find(std::make_pair(ds_vec[v], v)));

                ds_vec[v] = ds_vec[u] + dis;
                ds_set.insert(std::make_pair(ds_vec[v], v));
            }
        }
    }

    printf("vertex\t\tdistance from source\n");
    for (size_t i = 0; i < ds_vec.size(); ++i)
        printf("%d\t\t%3.0f\n", i, ds_vec[i]);
}