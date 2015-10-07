#ifndef TEMPLATE_H
#define TEMPLATE_H

template <class T>
class Arrays{
    private:
        int cols;
        int *d1ary;
        T **d2ary;
    public:
        Arrays(T);
        ~Arrays();
        void filD1ary();
        void filD2ary();
        void prntD1ary();
        void prntD2ary();

};

#endif // TEMPLATE_H
