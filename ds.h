#include <vector>

namespace util {

template <typename T = int>
class disjoint_sets {
public:
    disjoint_sets() = delete;
    explicit disjoint_sets(T size)
        : Parents(size)
        , Ranks(size)
        , Sizes(size, 1)
    {
        for (int i = 0; i < Parents.size(); ++i) {
            Parents[i] = i;
        }
    }

    T find(T u) {
        if (Parents[u] != u) {
            Parents[u] = find(Parents[u]);
        }
        return Parents[u];
    }

    void join(T u, T v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return;
        }

        if (Ranks[u] < Ranks[v]) {
            Parents[u] = v;
            Sizes[v] += Sizes[u];
        } else if (Ranks[u] > Ranks[v]) {
            Parents[v] = u;
            Sizes[u] += Sizes[v];
        } else {
            Parents[v] = u;
            ++Ranks[u];
            Sizes[u] += Sizes[v];
        }
    }

    T size(T u) {
        u = find(u);
        return Sizes[u];
    }

private:
    std::vector<T> Parents;
    std::vector<T> Ranks;
    std::vector<T> Sizes;
};

}
