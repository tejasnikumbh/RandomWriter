#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <map>
#include <iterator>
using namespace std;

int main(){

  // Introductory text
  cout<<"Program to demonstrate the abilities of the Random Writer!"<<endl;
  
  // Reading the file to be used as sample
  string fileName;
  cout<<"Enter the name of the sample file to be used ";
  cin>>fileName;
  
  // Input from user about the markov model to be used 
  int orderMarkov = -1;
  cout<<"Enter the order of the markov model to be used (Interger in 1-10)";
  cin>>orderMarkov;
  
  
  // Reading the file from the computer
  fstream fTStrm;
  fTStrm.open(fileName.c_str());
  string seed = "";
  map<string,vector<char> > modelMap;
  vector<char> charVec;
  vector<string> seedVec;
  char ch;
  while(fTStrm.get(ch) && seed.size()<orderMarkov)
    seed += ch;
    
  seedVec.push_back(seed);
  
  while(fTStrm.get(ch)){
    if(ch!='\n'){
      modelMap[seed].push_back(ch);
      seed = seed.substr(1) + ch;   
      seedVec.push_back(seed);
    }
  }  
   
  
  // Outputing random text
  int count = 0;
  string kGram = seedVec[rand()%seedVec.size()];
  string randomText = kGram;
  
  
  while(count<2000){
    char next;
    vector<char> charVec = modelMap[kGram];
    next = charVec[rand()%charVec.size()];
    kGram = kGram.substr(1) + next;
    randomText += next;
    count++;
  }
 
  cout<<randomText<<endl;
  return 0;
}
