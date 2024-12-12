// Represent a graph of your college campus using adjacency list /adjacency matrix. Nodes should represent the various departments/institutes and links should represent the distance between them. Find minimum spanning tree using 
// a) Using Kruskal’s algorithm. 

#include <iostream>

using namespace std;

#define MAX 100

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    Edge edges[MAX];

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int index, int src, int dest, int weight) {
        edges[index].src = src;
        edges[index].dest = dest;
        edges[index].weight = weight;
    }

    int find(int parent[], int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void Union(int parent[], int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        if (xset != yset) {
            parent[xset] = yset;
        }
    }

    void sortEdges() {
        for (int i = 0; i < E - 1; ++i) {
            for (int j = 0; j < E - i - 1; ++j) {
                if (edges[j].weight > edges[j + 1].weight) {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }

    void KruskalMST() {
        Edge result[MAX];
        int e = 0;
        int i = 0;

        sortEdges();

        int parent[MAX];
        for (int i = 0; i < V; ++i)
            parent[i] = -1;

        while (e < V - 1 && i < E) {
            Edge next_edge = edges[i++];

            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            if (x != y) {
                result[e++] = next_edge;
                Union(parent, x, y);
            }
        }

        cout << "Following are the edges in the constructed MST\n";
        for (int i = 0; i < e; ++i) {
            cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
        }
    }
};

int main() {
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph graph(V, E);

    // Add edges
    graph.addEdge(0, 0, 1, 10);
    graph.addEdge(1, 0, 2, 6);
    graph.addEdge(2, 0, 3, 5);
    graph.addEdge(3, 1, 3, 15);
    graph.addEdge(4, 2, 3, 4);

    graph.KruskalMST();

    return 0;
}

/*
#include <iostream>

using namespace std;

#define MAX 100

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    Edge edges[MAX];

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int index, int src, int dest, int weight) {
        edges[index].src = src;
        edges[index].dest = dest;
        edges[index].weight = weight;
    }

    int find(int parent[], int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void Union(int parent[], int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        if (xset != yset) {
            parent[xset] = yset;
        }
    }

    void sortEdges() {
        for (int i = 0; i < E - 1; ++i) {
            for (int j = 0; j < E - i - 1; ++j) {
                if (edges[j].weight > edges[j + 1].weight) {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
    }

    void KruskalMST() {
        Edge result[MAX];
        int e = 0;
        int i = 0;

        sortEdges();

        int parent[MAX];
        for (int i = 0; i < V; ++i)
            parent[i] = -1;

        while (e < V - 1 && i < E) {
            Edge next_edge = edges[i++];

            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            if (x != y) {
                result[e++] = next_edge;
                Union(parent, x, y);
            }
        }

        cout << "Following are the edges in the constructed MST\n";
        for (int i = 0; i < e; ++i) {
            cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V, E);

    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> src >> dest >> weight;
        graph.addEdge(i, src, dest, weight);
    }

    graph.KruskalMST();

    return 0;
}
*/