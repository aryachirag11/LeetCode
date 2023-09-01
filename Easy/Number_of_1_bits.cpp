#include<iostream>
using namespace std;

int number_of_1_bits(uint32_t n){


int  count =0;
        while(n!=0){
            if(n&1){
                count++;
            }
            n=n>>1;
        }
        return count;
}

int main(){
    uint32_t n;

    cout<<"Enter binary number: ";
    cin>>n;
    cout<<endl;

    cout<<"Answer is :"<<number_of_1_bits(n); 


}