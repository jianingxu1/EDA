#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool comp(const pair<string, int>& a, const pair<string, int>& b) {
    int a_elo = a.second;
    int b_elo = b.second;
    if (a_elo != b_elo) return a_elo > b_elo;
    else return a.first < b.first;
}

int main() {
    unordered_map<string, pair<bool, int>> players;
    string command;
    while (cin >> command) {
        string p1;
        cin >> p1;
        auto it1 = players.find(p1);
        if (command == "LOGIN") {
            if (it1 != players.end()) it1->second.first = true;
            else players.insert({p1, {true, 1200}});
        }
        else if (command == "LOGOUT") {
            if (it1 != players.end()) it1->second.first = false;
        }
        else if (command =="PLAY") {
            string p2;
            cin >> p2;
            auto it2 = players.find(p2);
            if (it1 == players.end() or it2 == players.end() or not it1->second.first or not it2->second.first) cout << "player(s) not connected" << endl;
            else {
                it1->second.second += 10;
                it2->second.second -= 10;
                if (it2->second.second < 1200) it2->second.second = 1200;
            }
        }
        else cout << p1 << ' ' << it1->second.second << endl;
    }
    
    vector<pair<string, int>> ranking(players.size());
    int i = 0;
    for (auto player:players) {
        ranking[i].first = player.first;
        ranking[i].second = player.second.second;
        ++i;
    }
    sort(ranking.begin(), ranking.end(), comp);
    cout << endl << "RANKING" << endl;
    for (auto player:ranking) {
        cout << player.first << ' ' << player.second << endl;
    }
}