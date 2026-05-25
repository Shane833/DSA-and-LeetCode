#include <stdio.h>
#include <Graph.h>
#include <Graph_algos.h>

int main(){
   int g[6][6] = {{0, 1, 0, 1, 0, 0},
                  {0, 0, 0, 0, 1, 0},
                  {0, 0, 0, 0, 1, 1},
                  {0, 1, 0, 0, 0, 0},
                  {0, 0, 0, 1, 0, 0},
                  {0, 0, 0, 0, 0, 1}}; 

   Graph *graph = Graph_create(sizeof g / sizeof g[0], g);
   check(graph != NULL, "Failed to create our graph!");
    
   printf("Graph Adjacency List : \n");
   for(int i = 0;i < Graph_count(graph);i++){
        printf("%d : ", i+1);
        List *l = (List *)DArray_get(graph->vertices, i);
        LIST_FOREACH(l, first, next, node){
            printf("%d ", *(int *)node->value);    
        } 
        printf("\n");
    }   

   printf("BFS : ");
   Graph_BFS(graph, 3);
   printf("\n");

   printf("DFS : ");
   Graph_DFS(graph);
   printf("\n");

   Graph_destroy(graph);
   graph = NULL;

   closeLog();

    return 0;
error:
    return EXIT_FAILURE;
}
