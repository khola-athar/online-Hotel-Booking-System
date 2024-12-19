# online-Hotel-Booking-System


---

## Hotel Room Reservation System

### Overview
The Hotel Room Reservation System allows hotel staff and customers to manage room bookings. It includes features for checking room prices, booking rooms, viewing reservation details, updating and deleting reservations, and displaying available rooms.

### Key Features

#### Hotel Staff Features:
- View Reservation Details
- Update Reservations
- Delete Reservations
- Show Available Rooms

#### Customer Features:
- Check Room Prices
- Book Room
- View Reservation Details

**Compiler**: C++ (Any standard C++ compiler, such as GCC or MSVC)

**Libraries**:
- `<iostream>` for input/output operations
- `<string>` for handling strings


### Usage
Once the program is running:
- You will be prompted to choose various options from the menu.
- Customers can check room prices, book rooms, and view reservation details.
- Hotel staff can view, update, or delete reservation details and show available rooms.
- Follow the on-screen prompts to make selections and input data.

### Example:
**Hotel Staff**: 
- View all reservation details.
- Update a reservation by changing contact information, room type, duration, or check-in date.
- Delete a reservation by the customer's name.
- Show which rooms are available or booked.

**Customers**:
- Check prices for single, double, and suite rooms.
- Book a room by entering details such as name, contact number, room type, duration, and check-in date.
- View reservation details including name, contact, room type, check-in date, and total bill.

### Data Structure
The system uses arrays and structures to store the following information:
- `reservationCount`: Number of current reservations.
- `reservations`: Stores details for each reservation (name, contact, room type, check-in date, room number).
- `durations`: Stores the duration of each reservation.
- `Room`: Structure to store room number and status (available/booked).

### Menu Options
- **1. Check Room Prices**
- **2. Book Room**
- **3. View Reservation Details**
- **4. Update Reservation**
- **5. Delete Reservation**
- **6. Show Available Rooms**
- **7. Exit**

### How It Works
- **Check Room Prices**: Customers can view prices for different room types and the services offered.
- **Book Room**: Customers can book a room by providing necessary details. The system assigns an available room and calculates the total bill.
- **View Reservation Details**: Displays details of all existing reservations.
- **Update Reservation**: Allows hotel staff to update reservation details based on the customer's name.
- **Delete Reservation**: Allows hotel staff to delete a reservation based on the customer's name.
- **Show Available Rooms**: Displays all available and booked rooms.

