// Copyright 2020 student 5471. All Rights Reserved.

#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

const int avgweight = 175;
const int maxseats = 143;
const int maxtakeoff = 175000;
const int baseWeight = 130000;


int main()
{
char airname[101];
char flightnum [101];
cout<<"\nEnter Airline Name without any space (Only the first 100 characters will count.): ";
cin >> setw(100) >> airname;
cout<<"\nAirline Name: " <<airname;

cout<<"\nEnter Airline Name without any space or commas (Only the first 100 digits will count.): ";
cin >> setw(100) >> flightnum;
cout<<"\nFlight Number: " <<flightnum;


int passenger;


while (true)
{
cout << "\nPlease Enter the Number of Passengers : ";
cin >> passenger;

if(!cin)
{
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout<<"\nInvalid input, please enter an integer number between 0 to "<< maxseats;
continue;
}

if (0<= passenger && passenger <= maxseats){
        break;}

cout<<"\nInvalid input, please enter an integer number between 0 to " << maxseats;
}

cout<<"\nBase Weight = "<<baseWeight<<endl;

cout<<"Passenger Weight Added= "<<(passenger*avgweight)<<endl;

int newweight = baseWeight + (passenger*avgweight); 

cout<<"New Weight = "<<newweight<<endl;


int *cargoweight = (int *)malloc(1000*sizeof(int));


int cargonum=0;

int shipmentweight = 0;

int cargoinput;

while(true){


cout<<"\nCurrent Shipment Weight = "<<shipmentweight<<endl;
cout<<"\nPlease Enter the Cargo Weight \nEnter 0 to Finish Adding Cargo Weight : ";
cin>>cargoinput;

if((cargoinput+newweight)>maxtakeoff){
cout<<cargoinput<<" This cargo cannot be loaded as it will overload the airplane. \nThe cargo needs to be less than " << maxtakeoff - newweight<<endl;
continue;
}

if(cargoinput<0){
cout << "\nPlease Enter a Positive Integer";
continue;
}

if(cargoinput == 0){
cout << "\n 0 is entered as input. Ending the input process.";
break;
}

if(!cin){
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cout<<"\nInvalid input, please enter an integer number";
continue;
}

cargoweight[cargonum] = cargoinput;
shipmentweight = shipmentweight + cargoweight[cargonum];
newweight = newweight + cargoinput;
cout<<"New weight = "<<newweight<<endl;
cargonum++;
}

cout<<"\nAirline : "<<airname<<endl;
cout<<"Flight Number : "<<flightnum<<endl;
cout<<"Number of Passengers : "<<passenger<<endl;
cout<<"Number of cargo shipments : "<<cargonum<<endl;
cout<<"For Each Cargo: "<<endl;
for(int i=0;i<cargonum;i++){
cout<<cargoweight[i]<<" ";
}
cout<<"\nTotal Weight : "<<newweight<<endl;
cout<<"Maximum Weight : "<<maxtakeoff<<endl;
return 0;
}

