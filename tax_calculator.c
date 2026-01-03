#include <stdio.h>

/* Function to display project introduction */
void displayIntro() {
    printf("============================================\n");
    printf("        INCOME TAX CALCULATOR (C)            \n");
    printf("============================================\n");
    printf("This program calculates income tax based on\n");
    printf("annual income using standard tax slabs.\n\n");
}

/* Function to calculate tax based on income */
float calculateTax(float income) {
    float tax = 0.0f;

    if (income <= 250000) {
        tax = 0.0f;
    }
    else if (income <= 500000) {
        tax = (income - 250000) * 0.05f;
    }
    else if (income <= 1000000) {
        tax = (250000 * 0.05f) + (income - 500000) * 0.20f;
    }
    else {
        tax = (250000 * 0.05f) +
              (500000 * 0.20f) +
              (income - 1000000) * 0.30f;
    }

    return tax;
}

/* Function to display the final result */
void displayResult(float income, float tax) {
    printf("\n----------- TAX DETAILS -----------\n");
    printf("Annual Income : INR %.2f\n", income);
    printf("Tax Payable   : INR %.2f\n", tax);
    printf("----------------------------------\n");
}

/* Main function */
int main(void) {
    float income = 0;
    float tax = 0;
    char choice;

    displayIntro();

    do {
        printf("Enter your annual income (INR): ");
        if (scanf("%f", &income) != 1 || income < 0) {
            printf("Invalid input! Please enter a valid income.\n");
            return 1;
        }

        tax = calculateTax(income);
        displayResult(income, tax);

        printf("\nDo you want to calculate tax again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Income Tax Calculator.\n");
    return 0;
}
