#include <iostream>
#include <iomanip>

using namespace std;

// prototypes
void printMenu();
void printClocks(int hours, int minutes, int seconds, bool isAM);
void addHour(int &hour, bool &isMorning);
int addMinute(int minute);
int addSeconds(int second);

int main() {

    // declare/initialize variables
    int hours = 11;
    int minutes = 00;
    int seconds = 00;
    bool isAM = true;
    char userInput = '0';

    // begin clock loop and exit the loop if the user enters 4
    while (userInput != '4'){

        // call printClocks to print the 12 hour and 24 hour clocks next to each other
        printClocks(hours, minutes, seconds, isAM);
        // call the printMenu() function to print the menu for the user
        printMenu();

        // get the user input
        cin >> userInput;

        // switch statement that executes a specific function based on the users input
        switch(userInput){

            case '1': // add one hour to both clocks
                addHour(hours, isAM);
                break;

            case '2': // add one minute to both clocks
                minutes = addMinute(minutes);
                break;

            case '3': // add one second to both clocks
                seconds = addSeconds(seconds);
                break;

            case '4': // exit program
                cout << "Exiting Program\n";
                break;
            
            default: // if userInput is not between 1 and 4 restart loop
                break;
        }
    }
    return 0;
}

// function definitions

// print the menu for the user
void printMenu(){
    cout << setw(43) << setfill(' ') << "***************************\n";
    cout << setw(43) << setfill(' ') << "* 1 - Add One Hour        *\n";
    cout << setw(43) << setfill(' ') << "* 2 - Add One Minute      *\n";
    cout << setw(43) << setfill(' ') << "* 3 - Add One Second      *\n";
    cout << setw(43) << setfill(' ') << "* 4 - Exit Program        *\n";
    cout << setw(43) << setfill(' ') << "***************************\n";
}

// print the 12 hour clock and 24 hour clock side by side
void printClocks(int hours, int minutes, int seconds, bool isAM){

    // AM
    if (isAM){

        // print the first two rows of the 12 hour and 24 hour clocks
        cout << "***************************" << "   " << "***************************\n";
        cout << "*      12-Hour Clock      *" << "   " << "*      24-Hour Clock      *\n";

        // print 12 hour clock
        cout << "*       ";

        // if hours is 0 print 12 for midnight otherwise print hours
        if (hours == 0){
            cout << setw(2) << setfill('0') << hours + 12 << ":";
        }
        else{
            cout << setw(2) << setfill('0') << hours << ":";
        }

        // print the minutes and seconds of the 12 hour clock
        cout << setw(2) << setfill('0') << minutes <<  ":";
        cout << setw(2) << setfill('0') <<  seconds << " " << "AM";
        cout <<"       *";

        // space between clocks
        cout << "   ";

        // print 24 hour clock
        cout << "*        ";
        cout << setw(2) << setfill('0') << hours << ":";
        cout << setw(2) << setfill('0') << minutes <<  ":";
        cout << setw(2) << setfill('0') <<  seconds;
        cout << "         *\n";

        // print the bottom row of the clocks
        cout << "***************************" << "   " << "***************************\n";
    }

        // Print PM
    else{

        // print the first two rows of the 12 hour and 24 hour clocks
        cout << "***************************" << "   " << "***************************\n";
        cout << "*      12-Hour Clock      *" << "   " << "*      24-Hour Clock      *\n";

        // print 12 hour clock
        cout << "*       ";

        // if hours is 12 print 12 for noon otherwise subtract 12 from hours
        if (hours == 12){
            cout << setw(2) << setfill('0') << hours << ":";
        }
        else{
            cout << setw(2) << setfill('0') << hours - 12 << ":";
        }

        // print the minutes and sesconds of the 12 hour clock
        cout << setw(2) << setfill('0') << minutes <<  ":";
        cout << setw(2) << setfill('0') <<  seconds << " " << "PM";
        cout <<"       *";

        // space between clocks
        cout << "   ";

        // print 24 hour clock
        cout << "*        ";
        cout << setw(2) << setfill('0') << hours << ":";
        cout << setw(2) << setfill('0') << minutes <<  ":";
        cout << setw(2) << setfill('0') <<  seconds;
        cout << "         *\n";

        // print the bottom row of the clocks
        cout << "***************************" << "   " << "***************************\n";
    }
}

// add one hour two both clocks
void addHour(int &hour, bool &isMorning){
    hour += 1;

    // if hour is between 12 and 23 set isAM in main to false which triggers the PM if else branch when printing clocks
    if (hour >= 12 && hour < 24){
        isMorning = false;
    }

    // when hour equals 24 set hours in main to 0 and isAM to true to trigger the AM if else branch when printing clocks
    else if (hour == 24){
        hour = 0;
        isMorning = true;
    }
}

// adds one minute to both clocks
int addMinute(int minute){
    minute += 1;

    // if minute equals 60 set minute to 0
    // this sets a range of 0-59 for minute
    if (minute == 60){
        minute = 0;
    }
    return minute;
}

// adds one second to both clocks
int addSeconds(int second){
    second += 1;

    // if second equals 60 set second to 0
    // this sets a range of 0-59 for second
    if (second == 60){
        second = 0;
    }
    return second;
}
