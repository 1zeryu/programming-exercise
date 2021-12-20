#include<iostream>
using namespace std;
void calc(int *a,const int size_ment,string molar,int &i){
    i++; 
    if(i>=molar.length()){
        a[size_ment]=1;
        return ;
    }
    else{
        if(molar[i]>=48&&molar[i]<=58){
            int get=molar[i]-48;
            i++;
            while(i<molar.size()&&molar[i]>=48&&molar[i]<=58){
                get=get*10+molar[i]-48;
                i++;
            }
            a[size_ment]=get;
        }
        else{
            a[size_ment]=1;
        }
    }
    return;
}
int main(void)
{
    string molar;
    cin >> molar;
    int ment[100];
    int num[100];
    int size_ment=0;
    int i=0;
    int *a=num;
    while(i<molar.length()){
        if(molar[i]=='O'){
            ment[size_ment]=16;
            calc(a,size_ment,molar,i);
            size_ment++;
        }
        else if(molar[i]=='C'){
            ment[size_ment]=12;
            calc(a,size_ment,molar,i);
            size_ment++;
        }
        else if(molar[i]=='H'){
            ment[size_ment]=1;
            calc(a,size_ment,molar,i);
            size_ment++;
        }
        else if(molar[i]=='N'){
            ment[size_ment]=14;
            calc(a,size_ment,molar,i);
            size_ment++;
        }
        // cout << ment[size_ment-1] << " " << num[size_ment-1] << endl;
    }
    int sum=0;
    for(i=0;i<size_ment;i++){
        sum=sum+ment[i]*num[i];
    }
    cout << sum;
    return 0;
}