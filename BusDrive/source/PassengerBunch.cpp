#include "../include/PassengerBunch.h"

void
PassengerBunch::boardOne() {
	if (_totalPassengers < MAX_PASSENGERS && _currentPassenger ==  nullptr) {
		_totalPassengers++;
		_currentPassenger = passengers.at(nextPassenger);
		nextPassenger++;
		_currentPassenger->startBoarding();
	}
}

void
PassengerBunch::disembarkOne() {

	int lowerLimit = _isControlInside ? 1 : 0;

	if (_totalPassengers > lowerLimit && _currentPassenger == nullptr) {
		_totalPassengers--;
		_currentPassenger = passengers.at(nextPassenger - 1);
		nextPassenger--;
		_currentPassenger->startDisembarking();
	}
}

void
PassengerBunch::boardControl() {
	if (!_isControlInside && _totalPassengers < MAX_PASSENGERS && _currentPassenger == nullptr) {
		_totalPassengers++;
		_isControlInside = true;
		_currentPassenger = _control;
		_currentPassenger->startBoarding();
	}
}

void
PassengerBunch::disembarkControl() {
	if (_isControlInside && _totalPassengers > 0 && _currentPassenger == nullptr) {
		_totalPassengers--;
		_isControlInside = false;
		_totalFines += randomNumber(totalPassengers);
		_currentPassenger = _control;
		_currentPassenger->startDisembarking();
	}
}

void PassengerBunch::pollMotionFinish() {
	if (_currentPassenger != nullptr) {
		if (_currentPassenger->state == PASG_BOARDED || _currentPassenger->state == PASG_UNBOARDED) {
			_currentPassenger = nullptr;
		}
	}
}