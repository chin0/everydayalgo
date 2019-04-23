#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
struct student {
    int age;
    int id;
    char name[101];
};

bool comp(student &s1, student &s2) {
    if(s1.age == s2.age) {
        return s1.id < s2.id;
    } else {
        return s1.age < s2.age;
    }
}

int main(void) 
{
    int n;
    student temp;
    vector<student> students;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        temp.id = i;
        scanf("%d %s",&temp.age,temp.name);
        students.push_back(temp);
    }
    sort(students.begin(), students.end(), comp);
    for(int i = 0; i < n; i++) {
        printf("%d %s\n",students[i].age, students[i].name);
    }
}