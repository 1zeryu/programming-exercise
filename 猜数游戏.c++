#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
    ifstream fin("data.in");
    streambuf *in;
    in=cin.rdbuf(fin.rdbuf());
    int game_num=1;
    int guess_num=1;
    while(true){
        cin >> guess_num;
        if(guess_num==0){
            break;
        }
        else{
            cout << "game" << game_num << endl;
        }
        int *guess=new int[guess_num];
        int *result=new int[guess_num];
        for(int i=0;i<guess_num;i++){
            cin >> result[i];
        }
        while(true){
            for(int i=0;i<guess_num;i++){
                cin >> guess[i];
            }
            int right=1;
            int equal=0;
            int exist=0;
            for(int i=0;i<guess_num;i++){
                if(guess[i]!=0){
                    right=0;
                }
            }
            if(right){
                break;
            }
            for(int i=0;i<guess_num;i++){
                if(guess[i]==result[i]){
                    equal++;
                }
            }
            for(int i=0;i<guess_num;i++){
                int right=0;
                for(int j=0;j<guess_num;j++){
                    if(result[j]==guess[i]&&i!=j){
                        exist++;
                        break;
                    }
                }
            }
            cout << "(" << equal << "," << exist << ")" << endl;
        }
    }
    cin.rdbuf(in);
    fin.close();
    return 0;
}