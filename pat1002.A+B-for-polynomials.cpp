#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int K;
    int exp;
    float coef;
    vector< pair<int, float> > a, b, res;
    scanf("%d", &K);
    while (K--) {
        scanf("%d%f", &exp, &coef);
        a.push_back(make_pair(exp, coef));
    }
    scanf("%d", &K);
    while (K--) {
        scanf("%d%f", &exp, &coef);
        b.push_back(make_pair(exp, coef));
    }
    auto it1 = a.begin(), it2 = b.begin();
    while (it1 != a.end() && it2 != b.end()) {
        if (it1->first < it2->first) res.push_back(*it2++);
        else if (it1->first > it2->first) res.push_back(*it1++);
        else {
            if (it1->second + it2->second != 0)
                res.push_back(make_pair(it1->first, it1->second + it2->second));
            it1++;
            it2++;
        }
    }
    while (it1 != a.end()) res.push_back(*it1++);
    while (it2 != b.end()) res.push_back(*it2++);
    printf("%lu", res.size());
    for (auto it = res.begin(); it < res.end(); it++)
        printf(" %d %.1f", it->first, it->second);
    return 0;
}
