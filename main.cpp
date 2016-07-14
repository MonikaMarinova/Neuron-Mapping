#include <QCoreApplication>
#include <bitset>
#include <iostream>

using namespace std;

void  makeArray();
void makeSet(u_int32_t arr[], int arraySize);
void bitwiseOperators(u_int32_t arr[], int arraySize);
void printSet(std::bitset<32> b);


int main()
{
    makeArray();
    return 0;
}

void   makeArray(){
    int arraySize;
    cout << "Enter size of the array you want to input: " << endl;
    cin >> arraySize;

    u_int32_t array[arraySize];

    cout << "Enter the elements of the array: " << endl;
    for(int index = 0; index < arraySize; index++){
        cin >> array[index];
    }


    bitwiseOperators(array,arraySize);
   //makeSet(array, arraySize);

}

void makeSet(u_int32_t arr[],int arraySize){
    for(int index = 0; index < arraySize; index++){
        std::bitset<32> bSet(arr[index]);
        printSet(bSet);
    }

}


void printSet(std::bitset<32> b){
    for(int index=32; index >0; index--){
            b[index] = !b[index];
    }

     cout << b << endl;
}


void bitwiseOperators(u_int32_t arr[], int arraySize){
   char matrix[32][32];

    for(int i=0; i < arraySize; i++){
        for(u_int32_t check= 2147483648, j = 0; check > 0, j <= 32 ; check /= 2, j++){
            if((arr[i] & check) == check )
                matrix[i][j] = '1';
                //cout << 1;
            else
                matrix[i][j] = '.';
                //cout << '.';
        }
        // cout << '\n';
    }

    int flag =0;

     for(int i=0; i<arraySize; i++){
       for(int j=0; j<32; j++){
           if(matrix[i][j] == '1'){
               flag = 1;
               if(matrix[i][j++] == '.'){
                   matrix[i][j++] = '1';
                   flag = 1;
               }
               if(matrix[i][j++] == '1')
                   flag = 0;
           }
           else if(matrix[i][j] == '.'){
               flag = 0;
           }
       }
     }

          /*
            if(flag == 1){
              if(matrix[i][j++] == '.'){
                  matrix[i][j++] = '1';
                  flag = 1;
              }
              if(matrix[i][j++] == '1')
                  flag = 0;
          }
           cout << flag << "  ";
           cout << j << "   After" << endl;
       }
       cout << '\n';
       cout << '\n';


           if(matrix[i][j] == '1')
               flag =1;
           else
               flag = 0;
           if(matrix[i][j] == '.' && flag == 1){
               matrix[i][j] = '1';
               flag = 1;
           }
           if(matrix[i][j] == '1' && flag == 1)
               flag = 0;

           cout << flag << "  ";
           cout << j << "   After" << endl;

     }
   }
   */



     for(int i=0; i<arraySize; i++){
         for(int j=0; j<32; j++)
             cout<<matrix[i][j];
         cout<<'\n';
     }

}

