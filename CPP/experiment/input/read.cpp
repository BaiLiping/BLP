
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
#include<fstream>
using namespace std;

int main(){
    ifstream inputFile("data.txt");
    string fileData(istreambuf_iterator<char>(inputFile),istreambuf_iterator<char>());
    //for(int i=0;i<fileData.size();i++)
      //  cout<<fileData[i]<<endl;
    //cout<<endl;
    return 0;
}
