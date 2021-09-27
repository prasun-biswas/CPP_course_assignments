#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<stdexcept>
#include<stdio.h>
#include<fenv.h>
#include<math.h>

using namespace std;

const unsigned int SPLIT_ERROR =0;

//-------------splitter class----------------------
class Splitter
{
public:
    Splitter(const string& string_to_split="");

    void set_string_to_split(const string& string_to_split);

    unsigned int split(char separator,bool skip_empty_fields=false);

    unsigned int number_of_fields() const;

    string fetch_field(unsigned int field_index) const;
private:
    string original_string_;
    vector<string> split_result_;
};


Splitter::Splitter(const string& string_to_split):
    original_string_(string_to_split),split_result_({}){

}

void Splitter::set_string_to_split(const string &string_to_split){
    original_string_=string_to_split;
    split_result_={};
}

unsigned int Splitter::split(char separator, bool skip_empty_fields){
    split_result_.clear();
    string::size_type startpos=0;
    string field_content;

    while (true) {
        string::size_type endpos;
        endpos = original_string_.find(separator,startpos);
        if(endpos==string::npos){break;}
        field_content=original_string_.substr(startpos,endpos-startpos);
        if(not(skip_empty_fields and field_content.empty())){
            split_result_.push_back(field_content);
        }
        startpos=endpos+1;
    }
    field_content=original_string_.substr(startpos);
    if(not(skip_empty_fields and field_content.empty())){
        split_result_.push_back(field_content);
    }
    return split_result_.size();
}

unsigned int Splitter::number_of_fields() const{
    if(split_result_.size()==0){
        return SPLIT_ERROR;
    }
    else {
        return split_result_.size();
    }

}

string Splitter::fetch_field(unsigned int field_index) const{

    if(split_result_.empty() or field_index>=split_result_.size()){
        throw out_of_range("Error: this is not a valid date!");
    }
    return split_result_.at(field_index);
}
//----------------splitter class ends-----------------------

//---------------date class--------------------

class Date_and_day
{
public:
    Date_and_day() {}
    int julian_day(int,int,int);
    string day_of_week(int);
    void previous_day_date(int);
    void next_day_date(int);
    string getGregorianDate(int jd);

};
int Date_and_day::julian_day(int D, int M, int Y){
    int julian_day_number =
            (1461 * (Y + 4800 + (M - 14)/12))/4
            + (367 * (M - 2 - 12 * ((M - 14)/12)))/12
            - (3 * ((Y + 4900 + (M - 14)/12)/100))/4 + D - 32075;

    return julian_day_number;

}

string Date_and_day::day_of_week(int JD){

    int weekday_number = JD % 7;

    switch ( weekday_number ) {
    case 0:
        return "Monday";

    case 1:
        return "Tuesday";

    case 2:
        return "Wednesday";

    case 3:
        return "Thursday";

    case 4:
        return "Friday";

    case 5:
        return "Saturday";

    case 6:
        return "Sunday";

    default:
        return "invalid";

    }

}

void Date_and_day::next_day_date(int JD){
    int nexJD=JD+1;
    Date_and_day nDate;
    cout<<"The next date will be: "<<nDate.day_of_week(nexJD)<<" "<<nDate.getGregorianDate(nexJD)<<endl;

}
void Date_and_day::previous_day_date(int JD){
    int preJD=JD-1;
    Date_and_day pDate;
    cout<<"The previous date was: "<<pDate.day_of_week(preJD)<<" "<<pDate.getGregorianDate(preJD)<<endl;


}

