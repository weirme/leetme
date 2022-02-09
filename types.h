#ifndef types_h
#define types_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class UFSet {
private:
    std::vector<int> vec;

public:
    UFSet(size_t n) {
        vec = *new std::vector<int>(n, -1);
    }
    
    int find(int v) {
        while (vec[v] != -1) {
            v = vec[v];
        }
        return v;
    }
    
    void connect(int p, int q) {
        p = find(p);
        q = find(q);
        vec[q] = p;
    }
    
    bool isconnect(int p, int q) {
        return find(p) == find(q);
    }

};

#endif /* types_h */
