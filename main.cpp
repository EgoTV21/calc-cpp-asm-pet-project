#include "help.hpp"
#include <iostream>
#include <windows.h>

extern "C" int func(int a, int b, int s);
extern "C" float func_f(float a, float b, int s);
extern "C" float func_two_f(float a, int s);
extern "C" int func_two(int a);

int main() {

	SetConsoleOutputCP(CP_UTF8);

	int a;
	int b;
	char s;
	int c;

	float a_f;
	float b_f;
	float c_f;

	std::string a_s;

	while (true) {

		std::cout << line << std::flush;

		std::cin >> a_s;

		if (a_s == "h" || a_s == "H" || a_s == "help" || a_s == "Help") {
			std::cout << "a + b - сложение" << std::endl;
			std::cout << "a - b - вычетание" << std::endl;
			std::cout << "a * b - умножение" << std::endl;
			std::cout << "a / b - деление" << std::endl;
			std::cout << "a ^ b - возвести a в степень b" << std::endl;
			std::cout << "a | - модуль" << std::endl;
			std::cout << "a c - квадратный корень" << std::endl;
			std::cout << "a k - кубический корень" << std::endl;
			std::cout << "help - помощь" << std::endl;
			std::cout << "clear - очистка" << std::endl;
			std::cout << "quit/exit - выход" << std::endl;

			continue;
		} else if (a_s == "c" || a_s == "C" || a_s == "clear" || a_s == "Clear") {
			system("cls");

			continue;
		} else if (a_s == "q" || a_s == "Q" || a_s == "quit" || a_s == "Quit" || a_s == "e" || a_s == "E" || a_s == "exit" || a_s == "Exit") {
			break;
		} else {
			try {
				a = std::stoi(a_s);

			}
			catch (const std::invalid_argument&) {
				if (error == true) {
					std::cout << "const std::invalid_argument&" << std::endl;

				} else {
					std::cout << "Error 1\nКоманда не найдена" << std::endl;
				}
				continue;
			} catch (const std::out_of_range&) {
				if (error == true) {
					std::cout << "const std::out_of_range&" << std::endl;

				} else {
					std::cout << "Error 2\nСлишком большое число" << std::endl;
				}
				continue;
			}
		}

		std::cin >> s;

		if (s == '|') {
			c = func_two(a);

			std::cout << s << a << s << " = " << c << std::endl;

			continue;
		} else if (s == 'c') {
			a_f = (float)a;
			c_f = func_two_f(a_f, 101);

			std::cout << s << " " << a << " = " << c_f << std::endl;

			continue;
		} else if (s == 'k') {
			a_f = (float)a;
			c_f = func_two_f(a_f, 102);

			std::cout << s << " " << a << " = " << c_f << std::endl;

			continue;
		} else if (s == '+' || s == '-' || s == '*' || s == '/' || s == '^') {
			if (std::cin >> b) {
				if (s == '+') {
					c = func(a, b, 1);
				} else if (s == '-') {
					c = func(a, b, 2);
				} else if (s == '*') {
					c = func(a, b, 3);
				} else if (s == '/') {
					a_f = (float)a;
					b_f = (float)b;
					c_f = func_f(a_f, b_f, 4);

					std::cout << a << " " << s << " " << b << " = " << c_f << std::endl;

					continue;
				}
				else if (s == '^') {
					c = func(a, b, 5);
				}

				std::cout << a << " " << s << " " << b << " = " << c << std::endl;

			} else {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				if (error == true) {
					std::cout << "std::cin.fail" << std::endl;
				} else {
					std::cout << "Error 4\nЭто не число" << std::endl;
				}

				continue;
			}
		} else {
			if (error == true) {
				std::cout << "Infinite error" << std::endl;
			} else {
				std::cout << "Error 3\nКоманда не найдена" << std::endl;
			}
			continue;
		}
	}
} 
