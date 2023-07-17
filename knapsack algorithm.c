#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}


// Function to solve the Knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    // Base case: If there are no items or knapsack capacity is 0
    if (n == 0 || W == 0)
        return 0;

    // If the weight of the nth item is more than the knapsack capacity, it cannot be included
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);

    // Return the maximum of two cases: (1) nth item included (2) nth item not included
    return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
               knapsack(W, wt, val, n - 1));
}

int main()
{
    int val[] = {60, 100, 120};   // Values of items
    int wt[] = {10, 20, 30};      // Weights of items
    int W = 50;                   // Knapsack capacity
    int n = sizeof(val) / sizeof(val[0]); // Number of items

    int maxValue = knapsack(W, wt, val, n);
    printf("Maximum value that can be obtained: %d\n", maxValue);

    return 0;
}
