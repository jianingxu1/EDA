#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> players;
    string name;
    while (cin >> name) {
        string command;
        cin >> command;
        auto it = players.find(name);
        if (command == "wins") {
            int money;
            cin >> money;
            if (it == players.end()) cout << name << " is not in the casino" << endl;
            else it->second += money;
        } else if (command == "leaves") {
            if (it == players.end()) cout << name << " is not in the casino" << endl;
            else {
                cout << name << " has won " << it->second << endl;
                players.erase(it);
            }
        } else {
            if (it != players.end()) cout << name << " is already in the casino" << endl;
            else players.insert({name, 0});
        }
    }
    cout << "----------" << endl;
    for (auto player : players) {
        cout << player.first << " is winning " << player.second << endl;
    }
}