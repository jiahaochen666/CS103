#ifndef LA5_VECTOR_HPP
#define LA5_VECTOR_HPP

template <typename T>
class Vector{
private:
    T* elem;
    int sz, cap;
public:
    Vector(int s);
    ~Vector();

    void insert(T e);
    T& operator[](int i);
    int size() const;
};

template<typename T>
Vector<T>::Vector(int s): elem(new T[s]), sz(0), cap(s) {}

template<typename T>
Vector<T>::~Vector() {
    delete[] elem;
}

template<typename T>
void Vector<T>::insert(T e) {
    elem[sz++] = e;
}

template<typename T>
T &Vector<T>::operator[](int i) {
    return elem[i];
}

template<typename T>
int Vector<T>::size() const {
    return sz;
}

#endif