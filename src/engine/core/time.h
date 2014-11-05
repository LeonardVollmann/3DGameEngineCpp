#ifndef TIME_H
#define TIME_H

#include <chrono>

static const std::chrono::time_point<std::chrono::high_resolution_clock> epoch = std::chrono::high_resolution_clock::now();

namespace Time
{
    inline double getTime()
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - epoch).count() / 1000000000.0;
    }
}

#endif
