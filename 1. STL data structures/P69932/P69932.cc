#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pqueue;
    string line;
    while (getline(cin, line)) {
        istringstream ss(line);
        int number;
        while (ss >> number) pqueue.push(number);

        int lastNum;
        int count = 0;
        if (not pqueue.empty()) {
            lastNum = pqueue.top();
            ++count;
            pqueue.pop();
        }
        while (not pqueue.empty()) {
            if ((lastNum + pqueue.top())%2 != 0) {
                ++count;
                lastNum = pqueue.top();
            }
            pqueue.pop();
        }
        cout << count << endl;
    }
}