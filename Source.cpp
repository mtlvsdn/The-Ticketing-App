//#define _CRTSECURE_NO_WARNINGS
#include "header.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <ctime>
//#include <hpdf.h>

int main() {
	Event event;
	event.chooseEvent();
	//std::cout << std::endl << event.getName();
	event.setNoOfRows(4);
	event.setNoOfColumns(5);

	event.initialiseOccuppiedSeatsCategory1(event.getNoOfRows(), event.getNoOfColumns());
	event.initialiseOccuppiedSeatsCategory2(event.getNoOfRows(), event.getNoOfColumns());
	event.selectBetweenTheTwoCategories();
}