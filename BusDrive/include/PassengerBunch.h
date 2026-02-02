#pragma once

#include <array>
#include <memory>

#include "Passenger.h"

class PassengerBunch {
private:
	static constexpr int MAX_PASSENGERS{ 10 };

	std::array<std::shared_ptr<Passenger>, MAX_PASSENGERS> passengers;

	std::shared_ptr<Passenger> _control;

	bool _isControlInside{ false };

	int nextPassenger{ 0 };

	int _totalPassengers{ 0 };
	int _totalFines{ 0 };

	std::shared_ptr<Passenger> _currentPassenger{ nullptr };

public:

	const std::shared_ptr<Passenger>& currentPassenger { _currentPassenger };

	PassengerBunch() {
		for (std::shared_ptr<Passenger>& p : passengers) {
			p = std::make_shared<Passenger>();
		}

		_control = std::make_shared<Passenger>();
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