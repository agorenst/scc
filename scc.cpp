#include <vector>
#include <algorithm>
#include <set>
#include <map>

#include <iostream>

#include "scc.h"

void strongly_connected_components::strongly_connected(const vertex v) {
    index[v] = vindex;
    lowlink[v] = vindex;
    ++vindex;
    S.push_back(v);

    // for every child of v:
    // basically, if v -> w -> root, then
    // root should have the lowest lowlink.
    for (const auto& e : G.edges()) {
        if (e.v != v) { continue; }
        auto w = e.w;
        if (index.find(w) == index.end()) {
            strongly_connected(w);
            lowlink[v] = std::min(lowlink[v], lowlink[w]);
        }
        else if (find(S.begin(), S.end(), w) != S.end()) {
            // note we use "index" here, not "lowlink". Why?
            lowlink[v] = std::min(lowlink[v], index[w]);
        }
    }

    std::set<vertex> component;
    if (lowlink[v] == index[v]) {
        vertex w;
        do {
            w = *(S.rbegin()); S.pop_back();
            component.insert(w); 
        } while (w != v); // we want to remove v.
    }

    if (component.size() > 0) {
        components.insert(component);
    }
}

std::set<std::set<vertex>> strongly_connected_components::compute() {
    for (const auto& v : G.vertices()) {
        if (index.find(v) == index.end()) {
            strongly_connected(v);
        }
    }
    return components;
}
