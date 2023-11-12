#include<iostream>
using namespace std;

enum BIT { Zero, One };
typedef BIT FOUR[4];

void print_FOUR(FOUR X) {
    //输出四比特数函数
    cout << X[3] << X[2] << X[1] << X[0];
}

BIT And(BIT a, BIT b) {
    //与门
    if (a && b)
        return BIT{ One };
    else
        return BIT{ Zero };
}

BIT Or(BIT a, BIT b) {
    //或门
    if (a || b)
        return BIT{ One };
    else
        return BIT{ Zero };
}

BIT Xor(BIT a, BIT b) {
    //异或门
    if (a == b)
        return BIT{ Zero };
    else
        return BIT{ One };
}

void half_adder(BIT x, BIT y, BIT& s, BIT& c) {
    s = Xor(x, y);
    c = And(x, y);
}

void full_adder(BIT X, BIT Y, BIT Cin, BIT& S, BIT& Cout) {
    BIT C1, C2;
    half_adder(X, Y, S, C1);
    half_adder(S, Cin, S, C2);
    Cout = Or(C1, C2);
}

void print_full_adder(BIT Cin, BIT X, BIT Y) {
    BIT S, Cout;
    full_adder(X, Y, Cin, S, Cout);
    cout << Cin << '\t' << X << '\t' << Y << '\t' << S << '\t' << Cout << '\n';
}

void test_full_adder() {
    cout << "Cin\tX\tY\tS\tCout\n";
    print_full_adder(Zero, Zero, Zero);
    print_full_adder(Zero, Zero, One);
    print_full_adder(Zero, One, Zero);
    print_full_adder(Zero, One, One);
    print_full_adder(One, Zero, Zero);
    print_full_adder(One, Zero, One);
    print_full_adder(One, One, Zero);
    print_full_adder(One, One, One);
}

void four_bit_adder(FOUR X, FOUR Y, BIT Cin, FOUR& S, BIT& Cout) {
    full_adder(X[0], Y[0], Cin, S[0], Cout);
    full_adder(X[1], Y[1], Cout, S[1], Cout);
    full_adder(X[2], Y[2], Cout, S[2], Cout);
    full_adder(X[3], Y[3], Cout, S[3], Cout);
}

void print_four_bit_adder(FOUR X, FOUR Y) {
    FOUR S;
    BIT Cout;
    four_bit_adder(X, Y, Zero, S, Cout);
    print_FOUR(X);
    cout << '\t';
    print_FOUR(Y);
    cout << '\t';
    print_FOUR(S);
    cout << '\t';
    cout << Cout << '\n';
}

void test_four_bit_adder() {
    cout << "X\tY\tX+Y\tC\n";
    FOUR X = { One, One, Zero, Zero }, Y = { Zero, One, Zero, One };
    print_four_bit_adder(X, Y);
    X[3] = One;
    print_four_bit_adder(X, Y);
    Y[3] = Zero;
    print_four_bit_adder(X, Y);
    X[2] = Y[2] = One;
    print_four_bit_adder(X, Y);
}

int main() {
    cout << "秦萌 E12214158" << endl << endl;
    test_full_adder();
    cout << endl;
    test_four_bit_adder();
}