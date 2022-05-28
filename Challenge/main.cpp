// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    vector<int> nums {};

    bool select {true};
    
    while (select) {
    // Select Screen
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "=========================================================" << endl;
    cout << "Please enter your choice: ";
    
    char choice {};
    cin >> choice;        
        
        switch (choice) {
            // Print numbers
            case 'P':
            case 'p':
            {
                // Empty list
                if (nums.size() == 0) {
                    cout << "\n[] - the list is empty\n" << endl;
                    break;
                } else {
                    cout << endl;
                
                    for (int i = 0; i < nums.size(); i++) {
                        cout << nums[i] << endl;
                    }
                    cout << endl;
                    break;
                }
            }
        
            // Add a number
            case 'A':
            case 'a':
            {
                int number {0};
                
                do {
                    if (cin.fail()) {
                        cout << "Invalid entry, please try again." << endl;
                    }
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "\nWhat number would you like to enter? ";
                    cin >> number;
                    cout << endl;
                } while (cin.fail());
                
                nums.push_back(number);
                
                break;
            }
        
            // Display the mean of the numbers
            case 'M':
            case 'm':
            {
                float sum {0};
                float mean {0.0};
                
                if (nums.size() != 0) {
                    for (int i = 0; i < nums.size(); i++) {
                        sum += nums.at(i);
                    }
                    
                    mean = sum / nums.size();
                    cout << "\nThe mean of the numbers is: " << fixed << setprecision(2) << mean << "\n" << endl;
                    break;
                    
                } else {
                    cout << "\nUnable to calculate mean - no data\n" << endl;
                    break;
                }
            }
            
            // Display the smallest number
            case 'S':
            case 's':
            {
                int smallestNumber {2147483647};
                
                if (nums.size() > 0) {
                    for (int i = 0; i < nums.size(); i++) {
                        if (smallestNumber > nums.at(i)) {
                            smallestNumber = nums.at(i);
                        }
                    }
                    cout << "\nThe smallest number is " << smallestNumber << "\n" << endl;
                    break;
                } else {
                    cout << "\nUnable to determine the smallest number - list is empty\n" << endl;
                    break;
                }
            }
        
            // Display the largest number
            case 'L':
            case 'l':
            {
                int largestNumber {-2147483647};
                
                if (nums.size() > 0) {
                    for (int i = 0; i < nums.size(); i++) {
                        if (largestNumber < nums.at(i)) {
                            largestNumber = nums.at(i);
                        }
                    }
                    cout << "\nThe largest number is " << largestNumber << "\n" << endl;
                    break;
                } else {
                    cout << "\nUnable to determine the largest number - list is empty\n" << endl;
                    break;
                }
            }
        
            // Quit
            case 'Q':
            case 'q':
            {
                cout << "\nGoodbye" << endl;
                
                return 0;
            }
        
            // Error or incorrect input
            default:
            {
                cout << "\nInvalid input\n" << endl;
            }
            
        }

    }
}

