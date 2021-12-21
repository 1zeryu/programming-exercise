#include<iostream>
using namespace std;
void go(int *person,int m,int k,int& a,int& b,int n){
    for(int i=0;i<m;){
        if(person[a]!=0){
            i++;
        }
        a++;
        if(a==n){
            a=0;
        }
    }
    a--;
    for(int i=0;i<k;){
        if(person[b]!=0){
            i++;
        }
        b--;
        if(b<0){
            b=n-1;
        }
    }
    b++;
    cout << person[a] << " " << person[b] << endl;
    person[a]=0;
    person[b]=0;
    return;
}
int main(void)
{
    int n;
    cin >> n;
    int *person=new int[n];
    for(int i=0;i<n;i++){
        person[i]=i+1;
    }
    int a=0,b=n-1;
    int m,k;
    cin >> m >> k;
    for(int i=0;i<3;i++){
        go(person,m,k,a,b,n);
    }
    return 0;
}