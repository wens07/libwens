#include "base/include/Graph.h"
#include "base/include/Timestamp.h"
#include "net/include/Buffer.h"
#include "Timer.h"
#include <iostream>

using namespace wens;
using namespace wens::net;

/*
 // following is for Graph test
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(0, 0);

   */
/* printf("Following is Breadth First Traversal (starting from vertex 0) \n");
    printf("BFS:\n");
    g.BFS(0);
    printf("NO RECUR DFS:\n");
    g.DFS_NO_RECUR(0);

     printf("RECUR DFS:\n");
     g.DFS_RECUR(0);*//*


    if (g.isCyclic())
        printf("there is a cycle in graph!\n");
    else
        printf("there is no cycle in graph!\n");


    return 0;
}
*/


/*
 * following is for dijkstra shortest path algorithm test

// Driver program to test methods of graph class
int main()
{
    int V = 9;
    GraphWeight g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath_by_set(0);

    return 0;
}*/



int main()
{

    TimerCallback cb;
    Timestamp t;
    Timer timer(cb, t, 10);
    timer.run();


    return 0;
}