string Date_and_day::getGregorianDate(int JD){
    int j,y,d,m;
    string dateString;
    j = nearbyint(JD - 1721119);
    y = nearbyint((4 * j - 1) / 146097);
    j = nearbyint(4 * j - 1 - 146097 * y);
    d = nearbyint(j / 4);
    j = nearbyint((4 * d + 3) / 1461);
    d = nearbyint(4 * d + 3 - 1461 * j);
    d = nearbyint((d + 4) / 4);
    m = nearbyint((5 * d - 3) / 153);
    d = nearbyint(5 * d - 3 - 153 * m);
    d = nearbyint((d + 5) / 5);
    y = nearbyint(100 * y + j);
    if (m < 10){
        m=m+3;
        dateString=to_string(d)+"."+ to_string(m)+"."+to_string(y);
        return dateString;
    }
    else {
        m=m-9;
        y=y+1;
        dateString=to_string(d)+"."+ to_string(m)+"."+to_string(y);
        return dateString;
    }

}

//---------------date class ends----------------

//--- helping methods--------
bool leapyear_check(int y) {
    return ((y%4==0) && (y%100!=0) or (y%400==0));
}

bool check_valid_date(int d, int m, int y){

    bool ly = leapyear_check(y);

    if ((d>0 && d<32)&&(m>0 && m<13)){
        if((m==4 || m==6 || m==9 || m==11) && d<=30){}

//            cout<<"The date is a valid date."<<endl;
        else if ((m==4 || m==6 || m==9 || m==11 || m==4 || m==6 || m==9 || m==11) && d<=31) {
//            cout<<"The date is a valid date."<<endl;

        } else if((m==2) && ((d<=28) && (ly==false)) ||((d<=29) && (ly==true))){
//            cout<<"The date is a valid date."<<endl;
        }
        return true;
    }
    else{
//        cout<<"Error: this is not a valid date!"<<endl;
        return false;
    }

}

//---helping methods ends----


//----------------main function starts here------------------

int main(){
    cout<<"--------------------------------"<<endl;
    cout<<"Welcome to date testing program!"<<endl;
    cout<<"--------------------------------\n"<<endl;

    int iDD,iMM,iYYYY,JD;
    Date_and_day aDate;

    string user_input,sDD,sMM,sYYYY;

    while (true) {
    cout<<"Input a date in day-month-year format: ";
    getline(cin,user_input);
    Splitter splitter_object(user_input);
    if (user_input == "quit") {
        cout<<"\nTest program ending, Goodbye!";
        return 0;
    }
    cout<<"--- TEST OUTPUT BEGIN"<<endl;

    //cout<<"passed user input into splitter class"<<endl;
    splitter_object.split('-');
    //cout<<"fields:"<<splitter_object.number_of_fields()<<endl;

    sDD=splitter_object.fetch_field(0);//----convert string to integer
    iDD=atoi(sDD.c_str());
    sMM=splitter_object.fetch_field(1);//----convert string to integer
    iMM=atoi(sMM.c_str());
    sYYYY=splitter_object.fetch_field(2);//----convert string to integer
    iYYYY=atoi(sYYYY.c_str());

    if(iDD==0|| iMM==0||iYYYY==0||iYYYY<1800){
        cout<<"Error: this is not a valid date!"<<endl;

    }
    else {
        if (check_valid_date(iDD,iMM,iYYYY)){
            cout<<"The date is a valid date."<<endl;
            JD=aDate.julian_day(iDD,iMM,iYYYY);
            cout<<"Day is "<<iDD<<endl;
            cout<<"Month is "<<iMM<<endl;
            cout<<"year is "<<iYYYY<<endl;
            cout<<"Weekday is "<<aDate.day_of_week(JD)<<endl;

            aDate.getGregorianDate(JD);
            aDate.previous_day_date(JD);
            aDate.next_day_date(JD);

        }
        else{
           cout<<"Error: this is not a valid date!"<<endl;
        }
        cout<<"--- TEST OUTPUT END\n\n";

    }


    for(unsigned int i=0; i<<splitter_object.number_of_fields();++i){
        string current_field_contents = splitter_object.fetch_field(i);
        cout<<i<<":["<<current_field_contents<<"]"<<endl;
    }
}
    return 0;
}

//----------------main function ends here------------------
