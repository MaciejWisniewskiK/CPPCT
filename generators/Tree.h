#include <bits/stdc++.h>
using namespace std;

class Tree {
protected:
    int n;
    vector <int> father;                                // father[root] = root

public:
    Tree(int n, const vector<int> father);              // father[root] = root
    Tree(int n, const vector<pair<int, int> > edges);

    int getN();

    void print();                                       // TODO add print type / stream
    
    void shuffleNodes();
};

class Path : public Tree {
public:
    Path(int n);
};

class K_ary : public Tree {
public:
    K_ary(int n, int k);
};

class Binary : K_ary {
public:
    Binary(int n);
};

class Ladder : public Tree {
public:
    Ladder(int n);
};

class Brush : public Tree {
public:
    Brush(int n);
    Brush(int n, int nodesOnPath);
};

class Random : public Tree {
public:
    Random(int n);
    Random(int n, int minDepth);
};

