#include <iostream>
#include "time.h"

std::string getTime(Time time) 
{
  return std::to_string(time.h) + ":" + std::to_string(time.m);
}

//Task A
int minutesSinceMidnight(Time time)
{
    int mins;
    mins = ((time.h * 60) + time.m);
    return mins;
}

int minutesUntil(Time earlier, Time later)
{
    int mins;
    mins = minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
    return mins;
}

//Task B
Time addMinutes(Time time0, int min)
{
    int hour = (time0.h + (min / 60));
    int mins = (time0.m + (min % 60));

    if (mins >= 60)
    {
        hour += mins / 60;
        mins = mins % 60;
    }

    return {hour, mins};
}

//Task C
std::string printMovie(Movie mv)
{
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    return mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
}

std::string getTimeSlot(TimeSlot ts)
{
    std::string result = printMovie(ts.movie);
    result += " [starts at " + getTime(ts.startTime) + ", ends by " + getTime(addMinutes(ts.startTime, ts.movie.duration)) + "]";
    return result;
}

//Task D
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    Movie film = ts.movie;
    Time new_start = addMinutes(ts.startTime, film.duration);
    return {nextMovie, new_start};
}

//Task E
bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    int ts1Start = minutesSinceMidnight(ts1.startTime);
    int ts2Start = minutesSinceMidnight(ts2.startTime);
    int ts1End = ts1Start + ts1.movie.duration;
    int ts2End = ts2Start + ts2.movie.duration;

    if ((ts1Start < ts2Start && ts1End <= ts2Start) || (ts2Start < ts1Start && ts2End <= ts1Start))
    {
        return false;
    }
    return true;
}