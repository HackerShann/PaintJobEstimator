#include <iostream>
#include <iomanip>

using namespace std;

double getPricePerGallon() {
    cout << "Paint Job Estimator ..." << endl;
    cout << endl;

    double price;
    do {
        cout << "Price per gallon of paint (>=0): ";
        cin >> price;
        cout << endl;
    } while (price < 0);
    return price;
}

int getRooms() {
    int rooms;
    do {
        cout << "Number of rooms to be painted (>=1): ";
        cin >> rooms;
        cout << endl;
    } while (rooms < 1);
    return rooms;
}

int calcWallSpace(int rooms) {
    cout << "Square Feet of wall space (>=25)" << endl;

    int totalWallSpace = 0;
    for (int i = 1; i <= rooms; i++) {
        int squareFeet;
        do {
            cout << "\tRoom " << i << ": ";
            cin >> squareFeet;
        } while (squareFeet < 25);
        totalWallSpace += squareFeet;
    }
    return totalWallSpace;
}

void calcPaint(int sqrFeet, double pricePaint, int& gallons, double& cost) {
    gallons = sqrFeet / 115 + 1; // Add 1 gallon for partial gallons
    cost = gallons * pricePaint;
}

void calcLabor(int sqrFeet, double& hours, double& cost) {
    hours = (sqrFeet / 115.0) * 8; // Calculate total hours of labor
    cost = hours * 25.00;
}

int main() {
    double pricePerGallon = getPricePerGallon();
    int numRooms = getRooms();
    int totalWallSpace = calcWallSpace(numRooms);

    int gallons;
    double paintCost;
    calcPaint(totalWallSpace, pricePerGallon, gallons, paintCost);

    double laborHours, laborCost;
    calcLabor(totalWallSpace, laborHours, laborCost);

    // Display the report
    cout << fixed << setprecision(2);

    cout << endl;
    cout << "\tPaint Job Estimate" << endl;

    cout << "\nPaint ...\n";
    cout << "Gallons of Paint:" << setw(8) << gallons << endl;
    cout << "Cost of Paint:" << setw(12) << "$ " << paintCost << endl;

    cout << endl;

    cout << "Labor: " << endl;
    cout << "Hours of Labor:" << setw(14) << laborHours << " hours" << endl;
    cout << "Cost of Labor:" << setw(12) << "$ " << laborCost << endl;
    cout << setw(34) << "----------" << endl;
    cout << "Total Cost:" << setw(15) << "$ " << paintCost + laborCost << endl;

    return 0;
}
