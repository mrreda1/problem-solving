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
    long id, l, r, parent;
    long long sum;
    vector<long> childs;
    Node(long l, long r, long long sum) {
        id = ID(), parent = -1;
        this->l = l, this->r = r;
        this->sum = sum;
    }
};
class Tree {
  private:
    vector<Node> nodes;
    function<ll(ll, ll)> op, inv_op;

  public:
    template <typename T>
    Tree(vector<T> a, function<ll(ll, ll)> op, function<ll(ll, ll)> inv_op) {
        this->op = op, this->inv_op = inv_op;
        for (long i = 0; i < a.size(); i++) {
            nodes.push_back(Node(i, i, a[i]));
        }
        for (long l = 0, r = a.size() - 1; l < r;
             l = r + 1, r = nodes.size() - 1) {
            for (long i = l; i < r; i += 2) {
                Node parent = Node(nodes[i].l, nodes[i + 1].r,
                                   op(nodes[i].sum, nodes[i + 1].sum));
                parent.childs = {nodes[i].id, nodes[i + 1].id};
                nodes[i].parent = nodes[i + 1].parent = parent.id;
                nodes.push_back(parent);
            }
            if (((r - l) & 1) == 0) {
                Node parent = Node(nodes[r].l, nodes[r].r, nodes[r].sum);
                parent.childs = {nodes[r].id};
                nodes[r].parent = parent.id;
                nodes.push_back(parent);
            }
        }
    }
    long long sum(long l, long r) {
        long long res = 0;
        stack<long> pending({long(nodes.size()) - 1});
        while (!pending.empty()) {
            Node current = nodes[pending.top()];
            pending.pop();
            if (current.l >= l && current.r <= r) {
                res = op(res, current.sum);
                continue;
            } else if (current.l <= r && current.r >= l) {
                for (long child : current.childs) {
                    pending.push(child);
                }
            }
        }
        return res;
    }
    void update(long i, long long v) {
        long long old_v = nodes[i].sum;
        while (nodes[i].parent != -1) {
            nodes[i].sum = op(inv_op(nodes[i].sum, old_v), v);
            i = nodes[i].parent;
        }
    }
};
void solve() {
    int n = nxt<int>(), q = nxt<int>();
    vector<ll> a(n);
    nxtseq(a);
    function<ll(ll, ll)> op = [](ll x, ll y) { return x ^ y; }, inv_op = op;
    Tree tree(a, op, inv_op);
    while (q--) {
        int type = nxt<int>();
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            tree.update(i - 1, v);
        } else {
            long l, r, target;
            cin >> l >> r >> target;
            cout << (tree.sum(l - 1, r - 1) == target ? "YES" : "NO") << '\n';
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
