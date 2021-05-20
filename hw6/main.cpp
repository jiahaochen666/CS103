//
// Created by jiaha on 5/15/2021.
//


#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>

#define FRONT 0
#define BACK 1

using namespace std;

struct Instructor {
    string name;
    int start;
    int end;
};

struct CourseInfo {
    string name;
    string type;
    string days;
    int start;
    int duration;
    Instructor instructor;
};

vector<vector<string>> course_plan;
map<string, vector<CourseInfo>> course_schedule;
map<string, Instructor> instructors;
int total = 0;

void add_course(const CourseInfo &course) {
    if (course_schedule.find(course.name) == course_schedule.end())
        course_schedule.insert({course.name, vector<CourseInfo>{course}});
    else
        course_schedule.at(course.name).push_back(course);
}

void read_instructor(const string &path) {
    ifstream file(path);
    string line, first, arrow, name;
    int start, end;
    while (getline(file, line)) {
        istringstream ss{line};
        if (ss >> first >> arrow) {
            ss.ignore();
            if (first == "instructor")
                getline(ss, name);
            else if (first == "start-time")
                ss >> start;
            else {
                ss >> end;
                instructors.insert({name, {name, start, end}});
            }
        }
    }
}

void read_coursePlans(const string &path) {
    ifstream file;
    file.open(path);
    string line, first, arrow, second;
    course_plan.emplace_back();
    int index = 0;
    while (getline(file, line)) {
        istringstream ss{line};
        if (ss >> first >> arrow) {
            ss.ignore();
            getline(ss, second);
            course_plan[index].push_back(second);
        } else {
            index++;
            course_plan.emplace_back();
        }
    }
}

void read_schedule(const string &path) {
    ifstream file;
    file.open(path);
    string line, first, arrow, second, name, type, days, instructor;
    int start, duration;
    while (getline(file, line)) {
        istringstream ss{line};
        if (ss >> first >> arrow) {
            ss.ignore();
            getline(ss, second);
            if (first == "course")
                name = second;
            else if (first == "type")
                type = second;
            else if (first == "days")
                days = second;
            else if (first == "start-time")
                start = stoi(second);
            else if (first == "duration")
                duration = stoi(second);
            else {
                instructor = second;
                add_course({name, type, days, start, duration, instructors.at(instructor)});
                total++;
            }
        }
    }
    file.close();
}

int time_diff(int time1, int time2) {
    if (time1 < time2){
        int temp = time1;
        time1 = time2;
        time2 = temp;
    }
    int minute1 = time1 % 100;
    int minute2 = time2 % 100;
    int hour = time1 / 100 - time2 / 100;
    if (minute1 < minute2) {
        int diff = minute2 - minute1;
        minute1 = 60 - diff;
        hour--;
    } else
        minute1 = minute1 - minute2;
    return hour * 60 + minute1;
}

bool move_time(int *time, const Instructor &instructor, int &duration) {
    int minute = *time % 100;
    if (minute == 40) {
        *time += 70;
    } else {
        *time += 30;
    }
    if (time_diff(instructor.end, *time) < duration || instructor.end <= *time) {
        return false;
    }
    return true;
}


vector<map<string, vector<CourseInfo>>> NEIGHBOR(map<string, vector<CourseInfo>> &schedule, int index) {
    vector<map<string, vector<CourseInfo>>> neighbor;
    int count = 0;
    for (auto &it: schedule) {
        for (int i = 0; i < it.second.size(); i++) {
            if (count == index) {
                int start = it.second[i].instructor.start + 10 - 30;
                while (move_time(&start, it.second[i].instructor, it.second[i].duration)) {
                    map<string, vector<CourseInfo>> temp = schedule;
                    temp.at(it.first)[i].start = start;
                    neighbor.push_back(temp);
                }
                break;
            }
            count++;
        }
    }
    return neighbor;
}

bool days_conflict(const string &first, const string &second) {
    for (auto &c1:first) {
        for (auto &c2:second) {
            if (c1 == c2)
                return true;
        }
    }
    return false;
}


