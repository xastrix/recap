#ifndef RECORDER_H
#define RECORDER_H

#include <string>

#define RECORDER_EXPORT __declspec(dllexport)

using RECORDER_STATUS = int;

struct desk_capture_params_t {
	std::wstring path;
	int fps;
	bool cursor;
	unsigned long long ms;
};

RECORDER_STATUS RECORDER_EXPORT __recorder_handle(desk_capture_params_t& dp);

#endif /* RECORDER_H */