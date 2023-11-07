#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <ctime>

enum class EventType {Movie, Theater, Match};
enum class ParticipantType {Standard, Child, Teen, Retired};
enum class PriceDiscounts {Standard = 0, Child = 50, Teen = 30, Retired = 40};
//enum class Months {January = 1, February, March, April, May, June, July,
	//				August, September, October, November, December};

class Event {
private:
	//OBJECTS
	EventType type = EventType::Movie;
	std::string name = "NaN";
	std::string city = "NaN";
	std::string venue = "NaN";
	std::string date = "20/01/2011";
	std::string time = "00:00";
	char* category = nullptr;
	int lengthOfCategory = 0;
	char* occupiedSeatsCategory1 = nullptr; // un vector uunidimensional pt toate loc din cat 1
	char* occupiedSeatsCategory2 = nullptr; // un vector uunidimensional pt toate loc din cat 2
	int noOfRows = 20;
	int noOfColumns = 20;
	int price = 0;

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
	static const int DATE_SIZE = 10;

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
	void setDate(std::string newDate) {
		if (newDate.size() != Event::DATE_SIZE) {
			throw std::exception("Date format is invalid!");
		}
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
	void setOccuppiedSeatsCategory1(int newSeat) {
		if (newSeat > this->noOfColumns * this->noOfRows || newSeat <= 0 || this->occupiedSeatsCategory1[newSeat] == 'O') {
			throw std::exception("Number of seat is invalid!");
		}
		this->occupiedSeatsCategory1[newSeat] = 'O';
	}
	void setOccuppiedSeatsCategory2(int newSeat) {
		if (newSeat > this->noOfColumns * this->noOfRows || newSeat <= 0 || this->occupiedSeatsCategory2[newSeat] == 'O') {
			throw std::exception("Number of seat is invalid!");
		}
		this->occupiedSeatsCategory2[newSeat] = 'O';
	}
	void setPrice(int newPrice) {
		if (newPrice <= 0) {
			throw std::exception("Invalid price!");
		}
		this->price = newPrice;
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
	std::string getDate() {
		return this->date;
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
	char* getOccupiedCategory1() {
		char* newArray = new char[this->noOfRows * this->noOfColumns];
		for (int i = 0; i < this->noOfRows * this->noOfColumns; i++) {
			newArray[i] = this->occupiedSeatsCategory1[i];
		}

		return newArray;
	}
	char* getOccupiedCategory2() {
		char* newArray = new char[this->noOfRows * this->noOfColumns];
		for (int i = 0; i < this->noOfRows * this->noOfColumns; i++) {
			newArray[i] = this->occupiedSeatsCategory2[i];
		}

		return newArray;
	}
	int getPrice() {
		return this->price;
	}

	//OTHER METHODS
	void initialiseOccuppiedSeatsCategory1(int noRows, int noColumns) {
		delete[] this->occupiedSeatsCategory1;
		this->occupiedSeatsCategory1 = new char[noRows * noColumns];

		for (int i = 0; i < noRows * noColumns; i++) {
			this->occupiedSeatsCategory1[i] = 'F';
		}
	}
	void initialiseOccuppiedSeatsCategory2(int noRows, int noColumns) {
		delete[] this->occupiedSeatsCategory2;
		this->occupiedSeatsCategory2 = new char[noRows * noColumns];

		for (int i = 0; i < noRows * noColumns; i++) {
			this->occupiedSeatsCategory2[i] = 'F';
		}
	}
	void chooseEvent() {
		int selection, eventSelection;
		std::string line;
		bool ok = false;
		int counter = 1;
		std::ifstream eventFile("movieEvents.txt");
		std::cout << "Choose your event type: ";
		std::cout << std::endl << "1. Movie";
		std::cout << std::endl << "2. Theater";
		std::cout << std::endl << "3. Match";

		while (!ok) {
			std::cout << std::endl << "-> ";
			std::cin >> selection;
			switch (selection) {
			case 1: ok = true; break;
			case 2: ok = true; break;
			case 3: ok = true; break;
			default: std::cout << std::endl << "Invalid input! Try again: "; std::cin >> selection;
			}
		}
		if (selection == 2) {
			system("cls");
			std::cout << "List of current Theter Events: ";
			eventFile.close();
			eventFile.open("theaterEvents.txt");
		}
		else if (selection == 3) {
			system("cls");
			std::cout << "List of current Match Events: ";
			eventFile.close();
			eventFile.open("matchEvents.txt");
		}
		else {
			system("cls");
			std::cout << "List of current Movie Events";
		}


		while (std::getline(eventFile, line)) {
			std::cout << std::endl << counter << ". " << line;
			counter++;
		}
		
		std::cout << std::endl << "Choose the event you wish to attend: ";
		std::cin >> eventSelection;
		while (eventSelection > counter) {
			std::cout << std::endl << "Invalid selection. Try again!";
			std::cin >> eventSelection;
		}

		//reset parameters
		std::string newName;
		std::string newCity;
		std::string newVenue;
		std::string newDate;
		std::string newTime;
		counter = 1;
		//eventFile.seekg(0, std::ios::beg);
		eventFile.close();
		if (selection == 1) {
			system("cls");
			eventFile.open("movieEvents.txt");
		}
		else if (selection == 2) {
			system("cls");
			eventFile.open("theaterEvents.txt");
		}
		else if (selection == 3) {
			system("cls");
			eventFile.open("matchEvents.txt");
		}
		else {
			system("cls");
			std::cout << "List of current Movie Events";
		}

		if (eventFile.is_open()) {
			while (std::getline(eventFile, newName, ',')) {
				std::getline(eventFile, newCity, ',');
				std::getline(eventFile, newVenue, ',');
				std::getline(eventFile, newDate, ',');
				std::getline(eventFile, newTime, ',');
				if (counter == eventSelection) {
					this->name = newName;
					this->city = newCity;
					this->venue = newVenue;
					this->date = newDate;
					this->time = newTime;
				}
				counter++;
			}
		}
		else {
			std::cout << "File cannot be opened!";
		}
	}
	void selectBetweenTheTwoCategories() {
		int selection, seatSelection;
		int counter = 1;
		std::cout << "Book tickets: ";
		std::cout << std::endl << "The chosen event: " << this->name << " " << this->city << " ";
		std::cout << this->venue << " " << this->date << " " << this->time;
		std::cout << std::endl << std::endl <<"Seats at the venue: " << std::endl;

		//Category 1
		char* newArray1 = this->getOccupiedCategory1();
		std::cout << std::endl << "Category 1" << std::endl;
		for (int i = 1; i <= this->noOfRows; i++) {
			for (int j = 1; j <= this->noOfColumns; j++) {
				std::cout << counter << "-" << newArray1[i] << " ";
				counter++;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
		//Category 2
		char* newArray2 = this->getOccupiedCategory2();
		std::cout << std::endl << "Category 2" << std::endl;
		for (int i = 1; i <= this->noOfRows; i++) {
			for (int j = 1; j <= this->noOfColumns; j++) {
				std::cout << counter << "-" << newArray2[i] << " ";
				counter++;
			}
			std::cout << std::endl;
		}

		std::cout << std::endl << std::endl << "In which category would you like to book your ticket?: ";
		std::cin >> selection;
		while (!(selection == 1 || selection == 2)) {
			std::cout << "Wrong selection! Try again: ";
			std::cin >> selection;
		}

		if (selection == 1) {
			std::cout << std::endl << "Select a seat: ";
			std::cin >> seatSelection;
			while (seatSelection < 1 || seatSelection > this->noOfRows * this->noOfColumns) {
				std::cout << "Invalid seat number! Try again: ";
				std::cin >> seatSelection;
			}
			this->setOccuppiedSeatsCategory1(seatSelection);
		}
		else {
			std::cout << std::endl << "Select a seat: ";
			std::cin >> seatSelection;
			while (seatSelection < 1 || seatSelection > this->noOfRows * this->noOfColumns) {
				std::cout << "Invalid seat number! Try again: ";
				std::cin >> seatSelection;
			}
			this->setOccuppiedSeatsCategory2(seatSelection);
		}
	}



	//CONSTRUCTORS
	Event() {
		this->setEventType(EventType::Movie);
		this->setName("Home Alone");
		this->setCity("Bucharest");
		this->setVenue("Afi Palace Cotroceni");
		this->setDate("20/01/2011");
		this->setTime("22:00");
		this->setNoOfRows(4);
		this->setNoOfColumns(5);
		this->setPrice(20);
	}
	Event (std::string name, std::string city) {
		setName(name);
		setCity(city);
	}
	Event (std::string name, std::string city, std::string venue,
		std::string date, std::string time) {
		setName(name);
		setCity(city);
		setVenue(venue);
		setDate(date);
		setTime(time);
	}
	
	//DESTRUCTOR
	~Event() {
		delete[] this->occupiedSeatsCategory1;
		delete[] this->occupiedSeatsCategory2;
	}
};

class Participant {
private:
	std::string name = "NaN";;
	int age = 0;
	int selectedSeat = 0;
	PriceDiscounts discount = PriceDiscounts::Standard;

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
	void setDiscount(PriceDiscounts newDiscount) {
		this->discount = newDiscount;
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
	std::string getDiscount() {
		switch (this->discount) {
		case PriceDiscounts::Standard: return "Standard";
		case PriceDiscounts::Child: return "Child";
		case PriceDiscounts::Teen: return "Teen";
		case PriceDiscounts::Retired: return "Retired";
		}
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
		int i = 0;
		while (this->ticketID[i] != '\0') {
			copy[i] = this->ticketID[i];
			i++;
		}
		return copy;
	}
	ParticipantType getTypeOfParticipant() {
		return this->type;
	}

	//OTHER METHODS
	static void viewAllMyTickets() {

	}

	//CONSTRUCTORS
	MyTickets() {
		this->nameOfTheEvent = "No Event";
		this->price = 1;
		this->ticketID = nullptr;
		this->type = ParticipantType::Standard;
	}

	//DESTRUCTOR
	~MyTickets() {
		delete[] this->ticketID;
	}
};
