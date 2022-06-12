# 1. 视C++为一个语言联邦

> **View C++ as federation of languages.**

## 理由

> `C++同时支持面向过程式、面向对象式、函数式、泛型式、元编程式的语言. `

## EG

> **可以当成以下四个次语言的联邦**
>
> -  C
> - Object-Oriented  C++
> - Template C++
> - STL

# 2. 尽量以const, enum, inline替换#define

> **Prefer consts, enums, and inlines to #defines.**
>
> **宁可以编译器替换预处理器.**

## 理由

> **1. 替换常量时，如果发生报错:**
>
> - 使用#define 会提示具体值，而非变量名，可能导致浪费时间来查找
> - 使用const，可以编译器可以提示变量名
>
> **2.  #define 无法定义专属的常量**
>
> **3. inline可以实现"宏函数在减少函数调用带来的额外开销"效果**
>
> - 宏函数还有实现上的缺点++ -- 导致的问题
>
> **4. #define实现的类似泛型编程，可以使用Template C++代替**

## 注意

> **1. const定义常量指针时**
>
> ```c++
> const char* const name = "xiaobai";
> const std::string name("xiaobai");
> ```
>
> **2. const 定义class专属常量**
>
> ```c++
> // 1. 类内声明初始化，类外定义
> class Player{
> private:
>     // 声明式，并且设置初始值
>     static const int Num = 5;
>     int scores[Num];
> };
> // 定义式，不能赋值
> const int Player::Num;
> 
> // 2. 类内声明，类外定义初始化
> class Person{
> private:
>     // 声明式
>     static const int Nums;
> };
> // 定义式，需要初始化
> const int Person:Nums = 5;
> 
> // 3. 使用the enum hack: 一个属于枚举类型的数值可权充ints被使用
> class Animal{
>     // 不允许取地址，类似#define 定义的值
>   	enum {Num = 5};
>   	int scores[Num];
> };
> ```

