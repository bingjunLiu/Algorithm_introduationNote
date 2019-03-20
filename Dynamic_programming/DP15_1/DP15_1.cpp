#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;
int fun_slice_wood_top_down(int Price[],int Wood_length,int* storage);
int* Storage();

int main()
{
    clock_t start,finish;
    double duration;
    start =clock();
    // int Length[]={1,2,3,4,5,6,7,8,9,10};
    int Price[]={1,5,8,9,10,17,17,20,24,30};
    int* storage=Storage();
    // char* test;
    

    cout<<fun_slice_wood_top_down(Price,5,storage)<<'*'
    <<endl;

    for(int i=0;i<10;i++){
        cout<<storage[i]<<endl;
    }
    // for(int i=0;i<sizeof(storage)/sizeof(storage[0]);i++){
    //     cout<<storage[i]<<endl;
    // }

    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<" sec" <<endl;
} // std;
////////////////////////////////////////////////////////////
int* Storage(void){
    static int storage[10]={-1};
    return (int*)storage;
}

int fun_slice_wood_top_down(int Price[],int Wood_length,int* storage){
    if(Wood_length==0){
        return 0;
    }
    if(storage[Wood_length-1]>0){
        // cout<<storage[Wood_length-1]<<endl;
        return storage[Wood_length-1];
    } 

    int total=0;
    int storage_lib[10]={0};
    for(int i=1;i<=Wood_length;i++){
        int total_temp=0;
        if(Price[Wood_length-1]>fun_slice_wood_top_down(Price,Wood_length-i,storage)+Price[i-1]){
            total_temp=Price[Wood_length-1];
        }else
        {
            total_temp=fun_slice_wood_top_down(Price, Wood_length-i,storage)+Price[i-1];

        }
        if(total<total_temp){
            total=total_temp;
        }
    }
    storage[Wood_length-1]=total;
    return total;
}
////////////////////////////////////////////////////////////
int fun_slice_wood(int Price[],int Wood_length){
    if( Wood_length==0 ){
        return 0;
    }
    int total=0;
    int total_temp;
     
    for(int i=1;i<=Wood_length;i++){
        if (Price[Wood_length-1]> fun_slice_wood(Price,Wood_length-i)+ Price[i-1]){
                total_temp= Price[Wood_length-1];
        }else{
                total_temp= fun_slice_wood(Price,Wood_length-i)+Price[i-1];
        };
        if (total_temp>total){
            total=total_temp;
        }
    };  
    return total;
}