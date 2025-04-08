#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

using namespace std;
template <typename T> T nxt();
template <typename T> class is_iterable {
  public:
    template <typename U>
    static auto test(U *u) -> decltype(u->begin(), u->end(), true_type{});
    template <typename> static false_type test(...);
    static constexpr bool value =
        !is_same<T, string>::value && decltype(test<T>(nullptr))::value;
};
template <typename T>
typename enable_if<is_iterable<T>::value>::type nxtseq(T &x);
template <typename T>
typename enable_if<!is_iterable<T>::value>::type nxtseq(T &x);
template <typename T1, typename T2> void nxtseq(pair<T1, T2> &p);
template <typename Itr> void nxtseq(Itr begin, Itr end);

using ld = long double;
using llu = uint64_t;
using ll = int64_t;

const bool T = 0;         // Multiple test cases?
const string iofile = ""; // I/O file?

class Node {
  private:
    static int ID() {
        static int n = 0;
        return n++;
    }

  public:
    int id, l, r, parent, max;
    vector<int> childs;
    Node(int l, int r, int max) {
        id = ID(), parent = -1;
        this->l = l, this->r = r;
        this->max = max;
    }
};
class Tree {
  private:
    vector<Node> nodes;
    vector<int> a;
    function<int(vector<int> &, int, int)> op;

  public:
    Tree(vector<int> &a, function<int(vector<int> &, int, int)> op) {
        this->op = op, this->a = a;
        for (int i = 0; i < a.size(); i++) {
            nodes.push_back(Node(i, i, i));
        }
        for (int l = 0, r = a.size() - 1; l < r;
             l = r + 1, r = nodes.size() - 1) {
            for (int i = l; i < r; i += 2) {
                Node parent = Node(nodes[i].l, nodes[i + 1].r,
                                   op(a, nodes[i].max, nodes[i + 1].max));
                parent.childs = {nodes[i].id, nodes[i + 1].id};
                nodes[i].parent = nodes[i + 1].parent = parent.id;
                nodes.push_back(parent);
            }
            if (((r - l) & 1) == 0) {
                Node parent = Node(nodes[r].l, nodes[r].r, nodes[r].max);
                parent.childs = {nodes[r].id};
                nodes[r].parent = parent.id;
                nodes.push_back(parent);
            }
        }
    }
    int findMax(int l, int r) {
        int res = l;
        stack<int> pending;
        pending.push(nodes.size() - 1);
        while (!pending.empty()) {
            Node current = nodes[pending.top()];
            pending.pop();
            if (current.l >= l && current.r <= r) {
                res = op(a, res, current.max);
                continue;
            } else if (current.l <= r && current.r >= l) {
                for (int child : current.childs) {
                    pending.push(child);
                }
            }
        }
        return res;
    }
    void update(int i, int v) {
        a[i] = v;
        do {
            for (int child : nodes[i].childs) {
                nodes[i].max = op(a, nodes[i].max, nodes[child].max);
            }
            i = nodes[i].parent;
        } while (i != -1);
    }
    int getV(int i) {
        return a[i];
    }
    int FindLeftMostValid(int min) {
        int root = nodes.size() - 1;
        if (a[nodes[root].max] < min) {
            return -1;
        }
        while (!nodes[root].childs.empty()) {
            vector<int> childs = nodes[root].childs;
            if (childs.size() == 2) {
                if (a[nodes[childs[0]].max] >= min) {
                    root = childs[0];
                } else {
                    root = childs[1];
                }
            } else {
                root = childs[0];
            }
        }
        return nodes[root].max;
    }
};
void solve() {
    int n = nxt<int>(), m = nxt<int>();
    vector<int> h(n);
    nxtseq(h);
    function<int(vector<int> &, int, int)> op =
        [](vector<int> &a, int i, int j) { return a[i] >= a[j] ? i : j; };
    Tree tree(h, op);
    while (m--) {
        int x = nxt<int>();
        int res = tree.FindLeftMostValid(x);
        cout << res + 1 << ' ';
        if (res != -1) {
            tree.update(res, tree.getV(res) - x);
        }
    }
}

void precompute() {
}

void IOSetter();
void TCGetter();

int main() { // Don't touch it, compile with "_DEBUG" flag
    precompute();
    IOSetter();
    TCGetter();
}

void TCGetter() {
    int t = T ? nxt<int>() : 1;
    do {
        solve();
    } while (--t && cout << '\n');
};

void IOSetter() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef _DEBUG
    freopen("../templates/default.in", "r", stdin);
    freopen("../templates/default.out", "w", stdout);
#else
    if (iofile != "") {
        freopen((iofile + ".in").c_str(), "r", stdin);
        freopen((iofile + ".out").c_str(), "w", stdout);
    }
#endif
};

template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
template <typename T>
typename enable_if<!is_iterable<T>::value>::type nxtseq(T &x) {
    cin >> x;
}
template <typename T>
typename enable_if<is_iterable<T>::value>::type nxtseq(T &x) {
    for (auto &v : x) {
        nxtseq(v);
    }
}
template <typename Itr> void nxtseq(Itr begin, Itr end) {
    for (Itr itr = begin; itr < end; ++itr) {
        nxtseq(*itr);
    }
}
template <typename T1, typename T2> void nxtseq(pair<T1, T2> &p) {
    nxtseq(p.first);
    nxtseq(p.second);
}
