#include <iostream>
#include <string>
using namespace std;

const int MAX_RESERVATIONS = 100;
int reservationCount = 0;
string reservations[MAX_RESERVATIONS][5]; // Name, Contact, RoomType, CheckInDate, RoomNumber
int durations[MAX_RESERVATIONS]; //for calculating bill a seperate string

struct Room 
{
    int roomNumber;
    string status;
};

void displayPrices();
void bookRoom(Room rooms[], int size);
void viewReservationDetails();
void updateReservation();
void deleteReservation();
int calculateTotalBill(string roomType, int duration);
void showAvailableRooms(Room rooms[], int size);

int main() 
{
    Room rooms[] = {
        {101, "Available"},
        {102, "Available"},
        {103, "Available"},
        {104, "Available"},
        {105, "Available"},
        {98, "Booked"},
        {99, "Booked"},
        {1006, "Booked"}
    };
    int size = sizeof(rooms) / sizeof(rooms[0]);//

    cout << "\t\t\t\t\t\t\t\t\t\t\t_________________________________________\n";
    cout << "\a\t\t\t\t\t\t\t\t\t\t\t.......Welcome to Seaside Serenity.......\n";
     cout << "\t\t\t\t\t\t\t\t\t\t\t_________________________________________\n\n";
    int choice;
    do  
    {
        cout << "\n\n\t\t\t1. Check Room Prices\n";
        
        cout << "\t\t\t2. Book Room\n";
        
        
        cout << "\t\t\t3. View Reservation Details(after reservation is made)\n";
        cout << "\t\t\t4. Update Reservation\n";
        
        cout << "\t\t\t5. Delete Reservation\n";
        cout << "\t\t\t6. Show Available Rooms\n";
        
        cout << "\t\t\t7. Exit\n";
        cout << "\t\t\t________________________________________________________________\n";
        cout << "\t\t\t----------------------------------------------------------------\n";
        cout << "\n\t\t\tEnter your choice: ";
        cin >> choice;
        cout << endl;
        
        switch (choice) 
        {
            case 1:
            	system("color B1");   
                displayPrices();
                break;
            case 2:
            	system("color E5");
                bookRoom(rooms, size);
                
                break;
                
            case 3:
            	system("color F8");
                viewReservationDetails();
                break;
            case 4:
            	system("color E6");
                updateReservation();
                break;
            case 5:
            	system("color C7");
                deleteReservation();
                break;
            case 6:
            	system("color E4");
                showAvailableRooms(rooms, size);
                break;
            case 7:
            	system("color F9");
                cout << "\t\t\t\t......Thank you for using Seaside Serenity Booking System!......\n";
                return 0;
            default:
            	system("color F4");
            	cout<<"\t\t\t-----------------------------------------\n";
                cout << "\t\t\tInvalid choice!! Please try again.\n";
                cout<<"\t\t\t-----------------------------------------\n";
        }
    } while (choice != 7);
}

void displayPrices() 
{
    cout<<endl;
	cout << "\t\t\t\t\t........Room Prices........\n\n";
    cout << "\t\tSingle Room: Rs. 4000 per day\n\t\tServices provided: Dinner & Lunch \n\n";
    cout << "\t\tDouble Room: Rs. 5500 per day\n\t\tServices provided: Dinner & Lunch\n\n";
    cout << "\t\tSuite: Rs. 8000 per day\n ";
    cout << "\t\tServices provided:\n\t\t1. Dinner & Lunch\n";
    cout << "\t\t2. Gymnasium\n";
    cout << "\t\t3. Hotel Buffet\n";
    cout << "\t\t4. Swimming Pool\n";
    cout << "\t\t________________________________________________________________________\n";
}

void bookRoom(Room rooms[], int size) 
{
    if (reservationCount >= MAX_RESERVATIONS) 
    {
        cout << "No more reservations can be made.\n";
        return;
    }

    cin.ignore(); // To clear the buffer
    cout << "\t\tEnter your name: ";
    getline(cin, reservations[reservationCount][0]);
    cout << "\t\tEnter your contact number: ";
    getline(cin, reservations[reservationCount][1]);
    cout << "\t\tSelect room type (1-Single, 2-Double, 3-Suite): ";
    int roomType;
    cin >> roomType;
    string selectedRoomType = (roomType == 1) ? "Single" : (roomType == 2) ? "Double" : "Suite";
    reservations[reservationCount][2] = selectedRoomType;
    cout << "\t\tEnter duration of stay (in days): ";
    cin >> durations[reservationCount];
    cin.ignore();
    cout << "\t\tEnter check-in date (YYYY-MM-DD): ";
    getline(cin, reservations[reservationCount][3]);

    // Assign an available room number
    int assignedRoomNumber = -1;
    for (int i = 0; i < size; i++) {
        if (rooms[i].status == "Available" && (selectedRoomType == "Single" || selectedRoomType == "Double" || selectedRoomType == "Suite")) 
		{
            assignedRoomNumber = rooms[i].roomNumber;
            rooms[i].status = "Booked";
            break;
        }
    }

    if (assignedRoomNumber == -1) 
	{
        cout << "\t\tNo available rooms for the selected type.\n";
        return;
    }

    reservations[reservationCount][4] = to_string(assignedRoomNumber);
    //total bill
    int totalBill = calculateTotalBill(reservations[reservationCount][2], durations[reservationCount]);//room type & days spent
    cout << "\t\tRoom booked successfully for " << reservations[reservationCount][0] << " for " << durations[reservationCount] << " days. \n\t\tTotal bill: Rs. " << totalBill << "\n";
    cout << "\t\tYour room number is: " << assignedRoomNumber << "\n";
    reservationCount++;
    cout << "\t\t________________________________________________________________________\n";
}

