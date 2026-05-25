#include <Graph.h>

Graph *Graph_create(size_t n, int nodes[n][n]){
    Graph *new_graph = (Graph *)malloc(sizeof(Graph));
    check(new_graph != NULL, "Failed to create graph!");
    
    new_graph->vertices = DArray_create(sizeof(List), n);
    check(new_graph->vertices != NULL, "Failed to create vertex array!");

    for(int i = 0;i < n;i++){
            List *node_list = List_create();
            check(node_list != NULL, "Failed to create vertex list!");
        for(int j = 0;j < n;j++){
            if(nodes[i][j] == 1){
                int *node_num = (int *)malloc(sizeof(int));
                check(node_num != NULL, "Failed to create vertex name!");
                *node_num = j+1; // Since j is index we add one to get the position
                                  // or in this the node number
                List_push(node_list, node_num);
            }
        }
        
        check(DArray_push(new_graph->vertices, node_list) == 0, "Failed to push list in the vertex array!")
    }

    return new_graph;
error:
    return NULL;
}

void Graph_destroy(Graph *g){
    if(g){
        for(int i = 0; Graph_count(g);i++){
            List *l = (List *)DArray_get(g->vertices, i);
            if(l){
                List_clear_destroy(l);
                l = NULL;
            }
        } 
        DArray_clear_destroy(g->vertices);
        g->vertices = NULL;

        free(g);
    }
}
