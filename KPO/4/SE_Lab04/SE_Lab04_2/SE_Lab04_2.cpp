#include <Windows.h>
#include <iostream>
using namespace std;

typedef double SquareFootage;
typedef int NumberOfRooms;
typedef int YearBuilt;
typedef int Floor;
typedef string KitchenAvailability;
typedef string BathroomAvailability;
typedef string ToiletAvailability;
typedef string BasementAvailability;
typedef string BalconyAvailability;

struct Apartments
{
	SquareFootage squareFootage;
	NumberOfRooms numberOfRooms;
	YearBuilt yearBuilt;
	Floor floor;
	KitchenAvailability kitchenAvailability;
	BathroomAvailability bathroomAvailability;
	ToiletAvailability toiletAvailability;
	BasementAvailability basementAvailability;
	BalconyAvailability balconyAvailability;

	Apartments(SquareFootage squareFootage,
		NumberOfRooms numberOfRooms,
		YearBuilt yearBuilt,
		Floor floor,
		KitchenAvailability kitchenAvailability,
		BathroomAvailability bathroomAvailability,
		ToiletAvailability toiletAvailability,
		BasementAvailability basementAvailability,
		BalconyAvailability balconyAvailability)
	{
		this->squareFootage = squareFootage;
		this->numberOfRooms = numberOfRooms;
		this->yearBuilt = yearBuilt;
		this->floor = floor;
		this->kitchenAvailability = kitchenAvailability;
		this->bathroomAvailability = bathroomAvailability;
		this->toiletAvailability = toiletAvailability;
		this->basementAvailability = basementAvailability;
		this->balconyAvailability = balconyAvailability;
	}
	friend ostream& operator<<(ostream& os, const Apartments& apartment)
	{
		os << "Square Footage: " << apartment.squareFootage << endl;
		os << "Number of Rooms: " << apartment.numberOfRooms << endl;
		os << "Year Built: " << apartment.yearBuilt << endl;
		os << "Floor: " << apartment.floor << endl;
		os << "Kitchen Availability: " << apartment.kitchenAvailability << endl;
		os << "Bathroom Availability: " << apartment.bathroomAvailability << endl;
		os << "Toilet Availability: " << apartment.toiletAvailability << endl;
		os << "Basement Availability: " << apartment.basementAvailability << endl;
		os << "Balcony Availability: " << apartment.balconyAvailability << endl;

		return os;
	}
	int operator==(const Apartments& other)
	{
		return
			this->squareFootage == other.squareFootage &&
			this->numberOfRooms == other.numberOfRooms &&
			this->yearBuilt == other.yearBuilt &&
			this->floor == other.floor &&
			this->kitchenAvailability == other.kitchenAvailability &&
			this->bathroomAvailability == other.bathroomAvailability &&
			this->toiletAvailability == other.toiletAvailability &&
			this->basementAvailability == other.basementAvailability &&
			this->balconyAvailability == other.balconyAvailability;
	}
	void setSquareFootage(SquareFootage squareFootage) {
		this->squareFootage = squareFootage;
	}

	SquareFootage getSquareFootage() const {
		return this->squareFootage;
	}
};

int main() {
	SetConsoleOutputCP(1251);

	Apartments apartment1 = { 75.5, 2, 1995, 3, "Yes", "Yes", "Yes", "No", "Yes" };
	Apartments apartment4 = { 75.5, 2, 1995, 3, "Yes", "Yes", "Yes", "No", "Yes" };
	Apartments apartment2 = { 90.0, 3, 2000, 5, "Yes", "Yes", "No", "Yes", "No" };
	Apartments apartment3 = { 60.8, 1, 1980, 2, "No", "Yes", "Yes", "No", "No" };
	cout << apartment1;
	cout << "\n\n";
	cout << (apartment1 == apartment4);
	apartment1.setSquareFootage(123.1243);
	cout << "\n\n" << apartment1;
	cout << "\n\n" << apartment1.getSquareFootage();
	return 0;
}