void viewReservationDetails() 
{
    if (reservationCount == 0) 
    {
        cout<<endl;
		cout << "\t\tNo reservations found!\n";
	    cout << "\t_____________________________________\n";
        return;
    }
    for (int i = 0; i < reservationCount; ++i) 
    {
        cout << "\t\tName: " << reservations[i][0] << "\n";
        cout << "\t\tContact: " << reservations[i][1] << "\n";
        cout << "\t\tRoom Type: " << reservations[i][2] << "\n";
        cout << "\t\tCheck-in Date: " << reservations[i][3] << "\n";
        cout << "\t\tDuration of Stay: " << durations[i] << " days\n";
        int totalBill = calculateTotalBill(reservations[i][2], durations[i]);
        cout << "\t\tTotal Bill: Rs. " << totalBill << "\n";
        cout << "\t\tRoom Number: " << reservations[i][4] << "\n";
        cout << "\t\t----------------------------------------------\n";
    }
}

void updateReservation() 
{
    cin.ignore();
    cout << "\tEnter the name for the reservation you want to update: ";
    string name;
    getline(cin, name);
    for (int i = 0; i < reservationCount; ++i) 
    {
        if (reservations[i][0] == name) 
        {
            cout << "\tEnter new contact number: ";
            getline(cin, reservations[i][1]);
            cout << "\tSelect new room type (1-Single, 2-Double, 3-Suite): ";
            int roomType;
            cin >> roomType;
            reservations[i][2] = (roomType == 1) ? "Single" : (roomType == 2) ? "Double" : "Suite";
            cout << "\tEnter new duration of stay (in days): ";
            cin >> durations[i];
            cin.ignore();
            cout << "\tEnter new check-in date (YYYY-MM-DD): ";
            getline(cin, reservations[i][3]);
            cout << "\tReservation updated successfully.\n";
            cout << "\t___________________________________________________\n";
            return;
        }
    }
    cout << "\t\tReservation not found.\n";
}

void deleteReservation() 
{
    cin.ignore();
    cout << "\tEnter the name for the reservation you want to delete: ";
    string name;
    getline(cin, name);
    for (int i = 0; i < reservationCount; ++i) 
    {
        if (reservations[i][0] == name) 
        {
            for (int j = i; j < reservationCount - 1; ++j) 
            {
                for (int k = 0; k < 5; ++k) 
                {
                    reservations[j][k] = reservations[j + 1][k];
                }
                durations[j] = durations[j + 1];
            }
            reservationCount--;
            cout << "\tReservation deleted successfully.\n";
            cout << "\t______________________________________\n";
            return;
        }
    }
    cout << "\tReservation not found.\n";
    cout << "\t_____________________________\n";
}

int calculateTotalBill(string roomType, int duration) 
{
    int pricePerDay;
    if (roomType == "Single") 
    { pricePerDay = 4000; } 
    else if (roomType == "Double") 
    { pricePerDay = 5500; } 
    else if (roomType == "Suite") 
    { pricePerDay = 8000; }
    return pricePerDay * duration;
}

void showAvailableRooms(Room rooms[], int size) 
{
    cout << "\n\t\t\t\t\t--- Available Rooms ---\n";
    for (int i = 0; i < size; i++) 
    {
        if (rooms[i].status == "Available") 
        {
            cout << "\t\t\t\t\tRoom " << rooms[i].roomNumber << " - " << rooms[i].status << endl;
        }
    }
    cout << "\n\t\t\t\t\t--- Booked Rooms ---\n";
    for (int i = 0; i < size; i++) 
    {
        if (rooms[i].status == "Booked") 
        {
            cout << "\t\t\t\t\tRoom " << rooms[i].roomNumber << " - " << rooms[i].status << endl;
        }
    }
    cout << "\t\t\t\t\t----------------------\n";
}
