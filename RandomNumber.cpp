#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()


// pseudo-random number generator
unsigned int PRNG()
{
    // our initial starting seed is 5323
    static unsigned int seed = 5323;
    
    // Take the current seed and generate a new value from it
    // Due to our large constants and overflow, it would be
    // hard for someone to casually predict what the next number is
    // going to be from the previous one.
    seed = 8253729 * seed + 2396403;
    
    // Take the seed and return a value between 0 and 32767
    return seed % 32768;
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
// Assumes max-min <= RAND_MAX
int getRandomNumber(int min, int max)
{
    // static used for efficiency, so we only calculate this value once
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    
    return min + static_cast<int>((max - min + 1) *(rand() * fraction));

}
