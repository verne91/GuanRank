#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// data structure for each sample
class Patient{
public:
    string PatientID;
    double survTime;
    short int status;
    double rankScore, kmScore, normalizeScore;
    Patient (string pid, double ptime, short int pstatus){
        PatientID = pid;
        survTime = ptime;
        status = pstatus;
        rankScore = 0.0;
        kmScore = 0.0;
        normalizeScore = 0.0;
    }
};
// read data from csv file
vector<Patient> readFromCSV(ifstream inFile){
        vector<Patient> temp_vec;
        string line;

        while(getline(inFile, line)){
                istringstream iss(line);

                string time, id, status;

                getline(iss, id, ',');
                getline(iss, time, ',');
                getline(iss, status, ',');

                Patient p(id, atof(time.c_str()), atoi(status.c_str()));
                temp_vec.push_back(p);
        }

        //Erase first element of patient vector because it's the headers
        temp_vec.erase(temp_vec.begin());
        return temp_vec;
}

bool by_time(const Patient& p1, const Patient& p2){
        return p1.survTime < p2.survTime;
}

// calculate K-M score for each patient
void CalKMscore(vector<Patient>& Patients){

        int n = Patients.size();

        sort(Patients.begin(), Patients.end(), by_time);
        
        int num_alive = n;
        for(int i=0; i<n; i++){
                num_alive = num_alive - Patients[i].status;
                Patients[i].kmScore = ((double)num_alive)/((double)n);
        }

}

// compare patients pairwise and calculate rank score
void compare(Patient& patient1, Patient& patient2){
    double p;
    if (patient1.survTime == patient2.survTime){
        if (patient1.status == patient2.status){
            patient1.rankScore += 0.5;
            patient2.rankScore += 0.5;
        } else {
            if (patient1.survTime < patient2.survTime){
                patient2.rankScore += 1;
            } else {
                patient1.rankScore += 1;
            }
        }
    } else{
        if (patient1.survTime < patient2.survTime){
            if (patient1.status == 1){
                patient1.rankScore += 1;
            } else {
                if (patient2.status == 1){
                    patient1.rankScore += (patient1.kmScore - patient2.kmScore)/patient1.kmScore;
                    patient2.rankScore += patient2.kmScore/patient1.kmScore;
                } else {
                    p = (patient1.kmScore - patient2.kmScore)/patient1.kmScore;
                    patient1.rankScore += 0.5*(1+p);
                    patient2.rankScore += 0.5*(1-p);
                }
            }
        } else {
            if (patient2.status == 1){
                patient2.rankScore += 1;
            } else {
                if (patient1.status == 1){
                    patient2.rankScore += (patient2.kmScore - patient1.kmScore)/patient2.kmScore;
                    patient1.rankScore += patient1.kmScore/patient2.kmScore;
                } else {
                    p = (patient2.kmScore - patient1.kmScore)/patient2.kmScore;
                    patient2.rankScore += 0.5*(1+p);
                    patient1.rankScore += 0.5*(1-p);
                }
            }
        }
    }
}

// calculate GuanRank score based on comparison
void GuanRank(vector<Patient>& Patients){
    for (int i=0; i<Patients.size(); i++){
        for (int j=i+1; j<Patients.size(); j++){
            compare(Patients[i], Patients[j]);
        }
    }
}

// normalize GuanRank score
void normalize(vector<Patient>& Patients){
    double max=Patients[0].rankScore;
    double min=Patients[0].rankScore;
    for(int i=1;i<Patients.size();i++)
    {
        if(Patients[i].rankScore>max)
            max=Patients[i].rankScore;
        if(Patients[i].rankScore<min)
            min=Patients[i].rankScore;
    }
    for(int i=0;i<Patients.size();i++)
    {
        Patients[i].normalizeScore=(Patients[i].rankScore-min)/(max-min);//normalize to 0-1
    }
}

// output to csv file
void outputToCSV(vector<Patient>& Patients, ifstream outFile){
    ofstream ofile;
    ofile.open("result.csv",ios::out | ios::trunc);
    ofile<<"Patient ID,Normalized Rank Score"<<endl;    //colnames
    for(int i=0;i<Patients.size();i++)
        
    {
        ofile<<Patients[i].PatientID<<"，";
        ofile<<Patients[i].normalizeScore<<"，";
        ofile<<endl;
    }
    ofile.close();
    
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


