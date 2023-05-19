#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int sales[12][31];
    int num_months = 3;
    int num_days = 5;

    for (int i = 0; i < num_months; i++) {
        for (int j = 0; j < num_days; j++) {
            cout << "Enter the sales for day " << j + 1 << " of month " << i + 1 << ": ";
            cin >> sales[i][j];
        }
    }

    double pledged_daily_donation = 0;
    double pledged_monthly_donation = 0;

    for (int i = 0; i < num_months; i++) {
        double five_day_sales = 0;
        for (int j = 0; j < num_days; j++) {
            int day_sales = sales[i][j];
            five_day_sales += day_sales;

            if (day_sales > 1500)
                pledged_daily_donation += day_sales * 0.05;
        }

        if (five_day_sales > 12000)
            pledged_monthly_donation += five_day_sales * 0.05;
    }

    cout.setf(ios::fixed);
    cout << setprecision(2);

    cout << "Total pledged daily donations: $" << pledged_daily_donation << endl;
    cout << "Total pledged monthly donations: $" << pledged_monthly_donation << endl << endl;

    cout << "Total pledged donations: $" << pledged_daily_donation + pledged_monthly_donation << endl;
    cin.ignore();
}