#include "time.h"

void Time::set_time(string new_time) {
	time_data = new_time;
}

string Time::get_time() {
	return time_data;
}

string Time::number_to_word(string number) {
	string word;

	if (number == "1") {
		word = "one";
	} else if (number == "2") {
		word = "two";
	} else if (number == "3") {
		word = "three";
	} else if (number == "4") {
		word = "four";
	} else if (number == "5") {
		word = "five";
	} else if (number == "6") {
		word = "six";
	} else if (number == "7") {
		word = "seven";
	} else if (number == "8") {
		word = "eight";
	} else if (number == "9") {
		word = "nine";
	} else if (number == "10") {
		word = "ten";
	} else if (number == "11") {
		word = "eleven";
	} else if (number == "12") {
		word = "twelve";
	} else if (number == "13") {
		word = "thirteen";
	} else if (number == "14") {
		word = "fourteen";
	} else if (number == "15") {
		word = "fifteen";
	} else if (number == "16") {
		word = "sixteen";
	} else if (number == "17") {
		word = "seventeen";
	} else if (number == "18") {
		word = "eighteen";
	} else if (number == "19") {
		word = "nineteen";
	}

	return word;
}

string Time::tens_to_word(string tens) {
	string word;

	if (tens == "2") {
		word = "twenty";
	} else if (tens == "3") {
		word = "thirty";
	} else if (tens == "4") {
		word = "forty";
	} else if (tens == "5") {
		word = "fifty";
	}

	return word;
}

void Time::format_first_two_characters() {

	length_to_colon = time_data.find_first_of(":");
	//cout << "Time::length_to_colon = " << length_to_colon << endl;

	string hours = time_data.substr(0, length_to_colon);

	if (hours.size() > 1) {
		if (hours[0] == *"0") {
			hours.erase(0, 1);
		}
	}

	if (hours == "0") {
		formatted_time += "twelve ";
		return;
	}

	int i_hour = atoi(hours.c_str());

	if (i_hour > 12) {
		i_hour -= 12;
		hours = to_string(i_hour);
		morning = false;
	} else {
		morning = true;
	}

	formatted_time += number_to_word(hours) + " ";

}

void Time::format_last_two_characters() {
	string minutes = time_data.substr(length_to_colon + 1, time_data.size());

	if (minutes == "00") {
		return;
	}

	int i_minutes = atoi(minutes.c_str());

	if (i_minutes >= 20) {

		string tens = minutes.substr(0, 1);
		formatted_time += tens_to_word(tens);

		string ones = minutes.substr(1, 1);
		if (!(ones == "0")) {
			formatted_time += " ";
		}
		formatted_time += number_to_word(ones);

	} else {
		if (minutes.size() == 1) {
			formatted_time += "oh ";
		}
		if (minutes[0] == *"0") {
			formatted_time += "oh ";
			minutes.erase(0, 1);
		}
	}
	formatted_time += number_to_word(minutes) + " ";
}

void Time::add_am_pm() {
	if (morning) {
		formatted_time += "am";
	} else {
		formatted_time += "pm";
	}
}

string Time::get_formatted_time() {

	format_first_two_characters();
	format_last_two_characters();
	add_am_pm();

	return formatted_time;
}