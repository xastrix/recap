#include "config.h"
#include "utils.h"

#include <recorder.h>

void print_usage()
{
	printf("recap - Quick and easy to use screen video recording utility\n\n");

	printf("Usage\n");
	printf("  recap <filename.mp4> <ms> [options]\n");

	printf("Options\n");
	printf("  --no-cursor     Don't record the cursor\n");
}

RECORDER_STATUS wmain(int argc, const wchar_t** argv)
{
	if (argc < 3) {
		print_usage();
		return 1;
	}

	desk_capture_params_t dp;

	dp.path   = argv[1];
	dp.fps    = DEFAULT_FPS;
	dp.cursor = DEFAULT_CURSOR_ENABLE;
	dp.ms     = utils::convertTimeStringToInt(argv[2]);

	for (int i = 3; i < argc; ++i) {
		std::wstring arg{ argv[i] };
		if (arg == L"--no-cursor") {
			dp.cursor = false;
		}
		else {
			print_usage();
			return 1;
		}
	}

	wprintf(L"Recording. (%ls)\n", argv[2]);

	return __recorder_handle(dp);
}