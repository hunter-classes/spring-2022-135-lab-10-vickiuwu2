#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "time.h"

Movie Movie1 = {"Back to the Future", COMEDY, 116};
Movie Movie2 = {"Black Panther", ACTION, 134};
TimeSlot morning = {Movie1, {9, 15}};  
TimeSlot daytime = {Movie2, {12, 15}}; 
TimeSlot evening = {Movie2, {16, 40}};

TEST_CASE("Task A")
{
    CHECK(minutesSinceMidnight({10,30}) == 630);
    CHECK(minutesSinceMidnight({13,40}) == 820);
    CHECK(minutesUntil({10,30}, {13,40}) == 190);
}

TEST_CASE("Task B")
{
    CHECK(getTime(addMinutes({8, 10}, 75)) == "9:25");
    CHECK(getTime(addMinutes({3, 55}, 30)) == "4:25");
    CHECK(getTime(addMinutes({4, 10}, 40)) == "4:50");
}

TEST_CASE("Task C")
{
    CHECK(getTimeSlot({{"Back to the Future", COMEDY, 116}, {9,15}}) == "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]");
    CHECK(getTimeSlot({{"Black Panther", ACTION, 134}, {12,15}}) == "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]");
    CHECK(getTimeSlot({{"Black Panther", ACTION, 134}, {16,45}}) == "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]");
}

TEST_CASE("Task D")
{
    CHECK(getTimeSlot(scheduleAfter(morning, Movie1)) == "Back to the Future COMEDY (116 min) [starts at 11:11, ends by 13:7]");
    CHECK(getTimeSlot(scheduleAfter(daytime, Movie2)) == "Black Panther ACTION (134 min) [starts at 14:29, ends by 16:43]");
}

TEST_CASE("Task E")
{
    CHECK(timeOverlap({{"Back to the Future", COMEDY, 116}, {9,15}}, {{"Black Panther", ACTION, 134}, {12,15}}) == false);
    CHECK(timeOverlap({{"Back to the Future", COMEDY, 116}, {9,15}}, {{"Black Panther", ACTION, 116}, {9,15}}) == true);
}