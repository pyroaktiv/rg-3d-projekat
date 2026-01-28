#include "../include/fsm.h"
#include "../include/globals.h"

void doFSMLoop() {
	g_bus.doStateStep();
	if (g_bunch.currentPassenger != nullptr)
		g_bunch.currentPassenger->doStateStep();

	g_bunch.pollMotionFinish();

}