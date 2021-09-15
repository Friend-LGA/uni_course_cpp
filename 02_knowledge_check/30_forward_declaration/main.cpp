// https://en.cppreference.com/w/cpp/language/class
// https://en.wikipedia.org/wiki/Forward_declaration

// Otherwise ERROR: unknown type name 'Month'
enum class Month;
enum class Day;

struct Date {
  Month month;
  Day day;
};

enum class Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
enum class Day { Mon, Tue, Wed, Thu, Fri, Sat, Sun };

int main() {
  const Date date = {Month::Jan, Day::Mon};
  return 0;
}
