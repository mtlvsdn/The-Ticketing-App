#pragma once

enum class EventType {Movie, Theater, Concert, Match};
enum class ParticipantType {Standard, Child, Teen, Retired};

class Event {
private:
	EventType type = EventType::Movie;
	std::string name = "NaN";
	std::string city = "NaN";
	std::string venue = "NaN";
	int date[3] = {};
	int time[2] = {};
	char* occupiedSeatsChars = nullptr; // un vector uunidimensional pt toate loc din sala
	int noOfRows = 0;
	int noOfColumns = 0;
	int* prices = nullptr;

public:
	static const int MIN_AGE = 5;
	static const int MIN_NAME_LENGTH = 3;
	static const int MIN_CITY_LENGTH = 4;
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

	void setDate(int newDate[3]) {
		int i;
		if (newDate[2] >= 2010 && newDate[2] <= 2090)
		{
			if (newDate[1] == 1 || newDate[1] == 3 || newDate[1] == 5 || newDate[1] == 7 || newDate[1] == 8 || newDate[1] == 10 || newDate[1] == 12)
			{
				if (newDate[0] >= 1 && newDate[0] <= 31)
				{
					for (i = 0; i < 3; i++)
						this->date[i] = newDate[i];
				}

			}
			else if (newDate[1] == 4 || newDate[1] == 6 || newDate[1] == 9 || newDate[1] == 11) {
				if (newDate[0] >= 1 && newDate[0] <= 30) {
					for (i = 0; i < 3; i++)
						this->date[i] = newDate[i];
				}


			}
			else if (newDate[1] == 2)
			{
				if (newDate[2] % 4 == 0) {
					if (newDate[0] >= 1 && newDate[0] <= 29)
					{
						for (i = 0; i < 3; i++)
							this->date[i] = newDate[i];
					}
				}
				else if (newDate[0] >= 1 && newDate[0] <= 28) {
					for (i = 0; i < 3; i++)
						this->date[i] = newDate[i];
				}
			}
			else
				throw std::exception("Invalid date!");
		}

	}

	void setTime(int newTime[2]) {
		if (newTime[0] >= 0 && newTime[0] <= 23 && newTime[1] >= 0 && newTime[1] <= 59)
		{
			this->time[0] = newTime[0];
			this->time[1] = newTime[1];
		}
		else {
			throw std::exception("Invalid date!");
		}
	}

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
		this->occupiedSeatsChars[newSeat] = 'O';
	}
	
	void initialiseOccuppiedSeats(int noRows, int noColumns) {
		//delete[] this->occupiedSeatsNumber;
		delete[] this->occupiedSeatsChars;
		//this->occupiedSeatsNumber = new int[noRows * noColumns];
		this->occupiedSeatsChars = new char[noRows * noColumns];

		for (int i = 1; i <= noRows * noColumns; i++) {
			//this->occupiedSeatsNumber[i] = i;
			this->occupiedSeatsChars[i] = 'F';
		}
	}

	void setPrices(int* newArray, int noOfTypes) {
		newArray = new int[noOfTypes];
		
		for (int i = 0; i < noOfTypes; i++) {
			//citire din fisier a preturilor;
		}
	}

	//GETTERS

	std::string getName() {
		return this->name;
	}

	std::string getCity() {
		return this->city;
	}

	int getDate() {
		return this->date[3];
	}

	int getTime() {
		return this->time[2];
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

	int* getPrices() {
		int* newArray = new int[this->noOfRows / 2];
		for (int i = 0; i < *newArray; i++) {
			newArray[i] = this->prices[i];
		}

		return newArray;
	}

	//Event {

	//}

	/*Event (EventType type, std::string name, std::string city, std::string venue, int date[3], int time[2]) {
		setEventType();
		setName();
		setCity();
		setVenue();
		setDate();
		setTime();

	}*/
	
};

class Participant {
private:
	std::string name = "NaN";
	char dateOfBirth[11] = {};
	int selectedSeat = 0;
	bool isConcessioned = false;

public:
	//SETTERS
	void setName(std::string newName) {
		this->name = newName;
	}

	void setDateOfBirth(char newDate[11]) {
		//char newArray[11];
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
	bool eventHasPassed = false;
	int* selectedSeats = nullptr;
	int totalPrice = 0;
	//int numberOfParticipants = 0;
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
