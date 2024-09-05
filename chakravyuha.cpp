#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if Abhimanyu can cross the Chakravyuha
bool canAbhimanyuCross(int p, vector<int>& enemyPowers, int index, int skipTimes, int rechargeTimes) {
    if (index == enemyPowers.size()) {
        return true; // Abhimanyu has crossed all circles
    }
    
    // Handle back attack from enemy 3 and 7
    if (index == 4 && enemyPowers[2] > 0) {
        int backAttack = enemyPowers[2] / 2;
        if (p < backAttack) return false;
        p -= backAttack;
    }
    if (index == 8 && enemyPowers[6] > 0) {
        int backAttack = enemyPowers[6] / 2;
        if (p < backAttack) return false;
        p -= backAttack;
    }
    
    // Case 1: Fight the current enemy
    if (p >= enemyPowers[index]) {
        return canAbhimanyuCross(p - enemyPowers[index], enemyPowers, index + 1, skipTimes, rechargeTimes);
    }
    
    // Case 2: Skip the current enemy if skipTimes > 0
    if (skipTimes > 0) {
        return canAbhimanyuCross(p, enemyPowers, index + 1, skipTimes - 1, rechargeTimes);
    }
    
    // Case 3: Recharge if rechargeTimes > 0 (Assuming recharge gives 50 power)
    if (rechargeTimes > 0) {
        return canAbhimanyuCross(p + 50, enemyPowers, index, skipTimes, rechargeTimes - 1);
    }
    
    return false; // Abhimanyu loses
}

int main() {
    int p, skipTimes, rechargeTimes;
    const int n = 11; // Number of enemy circles is fixed at 11
    
    // Taking inputs from the user
    cout << "Enter the initial power of Abhimanyu: ";
    cin >> p;
    
    vector<int> enemyPowers(n);
    cout << "Enter the powers of the 11 enemies: ";
    for (int i = 0; i < n; ++i) {
        cin >> enemyPowers[i];
    }
    
    cout << "Enter the number of times Abhimanyu can skip enemies: ";
    cin >> skipTimes;
    
    cout << "Enter the number of times Abhimanyu can recharge: ";
    cin >> rechargeTimes;

    // Check if Abhimanyu can cross the Chakravyuha
    bool result = canAbhimanyuCross(p, enemyPowers, 0, skipTimes, rechargeTimes);
    
    if (result) {
        cout << "Abhimanyu wins" << endl;
    } else {
        cout << "Abhimanyu loses" << endl;
    }

    return 0;
}
