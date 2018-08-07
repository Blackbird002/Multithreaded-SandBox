// CPP program to demonstrate multi-threading
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <iomanip>
#include <chrono>
using namespace std;

const int SIZE = 100000;

void swap(double &num1, double &num2);
long int selectionSort(double array[], const int &arraySize);
void readFile(ifstream &input, double array[]);

int main(void)
{
    double *arrayOne, *arrayTwo, *arrayThree, *arrayFour, *arrayFive, *arraySix, *arraySeven, *arrayEight;
    arrayOne = new double[SIZE];
    arrayTwo = new double[SIZE];
    arrayThree = new double[SIZE];
    arrayFour = new double[SIZE];
    arrayFive = new double[SIZE];
    arraySix = new double[SIZE];
    arraySeven = new double[SIZE];
    arrayEight = new double[SIZE];

    ifstream inputFile;

    inputFile.open("RandomNumbers.dat");

    if(inputFile.fail())
        cout<<"ERROR reading in file!\n";
    else{
        readFile(inputFile, arrayOne);
    }

    //Copies the contents of arrayOne to other arrays
    for(int i = 0; i < 100000; i++){
        arrayTwo[i] = arrayOne[i];
        arrayThree[i] = arrayOne[i];
        arrayFour[i] = arrayOne[i];
        arrayFive[i] = arrayOne[i];
        arraySix[i] = arrayOne[i];
        arraySeven[i] = arrayOne[i];
        arrayEight[i] = arrayOne[i];
    }

    cout<<"Running 4 selectionSort functions as threads on 100,000 random numbers (each)... \n";

    //Starts the timer
    int startTime = clock();

    // function pointer as callable
    thread th1(selectionSort, arrayOne, 100000);
    thread th2(selectionSort, arrayTwo, 100000);
    thread th3(selectionSort, arrayThree, 100000);
    thread th4(selectionSort, arrayFour, 100000);

    // Wait for the threads to finish
    th1.join();
    th2.join();
    th3.join();
    th4.join();

    int endTime = clock();
    cout<<"Execution Time (multithreaded): " <<(endTime - startTime)/double(CLOCKS_PER_SEC) <<endl;
    cout<<endl;

    cout<<"Running 4 selectionSort functions on 100,000 random numbers (each)... \n";

    //Starts the timer
    startTime = clock();
    selectionSort(arrayFive, 100000);
    selectionSort(arraySix, 100000);
    selectionSort(arraySeven, 100000);
    selectionSort(arrayEight, 100000);
    endTime = clock();

    cout<<"Execution Time (single thread): " <<(endTime - startTime)/double(CLOCKS_PER_SEC) <<endl;
    cout<<endl;

    inputFile.close();
    cout<<"Press enter to end program! \n";
    cin.ignore();

    return 0;
}

long int selectionSort(double array[], const int &arraySize)
{
    long int move = 0;
    int k,j,small;
    if (arraySize > 0)
    {
        for(k = 0; k< arraySize-1; k++){
            small = k;
            for(j = k+1; j < arraySize; j++){
                if(array[j] < array[small])
                    small = j;
            }
            if (k != small){
                swap(array[k],array[small]);
                move += 3;
            }
        }
    }
    return move;
}

//Swaps two given array elements
void swap(double &num1, double &num2)
{
    double temp = num1;
    num1 = num2;
    num2 = temp;
}

//Reads in numbers from file to array
void readFile(ifstream &input, double array[])
{
    string line;
    string newline;
    double number;
    int i = 0;

    for(int j = 0; j < 100000; j++){
        i = 0;
        line = "";
        newline = "";
        getline(input,line);

        //Gets rid of all the whitespace in the string
        while(line[i] != '\0'){
            if(line[i] != ' ')
                newline = newline + line[i];
            i++;
        }

        //Converts the string to a double type
        number = stod(newline);
        array[j] = number;
    }
    input.close();
}
