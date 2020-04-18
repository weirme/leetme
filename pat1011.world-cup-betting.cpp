#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    char results[] = {'W', 'T', 'L'};
    vector<float> vec(3);
    float prod = 1;
    for (int i = 0; i < 3; i++) {
        scanf("%f%f%f", &vec[0], &vec[1], &vec[2]);
        auto it = max_element(vec.begin(), vec.end());
        printf("%c ", results[it-vec.begin()]);
        prod *= *it;
    }
    prod = (prod * 0.65 - 1) * 2;
    printf("%.2f", prod);
    return 0;
}
