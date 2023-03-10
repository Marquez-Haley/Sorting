/*
Author: Haley Marquez
Date: 10/20
Purpose: to use sorting algorithms to sort random numbers in sets of 1000, 10,000, and 100,000. Sorts the numbers when they are both unsorted and sorted and outputs this data into .csv files. 
*/
#include <iostream>
#include <fstream>
#include <string>
#include "arrayList.h"
#include "sort.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "quickSort.h"

#define MAX_RUNS 10

void generateRandomNumbers(int, std::string);
void sortRandomNumbers(std::string, Sort<int>*, ArrayList<int>&);
void populateList(std::string, int, ArrayList<int>&);
void runAlgorithms(std::string, std::string, std::string, int, Sort<int>*);

int main(){
    ArrayList<int> unsorted_1000, unsorted_10000, unsorted_100000;
    generateRandomNumbers(1000, "1000Random.txt");
    generateRandomNumbers(10000, "10000Random.txt");
    generateRandomNumbers(100000, "100000Random.txt");

    BubbleSort<int> bubbleSort;
    populateList("1000Random.txt", 1000, unsorted_1000);
    sortRandomNumbers("1000Sorted.txt", &bubbleSort, unsorted_1000);

    populateList("10000Random.txt", 10000, unsorted_10000);
    sortRandomNumbers("10000Sorted.txt", &bubbleSort, unsorted_10000);

    populateList("100000Random.txt", 100000, unsorted_100000);
    sortRandomNumbers("100000Sorted.txt", &bubbleSort, unsorted_100000);

   
    std::cout << "Running Bubble Sort" << std::endl;
    runAlgorithms("1000Random.txt", "Bubble1000.csv", "Unsorted", 1000, &bubbleSort);
    runAlgorithms("1000Sorted.txt", "Bubble1000.csv", "Sorted", 1000, &bubbleSort);
    runAlgorithms("10000Random.txt", "Bubble10000.csv", "Unsorted", 10000, &bubbleSort);
    runAlgorithms("10000Sorted.txt", "Bubble10000.csv", "Sorted", 10000, &bubbleSort);
    runAlgorithms("100000Random.txt", "Bubble100000.csv", "Unsorted", 100000, &bubbleSort);
    runAlgorithms("100000Sorted.txt", "Bubble100000.csv", "Sorted", 100000, &bubbleSort);

    std::cout << "Running Insertion Sort" << std::endl;
    InsertionSort<int> insertionSort;
    runAlgorithms("1000Random.txt", "Insertion1000.csv", "Unsorted", 1000, &insertionSort);
    runAlgorithms("1000Sorted.txt", "Insertion1000.csv", "Sorted", 1000, &insertionSort);
    runAlgorithms("10000Random.txt", "Insertion10000.csv", "Unsorted", 10000, &insertionSort);
    runAlgorithms("10000Sorted.txt", "Insertion10000.csv", "Sorted", 10000, &insertionSort);
    runAlgorithms("100000Random.txt", "Insertion100000.csv", "Unsorted", 100000, &insertionSort);
    runAlgorithms("100000Sorted.txt", "Insertion100000.csv", "Sorted", 100000, &insertionSort);

    std::cout << "Running Quick Sort" << std::endl;
    QuickSort<int> quickSort;
    runAlgorithms("1000Random.txt", "Quick1000.csv", "Unsorted", 1000, &quickSort);
    runAlgorithms("1000Sorted.txt", "Quick1000.csv", "Sorted", 1000, &quickSort);
    runAlgorithms("10000Random.txt", "Quick10000.csv", "Unsorted", 10000, &quickSort);
    runAlgorithms("10000Sorted.txt", "Quick10000.csv", "Sorted", 10000, &quickSort);
    runAlgorithms("100000Random.txt", "Quick100000.csv", "Unsorted", 100000, &quickSort);
    runAlgorithms("100000Sorted.txt", "Quick100000.csv", "Sorted", 100000, &quickSort);
    
    return 0;
}

//generates random numbers and puts them into files
void generateRandomNumbers(int range, std::string fileName) {
    std::ofstream outputFile;
    outputFile.open(fileName);
    if (outputFile.fail()){
		std::cout << "Could not create file" << std::endl;
		exit(1);
	}
    else{
        srand((unsigned) time(0));
	    for (int i = 0; i < range; i++){
		outputFile << rand() % 1000001 << std::endl;
	    }
    }

    outputFile.close();
}

//sorts the random numbers and puts them in a new file
void sortRandomNumbers(std::string fileName, Sort<int>* sort, ArrayList<int>& list){
    std::ofstream outputFile;
    outputFile.open(fileName);
    if (outputFile.fail()){
		std::cout << "Could not open file" << std::endl;
		exit(1);
	}
    else{
        ArrayList<int> sorted = list;
        sort->sort(sorted);
        for(int i = 1; i < list.getLength(); i++){
            outputFile << sorted.getEntry(i) << std::endl;
        }
    }

    outputFile.close();
}

//takes what is in the file and puts it into the list
void populateList(std::string fileName, int range, ArrayList<int>& list){
    std::ifstream inFile;
    inFile.open(fileName);
    if (inFile.fail()){
		std::cout << "Could not open file" << std::endl;
		exit(1);
	}
    else{
        int number;
        for(int i = 1; i < range; i++){
                inFile >> number;
                list.insert(i, number);
            }
    }
    inFile.close();
}   

void runAlgorithms(std::string inFileName, std::string outFileName, std::string type, int range, Sort<int>* sort){
    ArrayList<int> aList;
    populateList(inFileName, range, aList);

    std::ofstream outputFile;
    outputFile.open(outFileName, std::ios::app);
	if (outputFile.fail()){
		std::cout << "Could not create file" << std::endl;
		exit(1);
	}
    else{
        //test the algortihm based on what text file is inputted
        ArrayList<int> sorted = aList;
        outputFile << type << std::endl;
        outputFile << "Run Time, Comparisons, Swaps" << std::endl;
        for(int i = 0; i < MAX_RUNS; i++){
            sorted = aList;
            sort->sort(sorted);
            outputFile << sort->getTime().count() << "," << sort->getComparisons() << "," << sort->getSwaps() << std::endl;
        }
    }
    
    outputFile.close();

}
