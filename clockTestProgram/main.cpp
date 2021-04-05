#include<iostream>
#include<string>
#include<chrono> // !!
#include<ctime>
#include<ratio>
using namespace std;
/*
int main()
{
    using std::chrono::system_clock;
    system_clock::time_point hour = system_clock::now();
    std::time_t tt;
    tt = system_clock::to_time_t ( hour );
    cout<<"today is: "<< ctime(&tt)<<endl;
    return(0);
}
*/
int main ()
{
    using namespace std::chrono;

    typedef duration<int,std::ratio<3600,1>> hours_type;
    typedef duration<int,std::ratio<60,1>> minutes_type;
    
    time_point<system_clock,hours_type> hour =  time_point_cast<hours_type>(system_clock::now());

    time_point<system_clock,minutes_type> minute =  time_point_cast<minutes_type>(system_clock::now());
    cout<< ((hour.time_since_epoch().count())%24) - 6 << " hours have passed today" <<endl;

    cout<< ((minute.time_since_epoch().count())%60) << " minutes"<<endl;
    
  return 0;
}
