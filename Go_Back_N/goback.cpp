#include <iostream>
#include <vector>
#include <unistd.h>
int main(){
 int n;int k=0;int z;int w;
 std::cin>>n;
 int arr[n];
// int brr [n];
std::cin>>w;
 for(int i=0;i<n;i++)
 std::cin>>arr[i];
 for(int i=0;i<n;i++){
  if(arr[i]==1 && k==0){
  for(int j=i;j<i+3;j++)
  std::cout<<"Frame: "<< j<<" Transmitted "<<std::endl; 
  k=1;   
  }
  if(arr[i]==1 && k==1){
   std::cout<<"Frame: "<< i <<" Acknowledged"<<std::endl;
   if(i<(n-w))
   std::cout<<"Frame: "<< i+3 <<" Transmitted"<<std::endl;
   }
  if(arr[i]==0){
 std::cout<<"Frame: "<< i <<" Not Acknowledged"<<std::endl;
  for(int j=i;j<i+3 && j<9;j++)
    std::cout<<"Frame: "<< j<<" Transmitted "<<std::endl; 
    
  std::cout<<"Frame: "<< i<<" Acknowledged"<<std::endl; 
  }
  }
  }
