#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "Dijkstra.h"


int main()
{
    Graph *g = create_graph(7);

    add_vertex_data(g, 0, 'A');
    add_vertex_data(g, 1, 'B');
    add_vertex_data(g, 2, 'C');
    add_vertex_data(g, 3, 'D');
    add_vertex_data(g, 4, 'E');
    add_vertex_data(g, 5, 'F');
    add_vertex_data(g, 6, 'G');

    add_edge(g, 3, 0, 4); // D - A, weight 4
    add_edge(g, 3, 4, 2); // D - E, weight 2
    add_edge(g, 0, 2, 3); // A - C, weight 3
    add_edge(g, 0, 4, 4); // A - E, weight 4
    add_edge(g, 4, 2, 4); // E - C, weight 4
    add_edge(g, 4, 6, 5); // E - G, weight 5
    add_edge(g, 2, 5, 5); // C - F, weight 5
    add_edge(g, 2, 1, 2); // C - B, weight 2
    add_edge(g, 1, 5, 2); // B - F, weight 2
    add_edge(g, 6, 5, 5); // G - F, weight 5


    int **adj_mat = g->adj_matrix;

    for (int i=0; i<7;i++)
    {
        for (int j=0; j<7; j++)
        {
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
    }


    dijkstra(g, 'A');
    free_graph(g);
    return 0;
}
