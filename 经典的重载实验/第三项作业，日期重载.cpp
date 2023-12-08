#include"日期的头文件.h"
#include <chrono>
int main()
{
    // 获取当前系统时间
    auto currentTime = chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // 转换为 tm 结构体
    std::tm currentTime_tm;
    localtime_s(&currentTime_tm, &currentTime);

    // 创建一个日期对象
    CDate date(currentTime_tm.tm_year + 1900,
        currentTime_tm.tm_mon + 1,
        currentTime_tm.tm_mday);



    // 显示日期
    cout << "Current Date: " << endl;
    date.DisplayDate();



    // 测试日期的加法和减法
    CDate futureDate = date + 30;
    CDate pastDate = date - 15;
    cout << "Date after adding 30 days: " << endl;
    futureDate.DisplayDate();
    cout << "Date after subtracting 15 days: " << endl;
    pastDate.DisplayDate();




    // 测试日期的比较
    if (date < futureDate)
    {
        cout << "Current date is less than the future date." << endl;
    }

    if (!(date < pastDate) && !(date == pastDate))
    {
        cout << "Current date is greater than the past date." << endl;
    }


    // 测试日期的自增和自减
    cout << "After incrementing one day: " << endl;
    (++date).DisplayDate();
    cout << "After decrementing one day: " << endl;
    (--date).DisplayDate();




    // 创建一个时间对象
    CTime time(currentTime_tm.tm_hour,
        currentTime_tm.tm_min,
        currentTime_tm.tm_sec);

    // 显示时间
    cout << "Current Time: " << endl;
    time.DisplayTime();




    // 创建一个日期时间对象
    CDateTime dateTime(
        currentTime_tm.tm_year + 1900,
        currentTime_tm.tm_mon + 1,
        currentTime_tm.tm_mday,
        currentTime_tm.tm_hour,
        currentTime_tm.tm_min,
        currentTime_tm.tm_sec
    );

    // 显示日期时间
    cout << "Current Date and Time: " << endl;
    dateTime.DisplayDateTime();



    // 测试日期时间的加法和减法
    CDateTime futureDateTime = dateTime + 3600;  // 添加一个小时
    CDateTime pastDateTime = dateTime - 1800;   // 减去半小时
    cout << "Date and Time after adding 1 hour: " << endl;
    futureDateTime.DisplayDateTime();
    cout << "Date and Time after subtracting 30 minutes: " << endl;
    pastDateTime.DisplayDateTime();



    // 测试日期时间的比较
    if (dateTime < futureDateTime) {
        cout << "Current date and time is less than the future date and time." << endl;
    }
    if (dateTime > pastDateTime) {
        cout << "Current date and time is greater than the past date and time." << endl;
    }



    // 测试日期时间的自增和自减
    cout << "After incrementing one day: " << endl;
    (++dateTime).DisplayDate();
    cout << "After decrementing one day: " << endl;
    (--dateTime).DisplayDate();

    return 0;
}
