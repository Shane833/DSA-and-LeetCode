#include <Graph_algos.h>

// Global Enum of Colors used in algorithms
// The members of the enum are directly
// available without needing to create 
// an object of type Color
enum Color{
        WHITE,
        GRAY,
        BLACK
};

void Graph_BFS(Graph *g, int src_vertex){
// YOU LEARN SOMETHING NEW EVERYDAY
   // check(g != NULL, "Invalid Graph!"); This is in error bcz the arrays declared below
   // are dynamic/modifiable in size and the program needs to know that first, as
   // it has to allocate memory on the stack, therefore with this "goto error"
   // there is a possibility that it may directly jump to the return statement
   // and the arrays can't be created properly
   // SOLUTION : One solution to this problem can be that we provide the size
   // of the arrays to be declared separately as an argument to the function
   // this would remove the dependence from Graph object 'g'

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
        vertex_parent[i] = 0; // 0 is equivalent of NIL
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

// Global time variable for keeping track of discovery and finishing time
static int time = 0;

// Utitlity function for visiting the adjacent nodes of 
// each newly discovered vertex in the DFS algorithm
static void DFS_visit(Graph *g, int vertex_dtime[], int vertex_ftime[], int vertex_color[], int vertex_parent[], int src_vertex){
    // Printing the order of DFS
    printf("%d ", src_vertex);
    int src_idx = src_vertex - 1;
    // increment time as we have discovered a new vertex
    time++;
    vertex_dtime[src_idx] = time;
    vertex_color[src_idx] = GRAY; // Paint it gray as it has been discovered now
    List *src_adj_list = (List *)DArray_get(g->vertices, src_idx);
    LIST_FOREACH(src_adj_list, first, next, cur){
        int cur_vertex_idx = *(int *)cur->value - 1;
        if(vertex_color[cur_vertex_idx] == WHITE){
            vertex_parent[cur_vertex_idx] = src_vertex;
            DFS_visit(g, vertex_dtime, vertex_ftime, vertex_color, vertex_parent, cur_vertex_idx + 1); // Exploring this newly discovered vertex
        }
    }
    
    time++; // increment time after exhausting all the vertices of our source vertex
    vertex_ftime[src_idx]; // Setting this as the finishing time
    vertex_color[src_idx] = BLACK;
}

void Graph_DFS(Graph *g){
    // Declaring the attribute array for each vertex
    const int vertex_count = Graph_count(g);
    int vertex_dtime[vertex_count];
    int vertex_ftime[vertex_count];
    int vertex_color[vertex_count];
    int vertex_parent[vertex_count];

    // Initialization
    for(int i = 0;i < Graph_count(g);i++){
        vertex_color[i] = WHITE;
        vertex_parent[i] = 0; // 0 is equivalent of NIL
        vertex_dtime[i] = 0;
        vertex_ftime[i] = 0;
    }
    time = 0; // Setting gloabl time to be zero
    
    for(int i = 0;i < Graph_count(g);i++){
        if(vertex_color[i] == WHITE){
            DFS_visit(g, vertex_dtime, vertex_ftime, vertex_color, vertex_parent, i+1); // Recursively visiting all the adjacent
                               // nodes of 'i+1'th vertex
        }
    }
}
