#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>  
#include <string>   /* atof */
using namespace std;

struct worldData {
  string index;
  string variant;
  string area;
  string notes;
  string countryCode;
  string yrs1950_1955;
  string yrs1955_1960;
  string yrs1960_1965;
  string yrs1965_1970;
  string yrs1970_1975;
  string yrs1975_1980;
  string yrs1980_1985;
  string yrs1985_1990;
  string yrs1990_1995;
  string yrs1995_2000;
  string yrs2000_2005;
  string yrs2005_2010;
  string yrs2010_2015;
};

int main () {
  //open and read csv file
  string line;
  ifstream myfile ("WPP2015_MORT_F07_1_LIFE_EXPECTANCY_0_BOTH_SEXES.csv");
  ofstream mynewfile ("ordered.txt");
  worldData data[258];
  for(int x = 0; x<258;x++){
    data[x].index = "";
    data[x].variant = "";
    data[x].area = "";
    data[x].notes = "";
    data[x].countryCode = "";
    data[x].yrs1950_1955 = "";
    data[x].yrs1955_1960 = "";
    data[x].yrs1960_1965 = "";
    data[x].yrs1965_1970 = "";
    data[x].yrs1970_1975 = "";
    data[x].yrs1975_1980 = "";
    data[x].yrs1980_1985 = "";
    data[x].yrs1985_1990 = "";
    data[x].yrs1990_1995 = "";
    data[x].yrs1995_2000 = "";
    data[x].yrs2000_2005 = "";
    data[x].yrs2005_2010 = "";
    data[x].yrs2010_2015 = "";
  }
  if (myfile.is_open() & mynewfile.is_open())
  {
    int x = 0;
    while ( getline (myfile,line) )
    {
      //cout << line << '\n';
      //mynewfile << line << '\n';
          int start = 0;
          data[x].index = line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].variant = line.substr(start,line.find(',',start)-start);
          start = line.find('"', line.find(',',start))+1;
          data[x].area = line.substr(start,line.find('"',start)-start+1);
          //start=start+2;
          start = line.find('"', start)+1;
          data[x].notes = line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].countryCode = line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs1950_1955 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs1955_1960 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs1960_1965 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs1965_1970 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs1970_1975 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs1975_1980 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs1980_1985 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs1985_1990 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs1990_1995 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs1995_2000 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs2000_2005 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs2005_2010 =  line.substr(start,line.find(',',start)-start);
          start = line.find(',', start)+1;
          data[x].yrs2010_2015 =  line.substr(start,line.find(',',start)-start);
         x++;
    
    }
    bool b = false;
    while(b == false){
      b = true;
      for(int a = 17; a<257;a++){
        int c = a+1;
        double x = stod (data[a].yrs2005_2010); //or stof
        double y = stod (data[c].yrs2005_2010);
        if(x<y) {
          worldData s = data[a];
          data[a] = data[c];
          data[c] = s;
          b = false;
        }
      }
    }


    for(int i = 0; i<258;i++){  
      mynewfile << data[i].index << ", ";
      mynewfile << data[i].variant << ", ";
      mynewfile << data[i].area << ", ";
      /*
      mynewfile << data[i].notes << ", ";
      mynewfile << data[i].countryCode << ", ";
      mynewfile << data[i].yrs1950_1955 << ", ";
      mynewfile << data[i].yrs1955_1960 << ", ";
      mynewfile << data[i].yrs1960_1965 << ", ";
      mynewfile << data[i].yrs1965_1970 << ", ";
      mynewfile << data[i].yrs1970_1975 << ", ";
      mynewfile << data[i].yrs1975_1980 << ", ";
      mynewfile << data[i].yrs1980_1985 << ", ";
      mynewfile << data[i].yrs1985_1990 << ", ";
      mynewfile << data[i].yrs1990_1995 << ", ";
      mynewfile << data[i].yrs1995_2000 << ", ";
      mynewfile << data[i].yrs2000_2005 << ", ";
      mynewfile << data[i].yrs2005_2010 << ", ";
      */
      mynewfile << data[i].yrs2005_2010 << '\n';
      
    }
    int count = -17;
    int countDeveloped = 0;
  for(int a = 0; a <258; a++){
    count++;
    if(data[a].area == "EUROPE\"" || data[a].area == "NORTHERN AMERICA\"" || data[a].area == "Australia/New Zealand\"" || data[a].area == "Japan\"" ){
      countDeveloped++;
    }
    if(data[a].area == "United States of America\""){
      cout << "The US ranking: " << count << '\n';
      cout << "The US ranking by developed countries: " << countDeveloped;
    }
  }
  
    
    myfile.close();
    mynewfile.close();
  }
  
  else cout << "Unable to open file"; 

  return 0;
}

