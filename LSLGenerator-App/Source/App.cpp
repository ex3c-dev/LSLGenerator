#include "Core/Core.h"
#include <iostream>

int main()
{
	std::cout << "Starting EEG Simulation...." << std::endl;
	LSLCore::StartLSLStream(64);
}