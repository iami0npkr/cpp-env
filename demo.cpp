#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // For std::setw



using namespace std;

class Flight {
public:
    string flightNumber;
    string destination;
    string departureTime;
    string arrivalTime;

    Flight(string fn, string dest, string depTime, string arrTime)
        : flightNumber(fn), destination(dest), departureTime(depTime), arrivalTime(arrTime) {}

    void display() const {
        cout << setw(15) << flightNumber << setw(20) << destination
             << setw(15) << departureTime << setw(15) << arrivalTime << endl;
    }
};

class AirportManagementSystem {
private:
    vector<Flight> flights;

public:
    void addFlight() {
        string flightNumber, destination, departureTime, arrivalTime;

        cout << "Enter Flight Number: ";
        cin >> flightNumber;
        cin.ignore(); // Ignore leftover newline character

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Departure Time (HH:MM): ";
        cin >> departureTime;

        cout << "Enter Arrival Time (HH:MM): ";
        cin >> arrivalTime;

        Flight newFlight(flightNumber, destination, departureTime, arrivalTime);
        flights.push_back(newFlight);

        cout << "Flight added successfully!" << endl;
    }

    void displayAllFlights() const {
        cout << "\nAll Flights:" << endl;
        cout << setw(15) << "Flight No" << setw(20) << "Destination"
             << setw(15) << "Departure" << setw(15) << "Arrival" << endl;

        for (const auto& flight : flights) {
            flight.display();
        }
    }

    void searchFlightByNumber(const string& flightNumber) const {
        bool found = false;

        for (const auto& flight : flights) {
            if (flight.flightNumber == flightNumber) {
                cout << "\nFlight Found:" << endl;
                cout << setw(15) << "Flight No" << setw(20) << "Destination"
                     << setw(15) << "Departure" << setw(15) << "Arrival" << endl;
                flight.display();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Flight not found!" << endl;
        }
    }
};

int main() {
    AirportManagementSystem system;
    int choice;

    do {
        cout << "\nAirport Management System" << endl;
        cout << "1. Add Flight" << endl;
        cout << "2. Display All Flights" << endl;
        cout << "3. Search Flight by Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addFlight();
                break;
            case 2:
                system.displayAllFlights();
                break;
            case 3: {
                string flightNumber;
                cout << "Enter Flight Number to Search: ";
                cin >> flightNumber;
                system.searchFlightByNumber(flightNumber);
                break;
            }
            case 4:
                cout << "Exiting the system..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
