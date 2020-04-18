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

using namespace std;

const int INF = 0x3f3f3f3f;

struct Student {
    string name;
    string id;
    int grade;
};

bool cmp(Student& a, Student& b) {
    return a.grade < b.grade;
}

int main() {
    vector<Student> male;
    vector<Student> female;
    int n;
    string name, id;
    char gender;
    int grade;
    cin >> n;
    while (n--) {
        cin >> name >> gender >> id >> grade;
        if (gender == 'M') male.push_back({name, id, grade});
        else female.push_back({name, id, grade});
    }
    sort(male.begin(), male.end(), cmp);
    sort(female.begin(), female.end(), cmp);
    if (male.empty()) {
        auto it = female.end()-1;
        cout << it->name << " " << it->id << endl;
        cout << "Absent" << endl;
        cout << "NA" << endl;
    }
    else if (female.empty()) {
        cout << "Absent" << endl;
        auto it = male.begin();
        cout << it->name << " " << it->id << endl;
        cout << "NA" << endl;
    }
    else {
        auto it1 = female.end()-1, it2 = male.begin();
        cout << it1->name << " " << it1->id << endl;
        cout << it2->name << " " << it2->id << endl;
        cout << it1->grade - it2->grade << endl;
    }
	return 0;
}
