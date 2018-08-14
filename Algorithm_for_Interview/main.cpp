//#include "all.h"
//#include "Cpp回顾/Cpp之string专题.hpp"
//#include "常用子函数/遍历子集（递归）.hpp"
//#include "动态规划/最长回文子串.hpp"
//#include "utils/位运算.hpp"
//#include "_必背算法/排序-堆排序.hpp"
//#include "_必背算法\atoi.hpp"
//#include "_必背算法\排序-桶排序.hpp"
//#include "_笔试\拼多多/1.数组中的最长山谷.hpp"
//#include "二分查找/旋转数组中查找目标值.hpp"
//#include "深度优先搜索\字符串的排列.hpp"

//#include <bits/stdc++.h>
//#include <vector>
//#include <sstream>

#include <iostream>
using namespace std;

class num_sequence {
public:
    // PtrType 是一个指针，指向 num_sequence 的成员函数，
    //  该成员函数必须只接受一个 int 型参数，以及返回类型为 void
    typedef void (num_sequence::*PtrType)(int);

    enum { cnt_seq = 2 };              // 预定义了两种序列
    enum ns_type {
        ns_fibonacci, ns_square
    };

    // 构造函数：默认指向斐波那契数列
    num_sequence(): _pmf(func_tbl[ns_fibonacci]) { }

    // 调整指针指向
    void set_sequence(ns_type nst) {
        switch (nst) {
        case ns_fibonacci: case ns_square:
            _pmf = func_tbl[nst];
            break;
        default:
            cerr << "invalid sequence type\n";
        }
    }
    void print(int n) {
        (this->*_pmf)(n); // 通过指针选择需要调用的函数
    }
    // _pmf 可以指向以下任何一个函数
    void fibonacci(int n) {
        int f = 1;
        int g = 1;
        for (int i = 2; i <= n; i++)
            g = g + f, f = g - f;
        cout << f << endl;
    }
    void square(int n) {
        cout << n * n << endl;
    }

private:
    PtrType _pmf;
    static PtrType func_tbl[cnt_seq];  // 保存所有序列函数的指针
                                       // 为了兼容性，不推荐写成 `static vector<vector<int>（没有空格）> _seq;`
};

// static 成员变量初始化
num_sequence::PtrType
num_sequence::func_tbl[cnt_seq] = {
    &num_sequence::fibonacci,
    &num_sequence::square,
};

int main() {

    auto ns = num_sequence();
    ns.print(5);  // 5
    ns.set_sequence(num_sequence::ns_square);  // 调整函数指针以获得多态的效果
    ns.print(5);  // 25

    cout << endl;
    system("PAUSE");
    return 0;
}

