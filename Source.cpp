#include"Question.h"
#include<iostream>
using namespace std;
#include"Header.h"


// ========================= Question 1 =========================
//int main() {
//    Tapcode tapCode;
//
//    int choice;
//    cout << "Tap Code Communication System"<<endl;
//    cout << "1. Convert Message to Tap Code"<<endl;
//    cout << "2. Convert Tap Code to Message"<<endl;
//    cout << "Enter your choice (1 or 2): ";
//    do {
//        cout << "Enter your choice (1 or 2): ";
//        cin >> choice;
//        cin.ignore(); 
//
//        if (choice == 1 || choice == 2)
//            break; 
//
//        cout << "Invalid choice! Please select 1 or 2."<<endl;
//    } while (true);
//	if (choice == 1) {// converting to tap code
//        char message[500];
//        cout << "Enter the message to convert to Tap Code : ";
//        cin.getline(message, 500);
//
//        char* convertedMessage = tapCode.converttotapcode(message);
//        cout << "Converted Tap Code: " << convertedMessage << endl;
//
//        delete[] convertedMessage; // free allocated memory
//    }
//	else if (choice == 2) { // converting to string
//        char tapInput[500];
//        cout << "Enter the Tap Code (use 0 for space, no commas): ";
//        cin.getline(tapInput, 500);
//
//        char* decodedMessage = tapCode.convertostring(tapInput);
//        cout << "Decoded Message: " << decodedMessage << endl;
//
//        delete[] decodedMessage; // free allocated memory
//    }
// 
//
//    return 0;
//}
// ========================= Question 2 =========================
//int countmaxchoco(int money , int price , int wrappers) {
//	int totalchocolates = money / price; 
//	int currentwrappers = totalchocolates; // initial wrappers from bought chocolates
//	while (currentwrappers >= wrappers) { 
//		int exchangedchocolates = currentwrappers / wrappers;
//		totalchocolates += exchangedchocolates;
//		currentwrappers = (currentwrappers % wrappers) + exchangedchocolates; // left wrappers + new wrappers
//	}
//	return totalchocolates;
//
//}
//int main() {
//	int money; // money to buy chocolates
//	int price; // price of each chocolate
//	int wrappers; //wrappers needed to exchange for a chocolate
//	cout << "enter the amount of money you have: ";
//	cin >> money;
//	cout << "enter the price of each chocolate: ";
//	cin >> price;
//	cout << "enter the number of wrappers needed to exchange for a chocolate: ";
//	cin >> wrappers;
//	
//	int maxchocolates = countmaxchoco(money, price, wrappers);
//	cout << "maximum chocolates you can get: " << maxchocolates << endl;
//	return 0;
//
//}
// ========================= Question 3 =========================
//int main() {
//    Array a(5);
//    for (int i = 0; i < a.length(); i++)
//        a.setAt(i, i + 1);
//    
//    
//    cout << "Original array: ";
//    a.display();
//
//    a.push_back(10);
//    cout << "After push_back: ";
//    a.display();
//
//    a.pop_back();
//    cout << "After pop_back: ";
//    a.display();
//
//    Array sub = a.subArr(2);
//    cout << "Subarray from index 2: ";
//    sub.display();
//
//    Array found = a.find(3);
//    cout << "Indices where value 3 found: ";
//    found.display();
//
//    return 0;
//}
// =========================================================
int main() {
    Question quiz[10] = {
       Question("when was c++ created?", "1979", "1983", "1985", "1990", 2),
       Question("who is the father of c++?", "bjarne stroustrup", "james gosling", "dennis ritchie", "guido van rossum", 1),
       Question("which company developed c++?", "microsoft", "bell labs", "ibm", "sun microsystems", 2),
       Question("what is the extension of a c++ file?", ".cpp", ".cxx", ".cc", ".c++", 1),
       Question("which of the following is not a c++ data type?", "int", "float", "string", "real", 4),
       Question("which operator accesses the value at the address stored in a pointer?", "&", "*", "%", "#", 2),
       Question("which is used to define a block of code in c++?", "{}", "()", "[]", "<>", 1),
       Question("which keyword is used to create a class in c++?", "class", "struct", "object", "module", 1),
       Question("which of the following is not a loop structure in c++?", "for", "while", "do-while", "foreach", 4),
       Question("which of the following handles exceptions in c++?", "try-catch", "if-else", "switch-case", "for-loop", 1)
    };
	int player1score = 0;
	int player2score = 0;
    int answer;

    cout << "===== c++ trivia quiz =====" << endl << endl;
    cout << "player 1's turn:\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nq" << i + 1 << ": " << quiz[i].getQuestion() << endl;
        for (int j = 0; j < 4; j++) {
            cout << j + 1 << ". " << quiz[i].getOption(j) << endl;
        }
        cout << "your answer (1-4): ";
        cin >> answer;
        if (answer == quiz[i].getCorrectAnswer()) player1score++;
    }

    // player 2
    cout << "\nplayer 2's turn:\n";
    for (int i = 5; i < 10; i++) {
        cout << "\nq" << i + 1 << ": " << quiz[i].getQuestion() << endl;
        for (int j = 0; j < 4; j++) {
            cout << j + 1 << ". " << quiz[i].getOption(j) << endl;
        }
        cout << "your answer (1-4): ";
        cin >> answer;
        if (answer == quiz[i].getCorrectAnswer()) player2score++;
    }
    cout << "\n===== final scores =====\n";
    cout << "player 1: " << player1score << endl;
    cout << "player 2: " << player2score << endl;

    if (player1score > player2score)
        cout << "player 1 wins!\n";
    else if (player2score > player1score)
        cout << "player 2 wins!\n";
    else
        cout << "it's a tie!\n";



	return 0;
}
//================ Question 4 ================================
//class Rational {
//	int numerator;
//	int denominator;
//public:
//	Rational() { // deafult 
//		numerator = 0;
//		denominator = 1;
//	}
//	Rational(int numerator = 0, int denominator = 1) {
//		if (denominator == 0) {
//			cout << "Error: Denominator cannot be zero! Setting to 0/1" << endl;;
//			this->numerator = 0;
//			this->denominator = 1;
//			return;
//		}
//		this->numerator = numerator;
//		this->denominator = denominator;
//		reducedForm();
//	}
//	void reducedForm() {
//		// get the highest common factor
//		int x = numerator;
//		if (x < 0) x = -x;
//		int y = denominator;
//		if (y < 0) y = -y;
//
//		int max;
//		if (x < y)
//			max = x;
//		else
//			max = y;
//
//		int HCF = 1;
//		for (int i = 1; i <= max; i++) {   
//			if (numerator % i == 0 && denominator % i == 0) {
//				HCF = i;
//			}
//		}
//
//		// divide by HCF
//		numerator = numerator / HCF;
//		denominator = denominator / HCF;
//
//		
//		if (denominator < 0) {
//			numerator = -numerator;
//			denominator = -denominator;
//		}
//	}
//	Rational operator+(const Rational& r) {
//		Rational temp(numerator * r.denominator + denominator * r.numerator,
//			denominator * r.denominator);
//		return temp;
//	}
//
//	// Operator -
//	Rational operator-(const Rational& r) {
//		Rational temp(numerator * r.denominator - denominator * r.numerator,
//			denominator * r.denominator);
//		return temp;
//	}
//
//	// Operator *
//	Rational operator*(const Rational& r) {
//		Rational temp(numerator * r.numerator,
//			denominator * r.denominator);
//		return temp;
//	}
//
//	// Operator /
//	Rational operator/(const Rational& r) {
//		if (r.numerator == 0) {
//			cout << "Error: division by zero fraction" << endl;
//			return Rational(0, 1);
//		}
//		Rational temp(numerator * r.denominator,
//			denominator * r.numerator);
//		return temp;
//	}
//	void printFraction() {
//		cout << numerator << "/" << denominator;
//	}
//
//	void printFloat() {
//		cout << (float)numerator / denominator;
//	}
//};
//int main() {
//	Rational r1(1, 0);
//	Rational r2(1, 1);
//
//	cout << "r1 = "; r1.printFraction();
//	cout << endl;
//	cout << "r2 = "; r2.printFraction(); 
//	cout << endl;
//
//	Rational sum = r1 + r2;
//	cout << "Sum = "; 
//	sum.printFraction(); 
//	cout << " = "; sum.printFloat(); 
//	cout << endl;
//
//	Rational diff = r1 - r2;
//	cout << "Difference = ";
//	diff.printFraction();
//	cout << " = "; 
//	diff.printFloat(); 
//	cout << endl;
//
//	Rational Mul = r1 * r2;
//	cout << "Product = ";
//	Mul.printFraction();
//	cout << " = ";
//	Mul.printFloat();
//	cout << endl;
//
//	Rational divAns = r1 / r2;
//	cout << "Quotient = ";
//	divAns.printFraction();
//	cout << " = ";
//	divAns.printFloat();
//	cout << endl;
//
//	return 0;
//}