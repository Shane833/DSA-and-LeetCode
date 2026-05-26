#include <stdio.h>
#include <Graph.h>
#include <Graph_algos.h>

void transposeMatrix(size_t n, int graph[n][n]){
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
           int temp = graph[i][j];
           graph[i][j] = graph[j][i];
           graph[j][i] = temp;
        }
    }
}

void printGraph(Graph *g){
    for(int i = 0;i < Graph_count(g);i++){
        printf("%d : ", i+1);
        List *l = (List *)DArray_get(g->vertices, i);
        LIST_FOREACH(l, first, next, cur){
            printf("%d ", *(int *)cur->value);
        }
        printf("\n");
    }
}

int main(){
   // Topological Sort works on only DAGs
   int g[8][8] = {{0, 1, 0, 0, 0, 0, 0, 0},
                  {0, 0, 1, 0, 1, 1, 0, 0},
                  {0, 0, 0, 1, 0, 0, 1, 0},
                  {0, 0, 1, 0, 1, 1, 0, 1},
                  {1, 0, 0, 0, 0, 1, 0, 0},
                  {0, 0, 0, 0, 0, 0, 1, 0},
                  {0, 0, 0, 0, 0 ,1, 0, 1},
                  {0, 0, 0, 0, 0, 0, 0, 1}}; 

   Graph *graph1 = Graph_create(sizeof g / sizeof g[0], g);
   check(graph1 != NULL, "Failed to create our graph!");

   printGraph(graph1);
   printf("\n");
    
   // Solution 1 : In order to tranpose graph we can tranpose
   // the matrix and then create a graph from that
   transposeMatrix(sizeof g / sizeof g[0], g);
   
   Graph *graph2 = Graph_create(sizeof g / sizeof g[0], g);
   check(graph2 != NULL, "Failed to create our graph!");

   printGraph(graph2);
   printf("\n");

   // Solution 2 : Or we can create a new graph from existing
   // graph by taking the tranpose from the adjacency list of each
   // of the node

   Graph *graph3 = Graph_transpose(graph1);
   check(graph3 != NULL, "Failed to create our graph!");

   printGraph(graph3);
   printf("\n");

   // Transposing again should give us the original graph
   Graph *graph4 = Graph_transpose(graph3);
   check(graph4 != NULL, "Failed to create our graph!");

   printGraph(graph4);
   printf("\n");

   Graph_destroy(graph1);
   graph1 = NULL;

   Graph_destroy(graph2);
   graph2 = NULL;

   Graph_destroy(graph3);
   graph3 = NULL;

   Graph_destroy(graph4);
   graph4 = NULL;

   closeLog();

    return 0;
error:
    return EXIT_FAILURE;
}
