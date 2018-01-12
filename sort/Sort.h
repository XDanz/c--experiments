//
// Created by danter on 2018-01-11.
//

#ifndef C_EXPERIMENTS_SORT_H
#define C_EXPERIMENTS_SORT_H
namespace sort {
    
    template <class T>
    inline void swap0(T *a , int i, int j) 
    {
        int w = a[i];
        a[i] = a[j];
        a[j] = w;
    }

    template <class T>
    inline void swap3(T &x, T &y, T &z)
    {
        T w = x;
        x = y;
        y = w;
    }


}
#endif //C_EXPERIMENTS_SORT_H
