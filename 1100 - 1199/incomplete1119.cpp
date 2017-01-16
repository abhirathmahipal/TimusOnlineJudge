#include <iostream>
#include <algorithm>


int main()
{
    int westeastsize, northsouthsize, diagnolcount;
    cin >> westeastsize >> northsouthsize >> diagnolcount;

    // Do we even need the points which can 
    // be crossed diagnolly? 
    // We anyways have a rough distance from home to 
    // station. Why not just optimise it with the
    // number of points that can be crossed diagnolly?

    // If we follow across the sides and reach the station
    // that would result in a distance of (N + M) * 100
    // We can try by just using the number of steps that 
    // can be crossed diagonally. Some diagonals are probably
    // going to be missed if some are taken





    return 0;
}
