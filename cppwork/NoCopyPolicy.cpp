
class NoCopyClass1 {
public:
    NoCopyClass1(){};
private:
    NoCopyClass1 (const NoCopyClass1&); // Declaration overwrites the default copy constructor
    NoCopyClass1 operator=(const NoCopyClass1);
};

// Prefered way
class NoCopyClass2 {
public:
    NoCopyClass2(){};
    NoCopyClass2 (const NoCopyClass2&) = delete; 
    NoCopyClass2 operator=(const NoCopyClass2) = delete;
};

int main() {
    NoCopyClass1 noCopyClass1_1;
    NoCopyClass1 noCopyClass1_2(noCopyClass1_1); // copy c'tor

    NoCopyClass2 noCopyClass2_1;
    NoCopyClass2 noCopyClass2_2 = noCopyClass2_1; // assignment c'tor

}
