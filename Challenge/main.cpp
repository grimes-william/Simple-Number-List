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

