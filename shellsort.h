#ifndef _SHELLSORT_H_
#define _SHELLSORT_H_
#include <string>
#include <vector>
using namespace std;

class Shellsort
{
public:
	Shellsort();
	vector<long> sort(vector<long> & arr);

private:
	void swap(vector<long> & arr, long j, long width);
	int compare(long a, long b);
	vector<long> delimits;
};

#endif