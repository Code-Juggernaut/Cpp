#include<iostream>
using namespace std;
int year = 0;
int day_in_month(int month){
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:return 31;break;

        case 2:
            if(year%400 == 0){
                return 29;
            }else{
                return 28;
            }break;

        case 4: case 6: case 9: case 11: return 30;break;
    }
}

int main(){
    int prev_year,prev_month,prev_day,year,month,day;
    cout<<"\033[93mEnter start date(DD MM YYYY)";
    cin>>prev_day>>prev_month>>prev_year;
    cout<<"Enter end date(DD MM YYYY)";
    cin>>day>>month>>year;

    if(prev_year == year && prev_month == month){
        cout<<day-prev_day;
    }else{

        if(prev_year == year){
            int count_days = 0;
            for(int i = prev_month;i<month;i++){
                count_days += day_in_month(i);
            }
            count_days +=day-prev_day;
            
            cout<<count_days;
        }else{
            int count_days= 0;
            if(prev_month == month){
                for(int i = prev_year;i<year;i++){
                    if(i%400 == 0){
                        count_days+=366;
                    }else{
                        count_days+=365;
                    }
                }
                cout<<count_days-(day-prev_day);
            }else{
                for(int i = 12;i>=prev_month;i--){
                    count_days+=day_in_month(i);
                    //cout<<count_days<<'\n';
                }
                count_days += day_in_month(prev_month)-prev_day;
            
                if(year-prev_year>1){
                    for(int i = prev_year+1;i<year;i++){
                        if(i%400 == 0){
                            count_days+=366;
                        }else{
                            count_days+=365;
                        }
                    }
                    //cout<<count_days<<'\n';
                }else{
                    count_days-=1;
                }
                
                for(int i = 1;i<month-1;i++){
                    count_days+=day_in_month(i);
                    //cout<<count_days<<'\n';
                }
                count_days+=day;
                cout<<"Days between two dates =\033[96m"<<count_days;
            
            }
        }

    }
}