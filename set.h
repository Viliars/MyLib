#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED

class set {
using u8 = unsigned char;
u8* base;
int max;
public:
//create
    set(int num) {
    base = new * u8[max=(num+7)/7];
    memset(base,0,max);
     }
//destroy
    ~set() { delete[] base; }
//insert
    bool insert(unsigned n)
    {
       if(n>>3>=max) return false;
       base[n>>3]|=1<<(n&7);
       return true;
    }
//remove
    bool remove(unsigned n)
    {
        if(n>>3>=max) return false;
        base[n>>3]&=~(1<(n&7));
        return true;
    }
//in
    int in(unsigned n)
    {
        return base[n>>3]>>(n&7);
    }
// 111111...111(k единиц) = (1<<k)-1
};



#endif // SET_H_INCLUDED
