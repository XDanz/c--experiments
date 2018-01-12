//
// Created by danter on 2018-01-10.
//

#ifndef C_EXPERIMENTS_MERGESORT_H
#define C_EXPERIMENTS_MERGESORT_H

namespace sort {
    std::string pp(int n) {
        std::string str = "";
        for (int j=0; j<n;j++) str.append(" * * ");
        return str;
    }

    template <class T>
    std::string toString(T *a, int n) {
        std::string c = "[";

        for (int i=0; i < n;i++) {
            c.append(std::to_string(a[i]));
            if (i+1 < n)
                c.append(",");
            else
                c.append("]");
        }

        return c;
    }

    template <class T>
    void print(T *a, int n, int t, std::string& val) {
        std::cout << pp(t).append(val).append(toString(a,n)) << std::endl;
    }

    void print(int t, const char* val) {
        std::cout << pp(t).append(val) << std::endl;
    }

    template <class T>
    void print(T *a, int n, int t, const char* str) {
        std::string s = str;
        print(a, n, t, s);
    }
    template <class T>
    void merge(const T *a, int na, const T *b, int nb, T *c, int t) {
        print(a, na, t, "merge() a:");
        print(b, nb, t, "        b:");
        int ia = 0, ib=0, ic=0;
        while (ia < na && ib < nb)
            c[ic++] = (a[ia] < b[ib] ? a[ia++] : b[ib++]);
        while (ia < na) c[ic++] = a[ia++];
        while (ib < nb) c[ic++] = b[ib++];
        print(c, ic, t, "        c:");
    }

    template <class T>
    void MergeSort(T *a, int n, int t) {
        print(a, n, t, "MergeSort() a:");
        if (n < 2) {
            print(a, n, t, "return:");
            return;
        }
        int nLeft = n/2, nRight = n-nLeft;
        MergeSort(a, nLeft, t+1);
        MergeSort(a + nLeft, nRight, t+1);

        char buf[10];
        std::sprintf(buf, "new T[%d]", n);
        print(t, buf);
        T *p = new T[n];
        merge(a, nLeft, a + nLeft, nRight, p, t);
        for (int i = 0; i < n; i++) a[i] = p[i];
        delete[] p;
    }
    template <class T>
    void MergeSort(T *a, int n) {
        MergeSort(a, n, 1);
    }

}


#endif //C_EXPERIMENTS_MERGESORT_H
