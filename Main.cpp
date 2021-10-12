#include <iostream>
#include <vector>
#include <string>
#include "StringData.h"

int linearSearch(std::vector<std::string> dataSet, std::string element){
    for (int i = 0; i < dataSet.size(); ++i) {
        if(dataSet[i] == element) return i;
    return -1;
    }
}

int binarySearch(std::vector<std::string> dataSet, std::string element){
    int bottom = 0;
    int top = dataSet.size() - 1;
    int mid;
    int compare;
    while(bottom <= top) {
        mid = (bottom + top) / 2;
        compare = dataSet[mid].compare(element);
        if (compare==0) return mid;
        else if (compare > 0) top = mid-1;
        else if (compare < 0) bottom = mid+1;
    }
    return -1;
}

int main() {
    std::string element = "not_here";
    long start;
    int index;
    long end;
    std::vector<std::string> data = getStringData();

    std::cout << "Searching for data using Linear Search\n";
    start = systemTimeNanoseconds();
    index = linearSearch(data, element);
    end = systemTimeNanoseconds();
    std::cout << "Time: " << (end - start) << "\n";

    std::cout << "Searching for data using Binary Search\n";
    start = systemTimeNanoseconds();
    index = binarySearch(data, element);
    end = systemTimeNanoseconds();
    std::cout << "Time: " << (end - start);

    return 0;
}
