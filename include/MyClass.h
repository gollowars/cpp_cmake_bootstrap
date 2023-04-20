#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
public:
    MyClass(int value);
    int get_value() const;

private:
    int m_value;
};

#endif