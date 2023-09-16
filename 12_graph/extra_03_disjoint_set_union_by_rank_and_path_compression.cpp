int parent[1e5];
int rank[1e5];

static int N;

void makeSet() {
    for (int i = 0;i < N;i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findPar(int node) {
    if (node == parent[node]) return node;

    
    return parent[node] = findPar(parent[node]);
}


void union(int u, int v) {
    u = findPar(u);
    v = findPar(v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) parent[v] = u;
    else {
        parent[v] = u;
        rank[u]++;
    }
}


int main() {
    cin >> N;

    makeSet();

    // if given M operation
    int M;
    cin >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        union(u, v);
    }

    // if we want to check 2 and 3 belong to same component or not
    if (findPar(2) == findPar(3)) cout << "same component" << endl;
    else cout << "different component" << endl;

}