#include <iostream>
#include <map>
using namespace std;
/* 
    words can be repeated -> 
*/

int main() {
    map<string, int, greater<string>> freq;
    string command;
    while (cin >> command) {
        if (command == "store") {
            string word;
            cin >> word;
            auto it = freq.find(word);
            
            if (it == freq.end()) freq.insert(it, {word, 1});
            else ++it->second;
        }
        else if (command == "delete") {
            string word;
            cin >> word;
            auto it = freq.find(word);

            if (it != freq.end()) {
                if (it->second >= 2) --it->second;
                else freq.erase(it);
            }
        }
        else if (command == "maximum?") {
            if (not freq.empty()) {
                auto it = freq.begin();
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
            else cout << "indefinite maximum" << endl;
        }
        else {
            if (not freq.empty()) {
                auto it = freq.end();
                --it;
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
            else cout << "indefinite minimum" << endl;
        }
    }
}