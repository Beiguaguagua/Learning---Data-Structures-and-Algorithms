//力扣202-快乐数

#include <iostream>
#include <string>
using namespace std;

bool isHappy(int n) {
    bool res = false;
    string tempStr = to_string(n);
    //如果长度等于1,就返回false
    if (tempStr.length() < 2) {
        return false;
    }
    int i = 0; 
    int num = n;
    while (num != 1) {
        string str = to_string(num);//int变量转化为string类型

        int i = str.length();//计算该字符串的长度

        int temp = 0;

        //计算平方每个数的平方,然后进行相加
        for (int k = 0; k < i; k++) {
            int tempNum = str[k] - '0';
            temp += tempNum * tempNum;
        }
        //如果为1，就返回true
        if (temp == 1) {
            return true;
        }
        num = temp;//将temp的值赋予给num；
    }
}

int main()
{
    bool res = isHappy(19);
    if (res) {
        cout << "成功" << endl;
    }
    else {
        cout << "失败" << endl;
    }
}
