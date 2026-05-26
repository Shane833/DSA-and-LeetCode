#ifndef graph_algos_h
#define graph_algos_h

#include <Graph.h>
#include <queue.h>
#include <math.h>
#include <dbg.h>
#include <list.h>

void Graph_BFS(Graph *g, int src_vertex);
void Graph_DFS(Graph *g, int vertex_dtime[], int vertex_ftime[]); // Apparently we don't need to specify a source
                          // bcz we can use the result of any DFS tree
void Graph_TopologicalSort(Graph *g, List *result);
#endif
