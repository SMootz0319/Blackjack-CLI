#include <cstdlib> // for rand() and srand()

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
// Assumes max-min <= RAND_MAX
int getRandomNumber(int min, int max)
{
    // static used for efficiency, so we only calculate this value once
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    
    return min + static_cast<int>((max - min + 1) *(rand() * fraction));

}
