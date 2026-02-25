#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs1(int v, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs1(u, graph, visited, Stack);
        }
    }
    Stack.push(v);
}

void dfs2(int v, const vector<vector<int>>& reverse_graph, vector<bool>& visited, vector<int>& scc) {
    visited[v] = true;
    scc.push_back(v);
    for (int u : reverse_graph[v]) {
        if (!visited[u]) {
            dfs2(u, reverse_graph, visited, scc);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> keys(n);
    for (int i = 0; i < n; ++i) {
        cin >> keys[i];
        keys[i]--;  // Przekształć na indeksy 0-based
    }

    // Graf i odwrócony graf
    vector<vector<int>> graph(n), reverse_graph(n);
    for (int i = 0; i < n; ++i) {
        graph[i].push_back(keys[i]);
        reverse_graph[keys[i]].push_back(i);
    }

    // Pierwsza faza algorytmu Kosaraju
    vector<bool> visited(n, false);
    stack<int> Stack;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i, graph, visited, Stack);
        }
    }

    // Druga faza algorytmu Kosaraju
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> scc_list;
    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();
        if (!visited[v]) {
            vector<int> scc;
            dfs2(v, reverse_graph, visited, scc);
            scc_list.push_back(scc);
        }
    }

    // Wyznaczenie minimalnej liczby skarbonek do stłuczenia
    int min_smash = 0;
    vector<int> in_degree(scc_list.size(), 0);

    // Obliczenie stopni wejściowych dla SCC w grafie składowych
    vector<int> scc_index(n, -1);
    for (int i = 0; i < scc_list.size(); ++i) {
        for (int v : scc_list[i]) {
            scc_index[v] = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int u : graph[i]) {
            if (scc_index[i] != scc_index[u]) {
                in_degree[scc_index[u]]++;
            }
        }
    }

    for (int i = 0; i < scc_list.size(); ++i) {
        if (in_degree[i] == 0) {
            min_smash++;
        }
    }

    // Wyświetlenie wyniku
    cout << "Minimalna liczba skarbonek do stłuczenia: " << min_smash << endl;
    cout << "Skarbonki do stłuczenia w każdej SCC:" << endl;
    for (int i = 0; i < scc_list.size(); ++i) {
        if (in_degree[i] == 0) {
            for (int v : scc_list[i]) {
                cout << v + 1 << " ";  // Przekształć na indeksy 1-based
                break;  // Wystarczy jedna skarbonka na SCC
            }
        }
    }
    cout << endl;

    return 0;
}