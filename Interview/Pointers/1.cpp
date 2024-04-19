#include<iostream>
using namespace std;

int main(){
    int num =5;
    cout << num << endl;

    // address of a variable 
    cout << &num << endl;
    
    //accessing value at a address
    cout << *(&num) << endl;

    //pointers -> store addresses to which it points 

    int* ptr = &num;

    cout << ptr << " " << &num  << endl;

    ptr = &num;

    

    return 0;
}
