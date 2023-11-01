#pragma once

enum class EventType {Movie, Theater, Concert, Match};
enum class ParticipantType {Standard, Child, Teen, Retired};
enum class PriceDiscounts {Standard = 0, Child = 50, Teen = 30, Retired = 40};
enum class Months {January = 1, February, March, April, May, June, July,
					August, September, October, November, December};

class Event {
private:
	//OBJECTS
	EventType type = EventType::Movie;
	std::string name = "NaN";
	std::string city = "NaN";
	std::string venue = "NaN";
	int day = 1;
	Months month = Months::January;
	int year = 2011;
	std::string time = "00:00";
	char* occupiedSeatsChars = nullptr; // un vector uunidimensional pt toate loc din sala
	int noOfRows = 0;
	int noOfColumns = 0;
	int price = 0;
	PriceDiscounts discount = PriceDiscounts::Standard;
	bool isConcessioned = false;

	//STATIC ATTRIBUTES
	static const int MIN_AGE = 5;
	static const int MIN_NAME_LENGTH = 3;
	static const int MIN_CITY_LENGTH = 4;
	static const int MIN_VENUE_LENGTH = 4;
	static const int MIN_ROWS = 2;
	static const int MAX_ROWS = 100;
	static const int MIN_COLUMNS = 5;
	static const int MAX_COLUMNS = 50;

public:
	//SETTERS
	void setEventType(EventType type) {
		this->type = type;
	}
	void setName(std::string newName) {
		if (newName.size() < Event::MIN_NAME_LENGTH) {
			throw std::exception("Name is too short!");
		}
		this->name = newName;
	}
	void setCity(std::string newCity) {
		if (newCity.size() < Event::MIN_CITY_LENGTH) {
			throw std::exception("The name of the city is too short!");
		}
		this->city = newCity;
	}
	void setVenue(std::string newVenue) {
		if (newVenue.size() < Event::MIN_VENUE_LENGTH) {
			throw std::exception("The name of the venue is too short!");
		}
	}
	void setYear(int newYear) {
		if (newYear < 2010 || newYear > 2030) {
			throw std::exception("Invalid date!");
		}
		this->year = newYear;
	}
	void setMonth(Months newMonth) {
		this->month = newMonth;
	}
	void setDay(int newDay) {
		if (newDay < 1 || newDay > 31) {
			throw std::exception("Invalid date!");
		}
		if (this->month == Months::February) {
			if (newDay == 30 || newDay == 31) {
				throw std::exception("Invalid date!");
			}
			if (this->year % 4 != 0) {
				if (newDay == 29) {
					throw std::exception("Invalid date!");
				}
			}
		}
		if (this->month == Months::April || this->month == Months::June
			|| this->month == Months::September || this->month == Months::November) {
			if (newDay == 31) {
				throw std::exception("Invalid date!");
			}
		}
		this->day = newDay;
	}
	void setTime(std::string newTime) {
		if (newTime.length() != 5) {
			throw std::exception("Invalid time!");
		}
		if (newTime[1] < '0' || newTime[1] > '9') {
			throw std::exception("Invalid time!");
		}
		if (newTime[4] < '0' || newTime[4] > '9') {
			throw std::exception("Invalid time!");
		}
		if (newTime[0] < '0' || newTime[1] > '2') {
			throw std::exception("Invalid time!");
		}
		if (newTime[3] < '0' || newTime[3] > '5') {
			throw std::exception("Invalid time!");
		}
		if ((newTime[0] == 2) && (newTime[1] == 5 || newTime[1] == 6 ||
			newTime[1] == 7 || newTime[1] == 8 || newTime[1] == 9)) {
			throw std::exception("Invalid time!");
		}
		this->time = newTime;
	} //.length() nu ia in considerare \0
	void setNoOfRows(int newNumber) {
		if (newNumber >= MIN_ROWS && newNumber <= MAX_ROWS) {
			this->noOfRows = newNumber;
		}
		else {
			throw std::exception("Invalid Number of Rows at the Venue!");
		}
	}
	void setNoOfColumns(int newNumber) {
		if (newNumber >= MIN_COLUMNS && newNumber <= MAX_COLUMNS) {
			this->noOfColumns = newNumber;
		}
		else {
			throw std::exception("Invalid Number of Columns at the Venue!");
		}
		
	}
	void setOccuppiedSeats(int newSeat) {
		if (newSeat > this->noOfColumns * this->noOfRows || newSeat <= 0) {
			throw std::exception("Number of seat is invalid!");
		}
		this->occupiedSeatsChars[newSeat] = 'O';
	}
	void setPrice(int newPrice) {
		if (newPrice <= 0) {
			throw std::exception("Invalid price!");
		}
		this->price = newPrice;
	}
	void setDiscount(PriceDiscounts newDiscount) {
		this->discount = newDiscount;
	}
	void IsConcessioned() {
		this->isConcessioned = true;
	}

