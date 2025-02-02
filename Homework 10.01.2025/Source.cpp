/*
	================
	РОБОТА з РЯДКАМИ
	================

Навчальний матеріал можете знайти за посиланням
	https://materials.itstep.org/content/f1811e94-507b-44c2-bfbe-ac7ac02a7178/uk

Результат роботи: посилання на GitHub
*/

#include <iostream> 
#include <windows.h>
#include <locale.h>
#include <string>
#include <utility>
#include <tuple>
#include <sstream>
#include <regex>
#include <type_traits>
#include <algorithm>

using namespace std; 

#pragma region Prototypes_of_Functions

inline void exercise(int exerciseNumber);

void replaceSpacesWithTabs(string& str);

tuple<int, int, int, int> countElements(string& str);

bool isWord(string& word);

int numberOfWords(string& str);

bool isPolindrom(string& str);

void replaceDotsWithExclamationMarks(string& str);

int countNumberOfCurrentLetterInString(char& symbolToFind, string& str);

#pragma endregion


int main() {

	system("chcp 1251>null");
	setlocale(LC_ALL, "uk_UA.UTF-8");
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

#pragma region Exercise 1

	/*
	№1
	Дано рядок символів. Замінити в ньому всі пробіли на табуляції.
	*/

	exercise(1);

	string userStr;
	cout << "\033[035mInput your string: \033[0m";
	getline(cin, userStr);

	cout << endl;

	cout << "\033[033mYou string before: \033[0m" << userStr;
	replaceSpacesWithTabs(userStr);

	cout << endl;

	cout << "\033[033mYou string with tabs: \033[0m" << userStr;

	cout << endl;


#pragma endregion



#pragma region Exercise 2

	/*
	№2
	Дано рядок символів. Визначити кількість літер, цифр та інших символів, присутніх у рядку.
	*/

	exercise(2);

	string userStr2;
	cout << "\033[035mInput your string: \033[0m";
	getline(cin, userStr2);
	int letters, numbers, others, spaces;
	tie(letters, numbers, others, spaces) = countElements(userStr2);
	
	cout << endl;
	cout << "\033[032mNumber of letters: \033[0m" << letters << endl 
		 << "\033[032mNumber of numbers: \033[0m" << numbers << endl 
		 << "\033[032mNumber of spaces: \033[0m" << spaces << endl
		 << "\033[032mNumber of other elements: \033[0m" << others << endl;

#pragma endregion



#pragma region Exercise 3

	/*
	№3
	Підрахувати кількість слів у введеному реченні.
	*/

	exercise(3);

	string userStr3;
	cout << "\033[035mInput your sentence: \033[0m";
	getline(cin, userStr3);

	int countWords = numberOfWords(userStr3);

	cout << "Number of words in sentence: " << countWords;

#pragma endregion



#pragma region Exercise 4

	/*
	№4
	Дано рядок символів. Необхідно перевірити чи є цей рядок паліндромом.
	*/

	exercise(4);

	string userStr4;
	cout << "\033[035mInput your sentence: \033[0m";
	getline(cin, userStr4);

	bool polindrom = isPolindrom(userStr4);

	cout << endl << "Результат: ";
	if (polindrom) cout << "\033[032mполіндром.\033[0m";
	else cout << "\033[031mНЕ поліндром.\033[0m";

#pragma endregion



#pragma region Exercise 5
	/*
	№5
	Написати програму, яка замінює всі символи крапки "." у рядку, введеному користувачем, на символи знака оклику "!".
	*/

	exercise(5);

	string userStr5;
	cout << "\033[035mInput your string: \033[0m";
	getline(cin, userStr5);

	cout << endl;

	cout << "\033[033mYou string before: \033[0m" << userStr5;
	replaceDotsWithExclamationMarks(userStr5);

	cout << endl;

	cout << "\033[033mYou string with exclamation marks: \033[0m" << userStr5;

	cout << endl;


#pragma endregion



#pragma region Exercise 6

	/*
	№6
	Користувач вводить рядок символів і шуканий символ. Порахувати скільки разів він зустрічається в рядку.
	*/

	exercise(6);

	string userStr6;
	cout << "\033[035mInput your string: \033[0m";
	getline(cin, userStr6);

	char symbolToFind;
	cout << endl << "\033[033mInput symbol: \033[0m";
	cin >> symbolToFind;
	cin.ignore();
	
	cout << endl;

	int numberOfSymbolInString = countNumberOfCurrentLetterInString(symbolToFind, userStr6);

	cout << "Element \033[036m" << symbolToFind << "\033[0m occurs \033[036m" << numberOfSymbolInString << "\033[0m times in your string.";
	cout << endl;

#pragma endregion


    return 0;  
}

#pragma region Functions

inline void exercise(int exerciseNumber)
{
	cout << endl << endl << "\t\t\t\t\033[032m Завдання  " << exerciseNumber << "\033[0m" << endl;
}

void replaceSpacesWithTabs(string& str)
{
	for (char& symbol : str)
	{
		if (symbol == ' ')
		{
			symbol = '\t';
		}
	}
}

tuple<int, int, int, int> countElements(string& str)
{

	int numberOfLetters = 0;
	int numbeOfNumbers = 0;
	int numbeOfOtherElements = 0;
	int numberOfSpaces = 0;

	for (char& symbol : str)
	{
		if (isalpha(symbol)) numberOfLetters++;
		else if (isdigit(symbol)) numbeOfNumbers++;
		else if (symbol == ' ') numberOfSpaces++;
		else numbeOfOtherElements++;
	}

	return make_tuple(numberOfLetters, numbeOfNumbers, numbeOfOtherElements, numberOfSpaces);
}

bool isWord(string& word)
{
	if (word.length() == 1)
	{
		return isalpha(word[0]);
	}

	for (size_t i = 0; i < word.length(); i++)
	{
		if (i == 0 || i == word.length() - 1)
		{
			if (!isalpha(word[i]) && word[i] != '\'' && word[i] != '-')
			{
				return false;
			}
		}
		else
		{
			if (!isalpha(word[i]) && word[i] != '\'' && word[i] != '-')
			{
				return false;
			}
		}
	}

	return true;
}

int numberOfWords(string& str)
{
	int numberOfWords = 0;
	regex punctuation("[^a-zA-ZА-Яа-яЄєІіЇїҐґ0-9'’-]+");

	str = regex_replace(str, punctuation, " ");

	/*cout << endl << str << endl;*/

	stringstream sin(str);
	string currentWord;

	while ( sin >> currentWord)
	{
		if (isWord(currentWord)) numberOfWords++;
	}
	
	return numberOfWords;
}

bool isPolindrom(string& str)
{
	bool ispolindrom = true;

	for (size_t i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - 1 - i]) ispolindrom = false;
	}

	return ispolindrom;

}

void replaceDotsWithExclamationMarks(string& str)
{
	for (char& symbol : str)
	{
		if (symbol == '.')
		{
			symbol = '!';
		}
	}
}

int countNumberOfCurrentLetterInString(char& symbolToFind, string& str)
{
	int numberOfLetter = count(str.begin(), str.end(), symbolToFind);

	return numberOfLetter;
}

#pragma endregion