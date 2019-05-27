#include <iostream>
#include "time.h"
using namespace std;

string get_formatted_time(string numerical_time) {

	Time time;
	time.set_time(numerical_time);

	//string formatted_time;

	//formatted_time += get_first_word(numerical_time);

	//return formatted_time;

	return time.get_formatted_time();
}

void clear_screen() {
	for (int i = 0; i < 25; ++i) {
		cout << "\n";
	}
}

int main() {

	string user_input;
	string formatted_time;

	while (true) {

		user_input = "";
		cout << ">>";
		cin >> user_input;
		clear_screen();
		formatted_time = get_formatted_time(user_input);

		cout << "It's " << formatted_time << "\n\n";
	}
}