


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


//#include "Buffer.h"
//
//using namespace wens;
//using namespace wens::net;
//int main()
//{
//    Buffer b;
//
//
//    return 0;
//}


//#include <stdio.h>
//#include <memory>
//
//#include <chrono>
//#include <iostream>


//#include "multi_thread/include/thread_pool.h"
//
//void test_print()
//{
//    printf("this is in thread %d\n", std::this_thread::get_id());
//}
//
//int main()
//{
//    ThreadPool pool(4);
//    std::vector< std::future<int> > results;
//
//    for(int i = 0; i < 8; ++i) {
//        results.emplace_back(
//            pool.enqueue([i] {
////                std::cout << "hello " << i << std::endl;
////                std::this_thread::sleep_for(std::chrono::seconds(1));
////                std::cout << "world " << i << std::endl;
//                std::cout<<"in thread "<<std::this_thread::get_id()<<std::endl;
//                return i*i;
//            })
//        );
//    }
//
//    for(auto && result: results)
//        std::cout << result.get() << ' ';
//    std::cout << std::endl;
//
//    return 0;
//
//
//    return 0;
//}


#include <stdio.h>
#include "base/include/comman_sort_algorithm.h"


int main()
{

//
//    int a[] = {7, 2, 10, 4, 1, 18};
//
//    bubble_sort(a, sizeof(a)/sizeof(int));
//
//    for (int i = 0; i < 6; ++i)
//        printf("%d ", a[i]);


    int a = 10, b = 0;
    auto tmp = a ^ b;
    a = tmp ^ a;
    b = tmp ^ b;

    decltype(a) c;
    char d;
    printf("%s\n", typeid(c).name());
    printf("%s\n", typeid(d).name());

    return 0;
}