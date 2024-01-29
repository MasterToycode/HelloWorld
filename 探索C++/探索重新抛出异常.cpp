#include <iostream>
#include <stdexcept>
using namespace std;

void innerFunction()
{
    try
    {
        // 在这里抛出一个异常
        throw runtime_error("Inner function exception");
    }

    catch (const exception& e)
    {
        cerr << "At the Function of the innerFunction ! Caught exception inside innerFunction: " << e.what() << endl;
        throw;
        //throw不指定任何参数，它会重新抛出当前正在处理的异常，具体指这个函数try；语句中的异常
        //这个异常传递到了outer Function函数的catch
        //将控制权交给调用链中的更高级别的 catch 语句块。
    }
}



void outerFunction()
{
    try
    {
        // 调用内部函数
        innerFunction();
    }

    catch (const exception& e)
    {
        cerr << "At teh Function of the outerFunction !Caught exception inside outerFunction: " << e.what() << endl;
        // 在这里进行进一步处理
        //指处理从innerFunction函数传递来的异常！
        throw;
    }
}




int main()
{
    try
    {
        // 调用外部函数
        outerFunction();
    }

    catch (const exception& e)
    {
        cerr << "At the function of the main ! Caught exception inside main: " << e.what() << endl;
        // 这里的异常来自于outerFunction函数传递而来的异常，如果在outerFunction函数中没有重新抛出异常
        //这里的main函数就不会执行这条语句，因为异常已经在outerFunction函数中处理了！
    }
    return 0;
}



/*
*
具体解释如下：
main 函数调用了 outerFunction。
outerFunction 内部调用了 innerFunction。
innerFunction 抛出异常，并进入 catch 语句块。
在 catch 语句块中使用 throw; 重新抛出异常。
这个重新抛出的异常会继续传递到调用 innerFunction 的地方，即 outerFunction。
outerFunction 中的相应 catch 语句块也捕获了这个异常。
所以，异常的传递是在调用链中的不同函数之间进行的。


在 innerFunction 中重新抛出异常后，它并不是在 innerFunction 内继续处理，
而是返回到调用 innerFunction 的上一级函数 outerFunction 中，
从而在 outerFunction 的 catch 语句块中进行处理。

*/