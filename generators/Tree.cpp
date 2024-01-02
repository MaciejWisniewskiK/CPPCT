#include <bits/stdc++.h>
#include "Tree.h"
using namespace std;

Tree::Tree(int n, const vector<int> father) : n(n), father(father) {}

void dfsSetFather(int v, const vector <vector <int> > &graph, vector <bool> &vis, vector <int> &father);
Tree::Tree(int n, const vector<pair<int, int> > edges) : n(n) {
    vector <vector <int> > graph(n + 1);
    vector <bool> vis(n + 1, false);
    for (auto pii : edges) {
        graph[pii.first].push_back(pii.second);
        graph[pii.second].push_back(pii.first);
    }

    dfsSetFather(1, graph, vis, father);
}

int Tree::getN() {
    return n;
}

void Tree::print() {
    cout << n << "\n";
    for (int i = 2; i <= n; i++) {
        cout << i << " " << father[i] << "\n";
    }
}

void Tree::shuffleNodes() {
    // TODO
}














void dfsSetFather(int v, const vector <vector <int> > &graph, vector <bool> &vis, vector <int> &father) {
    vis[v] = true;
    for (int s : graph[v]) {
        if (vis[s]) continue;
        dfsSetFather(s, graph, vis, father);
        father[s] = v;
    }
}