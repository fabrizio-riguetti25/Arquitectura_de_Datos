#include <iostream>
#include <bitset>
using namespace std;

const int  n = 4;


bool fullAdder(bool b1, bool b2, bool& carry)
{
    bool sum = (b1 ^ b2) ^ carry;
    carry = (b1 && b2) || (b1 && carry) || (b2 && carry);
    return sum;
}

template<int b>
bitset<b> bitsetAdd(bitset<b>& x, bitset<b>& y)
{
    bool carry = false;
    // bitset to store the sum of the two bitsets
    bitset<b> ans;
    for (int i = 0; i < b; i++) {
        ans[i] = fullAdder(x[i], y[i], carry);
    }
    return ans;
}

template<int b>
void lshift(bitset<b>& A, bitset<b-1>& Q){
    cout<<"Shifting A, Q: "<<Q[n-1]<<endl;
    A<<=1;
    A[0] = Q[n-1];
    Q<<=1;
}

int main(int argc, char const *argv[])
{
    bitset<n+1> M("00011");
    bitset<n+1> A;
    bitset<n> Q("1011");

    // cout<<A<<Q << " "<<Q[n-1]<<endl;
    // lshift<n+1>(A, Q);
    // cout<<A<<Q << " "<<Q[n-1]<<endl;
    bitset<n+1>comp_M;
    bitset<n+1>one(1);
    bitset<n+1> neg_M;
    bitset<n+1> last_A;
    cout<< neg_M <<endl;
    int count = n;

    while (count != 0){
        cout<<A<< "-" <<Q << " "<<count<<endl;
        lshift<n+1>(A, Q);
        last_A = A;
        cout<<A<< "-" <<Q << " "<<count<<endl;
        comp_M = ~M;
        neg_M = bitsetAdd<n+1>(comp_M, one);
        A = bitsetAdd<n+1>(A, neg_M);
        cout<<"\tA=A-M: "<<A<<endl;
        if (A[n] == 1){
            Q[0] = 0;
            A = last_A;
            cout<<"\tA=A+M: "<<A<<endl;

        }
        else{
            Q[0] = 1;
        }
        count--;
    }

    cout<< "Cociente: "<< Q<<endl;
    cout<<"Residuo: "<<A<<endl;
}
