#include"���ڵ�ͷ�ļ�.h"
#include <chrono>
int main()
{
    // ��ȡ��ǰϵͳʱ��
    auto currentTime = chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // ת��Ϊ tm �ṹ��
    std::tm currentTime_tm;
    localtime_s(&currentTime_tm, &currentTime);

    // ����һ�����ڶ���
    CDate date(currentTime_tm.tm_year + 1900,
        currentTime_tm.tm_mon + 1,
        currentTime_tm.tm_mday);



    // ��ʾ����
    cout << "Current Date: " << endl;
    date.DisplayDate();



    // �������ڵļӷ��ͼ���
    CDate futureDate = date + 30;
    CDate pastDate = date - 15;
    cout << "Date after adding 30 days: " << endl;
    futureDate.DisplayDate();
    cout << "Date after subtracting 15 days: " << endl;
    pastDate.DisplayDate();




    // �������ڵıȽ�
    if (date < futureDate)
    {
        cout << "Current date is less than the future date." << endl;
    }

    if (!(date < pastDate) && !(date == pastDate))
    {
        cout << "Current date is greater than the past date." << endl;
    }


    // �������ڵ��������Լ�
    cout << "After incrementing one day: " << endl;
    (++date).DisplayDate();
    cout << "After decrementing one day: " << endl;
    (--date).DisplayDate();




    // ����һ��ʱ�����
    CTime time(currentTime_tm.tm_hour,
        currentTime_tm.tm_min,
        currentTime_tm.tm_sec);

    // ��ʾʱ��
    cout << "Current Time: " << endl;
    time.DisplayTime();




    // ����һ������ʱ�����
    CDateTime dateTime(
        currentTime_tm.tm_year + 1900,
        currentTime_tm.tm_mon + 1,
        currentTime_tm.tm_mday,
        currentTime_tm.tm_hour,
        currentTime_tm.tm_min,
        currentTime_tm.tm_sec
    );

    // ��ʾ����ʱ��
    cout << "Current Date and Time: " << endl;
    dateTime.DisplayDateTime();



    // ��������ʱ��ļӷ��ͼ���
    CDateTime futureDateTime = dateTime + 3600;  // ���һ��Сʱ
    CDateTime pastDateTime = dateTime - 1800;   // ��ȥ��Сʱ
    cout << "Date and Time after adding 1 hour: " << endl;
    futureDateTime.DisplayDateTime();
    cout << "Date and Time after subtracting 30 minutes: " << endl;
    pastDateTime.DisplayDateTime();



    // ��������ʱ��ıȽ�
    if (dateTime < futureDateTime) {
        cout << "Current date and time is less than the future date and time." << endl;
    }
    if (dateTime > pastDateTime) {
        cout << "Current date and time is greater than the past date and time." << endl;
    }



    // ��������ʱ����������Լ�
    cout << "After incrementing one day: " << endl;
    (++dateTime).DisplayDate();
    cout << "After decrementing one day: " << endl;
    (--dateTime).DisplayDate();

    return 0;
}
