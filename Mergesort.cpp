#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

vector <long> vec;

void merge(vector<long> vec, long start, long mid, long end, vector<long> temp); 

void mergesort(vector<long> vec){
	vector<long> temp;
	for (int width = 1; width < vec.size(); width  = 2 * width){
		for(int i = 0; i < vec.size(); i = i + 2 * width){
			long start = i;
			long mid = i + (width - 1);
			if (mid >= vec.size()){
				mid = vec.size() - 1;
			}
			long end = i + ((2* width) - 1);
			if(end >= vec.size()){
				end = vec.size() - 1;
			}
			merge(vec, start, mid, end, temp);
		}
		for (int j = 0; j < vec.size(); j++){
			vec[j] = temp[j];
		}
	}

}

void merge(vector<long> vec, long start, long mid, long end, vector<long> temp){
	long i = start;
	long j = mid;
	long k = start;
	while ((i <= mid) && (j <= end)){
		if (vec[i] <= vec[j]){
			temp[k] = vec[i];
			i++;
		}else{
			temp[k] = vec[j];
			j++;
		}
		k++;
	}
	while (i <= mid){
		temp[k] = vec[i];
		i++;
		k++;		
	}
	while (j <= end){
		temp[k] = vec[j];
		j++;
		k++;
	}
	
}

int main(){
        string line;
        long num;
        ifstream input ("inData.txt");
        if (input.is_open()){
               while (getline (input, line))
                {
                        num = atoi(line.c_str());
                        vec.push_back (num);
                }
                input.close();
       	}else{
		cout << "Unable to open file";
        }
        mergesort(vec);
        ofstream output;
        output.open ("outData.txt");      
	copy(vec.begin(), vec.end(), ostream_iterator<long>(output, "\n"));
	output << endl;

	output.close();
        return 0;
}

