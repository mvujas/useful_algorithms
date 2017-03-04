#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int to, cost;

    bool operator< (const Edge& a) const {
        return cost > a.cost;
    }
};
struct Node {
    vector<Edge> adj;
};

const int N = 1000;
vector<Node> graph(N);

// Depth First Search
inline bool DFS(int startNode, int endNode) {
    vector<bool> visited(N, 0);
    stack<int> stek;
    stek.push(startNode);
    int i;
    while(!stek.empty()) {
        i = stek.top();
        stek.pop();
        visited[i] = true;
        if(i == endNode)
            return 1;
        for(const Edge& next : graph[i].adj)
            if(!visited[next.to])
                stek.push(next.to);
    }
    return 0;
}

// Breadth First Search
inline bool BFS(int startNode, int endNode) {
    vector<bool> visited(N, 0);
    queue<int> red;
    red.push(startNode);
    int i;
    while(!red.empty()) {
        i = red.front();
        red.pop();
        visited[i] = true;
        if(i == endNode)
            return 1;
        for(const Edge& next : graph[i].adj)
            if(!visited[next.to])
                red.push(next.to);
    }
    return 0;
}

// Djikstra algorithm for finding the shortest path between two nodes
// Works only for positive vertices
inline int dijkstra(int startNode, int endNode) {
    priority_queue<Edge> pq;
    vector<bool> visited(N, 0);
    pq.push({startNode, 0});
    Edge tmp;
    while(!pq.empty()) {
        tmp = pq.top();
        pq.pop();
        printf("%d %d\n", tmp.to, tmp.cost);
        if(tmp.to == endNode)
            return tmp.cost;
        visited[tmp.to] = true;
        for(const Edge& next : graph[tmp.to].adj)
            if(!visited[next.to])
                pq.push({next.to, tmp.cost + next.cost});
    }
    return -1;
}

int main()
{
    graph[0].adj.push_back({1, 1});
    graph[1].adj.push_back({2, 2});
    graph[1].adj.push_back({3, 6});
    graph[2].adj.push_back({3, 3});
    graph[4].adj.push_back({0, 3});
    graph[4].adj.push_back({1, 5});
    graph[4].adj.push_back({3, 10});

    printf("[DFS] Cvor 0 %s povezan sa cvorom 4.\n", (DFS(0, 4) ? "je" : "nije"));
    printf("[BFS] Cvor 1 %s povezan sa cvorom 2.\n", (BFS(1, 2) ? "je" : "nije"));

    int dist = dijkstra(0, 3);
    if(dist == -1)
        printf("[Dijkstra] Cvor 0 nije povezan sa cvorom 3.\n");
    else
        printf("[Dijkstra] Najkraci put od cvora 0 do cvora 3 je dugacak %d.\n", dist);
    return 0;
}
