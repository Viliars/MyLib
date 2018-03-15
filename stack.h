#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


class stack {
   int * char;
   int max;
   int size;
public:
// create
    stack(int num = 1000) { base = new char [max=num]; }
// destroy
    ~stack() { delete[] base; }
//push
    bool push (int elem) {
        if(size>=max) return false;
        //assept(size<max);
        base[size++]=elem;
        return true;
    }
//pop
    bool pop(int& elem) {
        if(size<=0) return false;
        elem=base[--size];
        return true;
    }
//empty
    bool empty() { return size<=0; }
};



#endif // STACK_H_INCLUDED
