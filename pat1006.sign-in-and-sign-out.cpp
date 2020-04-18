#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int M;
    vector<char*> ids;
    vector<int> start, end;
    scanf("%d", &M);
    int h, m, s;
    while (M--) {
        char* id = (char*)malloc(sizeof(char) * 20);
        scanf("%s", id);
        ids.push_back(id);
        scanf("%d:%d:%d", &h, &m, &s);
        start.push_back(3600*h + 60*m + s);
        scanf("%d:%d:%d", &h, &m, &s);
        end.push_back(3600*h + 60*m + s);
    }
    int first = min_element(start.begin(), start.end()) - start.begin();
    int last = max_element(end.begin(), end.end()) - end.begin();
    printf("%s %s", ids[first], ids[last]);
    return 0;
}
