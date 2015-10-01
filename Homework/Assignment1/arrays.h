#ifndef TEMPLATE_H
#define TEMPLATE_H


class Arrays{
    private:
        int cols;
        int *d1ary;
        int **d2ary;
    public:
        Arrays(int);
        ~Arrays();
        void filD1ary();
        void filD2ary();
        void prntD1ary();
        void prntD2ary();

};

#endif // TEMPLATE_H
