#include<iostream>
#include<iomanip>
using namespace std;
float ave(float **pa){
    float sum=0;
    for(int i=0;i<5;i++){
        sum+=pa[i][0];
    }
    return sum/5;
}
int fals(float **pa){
    int a[5]={0};
    for(int i=0;i<5;i++){
        int num=0;
        for(int j=0;j<4;j++){
            if(pa[i][j]<60){
                num+=1;
            }
        }
        if(num>=2){
            a[i]=1;
        }
    }
    int sum=0;
    for(int i=0;i<5;i++){
        if(a[i]==1){
            sum++;
        }
    }
    return sum;
}
int well(float **pa){
    int a[5]={0};
    float ave[5];
    for(int i=0;i<5;i++){
        int if_well=0;
        for(int j=0;j<4;j++){
            if_well+=pa[i][j];
        }
        ave[i]=if_well/5;
    }
    for(int i=0;i<5;i++){
        int num=0;
        for(int j=0;j<4;j++){
            if(pa[i][j]>=85){
                num+=1;
            }
        }
        if(num==4){
            a[i]=1;
        }
    }
    for(int i=0;i<5;i++){
        if(ave[i]>=90){
            a[i]=1;
        }
    }
    int sum=0;
    for(int i=0;i<5;i++){
        if(a[i]==1){
            sum+=1;
        }
    }
    return sum;
}
int main(void)
{
    float** pa=new float*[5];
    for(int i=0;i<5;i++){
        pa[i]=new float[4];
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            cin >> pa[i][j];
        }
    }
    float average=ave(pa);
    int fal=fals(pa);
    int is_well=well(pa);
    cout << setiosflags(ios::fixed) << setprecision(1) << average << " " << fal << " " << is_well;
    return 0;
}