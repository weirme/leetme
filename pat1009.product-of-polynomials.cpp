#include <cstdio>
#include <vector>

using namespace std;
const int N = 2010;

int main() {
    int k;
    int exp;
    double coef;
    vector< pair<int, double> > a, b;
    scanf("%d", &k);
    while (k--) {
        scanf("%d%lf", &exp, &coef);
        a.push_back(make_pair(exp, coef));
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%lf", &exp, &coef);
        b.push_back(make_pair(exp, coef));
    }
    double res[N] = {0};
    for (auto it1 = a.begin(); it1 < a.end(); it1++) {
        for (auto it2 = b.begin(); it2 < b.end(); it2++) {
            res[it1->first + it2->first] += it1->second * it2->second;
        }
    }
    int n = 0;
    for (int i = 0; i < N; i++) {
        if (res[i] > 0) n++;
    }
    printf("%d", n);
    for (int i = N-1; i >= 0; i--) {
        if (res[i] > 0) printf(" %d %.1lf", i, res[i]);
    }
    return 0;
}
