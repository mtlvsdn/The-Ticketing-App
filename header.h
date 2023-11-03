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

public:
	//STATIC ATTRIBUTES
	static const int MIN_AGE = 5;
	static const int MIN_NAME_LENGTH = 3;
	static const int MIN_CITY_LENGTH = 4;
	static const int MIN_VENUE_LENGTH = 4;
	static const int MIN_ROWS = 2;
	static const int MAX_ROWS = 100;
	static const int MIN_COLUMNS = 5;
	static const int MAX_COLUMNS = 50;

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
	EventType getType() {
		return this->type;
	}
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
	std::string getMonth() {
		switch (this->month) {
		case Months::January: return "January";
		case Months::February: return "February";
		case Months::March: return "March";
		case Months::April: return "April";
		case Months::May: return "May";
		case Months::June: return "June";
		case Months::July: return "July";
		case Months::August: return "August";
		case Months::September: return "September";
		case Months::October: return "October";
		case Months::November: return "November";
		case Months::December: return "December";
		default: return "Invalid Month";
		}
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
	void searchAnEventAndDisplayOnConsole() {

	}
	void generateTxtFileWithTicket(Participant participant) {
		std::ofstream writeFile("pdfTicket.txt");
		std::string word;

		writeFile << "Event-Ticket" << std::endl;
		writeFile << "Please print and show this ticket at the entrance to the venue" << std::endl;
		writeFile << "Event Name: " << this->getName() << std::endl;
		writeFile << "Name of person that made the purchase: " << participant.getName() << std::endl;
		writeFile << "Seat Nr: " << participant.getSeat() << std::endl;
		writeFile << "Date of Event: " << std::endl;
		writeFile << "\tYear: " << this->getYear() << std::endl;
		writeFile << "\tMonth: " << this->getMonth() << std::endl;
		writeFile << "\Day: " << this->getDay() << std::endl;


	}
	void generateMyTicket() {

	}
	void sendTicketViaEmail() {

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
	
	//DESTRUCTOR
	~Event() {
		delete[] this->occupiedSeatsChars;
	}
};

class Participant {
private:
	std::string name = "NaN";;
	int age = 0;
	int selectedSeat = 0;

public:

	static const int MIN_AGE = 3;
	static const int MIN_LENGTH_NAME = 3;

	//SETTERS
	void setName(std::string newName) {
		if (newName.length() < MIN_LENGTH_NAME) {
			throw std::exception("Name is too short!");
		}
		this->name = newName;
	}
	void setAge(int newAge) {
		if (newAge < MIN_AGE) {
			throw std::exception("Age is too small!");
		}
		this->age = newAge;
	}
	void setSeat(int newSeat) {
		if (newSeat <= 0) {
			throw std::exception("Seat number is invalid");
		}
		this->selectedSeat = newSeat;
	}

	//GETTERS
	std::string getName() {
		return this->name;
	}
	int getAge() {
		return this->age;
	}
	int getSeat() {
		return this->selectedSeat;
	}

	//OTHER METHODS
	void tellIfSeatIsAlreadyOccupied() {

	}
	void informBuyerToDownloadTicketsBeforeEvent() {

	}

	//CONSTRUCTOR
	Participant() {
		setName("John Doe");
		setAge(23);
		setSeat(1);
	}
	Participant(std::string name, int age, int seat) {
		setName(name);
		setAge(age);
		setSeat(seat);
	}

	//DESTRUCTOR
	~Participant() {

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
	//STATIC ATTRIBUTES
	static const int MIN_NAME_LENGTH = 3;

	//SETTERS
	void setNameOfTheEvent(std::string newName) {
		if (newName.length() < MyTickets::MIN_NAME_LENGTH) {
			throw std::exception("Name of the event is too short");
		}
		this->nameOfTheEvent = newName;
	}
	void setSeat(int newSeat) {
		if (newSeat <= 0) {
			throw std::exception("Invalid size number!");
		}
		this->selectedSeat = newSeat;
	}
	void setPrice(int newPrice) {
		if (newPrice <= 0) {
			throw std::exception("Invalid price!");
		}
		this->price = newPrice;
	}
	void setTicketID() {
		delete[] this->ticketID;

		std::random_device rd;
		std::mt19937 mt(rd());

		int min = 10000;
		int max = 100000000;

		std::uniform_int_distribution<int> dist(min, max);

		int randomNumber = dist(mt);
		//std::cout << randomNumber << std::endl;
		int copy = randomNumber;
		int count = 0;
		while (copy != 0) {
			count++;
			copy = copy / 10;
		}

		int* newTicketID = new int[count + 1];
		for (int i = 0; i < count; i++) {
			newTicketID[i] = randomNumber % 10;
			randomNumber = randomNumber / 10;
		}

		this->ticketID = newTicketID;
	}
	void setEventHasPassed(Event event) {
		//VALIDATION!!
		auto currentTime = std::chrono::system_clock::now();

		std::time_t time = std::chrono::system_clock::to_time_t(currentTime);
		std::tm* timeInfo = std::localtime(&time);

		int currentDay = timeInfo->tm_mday;
		int currentMonth = timeInfo->tm_mon + 1;
		int currentYear = timeInfo->tm_year + 1900;

		if (event.getYear() < currentYear) {
			throw std::exception("Event has already passed!");
		}
		if (int(event.getMonth()) < currentMonth && event.getYear() == currentYear) {
			throw std::exception("Event has already passed!");
		}
		if (event.getDay() < currentDay && int(event.getMonth()) == currentMonth && event.getYear() == currentYear) {
			throw std::exception("Event has already passed!");
		}
		this->eventHasPassed = true;
	}
	void setTypeOfParticipant(ParticipantType newType) {
		//do i need validation?
		this->type = newType;
	}

	//GETTERS
	std::string getNameOfTheEvent() {
		return this->nameOfTheEvent;
	}
	int getSeat() {
		return this->selectedSeat;
	}
	int getPrice() {
		return this->price;
	}
	int* getTicketID() {
		int* copy = new int[sizeof(this->ticketID) / sizeof(this->ticketID[0])];
		for (int i = 0; i < sizeof(this->ticketID) / sizeof(this->ticketID[0]); i++) {
			copy[i] = this->ticketID[i];
		}
		return copy;
	}
	bool getEventHasPassed() {
		return this->eventHasPassed;
	}
	ParticipantType getTypeOfParticipant() {
		return this->type;
	}

	//OTHER METHODS
	//a method that can generate me a pdf of my ticket and send it via email
	static void viewAllMyTickets() {

	}

	
	//CONSTRUCTORS
	MyTickets() {
		this->nameOfTheEvent = "No Event";
		this->price = 1;
		this->ticketID = nullptr;
		this->eventHasPassed = false;
		this->type = ParticipantType::Standard;
	}

	//DESTRUCTOR
	~MyTickets() {
		delete[] this->ticketID;
	}
};
