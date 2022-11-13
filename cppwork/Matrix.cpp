// Practice operator overloading

#include <cassert>
#include <vector>

class Matrix {
public:
    Matrix(int rows, int columns) : rows_(rows), columns_(columns), values_(rows * columns) {}
    int& operator()(int row, int column) {
        return values_[row*columns_ + column];
    }
    int operator()(int row, int column) const {
        return values_[row*columns_ + column];
    }
    Matrix operator+(Matrix& m) const {
        if (m.rows_*m.columns_ != this->rows_*this->columns_)
            throw std::length_error("The two matrixes have different sizes");

        Matrix result(m.rows_, m.columns_);
        for (int it = 0; it < m.rows_*m.columns_; it++) {
            result.values_[it] = this->values_[it] + m.values_[it];
        }
        return result;
    }
private:
    int rows_;
    int columns_;
    std::vector<int> values_;
};


int main()  {
    Matrix m1(1, 1);
    m1(0, 0) = 35;
    assert(m1(0, 0) == 35);
    Matrix m2(1, 1);
    m2(0, 0) = 15;
    Matrix m3(0, 0); // The matrix will be expanded anyway when using the [] operator while assignemnt (like push_back)
    m3 = m1 + m2;
    assert(m3(0, 0) == m1(0, 0) + m2(0, 0));
}
