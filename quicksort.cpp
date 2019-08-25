#include "quicksort.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

namespace anon 
{
    size_t partition(vector<int>& v, int left, int right)
    {
        if (right < 0 || left >= v.size()) {
            throw out_of_range("Out of range");
        }
        if (v.empty())
        {
            throw invalid_argument("Empty vector");
        }
        if (left > right)
        {
            throw invalid_argument("Left greater than right");
        }
        

        int i = left;
        int j = right;
        int pivot = v[(left + right)/2];
        
        while (i <= j)
        {
            while (v[i] < pivot) ++i;
            while (v[j] > pivot) --j;
            if (i <= j) 
            {
                swap(v[j], v[i]);
                j--;
                i++;
            }
        }

        return i;
    }

    void quicklysort(vector<int>& v, int left, int right)
    { 
        int middle = partition(v, left, right);    
        if (left < middle - 1)
            quicklysort(v, left, middle - 1);
        if (right > middle)
            quicklysort(v, middle, right);
    }
}

using namespace anon;

void quicksort(vector<int>& v)
{
    size_t n = v.size();
    quicklysort(v, 0, n - 1); 
}