int time_conflict(const CourseInfo &course1, const CourseInfo &course2) {
    if (course1.start == course2.start ||
        (course1.start < course2.start && time_diff(course2.start, course1.start) < course1.duration + 10))
        return course1.duration + 10 - time_diff(course2.start, course1.start);
    else if (course2.start < course1.start && time_diff(course1.start, course2.start) < course2.duration + 10)
        return course2.duration + 10 - time_diff(course1.start, course2.start);
    return 0;
}

map<string, std::vector<CourseInfo>> get_instructor(map<string, vector<CourseInfo>> &schedule){
    map<string, std::vector<CourseInfo>> out;
    for (auto& ins: instructors){
        out.insert({ins.first, {}});
        for (auto& it: schedule){
            for (auto& course: it.second){
                if (ins.first == course.instructor.name)
                    out.at(ins.first).push_back(course);
            }
        }
    }
    return out;
}

int EVAL(map<string, vector<CourseInfo>> &schedule) {
    int conflict = 0;
    for (auto &it: schedule) {
        for (int i = 0; i < it.second.size(); i++) {
            for (int j = i + 1; j < it.second.size(); j++) {
                if (days_conflict(it.second[i].days, it.second[j].days)) {
                    if (time_conflict(it.second[i], it.second[j]) != 0) {
                        conflict += time_conflict(it.second[i], it.second[j]);
                    }
                }
            }
        }
    }
    for (auto &v: course_plan) {
        for (int i = 0; i < v.size(); i++) {
            vector<CourseInfo> course1 = schedule.at(v[i]);
            for (int j = i + 1; j < v.size(); j++) {
                vector<CourseInfo> course2 = schedule.at(v[j]);
                for (auto &c1: course1) {
                    for (auto &c2: course2) {
                        if (days_conflict(c1.days, c2.days) && time_conflict(c1, c2) != 0)
                            conflict += time_conflict(c1, c2);
                    }
                }
            }
        }
    }
    map<string, std::vector<CourseInfo>> ins_to_course = get_instructor(schedule);
    for (auto& ins: ins_to_course){
        for (int i = 0; i < ins.second.size(); i++){
            if (ins.second[i].start < ins.second[i].instructor.start || time_diff(ins.second[i].instructor.end, ins.second[i].start) < ins.second[i].duration + 10)
                conflict++;
            for (int j = i + 1; j < ins.second.size(); j++){
                if (days_conflict(ins.second[i].days, ins.second[j].days) && time_conflict(ins.second[i], ins.second[j]) != 0)
                    conflict += time_conflict(ins.second[i], ins.second[j]);
            }
        }
    }
    return conflict;
}


void initial(){
    for (auto& v: course_schedule){
        for (auto& course: v.second){
            course.start = course.instructor.start + 10;
        }
    }
}

void hill_climbing() {
    initial();
    map<string, vector<CourseInfo>> current_schedule = course_schedule;
    int currentVal = EVAL(current_schedule);
    while (currentVal != 0) {
        cout << currentVal << endl;
        for (int i = 0; i < total; i++) {
            vector<map<string, vector<CourseInfo>>> neighbor = NEIGHBOR(current_schedule, i);
            for (auto &possibleNext: neighbor) {
                int possibleVal = EVAL(possibleNext);
                if (possibleVal <= currentVal) {
                    current_schedule = possibleNext;
                    currentVal = possibleVal;
                }
            }
            if (currentVal == 0)
                break;
        }
    }
    course_schedule = current_schedule;
}

void print_schedule() {
    string out = "";
    for (auto &it : course_schedule) {
        for (auto &course: it.second) {
            out += "course => " + course.name + "\n"
                   + "type => " + course.type + "\n"
                   + "days => " + course.days + "\n"
                   + "start-time => " + to_string(course.start) + "\n"
                   + "duration => " + to_string(course.duration) + "\n"
                   + "instructor => " + course.instructor.name + "\n" + "\n";
        }
    }
    cout << out.substr(0, out.size() - 1);
}

int main() {
    read_instructor("instructors.txt");
    read_schedule("inputSchedule.txt");
    read_coursePlans("coursePlans.txt");
    hill_climbing();
    print_schedule();
    return 0;
}
