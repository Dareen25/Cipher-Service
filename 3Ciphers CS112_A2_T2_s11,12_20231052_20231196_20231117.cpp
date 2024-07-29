/* Author :-
			 Author 1: Dareen Elsayed Ragab  ===>> Solved Cipher 2 (Atbash Cipher)
			 Author 2: Nayera Shaaban Rashad  ===>> Solved Cipher 6 (Polybius Square Cipher)
			 Author 3: Anan Hamdi Ali  ===>> Solved Cipher 7 (Morse Code)
Section :- S11,12
Emails :-
			 1- dareenelsayed443@gmail.com
			 3- nayerashaaban54@gmail.com
			 2- ananhamdi2@gmail.com
IDs :-
		   1- 20231052  ===>> Solved Cipher 2 (Atbash Cipher)
		   3- 20231196  ===>> Solved Cipher 6 (Polybius Square Cipher)
		   2- 20231117  ===>> Solved Cipher 7 (Morse Code)*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype> // Include cctype for character operations
#include <algorithm> // Include algorithm for transformations
#include <limits> // Include limits for numeric_limits
#include <sstream> // Include sstream for string streams

using namespace std;

// Function prototypes

string cipher(string& text, int option) {
	transform(text.begin(), text.end(), text.begin(), ::toupper);
	string valid_input, res;
	for (char element : text) {
		if (isalpha(element)) {
			valid_input += element;
		}
	}
	if (option == 1) {
		for (char i : valid_input) {
			if (i <= 'M') {
				res += static_cast<char>('Z' - (i - 'A'));
			}
			else {
				res += static_cast<char>('A' + ('Z' - i));
			}
		}
		return res;
	}
	else {
		for (char element : valid_input) {
			if (element <= 'M') {
				res += static_cast<char>('A' + ('M' - element));
			}
			else {
				res += static_cast<char>('Z' - (element - 'N'));
			}
		}
		return res;
	}
}



string atbashCipher()
{

	// Function to cipher and decipher using the Atbash Cipher
	cout << "You chose the Atbash Cipher.\n";

	// Function to perform the Atbash Cipher operation

	string text;
	double choice, option; // Changed double to int
	cout << "* Welcome to Atbash Cipher *\n\n";
	cout << "What do you want?\n";
	cout << "1- Cipher\n2- Decipher\n";

	while (true) {
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2) {
			cout << "You must enter either 1 or 2!\n";
			cin.clear(); // Clear error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
		}
		else {
			break; // Break out of the loop if input is valid
		}
	}

	while (true) {
		cout << "if you want first option enter (1)\nif you want second option enter (2) \n";
		cout << "Enter your option: ";
		cin >> option;
		if (option != 1 && option != 2) {
			cout << "You must enter either 1 or 2!\n";
			cin.clear(); // Clear error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
		}
		else {
			break; // Break out of the loop if input is valid
		}
	}

	cin.ignore(); // Clear input buffer

	if (choice == 1) {
		cout << "Enter the text to cipher: ";
		getline(cin, text);
		cout << "The cipher text is --> " << cipher(text, option) << '\n';
		cout<<"Press enter to continue.";
	}
	else if (choice == 2) {
		cout << "Enter the text to decipher: ";
		getline(cin, text);
		cout << "The decipher text is --> " << cipher(text, option) << '\n';
				cout<<"Press enter to continue.";

	}


	return "";
}

// Function to perform Polybius Square encryption
string polybius_encrypt(string plaintext, string key) {
// Initialize the Polybius Square grid
    unordered_map<char, pair<int, int>> grid;
    int row = 1, col = 1;
    // Fill the grid with key characters
    for (char & c : key) {
        grid[c] = {row, col};
        col++;
        if (col > 5) {
            col = 1;
            row++;
        }
    }

    // Fill the remaining grid with the alphabet
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue; // I/J are encrypted to the same numbers
        if (grid.find(c) == grid.end()) {
            grid[c] = {row, col};
            col++;
            if (col > 5) {
                col = 1;
                row++;
            }
        }
    }

    // Encrypt the plaintext
    string ciphertext;
    for (char & c : plaintext) {
        if (!isalpha(c) && c != ' ') continue;
        c = toupper(c);
        if (c == 'J') c = 'I'; // Replace J with I
        ciphertext += to_string(grid[c].first) + to_string(grid[c].second) + " ";
    }

    return ciphertext;
}
// Function to decrypt ciphertext using Polybius Square cipher
string polybius_decrypt(string ciphertext, string key) {
// Initialize the Polybius Square grid
    unordered_map<char, pair<int, int>> grid;
    int row = 1, col = 1;
    // Fill the grid with key characters
    for (char & c : key) {
        grid[c] = {row, col};
        col++;
        if (col > 5) {
            col = 1;
            row++;
        }
    }

    // Fill the remaining grid with the alphabet
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue; // I/J are encrypted to the same numbers
        if (grid.find(c) == grid.end()) {
            grid[c] = {row, col};
            col++;
            if (col > 5) {
                col = 1;
                row++;
            }
        }
    }

    // Decrypt the ciphertext
    string plaintext;
    istringstream iss(ciphertext);
    string code;
    while (iss >> code) {
        if (code == " ") {
            plaintext += " ";
            continue;
        }
        int row = code[0] - '0';
        int col = code[1] - '0';
        // Find the corresponding character in the grid
        for (auto & entry : grid) {
            if (entry.second.first == row && entry.second.second == col) {
                plaintext += entry.first;
                break;
            }
        }
    }

    return plaintext;
}

string polybiusSquareCipher()
{
	// Function to encrypt plaintext using Polybius Square cipher
	cout << "You chose the Polybius Square Cipher.\n";
	string key = "52341";
    string plaintext, ciphertext, decrypted_text;
    char choice;
    bool operation_success = false;

        cout << "* Welcome to Polybius Square Cipher *\n" << endl;
    while (!operation_success) {
        cout << "Do you want to encrypt (E) or decrypt (D) the text? ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the input buffer

        if (toupper(choice) == 'E') {
            cout << "Enter the plaintext to encrypt: ";
            getline(cin, plaintext);
            // Check if the plaintext contains valid characters
            bool valid_input = true;
            for (char c : plaintext) {
                if (!isalpha(c) && c != ' ') {
                    valid_input = false;
                    break;
                }
            }
            if (!valid_input) {
                cout << "Invalid plaintext. Please enter only alphabetic characters." << endl;
            } else {
                // Encrypt the plaintext
                ciphertext = polybius_encrypt(plaintext, key);
                cout << "Cipher text: " << ciphertext << endl;
                		cout<<"Press enter to continue.";

                operation_success = true;
            }
        } else if (toupper(choice) == 'D') {
            cout << "Enter the ciphertext to decrypt: ";
            getline(cin, ciphertext);
            // Check if the ciphertext contains valid characters
            if (ciphertext.find_first_not_of("0123456789 ") != string::npos) {
                cout << "Invalid ciphertext. Please enter only numeric characters." << endl;
            } else {
                // Decrypt the ciphertext
                decrypted_text = polybius_decrypt(ciphertext, key);
                cout << "Decrypted text: " << decrypted_text << endl;
                cout<<"Press enter to continue.";

                operation_success = true;
            }
        } else {
            cout << "Invalid choice. Please enter 'E' to encrypt or 'D' to decrypt." << endl;
        }
    }

	return "";
}
string morseCodeCipher()
{
	// Function to perform Morse Code Cipher
	cout << "You chose the Morse Code Cipher.\n";

	// Function to encrypt plaintext to Morse Code
	unordered_map<char, string> morseCode = {
			{'A', ".- "}, {'B', "-... "}, {'C', "-.-. "}, {'D', "-.. "}, {'E', ". "},
			{'F', "..-. "}, {'G', "--. "}, {'H', ".... "}, {'I', ".. "}, {'J', ".--- "},
			{'K', "-.- "}, {'L', ".-.. "}, {'M', "-- "}, {'N', "-. "}, {'O', "--- "},
			{'P', ".--. "}, {'Q', "--.- "}, {'R', ".-. "}, {'S', "... "}, {'T', "- "},
			{'U', "..- "}, {'V', "...- "}, {'W', ".-- "}, {'X', "-..- "}, {'Y', "-.-- "},
			{'Z', "--.. "}, {'1', ".---- "}, {'2', "..--- "}, {'3', "...-- "}, {'4', "....- "},
			{'5', "..... "}, {'6', "-.... "}, {'7', "--... "}, {'8', "---.. "}, {'9', "----. "},
			{'0', "----- "}, {',', "--..-- "}, {'.', ".-.-.- "}, {'?', "..--.. "},
			{'/', "-..-. "}, {'-', "-....- "}, {'(', "-.--. "}, {')', "-.--.- "}, {' ', "  "}
	};

	cout << "Welcome to our cipher service 🙂\n";

        string choice,input,result;
		cout << "Do you want to cipher/decipher?\n";
		cin>>choice;
        cin.ignore();
		if (choice == "cipher") {
			cout << "Enter the text: ";
			getline(cin, input);
			
			for (char c : input) {
				c = toupper(c);
				if (morseCode.find(c) != morseCode.end()) {
					result += morseCode[c];
				}
				else {
					result += "? ";
				}
			}
			cout << "Morse code: " << result << endl;
			cout<<"Press enter to continue.";
		}
		else if (choice == "decipher") {
			unordered_map<string, string> morse_decode = {
					{".-", "A"}, {"-...", "B"}, {"-.-.", "C"}, {"-..", "D"}, {". ", "E"},
					{"..-.", "F"}, {"--.", "G"}, {"....", "H"}, {"..", "I"}, {".---", "J"},
					{"-.-", "K"}, {".-..", "L"}, {"--", "M"}, {"-.", "N"}, {"---", "O"},
					{".--.", "P"}, {"--.-", "Q"}, {".-.", "R"}, {"...", "S"}, {"- ", "T"},
					{"..-", "U"}, {"...-", "V"}, {".--", "W"}, {"-..-", "X"}, {"-.--", "Y"},
					{"--..", "Z"}, {".----", "1"}, {"..---", "2"}, {"...--", "3"}, {"....-", "4"},
					{".....", "5"}, {"-....", "6"}, {"--...", "7"}, {"---..", "8"}, {"----.", "9"},
					{"-----", "0"}, {"--..--", ","}, {".-.-.-", "."}, {"..--..", "?"}, {"-..-.", "/"},
					{"-....-", "-"}, {"-.--.", "("}, {"-.--.-", ")"}, {" ", " "}
			};

		
				string input;
				cout << "Enter the Morse code: ";
				getline(cin, input);
				string result;
				string symbol;
				for (auto& letter : input) {
					if (letter == ' ') {
						if (!symbol.empty()) {
							result += morse_decode[symbol];
							symbol.clear();
						}
						result += ' ';
					}
					else {
						symbol += letter;
					}
				}
				if (!symbol.empty()) {
					result += morse_decode[symbol];
				}
				cout << "Deciphered text: " << result << endl;
						cout<<"Press enter to continue.";
			
		}
		else {
			cout << "Invalid choice. Please enter 'cipher' to cipher or 'decipher' to decipher." << endl;
		}
	
	return "";
}

int main() {
	cout << "*** Welcome to the Cipher Service ***\n";

	while (true)
	{
		cout << "1. Atbash Cipher\n2. Polybius Square Cipher\n3. Morse Code Cipher\n4-Exit\n";

		cout << "Enter your choice (1, 2, 3 or 4): ";

		
		double choice;
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter an integer number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
		if (choice == 1)
			atbashCipher();
		else if (choice == 2)
			polybiusSquareCipher();
		else if (choice == 3)
			morseCodeCipher();
		else if (choice == 4)
			break;

		else
			cout << "Invalid choice. Please select a valid option (1, 2, 3, or 4)\n";
		    cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			
			
	}

	return 0;


}






