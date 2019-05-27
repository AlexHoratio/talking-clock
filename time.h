// HEADER GUARD
#include <iostream>
using namespace std;

class Time {

  private:
	string time_data = "00:00";
	string formatted_time;
	size_t length_to_colon;
	bool morning;

  public:
	void set_time(string);
	string get_time();
	string number_to_word(string);
	string tens_to_word(string);
	string get_formatted_time();
	void format_first_two_characters();
	void format_last_two_characters();
	void add_am_pm();
};