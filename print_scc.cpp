#include "scc.h"

#include <iostream>
#include <set>

using namespace std;

void print_set_on_line(std::set<vertex> s) {
    cout << "{ ";
    for (auto&& e : s) {
        cout << e << " ";
    }
    cout << "}";
}

void print_sccs(std::set<std::set<vertex>> components) {
    cout << "{" << endl;
    for (auto&& c : components) {
        print_set_on_line(c);
        cout << endl;
    }
    cout << "}" << endl;
}

int main() {
    int v;
    vector<edge> e;
    while (cin >> v) {
        int w;
        cin >> w;
        e.push_back({v,w});
    }
    graph G(e);
    strongly_connected_components scc(G);
    auto components = scc.compute();
    print_sccs(components);
}

