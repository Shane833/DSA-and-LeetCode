#include <stdio.h>
#include <Graph.h>
#include <Graph_algos.h>

int main(){
   int g[5][5] = {{0, 1, 0, 0, 1},
                  {1, 0, 1, 1, 1},
                  {0, 1, 0, 1, 0},
                  {0, 1, 1, 0, 1},
                  {1, 1, 0, 1, 0}}; 

   Graph *graph = Graph_create(sizeof g / sizeof g[0], g);
   check(graph != NULL, "Failed to create our graph!");

   Graph_BFS(graph, 1);
   
   Graph_destroy(graph);
   graph = NULL;

   closeLog();

    return 0;
error:
    return EXIT_FAILURE;
}
