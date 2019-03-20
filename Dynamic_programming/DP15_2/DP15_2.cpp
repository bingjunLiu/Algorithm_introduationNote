#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
int function_min_calu(int Row[],int column[],int start,int end);

int main(){
    int Row[3]={10,100,5};
    int column[3]={100,5,50};
    cout<<function_min_calu(Row,column,0,2)<<endl;

}

int function_min_calu(int Row[],int column[],int start,int end){
    int total=INT16_MAX;
    if(start==end){
        return 0;
    } 
    for(int i=start;i<end;i++)
    {   
        cout<<i<<endl;
        if(start==end){
            return 0;
        } 
        int temp_total=function_min_calu(Row,column,start,i)+\
            function_min_calu(column,Row,i+1,end)+\
            Row[start]*column[i]*column[i+1]/* code */;
        if(temp_total<total)
            {          
                total=  temp_total;
            }
    }
    return total;
}