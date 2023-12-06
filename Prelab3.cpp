// Josue Marcial
// Pre Lab 4 
// 9/28/23


#include <iostream>

using namespace std;

int main()
{
     char user_input;
     string statement;

     cout << "Is Boba Fett better than Jango Fett? ('Y' or 'N')" << endl;
     cin >> user_input;

     switch (user_input)
     {
     case 'y':
     case 'Y':
          cout << "You think Boba Fett is better than Jango Fett..." << endl;
          statement = "Wrong!";
          break;
     case 'n':
     case 'N':
          cout << "You do not think Boba Fett is better than Jango Fett..." << endl;
          statement = "Correct!";
          break;
     default:
          statement = "Invalid Input.";
          break;
     }

     cout << statement << endl;

     return 0;
}
