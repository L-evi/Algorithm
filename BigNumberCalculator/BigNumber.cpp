//
// Created by Administrator on 2021/12/13.
//

#include "BigNumber.h"

//构造函数
BigNumber::BigNumber() {
    //Integer = new string();
    //Decimal = new string();
}

BigNumber::BigNumber(const BigNumber &number) {
    Integer = number.Integer;
    Decimal = number.Decimal;
    Flag = number.Flag;
}
/*//重载加法运算符
BigNumber BigNumber::operator+(const BigNumber number) {

}
//重载减法运算符
BigNumber BigNumber::operator-(const BigNumber number) {

}
//重载乘法运算符
BigNumber BigNumber::operator*(const BigNumber number) {

}
//重载除法运算符
BigNumber BigNumber::operator/(const BigNumber number) {

}
//规格化输出：保留多少位小数
void BigNumber::RemindDecimalShow(int count) {

}*/
//重载输出运算符
ostream& operator<<(ostream& out, BigNumber& number) {
    if (! number.Flag) out << "-";
    if (number.Decimal == "0") out << number.Integer;
    else out << number.Integer << "." << number.Decimal;
    return out;
}
//重载输入运算符
istream& operator>>(istream& in, BigNumber& number) {
    string Input;
    cin >> Input;
    //负数处理
    if (Input[0] == '-') number.Flag = false;
    //通过小数点来确定是什么类型输入
    int PointIndex = Input.find('.');
    if (PointIndex == -1) {
        //整数情况
        number.Integer = Input;
        number.Decimal = '0';
    } else if (Input[PointIndex - 1] == '0') {
        //纯小数情况
        number.Integer = '0';
        number.Decimal = Input.substr(PointIndex + 1, Input.length());
    } else {
        //普通小数
        number.Integer = Input.substr(0, PointIndex);
        number.Decimal = Input.substr(PointIndex + 1, Input.length());
    }
    //如果是负数，则需要将负号删除，因为Flag已经记录了正负数信息
    if (number.Integer[0] == '-') number.Integer = number.Integer.substr(1, number.Integer.length());
    return in;
}


void TestBigNumber() {
    BigNumber b1;
    cin >> b1;
    cout << b1 << endl;

}

int main() {
    TestBigNumber();
    return 0;
}