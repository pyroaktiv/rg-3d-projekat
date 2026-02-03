#pragma once

#include <array>
#include <memory>
#include <deque>

#include "Passenger.h"

class PassengerBunch {
private:
	static constexpr int MAX_PASSENGERS{ 50 };

	std::array<std::shared_ptr<Passenger>, MAX_PASSENGERS> passengers;

	std::shared_ptr<Passenger> _control;

	bool _isControlInside{ false };

	int nextPassenger{ 0 };

	int _totalPassengers{ 0 };
	int _totalFines{ 0 };

public:

	std::deque<std::shared_ptr<Passenger>> boardingPassengers;
	std::deque<std::shared_ptr<Passenger>> disembarkingPassengers;

	PassengerBunch() {
		for (std::shared_ptr<Passenger>& p : passengers) {
			p = std::make_shared<Passenger>();
		}

		boardingPassengers = {};
		disembarkingPassengers = {};

		_control = std::make_shared<Passenger>();
		_control->isControl = true;
	}

	const bool& isControlInside{ _isControlInside };

	const int& totalPassengers{ _totalPassengers };
	const int& totalFines{ _totalFines };

	void boardOne();
	void disembarkOne();
	void boardControl();
	void disembarkControl();

	void pollMotionFinish();
};