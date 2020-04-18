#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 10010;

struct Book {
    string id;
    string title;
    string author;
    vector<string> keywords;
    string publisher;
    int year;
} library[N];

bool cmp(Book& a, Book& b) {
    return a.id < b.id;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> library[i].id;
        getchar();
        getline(cin, library[i].title);
        getline(cin, library[i].author);
        string keywords;
        getline(cin, keywords);
        stringstream input(keywords);
        string token;
        while (input >> token) {
            library[i].keywords.push_back(token);
        }
        getline(cin, library[i].publisher);
        cin >> library[i].year;
    }
    sort(library, library+n, cmp);
    int m;
    cin >> m;
    while (m--) {
        int flag;
        bool find = false;
        cin >> flag;
        getchar();
        getchar();
        string str;
        int year;
        getline(cin, str);
        cout << flag << ": " << str << endl;
        switch (flag) {
            case 1:
                for (int i = 0; i < n; i++) {
                    if (library[i].title == str) {
                        cout << library[i].id << endl;
                        find = true;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    if (library[i].author == str) {
                        cout << library[i].id << endl;
                        find = true;
                    }
                }
                break;
            case 3:
                for (int i = 0; i < n; i++) {
                    for (auto it = library[i].keywords.begin(); it < library[i].keywords.end(); it++) {
                        if (*it == str) {
                            cout << library[i].id << endl;
                            find = true;
                        }
                    }
                }
                break;
            case 4:
                for (int i = 0; i < n; i++) {
                    if (library[i].publisher == str) {
                        cout << library[i].id << endl;
                        find = true;
                    }
                }
                break;
            case 5:
                year = atoi(str.c_str());
                for (int i = 0; i < n; i++) {
                    if (library[i].year == year) {
                        cout << library[i].id << endl;
                        find = true;
                    }
                }
            default:
                break;
        }
        if (!find) cout << "Not Found" << endl;
    }
	return 0;
}
