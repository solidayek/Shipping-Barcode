#include <iostream>
using namespace std;

void getZipcode(int zipcode);
void barcodeConversion(int digit);

int main() {
  cout << "Scan Zipcode into a Barcode \nLong Beach City College\nAuthor: "
         "Soliday Ek\nNovember 19, 2022"
      << endl;
  cout << "===============================================" << endl;
  
	int zipcode;
	cout << "Enter your zipcode: ";
	cin >> zipcode;

  //Check if the user's zipcode exceeds or is less five digits. Then, give them a warning.
  std::string convertIntToString = std::to_string(zipcode);
  if (convertIntToString.length() == 5){
    getZipcode(zipcode);
  } else {
    cout << "Zipcode can't be less or more than five digits." << endl;
  }
	return 0;
}

void barcodeConversion(int digit) {
	if (digit == 1)
		cout << ":::||";
	else if (digit == 2)
		cout << "::|:|";
	else if (digit == 3)
		cout << "::||:";
	else if (digit == 4)
		cout << ":|::|";
	else if (digit == 5)
		cout << ":|:|:";
	else if (digit == 6)
		cout << ":||::";
	else if (digit == 7)
		cout << "|:::|";
	else if (digit == 8)
		cout << "|::|:";
	else if (digit == 9)
		cout << "|:|::";
	else if (digit == 0)
		cout << "||:::";
}

void getZipcode(int zipcode) {
 	int digit1, digit2, digit3, digit4, digit5;
	int digitSum, correctDigit;
  
	digit1 = (zipcode % 100000) / 10000;
	cout << "Digit 1: " << digit1 << endl;  
	digit2 = (zipcode % 10000) / 1000;
	cout << "Digit 2: " << digit2 << endl;
	digit3 = (zipcode % 1000) / 100;
	cout << "Digit 3: " << digit3 << endl;
	digit4 = (zipcode % 100) / 10;
	cout << "Digit 4: " << digit4 << endl;
	digit5 = zipcode % 10;
	cout << "Digit 5: " << digit5 << "\n" << endl;
  
	digitSum = digit1 + digit2 + digit3 + digit4 + digit5;
  
  // the maximum of the sum of five digits is 45 if the zipcode is 99999.
  //So we can conclude that the maximum range of the sum is 50.
  if (digitSum > 0 && digitSum <= 10){
      correctDigit = 10 - digitSum;
  } else if (digitSum <= 20){
      correctDigit = 20 - digitSum;
  } else if (digitSum <= 30){
      correctDigit = 30 - digitSum;
  } else if (digitSum <= 40){
      correctDigit = 40 - digitSum;
  } else if (digitSum <= 50) {
      correctDigit = 50 - digitSum;
  };

  //Barcode Output
  cout << "The Barcode of the zipcode: " << endl;
  cout << "|";
  barcodeConversion(digit1);
  barcodeConversion(digit2);
  barcodeConversion(digit3);
  barcodeConversion(digit4);
  barcodeConversion(digit5);
  barcodeConversion(correctDigit);
  cout << "|" << endl;
}