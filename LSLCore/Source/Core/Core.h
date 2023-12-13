#pragma once
#include <filesystem>

namespace LSLCore {
	void StartLSLStream(int nChannels);
	void SimulateLSLStream(int nChannels, std::filesystem::path path);
}