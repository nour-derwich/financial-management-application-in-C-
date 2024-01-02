#include <stdio.h>
#include <string.h>
#include "unistd.h"
#define MAX_EXPENSES 100 // Maximum number of expenses

// Structure to hold date information
struct Date {
    int day;
    int month;
    int year;
};

// Structure to hold individual expense details
struct Expense {
    char category[50];
    float amount;
    struct Date expenseDate;
};

// Structure to hold financial data
struct FinancialData {
    float income;
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses;
};

// Function to calculate the total expenses
float calculateTotalExpenses(struct FinancialData *data) {
    float total = 0.0;
    for (int i = 0; i < data->numExpenses; ++i) {
        total += data->expenses[i].amount;
    }
    return total;
}

// Function to calculate the percentage of expenses compared to income
float calculatePercentage(float expenses, float income) {
    return (expenses / income) * 100;
}
//Title for pages
void title(){

    printf("\n================================================");
    printf("\n           Flouci PROGRAM");
    printf("\n================================================");
}
// Function to input expenses
void inputExpenses(struct FinancialData *data) {
     system("cls");
    title();
    printf("\n Enter your income: ");
    scanf("%f", &data->income);

    printf("Enter the number of expenses: ");
    scanf("%d", &data->numExpenses);

    for (int i = 0; i < data->numExpenses; ++i) {
        printf("\nEnter details for expense %d:\n", i + 1);

        printf("Category: ");
        scanf("%s", data->expenses[i].category);

        printf("Amount: ");
        scanf("%f", &data->expenses[i].amount);

        printf("Expense Date (DD MM YYYY): ");
        scanf("%d %d %d",
              &data->expenses[i].expenseDate.day,
              &data->expenses[i].expenseDate.month,
              &data->expenses[i].expenseDate.year);
    }
}

int main() {
     system("Color F0");
    struct FinancialData userData;

    inputExpenses(&userData);

    float totalExpenses = calculateTotalExpenses(&userData);
    float percentage = calculatePercentage(totalExpenses, userData.income);

    printf("\nTotal expenses: %.2f\n", totalExpenses);
    printf("Your expenses are %.2f%% of your income.\n", percentage);

    return 0;
}
