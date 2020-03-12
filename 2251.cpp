// Copyright 2020 student 2251. All Rights Reserved.

#include <iostream>
using namespace std;

const int weight = 175;
const int seats = 143;
const int maxWeight = 175000;

int main(int argc, char * argv[]){
  int inWeight = 130000;
  int passengers;
  cout<<"How many passengers? "<<endl;
  cin>>passengers;

  cout<<"Intial weight: "<<inWeight<<endl;
  cout<<"Current total weight: "<<(passengers*weight)<<endl;
  inWeight = inWeight + (passengers*weight);
  cout<<"New total weight: "<<inWeight<<endl;

  int *cargoWeight = (int *)malloc(1000*sizeof(int));
  int shipmentWeight = 0;
  int counter = 0;

  while(true){
    int newCargoWeight;
    cout<<"Current shipment weight: "<<shipmentWeight<<endl;
    cout<<"Enter cargo weight: ";
    cin>>newCargoWeight;
    cout<<endl;

    if((newCargoWeight + inWeight) > maxWeight){
      cout<<newCargoWeight<<"To much weight on the plane!"<<endl;
      break;
}

  cargoWeight[counter] = newCargoWeight;
  shipmentWeight = shipmentWeight + cargoWeight[counter];
  inWeight = inWeight + newCargoWeight;
  cout<<"New total weight: "<<inWeight<<endl;
  cout<<"Enter more cargo, until cargo wieght exceeds max. "<<endl;
}

  cout<<"Airline: "<<argv[1]<<endl;
  cout<<"Flight number: "<<argv[2]<<endl;
  cout<<"Number of passengers: "<<passengers<<endl;
  cout<<"Number of cargo shipments: "<<counter<<endl;
  cout<<"Cargo weights: "<<endl;
  for(int k = 0; k < counter; k++){
    cout<<cargoWeight[k]<<" ";
}
  cout<<endl;
  cout<<"Total Weight: "<<inWeight<<endl;
  cout<<"Max Weight: "<<maxWeight<<endl;
  return 0;
}
