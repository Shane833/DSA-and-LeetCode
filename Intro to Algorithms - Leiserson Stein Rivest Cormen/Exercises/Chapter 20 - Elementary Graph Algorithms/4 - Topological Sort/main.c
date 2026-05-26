#include <stdio.h>
#include <Graph.h>
#include <Graph_algos.h>

int main(){
   // Topological Sort works on only DAGs
   int g[9][9] = {{0, 0, 0, 1, 1, 0, 0, 0, 0},
                  {0, 0, 0, 0, 1, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 1, 1, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {0, 0, 0, 0, 0 ,1, 0, 1, 0},
                  {0, 0, 0, 0, 0, 0, 0, 0 ,1},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0}}; 

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
   Graph_BFS(graph, 1); // If a node is not reachable from a src
                        // it won't show up in its BFS path
   printf("\n");
    
   int vertex_dtime[sizeof g / sizeof g[0]] = { 0 };
   int vertex_ftime[sizeof g / sizeof g[0]] = { 0 };

   printf("DFS : ");
   Graph_DFS(graph, vertex_dtime, vertex_ftime); // DFS will create a DFS forest based on the various
                     // discovery and finishing times
   printf("Discovery and Finishing times : \n");
   // Displaying discovery and finishing time for each vertex
   for(int i = 0;i < Graph_count(graph);i++){
        printf("%d : (%d, %d)\n", i+1, vertex_dtime[i], vertex_ftime[i]);
    }
    
   List *result = List_create();
   Graph_TopologicalSort(graph, result); 

   printf("Topological Ordering : "); 
   LIST_FOREACH(result, first, next, cur){
    printf("%d ", *(int *)cur->value);
   }
   printf("\n");
    
   List_clear_destroy(result);
   result = NULL;

   Graph_destroy(graph);
   graph = NULL;

   closeLog();

    return 0;
error:
    return EXIT_FAILURE;
}
