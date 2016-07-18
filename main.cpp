#include <iostream>
#include <bitset>
#include <math.h>

using namespace std;

void odd (unsigned int array[32]);
void even (unsigned int array[32]);
void print (unsigned int array[32]);
void binToDec(unsigned int array[32]);

unsigned int s, num = 0;
unsigned int array[32];
unsigned int output[32];


int main()
{
    unsigned int input;
    cout << "Enter data(integer): " << endl;
    cin >> input;

    s=32;
    bitset<32> bSet(input);
    for(int i = s-1; i >= 0; i--){
        array[i] = bSet[i];
    }

    string choice;

    for(int i=s; i >= 0; i/=2){
        cin >> choice;
        if(choice == "Odd"){
            odd(array);
        }

        if(choice == "Even"){
            even(array);
        }
        if(choice == "Game over!"){
            binToDec(array);
            break;
        }
    }

    return 0;
}


void odd (unsigned int arr[32]){
   for(int i = s-1, j =0 ; i >= 0, j <= (s-1)/2; i--){
       if(i%2 == 1){
            output[j] = arr[i];
            j++;
            //cout<<i<<' '<<j<<endl;
       }
   }
   for(int i =0; i <= s; i++){
        array[i] = output[i];
   }
   s /= 2;
}

void even (unsigned int arr[32]){
   for(int i = s-1, j =0 ; i >= 0, j <= (s-1)/2; i--){
       if(i%2 == 0){
            output[j] = arr[i];
            j++;
          //  cout<<i<<' '<<j<<endl;
       }
   }
   for(int i =0; i <= s; i++){
        array[i] = output[i];
   }
   s /= 2;
}



void print (unsigned int array[32]){
    for(int i = s -1; i >= 0; i--)
        cout << array[i];
    cout << endl;
}

void binToDec(unsigned int array[32]){
    int cnt = 0;
    for(int i =0; i <= s; i++){
        if(array[i] == 1){
            cnt++;
            num += pow(2,i);
        }
   }
   cout << num << '     ' << cnt << endl;
}
