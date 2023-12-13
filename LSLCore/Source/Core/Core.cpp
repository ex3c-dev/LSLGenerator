#include "Core.h"
#include <chrono>
#include "lsl_cpp.h"
#include <thread>
#include <iostream>

namespace LSLCore {

	void StartLSLStream(int nChannels)
	{
		lsl::stream_info info("SimpleStream", "EEG", nChannels);
		lsl::stream_outlet outlet(info);

		while (!outlet.wait_for_consumers(120))
			;

		float* sample{ new float[nChannels] {} };

		while (outlet.have_consumers())
		{
			// Generate random data
			for (int c = 0; c < nChannels; c++)
			{
				sample[c] = (float)((rand() % 1500) / 500.0 - 1.5);
			}
			// Send the data
			outlet.push_sample(sample);
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}
	}

	void SimulateLSLStream(int nChannels, std::filesystem::path path)
	{
		lsl::stream_info info("type", "EEG", nChannels);
		lsl::stream_outlet outlet(info);

		while (!outlet.wait_for_consumers(120))
			;

		float* sample{ new float[nChannels] {} };

		while (outlet.have_consumers())
		{
			// Todo: Read filepath and extract data from csv file
			for (int c = 0; c < nChannels; c++)
			{
				sample[c] = (float)((rand() % 1500) / 500.0 - 1.5);
			}
			// Send the data
			outlet.push_sample(sample);
			std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}
	}

}