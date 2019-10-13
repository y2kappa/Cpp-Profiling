#include <vector>
#include "bubblesort.h"

using namespace std;

void bubblesort(vector<int>& v)
{
    for (size_t i = 0; i < v.size() - 1; ++i)
        for(size_t j = i+1; j < v.size(); ++j)
            if (v[i] > v[j])
                swap(v[i],v[j]);
}
