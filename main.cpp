#include <iostream>
#include<fstream>
using namespace std;
int A[100], n,temp;

void Bubblesort_naive(){ 
  for(int j=1; j<=n; j++){
    for(int i=0; i<(n-1); i++){
      if(A[i]>A[i+1]){
        temp=A[i];
        A[i]=A[i+1];
        A[i+1]=temp;
      }
    }
  }
}

void Bubblesort_opt(){
  int i=n; bool sorted;
  sorted=false;
  while((i>1)&&(!sorted)){
    sorted=true;
    for(int j=1; j<i;j++){
      if(A[j-1]>A[j]){
        temp=A[j-1];
        A[j]=temp;
        sorted=false;
      }
    }
    i--;
  }
}

void bsn_display(){
cout<<endl;
  cout<<"Bubble sort naive: "<<endl;
  for(int i=0; i<n; i++)
  cout<<A[i]<<"  ";
}

int main() {
  string myText;
// Read from the text file
ifstream MyReadFile("Myreadfile.txt");
int number_testcases;
   MyReadFile>> number_testcases; //just like cin
  cout << "number_testcases = " ;
  cout<< number_testcases;
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)){
for(int t=0; t<number_testcases; t++){
  MyReadFile>>n; //taking array size
 cout<<endl<<"Your array size: ";
 cout<<n<<"\n";

 for(int i=0; i<n; i++) //for bubble sort taking inputs
  MyReadFile>>A[i]; 
 cout<<"Before Sort the array: "<<endl;

for(int i=0; i<n; i++)
cout<<A[i]<<endl;
 Bubblesort_naive(); //call naive function
 bsn_display(); //call naive display function
 Bubblesort_opt(); //call optimization function
 cout<<endl<<"bubblesort_optimization is: ";
 
  for(int i=0; i<n; i++)
  cout<<A[i]<<" "; //print optimized value
}
}
MyReadFile.close(); // Close the file
  return 0;
}