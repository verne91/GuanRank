#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// data structure for each sample
class Patient{
    public:
        string PatientID;
        double survTime;
        short int status;
        double rankScore, kmScore;
    Patient (string pid, double ptime, short int pstatus){
        PatientID = pid;
        survTime = ptime;
        status = pstatus; 
        rankScore = 0.0;
        kmScore = 0.0
    }
}

// read data from csv file 
vector<Paitent> readFromCSV(ifstream inFile){
    
}

// calculate K-M score for each patient
void CalKMscore(&vector<Patient){

}

// compare patients pairwise and calculate rank score
void compare(&patient1, &patient2){

}

// calculate GuanRank score based on comparison
void GuanRank(&vector<Patient>){

}

// normalize GuanRank score
void normalize(&vector<Patient>){

}


int main(int argc, char const *argv[])
{
    //step 1: read data from file into a vector of Patient

    //step 2: calculate K-M score for each patient

    //step3: calculate GuanRank score for each patient based on pairwise comparison

    //step4: normalize GuanRank score

    //step 5: output Patient ID and GuanRank Score to a csv file

    return 0;
}

