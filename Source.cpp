#include <iostream>
#include "header.h"
#include <conio.h>
#include <fstream>
#include <string>

void mainMenu() {
	system("cls");
	std::cout << std::endl << "\t\t\t\t\tTicketing App";
	std::cout << std::endl << std::endl << "\tChoose your event or see your tickets: ";
	std::cout << std::endl << "\t1. Movie";
	std::cout << std::endl << "\t2. Musical";
	std::cout << std::endl << "\t3. Concert";
	std::cout << std::endl << "\t4. Football Match";
	std::cout << std::endl << "\t5. My Tickets";
	std::cout << std::endl << "\t6. Exit";
	std::cout << std::endl << std::endl << "\t-> ";
}

//std::string typeNameOfMovie() {
//	std::string nameOfEvent;
//	system("cls");
//	std::cout << std::endl << "\t\t\t\t\tTicketing App";
//	std::cout << std::endl << std::endl << "\tType in the name of the movie you wish to attend: ";
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	std::getline(std::cin, nameOfEvent);
//	return nameOfEvent;
//}
//std::string typeNameOfMusical() {
//	std::string nameOfEvent;
//	system("cls");
//	std::cout << std::endl << "\t\t\t\t\tTicketing App";
//	std::cout << std::endl << std::endl << "\tType in the name of the musical you wish to attend: ";
//	std::cin >> nameOfEvent;
//	return nameOfEvent;
//}
//std::string typeNameOfConcert() {
//	std::string nameOfEvent;
//	system("cls");
//	std::cout << std::endl << "\t\t\t\t\tTicketing App";
//	std::cout << std::endl << std::endl << "\tType in the name of the concert you wish to attend: ";
//	std::cin >> nameOfEvent;
//	return nameOfEvent;
//}
//std::string typeNameOfMatch() {
//	std::string nameOfEvent;
//	system("cls");
//	std::cout << std::endl << "\t\t\t\t\tTicketing App";
//	std::cout << std::endl << std::endl << "\tType in the name of the match you wish to attend: ";
//	std::cin >> nameOfEvent;
//	return nameOfEvent;
//}

void listOfMovies(std::string nameOfEvent) {
	system("cls");
	std::cout << std::endl << "\t\t\t\t\tTicketing App";
	std::cout << std::endl << std::endl << "\tList of Dates & Times for your selected event";
	std::cout << std::endl << "\tChoose your event:";
	std::ifstream readFile("movieEvents.txt");
	std::string data;
	
	while (!readFile.eof()) {
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(readFile, data, ',');
		if (data == nameOfEvent) {
			//NAME
			std::cout << std::endl << "\t" << data << " ";
			//CITY
			std::getline(readFile, data, ',');
			std::cout << data << " ";
			//VENUE
			std::getline(readFile, data, ',');
			std::cout << data << " ";
			//DATE
			std::getline(readFile, data, ',');
			std::cout << data << " ";
			//TIME
			std::getline(readFile, data, ',');
			std::cout << data << " ";
		} else {
			// Consume the rest of the line if the event name does not match
			std::getline(readFile, data);
		}
		//std::cout << data << " ";
	}

	readFile.close();
}

void initialiseUserEvent(Event event) {
	std::string nameOfEvent;
	system("cls");
	std::string name, city, venue;
	int date[3], time[2];

	std::cout << std::endl << "\t\t\t\t\tTicketing App";
	std::cout << std::endl << std::endl << "\tType in data about the event you wish to attend: ";
	////NAME
	//std::cout << std::endl << "Name: ";
	//std::cin >> name;
	//event.setName(name);
	////CITY
	//std::cout << std::endl << "City: ";
	//std::cin >> city;
	//event.setCity(city);
	////VENUE
	//std::cout << std::endl << "Venue: ";
	////DATE
	//std::cout << std::endl << "Date: ";
	////TIME
	//std::cout << std::endl << "Time: ";
}


int main() {
	Event event;
	EventType value = EventType::Concert;
	int selection;
	std::string nameOfEvent;

	mainMenu();
	std::cin >> selection;
	switch (selection) {
	case 1:
		nameOfEvent = typeNameOfMovie();
		listOfMovies(nameOfEvent);
		break;
	case 2:
		nameOfEvent = typeNameOfMusical();
		//listOfMusicals(nameOfEvent);
		break;
	case 3:
		nameOfEvent = typeNameOfConcert();
		//listOfConcerts(nameOfEvent);
		break;
	case 4:
		nameOfEvent = typeNameOfMatch();
		//listOfMatches(nameOfEvent);
		break;
	}


	//char location[] = "Sofia";

	//event.setLocation(location);

	////std::cout << event.getLocation() << std::endl;
	//
	//event.setNoOfRows(5);
	//event.setNoOfColumns(6);

	//event.initialiseOccuppiedSeats(event.getNoOfRows(), event.getNoOfColumns());
	//event.setOccuppiedSeats(21);
	//char* array = new char[event.getNoOfRows() * event.getNoOfColumns()];
	//array = event.getOccupiedSeats();

	//for (int i = 1; i <= event.getNoOfRows() * event.getNoOfColumns(); i++) {
	//	std::cout << i << '(' << array[i] << ')' << ' ';
	//	if (i % event.getNoOfColumns() == 0) {
	//		std::cout << std::endl;
	//	}
	//}

	_getch();
}