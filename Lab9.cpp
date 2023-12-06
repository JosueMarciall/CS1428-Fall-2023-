// Josue Marcial 
// 11/2/2023
// CS1428 Lab
// Lab 9 

#include <iostream>
using namespace std; 


// Function : Main()
// Purpose : Given a user-provided letter weight, a postage cost is identified, if existent.
// Pre: None 
// Post; A postage is declared for the letter, 0or user is informed of too much weight. 

int main(){


    const int NUM_ELEMENTS = 14 ; 
    // weight in ounces 
    double letterWeight[NUM_ELEMENTS] = {1.0, 2.0, 3.0, 3.5, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0};
    // Costs in center (usps. com 2017)
    int postageCosts [NUM_ELEMENTS] = {49, 70, 91, 112, 161, 182, 203, 224, 266, 287, 308, 329, 350};


    double userLetterWeight;
    bool foundWeight;
    int i ;



    // Prompt user to enter letter weight 
    cout << "Enter letter weight (in ounces) : ";
    cin >> userLetterWeight; 



    foundWeight = false;

    for(i = 0; (i < NUM_ELEMENTS) && (!foundWeight);++1 ){
        if ( userLetterWeight < )
    }
}