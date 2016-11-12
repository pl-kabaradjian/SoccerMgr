#ifndef _CHRONOMETRE_H
#define _CHRONOMETRE_H

#include <chrono>
using namespace std;

class chronometre {
public:
	static double elapsed_time(std::chrono::time_point<std::chrono::system_clock> start);
};
#endif // !_CHRONOMETRE_H

