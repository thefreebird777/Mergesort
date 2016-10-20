#include "Shellsort.h"
#include <vector>
#include <stdlib.h>

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{

	ifstream myfile;
  	myfile.open (argv[0] + ".txt");
  	cout << "Writing this to a file.\n" << endl;
  	vector<long> data;
  	long number;
  	myfile >> number;
  	cout << number << endl;
  	int k = 0;
  	while(!myfile.eof() && k < 3)
  	{
  		myfile >> number;
  		cout << number << endl;
  		k++;
  	}
  	// not working

  	myfile.close();

  	/*int k = 0;
  	while(k < 10000)
  	{
  		int v1 = (rand() % 100) * 100000 * (rand() % 100) + (rand() % 100) + (rand() % 1000);
  		data.push_back(v1);
  		k++;
  	}*/

  	Shellsort * shell = new Shellsort();

  	vector<long> arr = shell->sort(data);

  	int i = 0;
  	while(i < data.size()-1)
  	{
  		cout << arr[i] << endl;
  		i++;
  	}

}