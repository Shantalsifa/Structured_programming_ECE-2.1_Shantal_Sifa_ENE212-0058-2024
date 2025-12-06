#include <stdio.h>

int login();               // returns 1 = True (login success), 0 = False
int showMenu();            // returns user choice
int checkBalance(int balance);
int deposit(int balance);
int withdrawMoney(int balance);


int main() {

    int balance = 1000;   // starting balance
    int choice = 0;

    printf("=== ATM SYSTEM ===\n");

    // User must first login
    if (login() == 0) {
        printf("Access denied. Too many incorrect attempts.\n");
        return 0;
    }

    while (choice != 4) {

        choice = showMenu();

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;

            case 2:
                balance = deposit(balance);
                break;

            case 3:
                balance = withdrawMoney(balance);
                break;

            case 4:
                printf("Exiting... Thank you for using the ATM!\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}


int login() {

    int storedPIN = 1234;
    int enteredPIN;
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN == storedPIN) {
            printf("Login successful!\n\n");
            return 1;  // True
        }

        attempts++;
        printf("Incorrect PIN! Attempts used: %d out of 3\n", attempts);
    }

    return 0; // False
}


int showMenu() {
    int choice;
    printf("\n---- ATM MENU ----\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}



int checkBalance(int balance) {
    printf("Your current balance is: $%d\n", balance);
    return balance;  // returning balance is optional
}



int deposit(int balance) {
    int amount;

    printf("Enter amount to deposit: ");
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Deposit must be positive.\n");
        return balance;
    }

    balance += amount;
    printf("Deposit successful! New balance = $%d\n", balance);

    return balance;
}


int withdrawMoney(int balance) {
    int amount;

    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("Invalid amount. Withdrawal must be positive.\n");
        return balance;
    }

    if (amount > balance) {
        printf("Insufficient funds! Your balance is: $%d\n", balance);
        return balance;
    }

    balance -= amount;
    printf("Withdrawal successful! New balance = $%d\n", balance);

    return balance;
}
