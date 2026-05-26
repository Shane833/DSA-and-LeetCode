#include <stdio.h>
#include <Graph.h>
#include <Graph_algos.h>

int asc_order(int a, int b){
    return a - b;
}

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
    printf("Graph Adjacency List : \n");
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
    int g[12][12] = {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                     {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                     {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                     {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};


   Graph *graph = Graph_create(sizeof g / sizeof g[0], g);
   check(graph != NULL, "Failed to create our graph!");

   printGraph(graph);
    
   int vertex_dtime[sizeof g / sizeof g[0]];
   int vertex_ftime[sizeof g / sizeof g[0]];

   Graph_SSComponents(graph, vertex_dtime, vertex_ftime);
    
   printf("Strongly Connected Components : \n");

   int vertices[sizeof g / sizeof g[0]];
   for(int i = 0;i < Graph_count(graph);i++){
       vertices[i] = i + 1;
   }

   Graph_SortVertices(Graph_count(graph), vertex_dtime, vertices, asc_order);

   for(int i = 0;i < Graph_count(graph);i++){
       if(i == Graph_count(graph) - 1){
           if(vertex_dtime[i] - vertex_dtime[i-1] == 1){
                printf("%d\n", vertices[i]);
           }else{
                printf("%d\n", vertices[i]);
           } 
       } 
       else if(vertex_dtime[i+1] - vertex_dtime[i] == 1){
            printf("%d ", vertices[i]); 
       }else{
            printf("%d ", vertices[i]);
            printf("\n");
       }
   }

   Graph_destroy(graph);
   graph = NULL;

   closeLog();

    return 0;
error:
    return EXIT_FAILURE;
}
