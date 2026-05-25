#include <stdio.h>
#include <Graph.h>

int main(){
   int g[5][5] = {{0, 1, 0, 0, 1},
                  {1, 0, 1, 1, 1},
                  {0, 1, 0, 1, 0},
                  {0, 1, 1, 0, 1},
                  {1, 1, 0, 1, 0}}; 

   Graph *graph = Graph_create(sizeof g / sizeof g[0], g);

   if(graph){
        for(int i = 0;i < Graph_count(graph);i++){
            printf("%d : ", i+1);
            List *l = (List *)DArray_get(graph->vertices, i);
            LIST_FOREACH(l, first, next, node){
                printf("%d ", *(int *)node->value);    
            } 

            printf("\n");
        }
    }
    
   Graph_destroy(graph);
   graph = NULL;

   closeLog();

    return 0;
}
