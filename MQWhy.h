#pragma once

#include <vector>

inline std::vector<char> getCharacterTable() {
	std::vector<char> charTable;

	// Add lowercase letters a-z
	for (char c = 'a'; c <= 'z'; ++c) {
		charTable.push_back(c);
	}

	// Add uppercase letters A-Z
	for (char c = 'A'; c <= 'Z'; ++c) {
		charTable.push_back(c);
	}

	return charTable;
}

inline std::vector<char> getDigitTable() {
	std::vector<char> digitTable;

	for (char c = '0'; c <= '9'; ++c) {
		digitTable.push_back(c);
	}

	return digitTable;
}

inline std::vector<char> getPunctuationTable() {
	std::vector<char> punctuationTable = { '!', '?', ',', '.', '[', ']', ' ', ':' };
	return punctuationTable;
}

inline std::vector<char> splitNumberIntoDigits(int number) {
	std::vector<char> digits;

	std::string numberStr = std::to_string(number);

	for (char digit : numberStr) {
		digits.push_back(digit);
	}

	return digits;
}

inline int add(int a, int b) {
	while (b != 0) {
		int carry = (a & b) << 1;
		a = a ^ b;
		b = carry;
	}
	return a;
}

inline int subtract(int a, int b) {
	b = ~b;
	int carry = 1;
	
	while (carry != 0) {
		int temp = b ^ carry;
		carry = (b & carry) << 1;
		b = temp;
	}

	while (b != 0) {
		int temp = a ^ b;
		int carry = (a & b) << 1;
		a = temp;
		b = carry;
	}

	return a;
}

inline int multiply(int a, int b) {
	int result = 0;

	while (b != 0) {
		if (b & 1) {
			int carry = 0;
			int temp = result;
			while (a != 0 || carry != 0) {
				int sum = (temp ^ a) ^ carry;
				carry = ((temp & a) | (temp & carry) | (a & carry)) << 1;
				temp = sum;
				a = 0;
			}
			result = temp;
		}
		a <<= 1;
		b >>= 1;
	}
	return result;
}
