#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

struct Datetime {
    int year, month, day, hour, min, second;
};

time_t getTimestamp(int year, int month, int day, int hour, int min, int sec) {
    struct tm tm = {};
    tm.tm_year = year - 1900; // struct tm 内部会自动帮你加上一个 1900, 因此要手动减去
    tm.tm_mon = month - 1; // struct tm 内部会自动帮你加上一个 1, 因此要手动减去
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = min;
    tm.tm_sec = sec;
    //return timegm(&tm); // 使用UTC时间转换
    return _mkgmtime(&tm);
}

void solve() {
  // 1.难点一：要注意样例给的数据是 两个字符串(中间有个空格) + 一个 int
  // 我一开始以为只是一个字符串
    string dateStr, timeStr;
    int x;
    cin >> dateStr >> timeStr >> x;
    string datetimeStr = dateStr + " " + timeStr;

  // 2.难点二: 将获取的时间字符串提取时间信息
    Datetime dt;
    sscanf(datetimeStr.c_str(), "%d-%d-%d %d:%d:%d",
           &dt.year, &dt.month, &dt.day, &dt.hour, &dt.min, &dt.second);


  // 3.难点三: 获取并处理时间戳
  // 这里如果不不以时间戳为思路处理，就要暴力的从1970年1月1日 00:00:00开始计算！！相比之下前者更好  
    time_t timestamp = getTimestamp(dt.year, dt.month, dt.day, dt.hour, dt.min, dt.second);
    time_t interval = x * 60;// 因为题目闹钟的时间单位是min, 而时间戳是以秒为单位, 因此需要将闹钟时间间隔转换为以秒为单位
    time_t remainder = timestamp % interval;  // 除去前面 interval 的倍数时间，剩下的就是可以往前推移的时间
    time_t recent = timestamp - remainder;    // 当前时间戳-可以推移的时间 = 最近一次响铃的时间

    struct tm *tm = gmtime(&recent); // 用于将 time_t 类型的时间戳（通常表示自 Unix 纪元即1970年1月1日 00:00:00 UTC 以来的秒数）转换为 struct tm 结构体
  // 就这一步，就帮我省去了超级多的麻烦！如果我自己处理时间戳，需要处理很多时间进位的操作！易错且麻烦


    printf("%04d-%02d-%02d %02d:%02d:%02d\n",
           tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
           tm->tm_hour, tm->tm_min, tm->tm_sec);
}


int main() {
    std::cout << "dasd";
    std::cout.flush();
    int T;
    cin >> T;
    while (T--) {
    solve();
    }
    return 0;
}