#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef int vertex;
struct edge {
    const vertex v, w;
    bool operator<(const edge e) const {
        if (v < e.v) { return true; }
        if (v > e.v) { return false; }
        return e.w < w;
    }
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
    }
    const std::vector<vertex>& vertices() const {
        return V;
    }
    const std::vector<edge>& edges() const {
        return E;
    }
};

class strongly_connected_components {
    private:
    int vindex = 0;
    std::map<vertex,int> index;
    std::map<vertex,int> lowlink;
    std::vector<vertex> S;
    const graph& G;
    std::set<std::set<vertex>> components; // the main event.

    void strongly_connected(const vertex v);

    public:
    strongly_connected_components(const graph& G): G(G) {}

    std::set<std::set<vertex>> compute();
};

