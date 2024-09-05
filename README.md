# Abhimanyu in Chakravyuha Problem

## Problem Description

Abhimanyu is stuck inside a **Chakravyuha**, a series of **11 circles** guarded by enemies with different powers. He needs to pass through all these circles to return to the Pandavas' army, but each enemy presents a challenge. The goal is to determine if Abhimanyu can successfully pass through all 11 circles given certain constraints.

### Rules and Constraints:
1. **Initial Power (`p`)**: Abhimanyu starts with a given amount of power.
2. **Enemies' Powers**: Each of the 11 circles is guarded by enemies with specific powers: `k1, k2, ..., k11`.
3. **Skip Option (`a`)**: Abhimanyu has the ability to skip fighting enemies in `a` number of circles.
4. **Recharge Option (`b`)**: Abhimanyu can recharge his power `b` times (increasing his power by a fixed amount, say 50 units, each time).
5. **Back Attacks**:
   - If Abhimanyu is in **circle 4**, the enemy from **circle 3** (if still alive) can attack from behind with **half their power**.
   - If Abhimanyu is in **circle 8**, the enemy from **circle 7** (if still alive) can attack from behind with **half their power**.
6. **Fighting Enemies**: If Abhimanyu enters a circle with **less power** than the enemy guarding that circle, he loses.
7. **Win Condition**: Abhimanyu must survive all 11 circles, either by fighting, skipping, or recharging, to successfully pass the Chakravyuha.

### Input:
- Initial power `p` of Abhimanyu.
- Powers of the 11 enemies (`k1, k2, ..., k11`).
- Number of skips `a` (number of times Abhimanyu can skip a battle).
- Number of recharges `b` (number of times Abhimanyu can recharge his power).

### Output:
- The program will output whether **Abhimanyu wins** (successfully passes all circles) or **Abhimanyu loses** (fails to pass the Chakravyuha).

---

## Solution

We can approach this problem using **recursion** to simulate Abhimanyu’s journey through the 11 circles. The recursive function will handle different cases, including:
1. **Fighting**: Abhimanyu fights the enemy in the current circle and continues to the next.
2. **Skipping**: If Abhimanyu has remaining skips, he can skip the current enemy.
3. **Recharging**: If Abhimanyu has remaining recharges, he can increase his power and retry the current circle.

Additionally, we handle the **back attack** scenario for enemies in circles 3 and 7.

### Algorithm:

1. **Base Case**: If Abhimanyu has successfully crossed all circles (index reaches 11), return `true` (win).
2. **Back Attack**: If Abhimanyu is in circle 4 or 8, check for attacks from enemies in circles 3 or 7, respectively.
3. **Fight the Enemy**: If Abhimanyu’s current power is greater than or equal to the enemy’s power, deduct the enemy’s power from Abhimanyu and move to the next circle.
4. **Skip the Enemy**: If Abhimanyu can skip, move to the next circle without losing power and reduce the skip count.
5. **Recharge**: If Abhimanyu can recharge, add a fixed amount of power and retry the current circle.

If none of these options are feasible (i.e., Abhimanyu’s power is too low, no skips left, and no recharges left), he loses the battle.

### Example:

```plaintext
Input:
Initial Power of Abhimanyu: 100
Enemy Powers: [20, 30, 50, 25, 40, 60, 70, 35, 80, 90, 100]
Skip Times: 1
Recharge Times: 2

Output:
Abhimanyu wins
