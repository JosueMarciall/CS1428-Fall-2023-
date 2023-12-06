// Author: Josue Marcial
// Date: September 28, 2023
// CS1428 Lab
// Lab 4
// Description: This program will calculate the grocery bill
// based on user input

#include <iostream>
using namespace std;

int main() {
    char choice; // user's choice
    float weight, total_price;

    // Display greeting:
    cout << "Welcome to the Grocery Store!" << endl;

    // Get user input for the first iteam:
    cout << "Enter the item you wish to purchase: " << endl;
    cout << " V: Veggies \n F: Fruits \n C: Chips" << endl;
    cin >> choice;

    // Use a switch statement to evaluate the user's choice
    switch (choice) {
        case 'V': // if the choice is vegetables
            cout << "Select the vegetable you want to buy:" << endl;
            cout << "O: Onions ($0.79 per lb)\nT: Tomatoes ($0.68 per lb)\nP: Potatoes ($0.82 per lb)" << endl;
            cin >> choice;

            // Use a switch statement to evaluate the user's second choice and compute the total price
            switch (choice) {
                case 'O':
                    cout << "Enter the weight (lb):" << endl;
                    cin >> weight;
                    total_price = weight * 0.79;
                    break;
                case 'T':
                    cout << "Enter the weight (lb):" << endl;
                    cin >> weight;
                    total_price = weight * 0.68;
                    break;
                case 'P':
                    cout << "Enter the weight (lb):" << endl;
                    cin >> weight;
                    total_price = weight * 0.82;
                    break;
                default:
                    cout << "Invalid choice. Terminating the program." << endl;
                    return 1; // Terminate the program due to invalid input
            }
            // Each option needs their own case + cases for the options for each catogory 
            break;
        case 'F': // If the choice is fruits
            cout << "Select the fruits you want to buy:" << endl;
            cout << "G: Grapes ($1.9 per lb)\nA: Apples ($0.98 per lb)\nB: Bananas ($0.60 per lb)" << endl;
            cin >> choice;

            // Use a switch statement to evaluate the user's second choice and compute the total price
            switch (choice) {
                case 'G':
                    cout << "Enter the weight (lb):" << endl;
                    cin >> weight;
                    total_price = weight * 1.9;
                    break;
                case 'A':
                    cout << "Enter the weight (lb):" << endl;
                    cin >> weight;
                    total_price = weight * 0.98;
                    break;
                case 'B':
                    cout << "Enter the weight (lb):" << endl;
                    cin >> weight;
                    total_price = weight * 0.60;
                    break;
                default:
                    cout << "Invalid choice. Terminating the program." << endl;
                    return 1; // Terminate the program due to invalid input
            }
            break;
        case 'C': // if the choice is chips
            cout << "Select the chips you want to buy:" << endl;
            cout << "W: Wavy ($2.28)\nL: Lays ($2.50)\nR: Onion Rings ($1.50)" << endl;
            cin >> choice;

            // Use a switch statement to evaluate the user's second choice and compute the total price
            switch (choice) {
                case 'W':
                    total_price = 2.28;
                    break;
                case 'L':
                    total_price = 2.50;
                    break;
                case 'R':
                    total_price = 1.50;
                    break;
                default:
                    cout << "Invalid choice. Terminating the program." << endl;
                    return 1; // Terminate the program due to invalid input
            }
            break;
        default:
            cout << "Invalid choice. Terminating the program." << endl;
            return 1; // Terminate the program due to invalid input
    }

    cout << "The total price is $" << total_price << endl;

    return 0;
}