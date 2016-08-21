#include <algorithm>
#include <map>
#include <set>
#include <iostream>

#include "scc.h"

using namespace std;

graph condensation(const graph& g) {
    int u = 0;
    strongly_connected_components make_sccs(g);
    auto scc = make_sccs.compute();

    map<vertex, vertex> remap_vertex;
    for (auto&& c : scc) {
        for (auto&& v : c) {
            remap_vertex[v] = u;
        }
        ++u;
    }

    set<edge> edges;
    vector<edge> new_edges;
    for (auto&& e : g.edges()) {
        auto new_edge = edge{remap_vertex[e.v], remap_vertex[e.w]};
        if (new_edge.v != new_edge.w && edges.find(new_edge) == edges.end()) {
            edges.insert({new_edge});
            new_edges.push_back({new_edge});
        }
    }
    return graph{new_edges};
    //return graph{vector<edge>{edges.begin(), edges.end()}};
}

void print_graph(const graph& G) {
    for (auto&& e : G.edges()) {
        cout << e.v << " " << e.w << endl;
    }
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
    auto condensed = condensation(G);
    print_graph(condensed);
}
