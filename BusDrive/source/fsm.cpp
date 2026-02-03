#include "../include/fsm.h"
#include "../include/globals.h"

void doFSMLoop() {
	g_bus.doStateStep();
	if (g_bunch.boardingPassengers.empty() == false) {
		for (auto p : g_bunch.boardingPassengers) {
			p->doStateStep();
		}
	}
	if (g_bunch.disembarkingPassengers.empty() == false) {
		for (auto p : g_bunch.disembarkingPassengers) {
			p->doStateStep();
		}
	}

	g_bunch.pollMotionFinish();

}