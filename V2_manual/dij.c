#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


int min_distance(int distances[], bool visited[], int size)
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v<size; v++)
    {
        if ( !visited[v] && distances[v] <= min )
        {
            min = distances[v];
            min_index = v;
        }
    }
    return min_index;
}


void dijkstra(int adj_mat[7][7],char *vertex_data, int size, char start_vertex_data)
{
    int start_vertex = -1;
    for (int i=0; i < size; i++)
    {
        if (vertex_data[i] == start_vertex_data)
        {
            start_vertex = i;
            break;
        }
    }

    int distances[size];
    bool visited[size];

    for (int i=0; i<size;i++)
    {
        distances[i] = INT_MAX;
        visited[i] = false;
    }
    distances[start_vertex] = 0;

    for (int i=0; i<size -1; i++)
    {
        int u=min_distance(distances,visited,size);
        visited[u] = true;
        for (int v=0; v< size; v++)
        {
            if (!visited[v] && adj_mat[u][v] && distances[u] != INT_MAX && distances[u] + adj_mat[u][v] < distances[v])
            {
                distances[v] = distances[u] + adj_mat[u][v];
            }
        }
    }

    printf("Dijkstra's Algorithm starting from vertex %c: \n\n", start_vertex_data);
    for (int i=0; i<size; i++)
    {
        printf("Shortest distance from %c to %c: %d\n", start_vertex_data, vertex_data[i], distances[i]);
    }
}
