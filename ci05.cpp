#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

char* replaceSpace(char* s){
    if (s == NULL || *s == '\0')
        return s;
    int len = 0;
    int n = 0;
    char* p = s;
    char* q = NULL;
    while (*p != '\0') {
        len++;
        if (*p == ' ')
            n++;
        p++;
    }
    s = (char*)realloc(s, sizeof(char) * (len + 1 + n * 2));
    q = s + len;
    p = q + n * 2;
    while (q >= s) {
        if (*q != ' ')
            *p-- = *q--;
        else {
            *p-- = '0';
            *p-- = '2';
            *p-- = '%';
            q--;
        }
    }
    return s;
}

int main() {
    char* s = (char*)malloc(sizeof(char) * 3);
    char str[3] = "  ";
    for (int i = 0; i < 3; i++)
        s[i] = str[i];
    s = replaceSpace(s);
    return 0;
}
