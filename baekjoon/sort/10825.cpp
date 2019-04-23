#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
struct student {
    int kor;
    int eng;
    int mat;
    char name[10];
};

bool comp(const student &s1, const student &s2) {
    if(s1.kor == s2.kor) {
        if(s1.eng == s2.eng) {
            if(s1.mat == s2.mat) 
                return strcmp(s1.name, s2.name) < 0;
            else
                return s1.mat > s2.mat;
        }
        return s1.eng < s2.eng;
    } else {
        return s1.kor > s2.kor;
    }
}

int main(void) 
{
    int n;
    student temp;
    vector<student> students;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%s %d %d %d",temp.name,&temp.kor, &temp.eng, &temp.mat);
        students.push_back(temp);
    }
    sort(students.begin(), students.end(), comp);
    for(int i = 0; i < n; i++) {
        printf("%s\n", students[i].name);
    }
}