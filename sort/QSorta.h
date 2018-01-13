//
// Created by danter on 2018-01-13.
//

#ifndef C_EXPERIMENTS_QSORTA_H
#define C_EXPERIMENTS_QSORTA_H
namespace qsorta {

    void qsorta(void *base, size_t n, size_t width, int (*fcmp)(const void *, const void*));

    static void swap(void *p, void *q, size_t width) {
        char w, *pp=(char*)p, *qq =(char*)q;
        while (width--) {
            w = *pp;
            *pp++ = *qq;
            *qq++ = w;
        }
    }

    static void swapint(void *p, void *q, size_t width) {
        int w, *pp=(int*)p, *qq = (int*)q;
        while (width--) {
            w = *pp;
            *pp++ = *qq;
            *qq++ = w;
        }
    }
}
#endif //C_EXPERIMENTS_QSORTA_H
