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
            while (a[i] < x) i++;
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

    template <class T>
    void qsort2(T *a, int n) {
        int i, j;
        T x, w;

        do
        {
            i = 0;
            j = n - 1;
            x = a[j/2];
            do {
                while (a[i] < x) i++;
                while (a[j] > x) j--;
                if (i < j) {
                    swap0(a, i, j);
                } else {
                    if (i == j) {
                        i++;
                        j--;
                    }
                    break;
                }
            } while (++i <= --j);

            if (j+1 < n-i)
            {
                if (j > 0) qsort2(a, j+1);
                a += i;
                n -= i;
            } else {
                if (i < n-1) qsort2(a+i, n-i);
                n = j + 1;
            }

        } while (n > 1);
    }

} // namespace

#endif //C_EXPERIMENTS_QUICKSORT_H
