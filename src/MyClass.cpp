#include "MyClass.h"

MyClass::MyClass(int value) : m_value(value) {}

int MyClass::get_value() const {
    return m_value;
}