#include <vector>
#include <algorithm>
#include <set>
#include <map>

#include <iostream>

typedef int vertex;
struct edge {
    const vertex v, w;
};

class graph {
    private:
    std::vector<vertex> V;
    std::vector<edge> E;
    public:
    graph(const std::vector<edge> edges): E(edges) {
        // very stupid, but it will get the job done.
        for (auto&& e : E) {
            if (std::find(V.begin(), V.end(), e.v)  == V.end()) {
                V.push_back(e.v);
            }
            if (std::find(V.begin(), V.end(), e.w)  == V.end()) {
                V.push_back(e.w);
            }
        }
        for (auto&& v : V) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    const std::vector<vertex>& vertices() const {
        return V;
    }
    const std::vector<edge>& edges() const {
        return E;
    }
};


using namespace std;
class strongly_connected_components {
    private:
    int vindex = 0;
    std::map<vertex,int> index;
    std::map<vertex,int> lowlink;
    std::vector<vertex> S;
    const graph& G;
    std::set<std::set<vertex>> components; // the main event.

    void strongly_connected(const vertex v) {
        cout << "strongly_connected(" << v << ")" << endl; 
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
            cout << "Considering child: " << w << endl;
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

    public:
    strongly_connected_components(const graph& G): G(G) {}

    std::set<std::set<vertex>> compute() {
        for (const auto& v : G.vertices()) {
            if (index.find(v) == index.end()) {
                strongly_connected(v);
            }
        }
        return components;
    }
};


#include <iostream>

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
