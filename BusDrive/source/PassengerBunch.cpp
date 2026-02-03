#include "../include/PassengerBunch.h"

void
PassengerBunch::boardOne() {
	if (_totalPassengers < MAX_PASSENGERS && disembarkingPassengers.empty() == true && _isControlInside == false) {
		_totalPassengers++;
		boardingPassengers.push_back(passengers.at(nextPassenger));
		nextPassenger++;
		boardingPassengers.back()->startBoarding();
	}
}

void
PassengerBunch::disembarkOne() {

	int lowerLimit = _isControlInside ? 1 : 0;

	if (_totalPassengers > lowerLimit && boardingPassengers.empty() == true && _isControlInside == false) {
		_totalPassengers--;
		disembarkingPassengers.push_back(passengers.at(nextPassenger - 1));
		nextPassenger--;
		disembarkingPassengers.back()->startDisembarking();
	}
}

void
PassengerBunch::boardControl() {
	if (!_isControlInside && _totalPassengers < MAX_PASSENGERS && disembarkingPassengers.empty() == true) {
		_totalPassengers++;
		_isControlInside = true;
		boardingPassengers.push_back(_control);
		boardingPassengers.back()->startBoarding();
	}
}

void
PassengerBunch::disembarkControl() {
	if (_isControlInside && _totalPassengers > 0 && boardingPassengers.empty() == true) {
		_totalPassengers--;
		_isControlInside = false;
		_totalFines += randomNumber(totalPassengers);
		disembarkingPassengers.push_back(_control);
		disembarkingPassengers.back()->startDisembarking();
	}
}

void PassengerBunch::pollMotionFinish() {
	if (boardingPassengers.empty() == false) {
		if (boardingPassengers.front()->state == PASG_BOARDED) {
			boardingPassengers.pop_front();
		}
	}
	if (disembarkingPassengers.empty() == false) {
		if (disembarkingPassengers.front()->state == PASG_UNBOARDED) {
			disembarkingPassengers.pop_front();
		}
	}
}