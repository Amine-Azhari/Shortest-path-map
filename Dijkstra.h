typedef struct Graph {
    int size;
    int **adj_matrix;
    char *vertex_data;
} Graph;
Graph* create_graph(int size);
void add_edge(Graph *g, int u, int v, int weight);
void add_vertex_data(Graph *g, int vertex, char data);
int min_distance(int distances[], bool visited[], int size);
void dijkstra(Graph *g, char start_vertex_data);
void free_graph(Graph *g);