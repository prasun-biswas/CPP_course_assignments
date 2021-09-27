#include<iostream>
#include<iomanip>
#include <vector>
#include<algorithm>
#include<stdexcept>

using namespace std;

const int Mins_per_day=60*24;

class Clock{
public:
    Clock(int hour, int minute);
    void tick_tock();
    void print() const;
    int difference (const Clock& endtime) const;

    int get_hour() const;
    int get_minutes() const;
private:
    int count_total_minute_;

};

Clock::Clock(int hour, int minute):
    count_total_minute_(60*hour +minute){};

void Clock::tick_tock(){
    ++count_total_minute_;
    if(count_total_minute_ >=24*60){
        count_total_minute_=0;}
}

int Clock::difference(const Clock& endtime) const{

    if (count_total_minute_<=endtime.count_total_minute_){
        return endtime.count_total_minute_ - count_total_minute_;
    }
    else{
        return Mins_per_day-count_total_minute_+endtime.count_total_minute_;

    }
}

int Clock::get_hour() const {

    return count_total_minute_/60;
}

int Clock::get_minutes() const{

    return count_total_minute_%60;
}

void Clock::print() const{
    cout<< setfill('0')<< setw(2)<< get_hour()<<"."<<setw(2)<<get_minutes()<<endl;
}
// implementation of clock;


bool time_comparator(const Clock& time1, const Clock& time2) {

    if (time1.get_hour()<time2.get_hour()
            and time1.get_minutes()<time2.get_minutes()){
        return true;
    }
    else if(time1.get_hour()==time2.get_hour() and time1.get_minutes()<<time2.get_minutes()){
        return true;
    }
    else {
        return false;
    }
}
Clock read_time(){
    cout<< "input time (hh:mm):";
    int hours,minutes;
    char colon;
    cin>>hours;
    if(cin.fail() or hours <0 or hours >23){
        throw out_of_range("hour value is not valid");
    }
    cin>> colon;
    if(cin.fail() or colon !=':'){
        throw invalid_argument("separator character in time input is incorrect");
    }
    cin>>minutes;
    if (cin.fail() or minutes<0 or minutes>59){
        throw out_of_range("minute value is not valid");
    }
    cin.ignore();
    return Clock(hours,minutes);
}

int main(){
    Clock test(10,20);
    vector<Clock> times ={
        {23,45},{5,55},{20,02}, test,

    };
    times.push_back({21,12});
    times.push_back({11,11});
    test = read_time();
    times.push_back(test);
    times.push_back(read_time());

    sort(times.begin(),times.end(),time_comparator);
    for (Clock timeobject:times){
        timeobject.print();
    }
}







