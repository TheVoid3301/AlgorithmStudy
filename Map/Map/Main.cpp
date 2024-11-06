#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <stack>
using namespace std;
// ����ͼ���ڽӱ�ṹ
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
                    cout << "�� ";
                }
            }
            cout << endl;
        }
    }
};
//����
void DFS(int i, vector<int> &visited, Graph &g) 
{//���������һ�������з���
    visited[i] = 1;//���ʺ���Ϊ�ѷ���
    cout << i << " ";//������
    for (int j = 0; j < g.V; j++) 
    {
        if ((g.adj[i][j] != 0 && g.adj[i][j] != INT_MAX) && visited[j] != true)
        {//���������δ���ʹ�
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
// ����
void BFS_start(int k, vector<int>& visited, Graph& g) 
{
    cout << "������ȱ����㷨:" << endl;
    queue<int> q;
    for(int k = 0; k < g.V; ++k)
    {
        for (int i = 0; i < g.V; i++)
        {//���������ѭ����ʾÿ����㶼Ҫ��Ϊ�������һ�Σ�������ڷ���ͨͼ
            if (visited[i] != 1)
            {//�ѷ��ʹ��Ľ�㲻���ٴη���
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
                        {//i��j������δ���ʹ�j
                            visited[j] = 1;
                            q.push(j);//j������
                            cout << j << " ";
                        }
                    }
                }
            }
        }
    }
}
//���·���㷨
void dijkstra(vector<vector<int>>& graph, int src) {
    cout << "���·��Dijkstra�㷨:" << endl;
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<int> prev(V, -1);
    vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V; count++) {
        // �ҵ�δ����Ķ���
        int u = src;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && dist[v] != INT_MAX)
            {
                u = v;
                break;
            }
        }
        // ���ҵ��Ķ�����뵽�Ѵ���ļ�����
        sptSet[u] = true;

        // ������u���ڵĶ���ľ���
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INT_MAX  && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    // ��ӡ���·���ľ����·��
    for (int i = 0; i < V; i++) {
        cout << "��" << src << "��" << i << "�����·������Ϊ��" << dist[i] << endl;
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
        cout << "���·��Ϊ��";
        for (int j = path.size() - 1; j >= 0; j--) {
            cout << path[j];
            if (j != 0) cout << " -> ";
        }
        cout << endl;
    }
}
//��������
int topu(Graph g, vector<int> visited, vector<int> &topusort)
{
    cout << "��������:" << endl;
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
    for (int i = 0; i < g.V; ++i)//ͳ�Ƹ�����Ⱥͳ���
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
    for (int i = 0; i < g.V; ++i)//����
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
//����������
int nitopu(Graph g, vector<int> visited, vector<int>& nitopusort)
{
    cout << "����������:" << endl;
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
    for (int i = 0; i < g.V; ++i)//ͳ�Ƹ�����Ⱥͳ���
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
//�ؼ�·���㷨
int guanjian(Graph g)
{
    cout << "�ؼ�·���㷨:" << endl;
    vector<int> eth(g.V, -1);
    vector<int> lth(g.V, INT_MAX);
    vector<int> epo;
    vector<bool> visited(g.V, false);
    eth[0] = 0;
    lth[0] = 0;
    for (int count = 0; count < g.V; count++)//�¼����翪ʼʱ��
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
    for (int count = 0; count < g.V; count++)//�¼�����ʼʱ��
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

    for (int i = 0; i < g.V; ++i)//����翪ʼʱ��
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
    for (int i = g.V - 1; i >= 0; --i)//�����ʼʱ��
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
//ͼ�Ľ���
int createMap(int n, Graph& g, FILE* file)//����ͼ
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
    cout << "������ȱ����㷨:" << endl;
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
