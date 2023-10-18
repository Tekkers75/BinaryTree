// @author Саранчин К.А.
#pragma once
#include <iostream>


template <typename T>
class AbstractIterator {
public:
    virtual T& operator*() = 0;
    virtual AbstractIterator<T>& operator++() = 0;
    virtual AbstractIterator<T>& operator++(int) = 0;
    virtual bool operator==(const AbstractIterator<T>& other) = 0;
    virtual bool operator!=(const AbstractIterator<T>& other) = 0;
    virtual ~AbstractIterator() {}
};
