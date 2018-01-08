//
// Created by danter on 2018-01-07.
//

#ifndef C_EXPERIMENTS_QUICKSORT_H
#define C_EXPERIMENTS_QUICKSORT_H

namespace sort {

    template <class T>
    void swap0(T *a , int i, int j) {
        int w = a[i];
        a[i] = a[j];
        a[j] = w;

    }
    template <class T>
    void qsort(T *a , int n)
    {
        int i = 0;
        int j = n - 1;
        T x = a[j/2], w;
        do
        {
            while(a[i] < x) i++;
            while (a[j] > x) j--;
            if (i < j) {
                swap0(a, i, j);
            }
            else {
                if (i == j) {
                    i++;
                    j--;
                }
                break;
            }

        } while (++i <= --j);
        if (j > 0) qsort(a, j+1);
        if (i < n-1) qsort(a+i, n - i);

    }

} // namespace

#endif //C_EXPERIMENTS_QUICKSORT_H
