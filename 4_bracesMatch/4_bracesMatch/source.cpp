//编程题＃4：扩号匹配问题
//
//来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)
//
//注意： 总时间限制: 1000ms 内存限制: 65536kB
//
//描述
//
//在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.
//
//输入
//
//输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100
//
//注意：cin.getline(str,100)最多只能输入99个字符！
//
//输出:
//对每组输出数据，!!!输出两行，第一行包含原始输入字符!!!，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。

// 样例输入:
// ((ABCD(x)
// )(rttyy())sss)(

// 样例输出:
// ((ABCD(x)
// $$
// )(rttyy())sss)(
// ?            ?$

#include <iostream>
#include "string.h"
using namespace std;

unsigned long strLength=0;
char a[101]={'\0'};
char b[101]={'\0'};
int balance=0;
int get(int);

int main(int argc, const char * argv[]) {
    cin.getline(a, 101);
    strLength=strlen(a);
    for (int i=0; i<strLength; i++) {
        i=get(i);
        if(i==-1){
            break;
        }

    }
    b[strLength]='\0';
    cout<<b<<endl;
    return 0;
}


int get(int x){
    b[x]=' ';
    if (x>=strLength) {
        return -1;
    }
    int y=0;
    if(a[x]=='('){
        //cout<<"(";
        balance++;
        y=get(x+1);
        if(y==-1){
            b[x]='$';
            return -1;
        }else{
            b[x]=' ';
        }
        return get(y+1);
    }
    if (a[x]==')') {
        //cout<<")";
        if (balance<=0) {
            b[x]='?';
        }else{
            balance--;
        }
        return x;
    }
    if (a[x]=='\0') {
        return -1;
    }
    
    return get(x+1);
    
}
