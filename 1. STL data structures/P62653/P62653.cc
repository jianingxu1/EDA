#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    string w;
    while (cin >> w) {
        const auto comp = [&] (const string& a, const string& b) -> bool {
            string comp_string = w.substr(0, b.length());
            if (a.length() != b.length()) return a.length() > b.length();
            if (a < comp_string and b >= comp_string) return true;
            if (b < comp_string and a >= comp_string) return false;
            return a > b;
        };

        int ticketsAvailable = 0;
        priority_queue<string, vector<string>, decltype(comp)> ticketsAsked(comp);
        char c;
        cin >> c;
        while (c != 'E') {
            if (c == 'S') {
                string supporterCode;
                cin >> supporterCode;
                if (ticketsAvailable == 0) ticketsAsked.push(supporterCode);
                else {
                    --ticketsAvailable;
                    cout << supporterCode << endl;
                }
            }
            else {
                if (not ticketsAsked.empty()) {
                    cout << ticketsAsked.top() << endl;
                    ticketsAsked.pop();
                }
                else ++ticketsAvailable;
            }
            cin >> c;
        }
        cout << ticketsAvailable << " ticket(s) left" << endl;
        cout << ticketsAsked.size() << " supporter(s) with no ticket" << endl << endl;
    }
}