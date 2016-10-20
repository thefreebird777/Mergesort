#include "Shellsort.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

Shellsort::Shellsort()
{
    delimits.push_back(524287);
    delimits.push_back(262143);
    delimits.push_back(131071);
    delimits.push_back(65535);
    delimits.push_back(32767);
    delimits.push_back(16383);
    delimits.push_back(8191);
    delimits.push_back(4095);
    delimits.push_back(2047);
    delimits.push_back(1023);
    delimits.push_back(511);
    delimits.push_back(255);
    delimits.push_back(127);
    delimits.push_back(63);
    delimits.push_back(31);
    delimits.push_back(15);
    delimits.push_back(7);
    delimits.push_back(3);
    delimits.push_back(1);
}
vector<long> delimits;

vector<long> Shellsort::sort(vector<long> & arr)
{
    long arrSize = arr.size(); //determines length of array
    long delimitSize = 19; 
    for(int i = 0; i < delimitSize; i++)
    {
        // first gap already figured out
        long width = delimits[i];
        if(width < arrSize-1)
        {
            for(int j = width-1; j < arrSize; j++)
            {
                swap(arr, j, width); // recursively swap
            }
        }
    }
    return arr;
}

void Shellsort::swap(vector<long> & arr, long j, long width)
{
    if(j-width >= 0)
    {
        if(compare(arr[j-width], arr[j]) == 1) //a is larger than b
        {
            long temp = arr[j];
            arr[j] = arr[j-width];
            arr[j-width] = temp;
            swap(arr, j-width, width); // recursively swap
        }
    }
}

int Shellsort::compare(long a, long b)
{
    if(a > b)
        return 1;
    if(a == b)
        return 0;
    else
        return -1;
}
