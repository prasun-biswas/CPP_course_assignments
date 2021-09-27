#include <iostream>
#include <iomanip>

using namespace std;


class Clock {
  public:
    Clock(int hour1,int hour2,int minute1, int minute2);
    void tick_tock();
    void print() const;
    //void timeDiff();


  private:
    int hours1_;
    int minutes1_;
    int hours2_;
    int minutes2_;
};


int main() {
    Clock time(22,20,30,40);
    time.print();

}


Clock::Clock(int hour1,int hour2, int minute1, int minute2):
    hours1_(hour1),hours2_(hour2), minutes1_(minute1),minutes2_(minute2) {
}





void Clock::print() const {
    cout << setw(2) << setfill('0') << hours1_
         << "."
         << setw(2) << minutes1_
         << endl;
    cout << setw(2) << setfill('0') << hours2_
         << "."
         << setw(2) << minutes2_
         << endl;
    int hourDiff= (hours1_-hours2_);
    if (hourDiff<0){hourDiff=hourDiff*(-1);}
    int minuteDiff=(minutes1_-minutes2_);
    //if (minuteDiff<0){minuteDiff=minuteDiff*(-1);}
    int differnce = (hourDiff*60) + minuteDiff;
    cout<< "time difference is "<<differnce<<" minutes";
}