	//GETTERS
	std::string getName() {
		return this->name;
	}
	std::string getCity() {
		return this->city;
	}
	std::string getVenue() {
		return this->venue;
	}
	int getYear() {
		return this->year;
	}
	Months getMonth() {
		return this->month;
	}
	int getDay() {
		return this->day;
	}
	std::string getTime() {
		return this->time;
	}
	int getNoOfRows() {
		return this->noOfRows;
	}
	int getNoOfColumns() {
		return this->noOfColumns;
	}
	char* getOccupiedSeats() {
		char* newArray = new char[this->noOfRows * this->noOfColumns];
		for (int i = 1; i <= this->noOfRows * this->noOfColumns; i++) {
			newArray[i] = this->occupiedSeatsChars[i];
		}

		return newArray;
	}
	int getPrice() {
		return this->price;
	}
	PriceDiscounts getDiscount() {
		return this->discount;
	}
	bool hasConcession() {
		return this->isConcessioned;
	}

	//OTHER METHODS
	void initialiseOccuppiedSeats(int noRows, int noColumns) {
		delete[] this->occupiedSeatsChars;
		this->occupiedSeatsChars = new char[noRows * noColumns];

		for (int i = 1; i <= noRows * noColumns; i++) {
			this->occupiedSeatsChars[i] = 'F';
		}
	}

	//CONSTRUCTORS
	Event() {
		this->setEventType(EventType::Movie);
		this->setName("Home Alone");
		this->setCity("Bucharest");
		this->setVenue("Afi Palace Cotroceni");
		this->setYear(2011);
		this->setMonth(Months::January);
		this->setDay(1);
		this->setTime("22:00");
		this->setNoOfRows(4);
		this->setNoOfColumns(5);
		this->setPrice(20);
		this->setDiscount(PriceDiscounts::Standard);
	}

	Event (std::string name, std::string city) {
		setName(name);
		setCity(city);
	}

	Event (EventType type, std::string name, std::string city,
		int year, Months month, int day) {
		setEventType(type);
		setName(name);
		setCity(city);
		setVenue(venue);
		setYear(year);
		setMonth(month);
		setDay(day);
	}
	
};

class Participant {
private:
	std::string name = "NaN";;
	int age = 0;
	int selectedSeat = 0;

public:

	static const int MIN_AGE = 3;

	//SETTERS
	void setName(std::string newName) {
		this->name = newName;
	}

	void setDateOfBirth(char newDate[11]) {
		////char newArray[11];

		//// Get the current time as a time_t object
		//std::time_t currentTime = std::time(nullptr);
		//// Convert the time to a tm struct
		//std::tm* timeInfo = std::localtime(&currentTime);
		//// Extract the current year
		//int currentYear = timeInfo->tm_year + 1900;
		//if (currentYear - newDate[])
		for (int i = 0; i < 11; i++) {
			this->dateOfBirth[i] = newDate[i];
		}
	}

	void setSeats(int newSeat) {
		this->selectedSeat = newSeat;
	}

	void setIsConcessioned() {
		this->isConcessioned = true;
	}

	void setIsNotConcessioned() {
		this->isConcessioned = false;
	}

	//GETTERS
	std::string getName() {
		return this->name;
	}

	char getDateOfBirth() {
		return this->dateOfBirth[11];
	}

	int getSeat() {
		return this->selectedSeat;
	}

	bool hasConcession() {
		return this->isConcessioned;
	}
};

class MyTickets {
private:
	std::string nameOfTheEvent = "NaN";
	int selectedSeat = 0;
	int price = 0;
	int* ticketID = nullptr;
	bool eventHasPassed = false;
	ParticipantType type = ParticipantType::Standard;

public:
	void setNameOfTheEvent(std::string newName) {
		this->nameOfTheEvent = newName;
	}

	void setEventHasPassed() {
		this->eventHasPassed = true;
	}

	void setEventHasNotPassed() {
		this->eventHasPassed = false;
	}

};
