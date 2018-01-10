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
    void merge(T *a, int na, const T *b, int nb, T *c) {
            int ia = 0, ib=0, ic=0;
        while (ia < na && ib < nb)
            c[ic++] = (a[ia] < b[ib] ? a[ia++] : b[ib++]);
        while (ia < na) c[ic++] = a[ia++];
        while (ib < nb) c[ic++] = a[ib++];
    }

    template <class T>
    void MergeSort(T *a, int n) {
        if (n < 2) return;
        int nLeft = n/2, nRight = n-nLeft;
        MergeSort(a, nLeft);
        MergeSort(a + nLeft, nRight);
        T *p = new T[n];
        merge(a, nLeft, a + nLeft, nRight, p);
        for (int i = 0; i < n; i++) a[i] = p[i];
        delete[] p;
    }

} // namespace

#endif //C_EXPERIMENTS_QUICKSORT_H
