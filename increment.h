#ifndef INCREMENT_H
#define INCREMENT_H


class Increment
{
private:
    int num;
public:
    Increment(int n);

    // This operator overloading enables calling
    // operator function () on objects of increment
    int operator () (int arr_num) const {
        return num + arr_num;
    }
};

#endif // INCREMENT_H
