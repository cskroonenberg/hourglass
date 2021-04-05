//
//  main.cpp
//  bored
//
//  Created by Caden Kroonenberg on 3/24/20.
//  Copyright © 2020 Caden Kroonenberg. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    #define RESET   "\033[0m"
    #define SANDCOLOR  "\033[93m\033[103m"      /* Bold Yellow */
    #define HOURGLASSCOLOR  "\033[97m\033[107m"      /* HOURGLASSCOLOR Black?*/
    int hour;
    int minute;
    int totalCount;
    int remainderH;
    int remainderM;
    int passed;
    int remainder;
    int glassArea;
    int remAmt;
    int nextGlassArea;
    int bottomRemAmt = 0;
    int rowCount = 0;
    bool nextRowFull = false;
    bool replay = false;
    string AMPM;
    do
    {
    cout<<"Enter hour: ";
    cin>>hour;
    if(hour>=1 && hour<=12)
    {

    cout<<"Enter minute: ";
    cin>>minute;
    if(0<=minute && minute<60)
    {
    cout<<"AM or PM?: ";
    cin>>AMPM;
    if(AMPM == "PM" || AMPM == "pm" || AMPM == "Pm" || AMPM == "pM" || AMPM == "AM" || AMPM == "am" || AMPM == "Am" || AMPM == "aM")
    {
        if(minute>=10)
        {
        cout<<"The time is "<<hour<<":"<<minute<<" "<<AMPM<<endl;
        }
        else
        {
        cout<<"The time is "<<hour<<":0"<<minute<<" "<<AMPM<<endl;
        }
        if(hour == 12)
        {
            hour = 0;
        }
    if (AMPM == "PM" || AMPM == "pm" || AMPM == "Pm" || AMPM == "pM")
    {
        hour = hour + 12;
    }
    totalCount = hour*60+minute;
    passed = totalCount/10;
    cout<<totalCount<<" minutes have passed today"<<endl;
    remainderH = 23 - hour;
    remainderM = 60 - minute;
    remainder = remainderH*60+remainderM;
    remainder = remainder/10;
    if(totalCount % 10 >= 5)
    {
        passed++;
    }
    else
    {
        remainder++;
    }
    cout<<"There are "<<remainderH<<" hours and "<<remainderM<<" minutes left today\n";
    cout<<endl;
    //cout<<"int remainder = "<<remainder<<endl;
    //cout<<"int passed = "<<passed<<endl;
    //cout<<"total = "<<passed+remainder<<endl;
    //cout<<endl;
        cout<<HOURGLASSCOLOR<<"___________________________"<<RESET<<endl;
        cout<<HOURGLASSCOLOR<<"\\-------------------------/"<<RESET<<endl;
    for (int i = 1; i<=12; i++) //top half
    {
        for (int j = 1; j<=27; j++)
        {
            glassArea = (13-i)*(13-i);
            nextGlassArea = (12-i)*(12-i);
            if (remainder<=glassArea && remainder>=nextGlassArea)
            {
                remAmt = remainder - nextGlassArea;
                nextRowFull = true;
            }
            else
            {
                nextRowFull = false;
            }
            if(j<=i)
            {
                cout<<" ";
            }
            else if(j==i+1)
            {
                cout<<HOURGLASSCOLOR<<"\\"<<RESET;
            }
            else if(j<27-i && remainder>=glassArea) //full row
            {
                cout<<SANDCOLOR<<"*"<<RESET;
            }
            else if(j == 14 && nextRowFull == true && remainder != nextGlassArea)
            {
                cout<<SANDCOLOR<<"*"<<RESET;
            }
            else if(remAmt%2 == 0 && j>14-(remAmt/2) && j<=14+(remAmt/2) && nextRowFull == true)
            {
                cout<<SANDCOLOR<<"*"<<RESET;
            }
            else if(remAmt%2 == 1 && j>=14-(remAmt/2) && j<=14+(remAmt/2) && nextRowFull == true)
            {
                cout<<SANDCOLOR<<"*"<<RESET;
            }
            else if (j<27-i)
            {
                cout<<" ";
                if(nextRowFull == true)
                {
                bottomRemAmt++;
                }
            }
            if(j==27-i)
            {
                cout<<HOURGLASSCOLOR<<"/"<<RESET;
            }
        }
        cout<<endl;
    }
    for (int i = 12; i>=1; i--) //bottom half
       {
           glassArea = (13-i)*(13-i);
           nextGlassArea = (14-i)*(14-i);
           if (glassArea<=remainder && remainder<=nextGlassArea)
           {
               rowCount = i - 1;
           }
          for (int j = 1; j<=27; j++)
                 {
                     
                     if(j<=i)
                     {
                         cout<<" ";
                     }
                     else if(j==i+1)
                     {
                         cout<<HOURGLASSCOLOR"/"<<RESET;
                     }
                     else if(j<27-i && remainder>=glassArea) //full row
                     {
                         cout<<" ";
                     }
                     else if(j == 14 && passed != nextGlassArea && i == rowCount) //&& nextRowFull == true)
                     {
                         cout<<SANDCOLOR<<"*"<<RESET;
                     }
                     else if(bottomRemAmt%2 == 0 && j>14-(bottomRemAmt/2) && j<=14+(bottomRemAmt/2) && i == rowCount)
                     {
                         cout<<SANDCOLOR<<"*"<<RESET;
                         //nextRowFull = false;
                     }
                     else if(bottomRemAmt%2 == 1 && j>=14-(bottomRemAmt/2) && j<=14+(bottomRemAmt/2) && i == rowCount)
                     {
                         cout<<SANDCOLOR<<"*"<<RESET;
                         //nextRowFull = false;
                     }
                     else if (j<27-i && i != rowCount)
                     {
                         cout<<SANDCOLOR<<"*"<<RESET;
                     }
                     else if (j<27-i && i == rowCount)
                    {
                        cout<<" ";
                    }
                     if(j==27-i)
                     {
                         cout<<HOURGLASSCOLOR<<"\\"<<RESET;
                     }
                 }
          // cout<<glassArea<<" - "<<nextGlassArea<<" - "<<rowCount;
           cout<<endl;
           replay = false;
       }
        cout<<HOURGLASSCOLOR<<"/-------------------------\\"<<RESET<<endl;
        cout<<HOURGLASSCOLOR<<"|_________________________|"<<RESET<<endl;
    //cout<<"bottomRemAmt: "<<bottomRemAmt<<endl;
    //cout<<"bool nextRowFull: "<<nextRowFull<<endl;
    }
    else
    {
        cout<<AMPM<<" is not a valid entry. Try again."<<endl<<endl;
    }
    }
    else
    {
        cout<<minute<<" is not a valid entry. Try again."<<endl<<endl;
        replay = true;
    }
    }
    else
    {
        cout<<hour<<" is not a valid entry. Try again."<<endl<<endl;
        replay = true;
    }
    } while (replay == true);
    return(0);
}
