
#include<iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs1(int v, const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u, adj, visited, st);
        }
    }
    st.push(v);
}

void dfs2(int v, const vector<vector<int>>& radj, vector<bool>& visited, vector<int>& component, vector<bool>& has_back_edge) {
    visited[v] = true;
    component.push_back(v);
    for (int u : radj[v]) {
        if (!visited[u]) {
            dfs2(u, radj, visited, component, has_back_edge);
        } else if (!has_back_edge[u]) {
            for (int &c : component) {
                has_back_edge[c] = true;
            }
            has_back_edge[v] = true;
            has_back_edge[u] = true;
        }
    }
}



int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<vector<int>> radj(n);

    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;
        key--;
        adj[i].push_back(key);
        radj[key].push_back(i);
    }

    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }

    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;

    vector<bool> has_back_edge(n, false);
    while (!st.empty()) {
       int v = st.top();
        st.pop();
        if (!visited[v]) {
            vector<int> component;
            dfs2(v, radj, visited, component, has_back_edge);
            sccs.push_back(component);
        }
    }
    
    vector<int> scc_id(n, -1);
    for (int i = 0; i < sccs.size(); ++i) {
        for (int v : sccs[i]) {
            scc_id[v] = i;
        }
    }

    vector<bool> has_incoming(sccs.size(), false);
    for (int i = 0; i < n; ++i) {
        for (int u : adj[i]) {
            if (scc_id[i] != scc_id[u]) {
                has_incoming[scc_id[u]] = true;
            }
        }
    }

   int source_scc_count = 0;
    for (int i = 0; i < sccs.size(); ++i) {
    bool has_back_edge = false;
    for (int v : sccs[i]) {
        for (int u : adj[v]) {
            if (scc_id[v] != scc_id[u]) {
                has_back_edge = true;
                break;
            }
        }
        if (has_back_edge) {
            break;
        }
    }
    if (!has_back_edge) {
        source_scc_count++;
    }

}
    cout << "Minimalna liczba skarbonek do zbicia: " << source_scc_count << endl;
    return 0;

}

