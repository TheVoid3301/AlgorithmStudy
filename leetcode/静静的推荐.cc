#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
 
using namespace std;
 
struct Student {
    int t_score; // 天梯赛成绩
    int p_score; // PAT成绩
};
 
bool compare(const Student &a, const Student &b) {
    if (a.t_score != b.t_score) return a.t_score < b.t_score;
    return a.p_score > b.p_score;
}
 
void solve(){
    int N, K, S;
    cin >> N >> K >> S;
 
    vector<Student> students(N);
    for (int i = 0; i < N; ++i) {
        cin >> students[i].t_score >> students[i].p_score;
    }
 
    // 筛选天梯赛成绩不低于175分的学生
    students.erase(remove_if(students.begin(), students.end(), [](const Student &s) {
        return s.t_score < 175;
    }), students.end());
 
    // 按天梯赛成绩升序，PAT成绩降序排序
    sort(students.begin(), students.end(), compare);
 
    int total_count = 0;
    vector<int> dp; // 动态规划数组，记录当前批次的最大递增子序列长度
 
    for (int batch = 0; batch < K; ++batch) {
        vector<int> temp; // 临时数组，用于记录当前批次的递增子序列
        for (const auto &student : students) {
            if (temp.empty() || student.t_score > temp.back()) {
                temp.push_back(student.t_score);
            } else if (student.t_score == temp.back() && student.p_score >= S) {
                temp.push_back(student.t_score);
            }
        }
        total_count += temp.size();
        students.erase(students.begin(), students.begin() + temp.size());
    }
 
    cout << total_count << endl;
}
 
int main(){
	int t = 1;
	// cin >> t;
	while(t --)
	solve();
	return 0;
}