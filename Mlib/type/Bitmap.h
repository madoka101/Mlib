#pragma once
#include <stdint.h>
#include <bitset>

#include "Mlib/common/Lock.h"

static const size_t mask16[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4 };

class Bitmap {
public:
    Bitmap();
    template<typename T> 
    Bitmap(T in);

    inline bool checkEmpty() { return _map == 0; }
    inline bool checkFull() { return _map == UINT64_MAX; } 
    inline size_t count();
    inline bool check(int idx);
    inline void set(int idx, bool t);
    inline Bitmap operator= (const Bitmap& rhs){
        
    }
private:
    uint64_t _map;
private:
    
};

template<typename T>
Bitmap::Bitmap(T in) {
    
}

size_t Bitmap::count() {
    uint64_t tmap=_map;
    size_t res=0;
    while(tmap){
        res += mask16[tmap&15];
        tmap = tmap>>4;
    }
    return res;
}

typedef std::shared_ptr<Bitmap> BitmapPtr;

#define indexLevel2Num 64

class LargeBitmap {
public:
    template<typename T>
    explicit LargeBitmap(T in, size_t count);
    template<typename T, typename Alloc>
    explicit LargeBitmap(T in, size_t count, Alloc *allocator);

    inline bool check(int idx);
    inline void set(int idx, bool t);

    LargeBitmap& operator= (const LargeBitmap &rhs);
    LargeBitmap& operator== (const LargeBitmap &rhs);
    LargeBitmap& operator& (const LargeBitmap &rhs);
    LargeBitmap& operator| (const LargeBitmap &rhs);
    LargeBitmap& operator>> (int m);
    LargeBitmap& operator<< (int m);

private:
    inline int convertIdx(int idx);
private:
    uint64_t indexLevel2[indexLevel2Num];
    uint64_t *_map;
};

typedef std::shared_ptr<LargeBitmap> LargeBitmapPtr;

int LargeBitmap::convertIdx(int idx) {
    
}

#undef indexLevel2Num 