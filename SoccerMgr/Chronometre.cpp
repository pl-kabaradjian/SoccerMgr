#include "Chronometre.h"

double chronometre::elapsed_time(std::chrono::time_point<std::chrono::system_clock> start)
{
	return std::chrono::duration<double, milli>(std::chrono::system_clock::now() - start).count();
}
