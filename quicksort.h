#ifndef __quicksort__
#define __quicksort__

#include <iostream>
#include <vector>

using namespace std;

namespace anon
{
    size_t partition(vector<int>& v, int left, int right);
    void quicklysort(vector<int>& v, int left, int right);
}

void quicksort(vector<int>& v);

#endif
