// Reference: https://www.hackerrank.com/challenges/the-power-sum/problem

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ---------------------------------------------------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------------------------------------------------

// Memo-Table: (Largest-Number + 1) x (Total + 1)
//    Rows: Numbers of Combinations for various Total-Sums with a certain Current-Number
//      -> Supporting all possible Numbers (1..[Largest-Number])
//    Columns: Number of Combinations for a specific Total-Sum of a certain Current-Number (By Row)
//      -> Supporting all possible Totals
// Note: Adding 1 for proper indexing support

// Largest-Number: "Total^(1/Power)" - Finding the Root of the total
//    -> Could be equal to the total when brought to the Power (If whole)
int compute_largest_number(int total, int power) {
    return (int) pow(total, 1.0 / ((double) power));
}

int find_power_sum_combinations(int total, int power, int number, int** memo_table) {
    // ---------------------------------------------------------------------------
    // Base-Cases / Terminating-Cases
    // ---------------------------------------------------------------------------

    // Proper sum was found
    if (total == 0) return 1;

    // Proper sum was NOT found (Overflow)
    if (total < 0) return 0;

    // Proper sum was NOT found (Underflow)
    if (total > 0 && number == 0) return 0;

    // ---------------------------------------------------------------------------
    // Recursive-Case with Memoization
    // ---------------------------------------------------------------------------

    if (memo_table[number][total] == -1) {
        int combinations_with_number = find_power_sum_combinations(
                total - ((int) pow(number, power)),
                power,
                number - 1,
                memo_table
        );

        int combinations_without_number = find_power_sum_combinations(
                total,
                power,
                number - 1,
                memo_table
        );

        memo_table[number][total] = combinations_with_number + combinations_without_number;
    }

    return memo_table[number][total];
}

int power_sum(int total, int power) {
    // Step 1. Computing the largest number for the range of values to try combine

    int largest_number = compute_largest_number(total, power);

    // Step 2. Building the Memoization-Table (Largest-Number x Total)
    //   -> Adding 1 to support proper Index-Based access by values

    int** memo_table = (int**) malloc(sizeof(int*) * (largest_number + 1));

    for (int i = 0; i <= largest_number; i++) {
        memo_table[i] = (int*) malloc(sizeof(int) * (total + 1));

        // Specifying that the Number of Combinations was NOT found yet
        //   - "0" would be claiming that there are no combinations (VALID)
        for (int j = 0; j <= total; j++) memo_table[i][j] = -1;
    }

    // Step 3. Performing Recursive Combination-Finding with Memoization-Table
    //  - Starting from Largest-Number and going down to 1
    //  -> Knowing when to terminate implicitly + More cost-effective

    int combinations = find_power_sum_combinations(total, power, largest_number, memo_table);

    // Step 4. Releasing / Freeing up Memoization-Table

    for (int i = 0; i <= largest_number; i++) free(memo_table[i]);

    free(memo_table);

    // Step 5. Returning the found number of combinations

    return combinations;
}

// ---------------------------------------------------------------------------------------------------------------------
// Tester
// ---------------------------------------------------------------------------------------------------------------------

int main() {
    // Total=10 and Power=2 -> 1 Combination
    printf("%d\n", power_sum(10, 2));

    // Total=100 and Power=2 -> 3 Combinations
    printf("%d\n", power_sum(100, 2));

    // Total=100 and Power=3 -> 1 Combination
    printf("%d\n", power_sum(100, 3));

    return 0;
}
