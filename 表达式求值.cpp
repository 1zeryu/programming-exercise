#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

// 表达式求值包括三个步骤
// 1.输入表达式用于分析
// 2.将中缀表达式转化为后缀表达式
// 3.计算后缀表达式（栈）


// 将中缀表达式转换成后缀表达式，我们需要运用栈的操作，同时注意运算符的优先级
// 存入#为运算符栈的基元，扫描表达式，当遇到运算数时压入结果表达式
// 遇到运算符时，根据栈顶和当前运算符的优先级做以下操作
// theta1为栈顶运算符，theta2为当前运算符
// 当theta1>theta2，将theta1压入结果表达式
// theta2>theta1， 将theta2压入运算符栈顶
// theta1==theta2, 要么是#要么是()

bool pripoty(char theta1,char theta2){
    static int a[7][7]={{1,1,0,0,0,1,1},
    {1,1,0,0,0,1,1},
    {1,1,1,1,0,1,1},
    {1,1,1,1,0,1,1},
    {0,0,0,0,0,-1,-1},
    {1,1,1,1,-1,1,1},
    {0,0,0,0,0,-1,-1}};
    int pos[2];
    switch(theta1){
        case '+': pos[0]=0; break;
        case '-': pos[0]=1; break;
        case '*': pos[0]=2; break;
        case '/': pos[0]=3; break;
        case '(': pos[0]=4; break;
        case ')': pos[0]=5; break;
        case '#': pos[0]=6; break;
    }
    switch(theta2){
        case '+': pos[1]=0; break;
        case '-': pos[1]=1; break;
        case '*': pos[1]=2; break;
        case '/': pos[1]=3; break;
        case '(': pos[1]=4; break;
        case ')': pos[1]=5; break;
        case '#': pos[1]=6; break;
    }
    return a[pos[0]][pos[1]];
}

string post(string infix_exp){
    infix_exp+="#";
    char operation[100];
    int oper_size=0;
    string result;
    int result_size=0;
    operation[0]='#';
    oper_size++;
    for(int i=0;i<infix_exp.size();i++){
        if(infix_exp[i]>=48&&infix_exp[i]<=58){
            result[result_size]=infix_exp[i];
            result_size++;
        }
        else{
            if(infix_exp[i]==')'){
                while (true)
                {
                    if(operation[oper_size-1]!='('){
                        result[result_size]=operation[oper_size-1];
                        oper_size--;
                        result_size++;
                    }
                    else{
                        oper_size--;
                        break;
                    }
                }
            }
            else if(infix_exp[i]=='#'){
                while(true){
                    if(operation[oper_size-1]!='#'){
                        result[result_size]=operation[oper_size-1];
                        oper_size--;
                        result_size++;
                    }
                    else{
                        oper_size--;
                        break;
                    }
                }
            }
            else{
                if(pripoty(operation[oper_size-1],infix_exp[i])){
                    result[result_size]=operation[oper_size-1];
                    oper_size--;
                    result_size++;
                    while(true){
                        if(pripoty(operation[oper_size-1],infix_exp[i])){
                            result[result_size]=operation[oper_size-1];
                            oper_size--;
                            result_size++;
                        }
                        else{
                            operation[oper_size]=infix_exp[i];
                            oper_size++;
                            break;
                        }
                    }
                }
            }
        }
    }
    return result;
}

// 将符号的数字字符转化成数字
int tansform(char op){
    return op-48;
}

// 计算后缀表达式，可以利用栈，也可以使用递归
int calc(string exp){
    char operation[1000]; // 定义运算符栈
    int digit[1000];     // 定义数据栈
    int oper_size=0;
    int dig_size=0;
    for(int i=0;i<exp.size();i++){
        if(exp[i]>=48&&exp[i]<=58){
            digit[dig_size]=tansform(exp[i]);
            dig_size++;
        }
        else{
            switch(exp[i]){
                case '*': digit[dig_size-2]=digit[dig_size-2]*digit[dig_size-1];
                dig_size-=1; break;
                case '+': digit[dig_size-2]=digit[dig_size-2]+digit[dig_size-1];
                dig_size-=1; break;
                case '-': digit[dig_size-2]=digit[dig_size-2]-digit[dig_size-1];
                dig_size--; break;
                case '/': digit[dig_size-2]=digit[dig_size-2]/digit[dig_size-1];
                dig_size--; break;
                case '%': digit[dig_size-2]=digit[dig_size-2]%digit[dig_size-1];
                dig_size--; break;
            }
        }
    }
    return digit[0];
}
int main(void){
    ifstream fin("data.in");
    streambuf *in;
    in=cin.rdbuf(fin.rdbuf());
    string infix_exp;
    cin >> infix_exp;
    string  postfix_exp;
    postfix_exp=post(infix_exp);
    int result=calc(postfix_exp);
    cout << result << endl;
    cin.rdbuf(in);
    fin.close();
    return 0;
}
