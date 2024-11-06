#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <stack>
using namespace std;
// 定义图的邻接表结构
struct Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V) 
    {
        adj.resize(V, vector<int>(V));
    }

    void addEdge(int v, int w, int k) 
    {
        adj[v][w] = k;
    }

    void display() {
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] != INT_MAX)
                {
                    cout << adj[i][j] << " ";
                }
                else
                {
                    cout << "∞ ";
                }
            }
            cout << endl;
        }
    }
};
//深搜
void DFS(int i, vector<int> &visited, Graph &g) 
{//这个函数对一个结点进行访问
    visited[i] = 1;//访问后设为已访问
    cout << i << " ";//输出结点
    for (int j = 0; j < g.V; j++) 
    {
        if ((g.adj[i][j] != 0 && g.adj[i][j] != INT_MAX) && visited[j] != true)
        {//如果相连且未访问过
            DFS(j, visited, g);
        }
    }
}
void DFS_start(vector<int>& visited, Graph& g) 
{
    for (int i = 0; i < g.V; i++) 
    {
        if (visited[i] != 1)
            DFS(i, visited, g);
    }
}
// 广搜
void BFS_start(int k, vector<int>& visited, Graph& g) 
{
    cout << "广度优先遍历算法:" << endl;
    queue<int> q;
    for(int k = 0; k < g.V; ++k)
    {
        for (int i = 0; i < g.V; i++)
        {//最外面这个循环表示每个结点都要作为访问起点一次，避免存在非联通图
            if (visited[i] != 1)
            {//已访问过的结点不用再次访问
                visited[i] = 1;
                q.push(i);
                cout << i << " ";
                while (!q.empty())
                {
                    i = q.front();
                    q.pop();
                    for (int j = 0; j < g.V; j++)
                    {
                        if ((g.adj[i][j] != 0 && g.adj[i][j] != INT_MAX) && !visited[j])
                        {//i，j相连且未访问过j
                            visited[j] = 1;
                            q.push(j);//j结点入队
                            cout << j << " ";
                        }
                    }
                }
            }
        }
    }
}
//最短路径算法
void dijkstra(vector<vector<int>>& graph, int src) {
    cout << "最短路径Dijkstra算法:" << endl;
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<int> prev(V, -1);
    vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V; count++) {
        // 找到未处理的顶点
        int u = src;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && dist[v] != INT_MAX)
            {
                u = v;
                break;
            }
        }
        // 将找到的顶点加入到已处理的集合中
        sptSet[u] = true;

        // 更新与u相邻的顶点的距离
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INT_MAX  && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    // 打印最短路径的距离和路径
    for (int i = 0; i < V; i++) {
        cout << "从" << src << "到" << i << "的最短路径长度为：" << dist[i] << endl;
        if (dist[i] == INT_MAX)
        {
            continue;
        }
        vector<int> path;
        int temp = i;
        while (temp != src) {
            path.push_back(temp);
            temp = prev[temp];
        }
        path.push_back(src);
        cout << "最短路径为：";
        for (int j = path.size() - 1; j >= 0; j--) {
            cout << path[j];
            if (j != 0) cout << " -> ";
        }
        cout << endl;
    }
}
//拓扑排序
int topu(Graph g, vector<int> visited, vector<int> &topusort)
{
    cout << "拓扑排序:" << endl;
    vector<vector<int>> k;
    k.resize(g.V, vector<int>(g.V, 0));
    for (int i = 0; i < g.V; ++i)
    {
        for (int j = 0; j < g.V; ++j)
        {
            if (g.adj[i][j] != 0 && g.adj[i][j] != INT_MAX)
            {
                k[i][j] = 1;
            }
        }
    }
    //int matrix[9][9] =
    //{
    //    0,0,1,0,0,0,0,1,0,
    //    0,0,1,1,1,0,0,0,0,
    //    0,0,0,1,0,0,0,0,0,
    //    0,0,0,0,0,1,1,0,0,
    //    0,0,0,0,0,1,0,0,0,
    //    0,0,0,0,0,0,0,0,0,
    //    0,0,0,0,0,0,0,0,0,
    //    0,0,0,0,0,0,0,0,1,
    //    0,0,0,0,0,0,1,0,0
    //};
    vector<int> out;
    out.resize(g.V, 0);
    vector<int> in;
    in.resize(g.V, 0);
    for (int i = 0; i < g.V; ++i)//统计各点入度和出度
    {
        for (int j = 0; j < g.V; ++j)
        {
            if (k[i][j] == 1)
            {
                out[i]++;
                in[j]++;
            }
        }
    }
    for (int i = 0; i < g.V; ++i)//拓扑
    {
        if (in[i] == 0 && visited[i] != 1)
        {
            cout << i << " ";
            topusort.push_back(i);
            for (int j = 0; j < g.V; ++j)
            {
                if (k[i][j] == 1)
                {
                    in[j]--;
                }
            }
            visited[i] = 1;
            i = -1;
        }
    }
    return 1;
}
//逆拓扑排序
int nitopu(Graph g, vector<int> visited, vector<int>& nitopusort)
{
    cout << "逆拓扑排序:" << endl;
    vector<vector<int>> k;
    k.resize(g.V, vector<int>(g.V, 0));
    for (int i = 0; i < g.V; ++i)
    {
        for (int j = 0; j < g.V; ++j)
        {
            if (g.adj[i][j] != 0 && g.adj[i][j] != INT_MAX)
            {
                k[i][j] = 1;
            }
        }
    }
    vector<int> out;
    out.resize(g.V, 0);
    vector<int> in;
    in.resize(g.V, 0);
    for (int i = 0; i < g.V; ++i)//统计各点入度和出度
    {
        for (int j = 0; j < g.V; ++j)
        {
            if (k[i][j] == 1)
            {
                out[i]++;
                in[j]++;
            }
        }
    }
    for (int i = g.V - 1; i >= 0; --i)
    {
        if (out[i] == 0 && visited[i] != 1)
        {
            cout << i << " ";
            nitopusort.push_back(i);
            for (int j = g.V - 1; j >= 0; --j)
            {
                if (k[j][i] == 1)
                {
                    out[j]--;
                }
            }
            visited[i] = 1;
            i = g.V;
        }
    }
    return 1;
}
//关键路径算法
int guanjian(Graph g)
{
    cout << "关键路径算法:" << endl;
    vector<int> eth(g.V, -1);
    vector<int> lth(g.V, INT_MAX);
    vector<int> epo;
    vector<bool> visited(g.V, false);
    eth[0] = 0;
    lth[0] = 0;
    for (int count = 0; count < g.V; count++)//事件最早开始时间
    {
        int u = 0;
        for (int v = 0; v < g.V; v++)
        {
            if (!visited[v] && eth[v] != -1)
            {
                u = v;
                break;
            }
        }
        visited[u] = true;
        for (int v = 0; v < g.V; v++) {
            if (g.adj[u][v] != INT_MAX && eth[u] != -1 && (eth[u] + g.adj[u][v] > eth[v])) {
                eth[v] = eth[u] + g.adj[u][v];
            }
        }
    }

    lth[g.V-1] = eth[g.V-1];
    fill(visited.begin(), visited.end(), false);
    for (int count = 0; count < g.V; count++)//事件最晚开始时间
    {
        int u = g.V - 1 - count;
        for (int i = g.V - 1; i >= 0; --i)
        {
            if (g.adj[i][u] != INT_MAX && (lth[u] - g.adj[i][u] < lth[i]))
            {
                lth[i] = lth[u] - g.adj[i][u];
            }
        }
    }

    vector<vector<int>> w(g.V, vector<int>(g.V, -1));
    for (int i = 0; i < g.V; ++i)
    {
        for (int j = 0; j < g.V; ++j)
        {
            if (g.adj[i][j] != 0 && g.adj[i][j] != INT_MAX)
            {
                w[i][j] = g.adj[i][j];
            }
        }
    }

    for (int i = 0; i < g.V; ++i)//活动最早开始时间
    {
        for (int j = 0; j < g.V; ++j)
        {
            if (w[i][j] != -1)
            {
                epo.push_back(eth[i]);
            }
        }
    }
    vector<int> lpo(epo.size(), -1);
    int m = epo.size() - 1;
    for (int i = g.V - 1; i >= 0; --i)//活动最晚开始时间
    {
        for (int j = g.V - 1; j >= 0; --j)
        {
            if (w[i][j] != -1)
            {
                lpo[m] = lth[j] - w[i][j];
                m--;
            }
        }
    }
    m = -1;
    vector<int> s;
    vector<int> e;
    for (int i = 0; i < g.V; ++i)
    {
        for (int j = 0; j < g.V; ++j)
        {
            if (w[i][j] != -1)
            {
                m++;
                if (lpo[m] - epo[m] == 0)
                {
                    s.push_back(i);
                    e.push_back(j);
                }
            }
        }
    }
    for (int i = 0; i < s.size(); ++i)
    {
        int j;
        if (s[i] == 0)
        {
            cout << s[i] << "->";
            int k = i;
            for (j = k + 1; j < e.size(); j++)
            {
                if (e[k] == s[j])
                {
                    cout << s[j] << "->";
                    k = j;
                    
                }
            }
            cout << e[j - 1];
            cout << endl;
        }
    }
    cout << endl;
    return 0;
}
//图的建立
int createMap(int n, Graph& g, FILE* file)//有向图
{
    int k;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fscanf_s(file, "%d", &k);
            g.addEdge(i, j, k);
        }
    }
    return 1;
}

int main() {
    int n;
    FILE* file;
    fopen_s(&file, "Map.txt", "r");
    fscanf_s(file, "%d", &n);
    Graph g(n);
    createMap(n, g, file);
    for (int i = 0; i < g.V; i++)
    {
        for (int j = 0; j < g.V; j++)
        {
            if (g.adj[i][j] == 0 && i != j)
            {
                g.adj[i][j] = INT_MAX;
            }
        }
    }
    g.display();
    vector<int> visited(n, 0);
    cout << "深度优先遍历算法:" << endl;
    DFS_start(visited, g);
    cout << endl;
    fill(visited.begin(), visited.end(), 0);
    BFS_start(0, visited, g);
    cout << endl;
    fill(visited.begin(), visited.end(), 0);
    dijkstra(g.adj, 0);
    vector<int> topusort(n, 0);
    vector<int> nitopusort(n, 0);
    topu(g, visited, topusort);
    cout << endl;
    nitopu(g, visited, nitopusort);
    cout << endl;
    guanjian(g);
    return 0;
}
