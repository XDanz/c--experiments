//
// Created by danter on 2018-01-10.
//

#ifndef C_EXPERIMENTS_MERGESORT_H
#define C_EXPERIMENTS_MERGESORT_H

namespace sort {
    void pp(int n) {
        for (int j=0; j<n;j++) std::cout << "**";
    }
    template <class T>
    void print(T *a, int n, int t) {
        pp(t);
        std::cout << " [ ";
        for (int i=0; i < n;i++) {
            if (i+1 < n)
                std::cout << a[i] << ",";
            else
                std::cout << a[i];
        }

        std::cout << " ]" << std::endl;
    }
    template <class T>
    void merge(const T *a, int na, const T *b, int nb, T *c, int t) {
        pp(t);
        std::cout << "merge() a:";
        print(a, na,t);
        std::cout << "        b:";
        print(b, nb,t);
        int ia = 0, ib=0, ic=0;
        while (ia < na && ib < nb)
            c[ic++] = (a[ia] < b[ib] ? a[ia++] : b[ib++]);
        while (ia < na) c[ic++] = a[ia++];
        while (ib < nb) c[ic++] = b[ib++];

        std::cout << "res: c:";
        print(c, ic,t);

    }

    template <class T>
    void MergeSort(T *a, int n, int t) {
        pp(t);
        std::cout << "MergeSort() a:";
        print(a, n,t);
        if (n < 2) return;
        int nLeft = n/2, nRight = n-nLeft;
        MergeSort(a, nLeft,t+1);
        MergeSort(a + nLeft, nRight,t+1);
        T *p = new T[n];
        merge(a, nLeft, a + nLeft, nRight, p, t+1);
        for (int i = 0; i < n; i++) a[i] = p[i];
        delete[] p;
    }

}


#endif //C_EXPERIMENTS_MERGESORT_H
