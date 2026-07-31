#include <stdio.h>

int novertices, i, j;

void print_graph(int adj[20][20])
{
    for(i = 1; i <= novertices; i++)
    {
        for(j = 1; j <= novertices; j++)
        {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int s, d;
    int adj[20][20];

    printf("Enter number of vertices: ");
    scanf("%d", &novertices);

    // Initialize adjacency matrix with 0
    for(i = 1; i <= novertices; i++)
    {
        for(j = 1; j <= novertices; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("\nEnter edges (Enter -1 -1 to stop):\n");

    while(1)
    {
        printf("Source Destination: ");
        scanf("%d%d", &s, &d);

        if(s == -1 && d == -1)
        {
            break;
        }

        if(s >= 1 && s <= novertices && d >= 1 && d <= novertices)
        {
            adj[s][d] = 1;
            adj[d][s] = 1;   // Remove this line for Directed Graph
        }
        else
        {
            printf("Invalid vertices!\n");
        }
    }

    printf("\nAdjacency Matrix:\n");
    print_graph(adj);

    return 0;
}