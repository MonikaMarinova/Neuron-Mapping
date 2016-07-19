#include <QCoreApplication>
#include <iostream>

using namespace std;

int main()
{
    u_int32_t size;
    u_int32_t step;


    cout << "Enter size of the array" << endl;
    cin >> size;


    cout << "Enter step:" << endl;
    cin >> step;

     u_int32_t input[size];
     u_int8_t cnvdInput[size*8];

    cout << "Enter numbers:" << endl;
    for(int i = 0; i < size; i++ ){
        cin >> input[i];
    }

    for(int i = 0, j =0; i < size; i++ ){
        for(int c = 128; c > 0; c/=2, j++){     //check if input[i] contains 2^c and store it in array
            cnvdInput[j] = ((input[i]&c) == c); //sequence of 0 and 1
        }
    }

    for(int i = 0; i < size*8; i += step){
        if(cnvdInput[i] == 1)
            cnvdInput[i] = 0;
        else
            cnvdInput[i] = 1;
    }

    uchar output[size];
    uchar number;

    for(int j = 0; j < size; j++){
        output[j] = 0;
        number = 0x80;
        for(int i = 0; i < 8; i++){
            output[j] += cnvdInput[j*8+i]*number;
            number = number >> 1;
        }
    }

    cout << "Output: " << endl;
    for(int i = 0; i < size; i++){
        cout << (int)output[i] << endl;
    }


    return 0;
}


