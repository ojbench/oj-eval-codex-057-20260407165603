#include <bits/stdc++.h>
using namespace std;

struct Student {
    string id;
    string name;
    int score;
    int idx;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Student> students;
    students.reserve(10000);
    unordered_map<string,int> id2pos;
    id2pos.reserve(16384);
    unordered_map<string,int> name2pos;
    name2pos.reserve(16384);

    int cmd;
    int nextIdx = 0;
    while (cin >> cmd){
        if(cmd==1){
            string id, name;
            int score;
            if(!(cin >> id >> name >> score)) break;
            if(id2pos.find(id)!=id2pos.end()){
                cout << "FAILED\n";
                continue;
            }
            Student s{ id, name, score, nextIdx++ };
            int pos = (int)students.size();
            students.push_back(s);
            id2pos[id] = pos;
            name2pos[name] = pos;
            cout << "SUCCESS\n";
        } else if(cmd==2){
            if(!students.empty()){
                for(const auto &s: students){
                    cout << s.id << ' ' << s.name << ' ' << s.score << "\n";
                }
            }
        } else if(cmd==3){
            string id; cin >> id;
            auto it = id2pos.find(id);
            if(it!=id2pos.end()){
                const auto &s = students[it->second];
                cout << s.id << ' ' << s.name << ' ' << s.score << "\n";
            }
        } else if(cmd==4){
            string name; cin >> name;
            auto it = name2pos.find(name);
            if(it!=name2pos.end()){
                const auto &s = students[it->second];
                cout << s.id << ' ' << s.name << ' ' << s.score << "\n";
            }
        } else if(cmd==5){
            if(!students.empty()){
                vector<int> order(students.size()); iota(order.begin(), order.end(), 0);
                stable_sort(order.begin(), order.end(), [&](int a, int b){
                    return students[a].id < students[b].id;
                });
                for(int idx : order){
                    const auto &s = students[idx];
                    cout << s.id << ' ' << s.name << ' ' << s.score << "\n";
                }
            }
        } else if(cmd==6){
            if(!students.empty()){
                vector<int> order(students.size()); iota(order.begin(), order.end(), 0);
                stable_sort(order.begin(), order.end(), [&](int a, int b){
                    if(students[a].score != students[b].score) return students[a].score > students[b].score;
                    return students[a].idx < students[b].idx;
                });
                for(int idx : order){
                    const auto &s = students[idx];
                    cout << s.id << ' ' << s.name << ' ' << s.score << "\n";
                }
            }
        } else if(cmd==7){
            cout << "END\n";
            break;
        } else {
            // ignore unknown command tokens safely
        }
    }
    return 0;
}
