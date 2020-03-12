// Copyright 2020 student 2133. All Rights Reserved.

#include <iostream>
#include <climits>


using namespace std;


const int AvgPassWeight = 175;
const int PassSeats = 143;
const int TakeoffWeight = 175000;

int main(int argc, char * argv[]) {

int baseWeight = 130000;
int numOfPass;

cout << "Enter the number of passengers: " << endl;
cin >> numOfPass;
while ( !cin.good() || numOfPass > PassSeats){

  cout << "BAD INPUT!" <<endl;
  cin.clear();
  cin.ignore(INT_MAX,'\n');
  cout << "Enter the number of passengers: " << endl;
  cin >> numOfPass;
}

cout << "Original weight = " << baseWeight << endl;
cout << "Passenger weight added = " << AvgPassWeight*numOfPass << endl;
baseWeight = baseWeight + (AvgPassWeight*numOfPass);
cout << "New weight = " << baseWeight << endl;
cout << endl;


int *cargoWeights = (int *)malloc(10*sizeof(int));
int ct = 0;
int shipWeight = 0;

while (true) {

  int currWeight;

  cout << "Current shipment weight: " << shipWeight << endl;
  cout << "Enter the cargo weight: ";
  cin >> currWeight;

  while (!cin.good()){
    cout << "BAD INPUT!" << endl;
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    cout << "Enter the cargo weight: ";
    cin >> currWeight;

  }

  if ((currWeight + baseWeight) > TakeoffWeight) {
    cout << currWeight << " cant be loaded as the plane will get overloaded. " << endl;
    break;

  }

  cargoWeights[ct] =  currWeight;
  shipWeight = shipWeight + cargoWeights[ct];
  baseWeight = baseWeight + currWeight;
  cout << "New Weight = " << baseWeight << endl;
  cout << endl;
  ct++;
}

delete[] cargoWeights;

cout << "\n Airline: " << argv[1];
cout << "\n Flight Number: " << argv[2];
cout << "\n Number of Passenger " << numOfPass;
cout << "\n Number of Cargo Shipments " << ct;
for (int i = 0; i < ct; i++){ cout << "\n Cargo Weights:  " << cargoWeights[i];}

cout << "\n Total Weight: " << baseWeight;
cout << "\n Maximum Weight: " << TakeoffWeight << endl;



return 0;
}
