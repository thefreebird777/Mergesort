#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

vector<long> vec;

void merge(vector<long>& vec, int left, int mid, int right, vector<long>& temp);

int min(int a, int b) {
    return (a <= b) ? a : b; //returns minimum of two numbers
}

void copy(vector<long>& temp, vector<long>& vec, int n)
{
    for(int i = 0; i < n; i++)
        vec[i] = temp[i]; //
}

void mergesort(vector<long>& vec, vector<long>& temp, int n) {
    //each run though the loop the width is doubled until it reaches the original length
    for (int width = 1; width < n; width = 2 * width)
    {
        for (int i = 0; i < n; i = i + 2 * width)
        {
            merge(vec, i, min(i+width, n), min(i + 2 * width, n), temp);
        }
        copy(temp, vec, n);
    }
}

void merge(vector<long>& vec, int left, int mid, int right, vector<long>& temp) {

    int leftEnd = mid - 1;
    int tempP = left;
    int num = right - left + 1;
    while ((left <= leftEnd) && (mid <= right)) {
        if (vec[left] <= vec[mid]) {
            temp[tempP++] = move(vec[left++]);
        } else {
            temp[tempP++] = move(vec[mid++]);
        }
    }
    while (left <= leftEnd) {
        // copying first half of vector
        temp[tempP++] = move(vec[left++]);
    }
    while (mid <= right) {
        //copying second half of vector
        temp[tempP++] = move(vec[mid++]);
    }
    for (int i = 0; i < num; i++, right--) {
        //copying back
        vec[right] = move(temp[right]);
    }
}

int main() {
    string line;
    long num;
    ifstream input("inData.txt");
    if (input.is_open()) {
        while (getline(input, line)) {
            num = atoi(line.c_str());
            vec.push_back(num);
        }
        input.close();
    } else {
        cout << "Unable to open file";
    }
    vector<long> temp(vec.size());
    mergesort(vec, temp, vec.size());
    ofstream output;
    output.open("outData.txt");
    //output sorted vector to text file
    copy(vec.begin(), vec.end(), ostream_iterator<long>(output, "\n"));
    output << endl;
    output.close();
    return 0;
}

