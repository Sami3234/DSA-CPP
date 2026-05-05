#include <iostream>
#include <queue>
using namespace std;
struct Patient {
string name;
int age;
string condition;
int priority;
bool operator<(const Patient& p) const {
    return priority < p.priority;
}

};

int main() {
priority_queue<Patient> pq;
pq.push({"Ali", 25, "Fever", 1});
pq.push({"Ahmed", 40, "Accident", 5});
pq.push({"Sara", 30, "Chest Pain", 4});
pq.push({"Zain", 50, "Cold", 2});

cout << "Patients treated in order:\n";
while (!pq.empty()) {
    Patient p = pq.top();
    pq.pop();
    cout << p.name << " | Age: " << p.age
         << " | Condition: " << p.condition
         << " | Priority: " << p.priority << endl;
}
return 0;
}