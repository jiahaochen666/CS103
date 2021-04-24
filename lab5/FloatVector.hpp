#ifndef LA5_FLOATVECTOR_HPP
#define LA5_FLOATVECTOR_HPP

class FloatVector {
private:
    float* elem;
    int sz, cap;
public:
    FloatVector(int s);
    ~FloatVector();

    void insert(float e);
    float& operator[](int i);
    int size() const;
};


FloatVector::FloatVector(int s) : elem(new float[s]), sz(0), cap(s) {}

FloatVector::~FloatVector() {
    delete elem;
}

void FloatVector::insert(float e) {
    elem[sz++] = e;
}

float& FloatVector::operator[](int i) {
    return elem[i];
}

int FloatVector::size() const {
    return sz;
}


#endif //LA5_FLOATVECTOR_HPP
