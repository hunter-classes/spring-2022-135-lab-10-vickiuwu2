#include <iostream>
#include "time.h"

int main()
{
    Movie Movie1 = {"Back to the Future", COMEDY, 116};
    Movie Movie2 = {"Black Panther", ACTION, 134};
    TimeSlot morning = {Movie1, {9, 15}};  
    TimeSlot daytime = {Movie2, {12, 15}}; 
    TimeSlot evening = {Movie2, {16, 40}};

    std::cout << "---------------TASK A---------------\n";
    std::cout << "minutesSinceMidnight({10,30}) returns: " << minutesSinceMidnight({10,30}) << "\n";
    std::cout << "minutesSinceMidnight({13,40}) returns: " << minutesSinceMidnight({13,40}) << "\n";
    std::cout << "minutesUntil({10,30}, {13,40}) returns: " << minutesUntil({10,30}, {13,40}) << "\n\n";

    std::cout << "---------------TASK B---------------\n";
    std::cout << "addMinutes({8, 10}, 75) returns: " << getTime(addMinutes({8, 10}, 75)) << "\n";
    std::cout << "addMinutes({3, 55}, 30) returns: " << getTime(addMinutes({3, 55}, 30)) << "\n";
    std::cout << "addMinutes({4, 10}, 40) returns: " << getTime(addMinutes({4, 10}, 40)) << "\n\n";

    std::cout << "---------------TASK C---------------\n";
    std::cout << "getTimeSlot({{\"Back to the Future\", COMEDY, 116}, {9,15}}) returns:\n" << getTimeSlot({{"Back to the Future", COMEDY, 116}, {9,15}}) << "\n\n";
    std::cout << "getTimeSlot({{\"Black Panther\", ACTION, 134}, {12,15}}) returns:\n" << getTimeSlot({{"Black Panther", ACTION, 134}, {12,15}}) << "\n\n";
    std::cout << "getTimeSlot({{\"Black Panther\", ACTION, 134}, {16,45}}) returns:\n" << getTimeSlot({{"Black Panther", ACTION, 134}, {16,45}}) << "\n\n";

    std::cout << "---------------TASK D---------------\n";
    std::cout << "getTimeSlot(scheduleAfter(morning, Movie1)) returns:\n" << getTimeSlot(scheduleAfter(morning, Movie1)) << "\n\n";
    std::cout << "getTimeSlot(scheduleAfter(morning, Movie1)) returns:\n" << getTimeSlot(scheduleAfter(daytime, Movie2)) << "\n\n";

    std::cout << "---------------TASK E---------------\n";
    std::cout << "timeOverlap({{\"Back to the Future\", COMEDY, 116}, {9,15}}, {{\"Black Panther\", ACTION, 134}, {12,15}}) returns: " << std::boolalpha << timeOverlap({{"Back to the Future", COMEDY, 116}, {9,15}}, {{"Black Panther", ACTION, 134}, {12,15}}) << "\n";
    std::cout << "timeOverlap({{\"Back to the Future\", COMEDY, 116}, {9,15}}, {{\"Black Panther\", ACTION, 126}, {9,15}}) returns: " << std::boolalpha << timeOverlap({{"Back to the Future", COMEDY, 116}, {9,15}}, {{"Black Panther", ACTION, 116}, {9,15}}) << "\n\n";
}