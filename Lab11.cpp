// Josue Marcial
//11-16-23
// CS-1428 Lab
//Description: this program will keep track of a dealership inventory

#include <iostream> 
#include <string> 

using namespace std;

struct Car{
    string make;
    int year;
    int quantity;
};

int main (){
    const int SIZE = 3;
    Car car[SIZE];
    int total = 0;
    string highestMake, lowestMake;
    int highestInventory = 0, lowestInventory = INT_MAX;

    for(int i = 0; i< SIZE; ++i){
        cout << "Record #" << i + 1 << endl; 
        cout << "Enter make: "; 
        getline(cin >> ws, car[i].make); // Using getline to read entire line since problems occrued when inputing "Range Rover"
        cout << "Enter year: ";
        cin >> car[i].year;
        cout << "Enter quantity: ";
        cin >> car[i].quantity;
        cout << endl;

        total += car[i].quantity;

        if (car[i].quantity > highestInventory){
            highestInventory = car[i].quantity;
            highestMake = car[i].make;

        }
        if (car[i].quantity < lowestInventory){
            lowestInventory = car[i].quantity;
            lowestMake = car[i].make;
        }
    }

    cout << "Total Inventory: " << total << endl;
    cout << "Highest Inventory: " << highestMake << endl;
    cout << " Lowest Inventory: " << lowestMake << endl;

    return 0;
}