#include <Graph_algos.h>

void Graph_BFS(Graph *g, int src_vertex){
    // The members of the enum are directly
    // available without needing to create 
    // an object of type Color
     enum Color{
        WHITE,
        GRAY, 
        BLACK
    };

   // YOU LEARN SOMETHING NEW EVERYDAY
   // check(g != NULL, "Invalid Graph!"); This is in error bcz the arrays declared below
   // are dynamic/modifiable in size and the program needs to know that first as
   // it has to allocate memory on the stack, therefore which this "goto error"
   // there is a possibility that it may directly jump to the return statement
   // and the arrays can't be created properly

   // Storing each of the attributes in a separate array
    const int vertex_count = Graph_count(g);
    int vertex_color[vertex_count];
    float vertex_distance[vertex_count];
    int vertex_parent[vertex_count];
    
    check(g != NULL, "Invalid Graph!");

    // Initialization of all vertices except our src vertex
    // Setting up all of the vertices to be white i.e. unvisited
    // distance from source to be infinity
    // and each having no parent

    int src_vertex_idx = src_vertex - 1;

    for(int i = 0;i < Graph_count(g);i++){
        if(i == src_vertex_idx) continue;
        vertex_color[i] = WHITE;
        vertex_distance[i] = INFINITY;
        vertex_parent[i] = 0;
    }
    
    // Initializing our src vertex
    vertex_color[src_vertex_idx] = GRAY;
    vertex_distance[src_vertex_idx] = 0;
    vertex_parent[src_vertex_idx] = 0;
    
    Queue *q = Queue_create();
    check(q != NULL, "Failed to create the queue!");
    
    // Pushing our source vertex into the queue
    int *src = (int *)malloc(sizeof(int));
    check(src != NULL, "Failed to allocate src node!");
    *src = src_vertex;

    Queue_enqueue(q, src);
    
    // Until our queue becomes empty we will keep on visiting nodes
    while(Queue_count(q) > 0){
        int u_idx = *(int *)Queue_dequeue(q) - 1; // Since the queue contains the node num
                                                  // we convert it to index
        // Printing our BFS path
        printf("%d ", u_idx + 1);
        
        List *u_adj_list = (List *)DArray_get(g->vertices, u_idx);
        // Going through all the neighbors of u
        LIST_FOREACH(u_adj_list, first, next, cur){
            // cur->value contains the graph node
            int cur_vertex_idx = *(int *)cur->value - 1;

            if(vertex_color[cur_vertex_idx] == WHITE){
                vertex_color[cur_vertex_idx] = GRAY;
                vertex_distance[cur_vertex_idx] = vertex_distance[u_idx] + 1;
                vertex_parent[cur_vertex_idx] = u_idx + 1;

                int *cur_node = (int *)malloc(sizeof(int));
                check(cur_node != NULL, "Failed to allocate cur node!");
                *cur_node = *(int *)cur->value;

                Queue_enqueue(q, cur_node);
            }
        }
        vertex_color[u_idx] = BLACK;
    }
    
    Queue_clear_destroy(q);

error:
    return;
}

