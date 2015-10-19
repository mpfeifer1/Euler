#include <iostream>

using namespace std;

int main() {
    // Calculate total days, modify for weird cases, divide by 7
    const int YEARS = 100;
    const int DAYS_IN_YEAR = 365;

    int days = YEARS * DAYS_IN_YEAR; // 100 years, 365 days per year
    days += YEARS / 4; // All leap years
    days += 1; // Adds 1 leap century, skips leap 400-yr

    int sundays = days / 7;
    const double AVG_DAYS_MONTH = 30 + (5.0 / 12);

    cout << "There were " << int(sundays / AVG_DAYS_MONTH) << " Sundays" << endl;
}
