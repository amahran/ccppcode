#include "cassert"
#include <stdexcept>

class Pyramid {
public:
    Pyramid(int l, int w, int h) : length_(l), width_(w), height_(h) {
        Validate();
    }
    int Length() const { return length_; }
    int Width() const {return width_; }
    int Height() const { return height_; }
    void Length(int l) { 
        length_ = l;
        Validate();
    }
    void Width(int w) { 
        width_ = w;
        Validate();
    }
    void Height(int h) { 
        height_ = h;
        Validate();
    }
    float Volume() const { return ((Length() * Width() * Height()) / 3); }
private:
    int length_;
    int width_;
    int height_;
    void Validate() {
        if (length_ < 0 || width_ < 0 || height_ <0)
            throw std::invalid_argument("Negative dimention!");
    }
};


int main() {
    bool caught{false};
    try {
        Pyramid p(4, 5, 6);
        assert(p.Length() == 4);
        assert(p.Width() == 5);
        assert(p.Height() == 6);
        assert(p.Volume() == 40);
    } catch (...) {
        caught = true;
    }
    assert(caught == false);
}