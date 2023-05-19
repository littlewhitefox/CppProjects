#include <iostream>
#include <iomanip>

using namespace std;

// 5(a) begin
struct mobilePlan {
    int code;
    double subscription;
    double incoming;
    double SMS;
    int data;
};

mobilePlan mobileTable[5];
// 5(a) end

// 5(c) begin
double computeBill(int code, double incoming, double SMS, int data) {
    double totalBill = 0.0;
    int index = code--;

    if (index > 1)
        return -1.0;

    double planSubscription = mobileTable[index].subscription;
    double planIncoming = mobileTable[index].incoming;
    double planSMS = mobileTable[index].SMS;
    int planData = mobileTable[index].data;

    if (incoming > planIncoming)
        totalBill += (incoming - planIncoming) * 0.05;

    if (SMS > planSMS)
        totalBill += (SMS - planSMS) * 0.03;

    if (data > 10)
        totalBill += ((((float)data - (float)planData) * 1000) / 100) * 0.5;

    totalBill += planSubscription;

    return totalBill;
}
// 5(c) end

int main() {
// 5(b) begin
//	mobileTable[4].code = 3;
//	mobileTable[4].subscription = 59.9;
//	mobileTable[4].data = 30;
// 5(b) end

// 5(d) begin
    mobileTable[0].code = 1;
    mobileTable[0].subscription = 39.9;
    mobileTable[0].incoming = 100;
    mobileTable[0].SMS = 500;
    mobileTable[0].data = 10;

    mobileTable[1].code = 2;
    mobileTable[1].subscription = 49.9;
    mobileTable[1].incoming = 500;
    mobileTable[1].SMS = 1500;
    mobileTable[1].data = 20;

    cout.setf(ios::fixed);
    cout << setprecision(2);
    double totalBill;

    // Test Case 1
    cout << "Test Case 1:" << endl;
    totalBill = computeBill(1, 100, 500, 10);

    if (totalBill == -1.0)
        cout << "No such mobile plan..." << endl << endl;
    else
        cout << "Total Fees: $" << totalBill << endl << endl;

    // Test Case 2
    cout << "Test Case 2:" << endl;
    totalBill = computeBill(1, 200, 600, 25);

    if (totalBill == -1.0)
        cout << "No such mobile plan..." << endl << endl;
    else
        cout << "Total Fees: $" << totalBill << endl << endl;

    // Test Case 3
    cout << "Test Case 3:" << endl;
    totalBill = computeBill(4, 100, 500, 10);

    if (totalBill == -1.0)
        cout << "No such mobile plan..." << endl << endl;
    else
        cout << "Total Fees: $" << totalBill << endl << endl;

    cout << "Press any key to continue . . .";
    cin.ignore();
// 5(d) end
}