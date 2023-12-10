#include <iostream>
#include <string>

// Класс University
class University {
private:
    std::string name;
    Students* students;
    Faculty* faculty;
public:
    University(const std::string& n, Students* s, Faculty* f) : name(n), students(s), faculty(f) {
    }

    std::string getName() const {
        return name;
    }

    Students* getStudents() const {
        return students;
    }

    Faculty* getFaculty() const {
        return faculty;
    }
};

// Класс Students
class Students {
private:
    int numStudents;
public:
    Students() {
        numStudents = 0;
    }

    Students(int num) : numStudents(num) {
    }

    int getNumStudents() const {
        return numStudents;
    }

    void setNumStudents(int num) {
        numStudents = num;
    }

    void showUniversity(University& university) {
        std::cout << "This is " << university.getName() << ", where " << numStudents << " students study." << std::endl;
    }
};

// Класс Faculty (родительский класс)
class Faculty {
private:
    std::string department;
    std::string head;
public:
    Faculty() {
        department = "Unknown";
        head = "Unknown";
    }

    Faculty(const std::string& dep, const std::string& h) : department(dep), head(h) {
    }

    std::string getDepartment() const {
        return department;
    }

    std::string getHead() const {
        return head;
    }
};

// Класс FullTimeEducation (наследник класса Faculty)
class FullTimeEducation : public Faculty {
private:
    int numCourses;
    std::string location;
public:
    FullTimeEducation() : Faculty() {
        numCourses = 0;
        location = "Unknown";
    }

    FullTimeEducation(const std::string& dep, const std::string& h, int num, const std::string& loc) :
        Faculty(dep, h), numCourses(num), location(loc) {
    }

    FullTimeEducation(const std::string& dep, const std::string& h, int num) :
        Faculty(dep, h), numCourses(num), location("Unknown") {
    }

    FullTimeEducation(int num) : Faculty(), numCourses(num), location("Unknown") {
    }

    int getNumCourses() const {
        return numCourses;
    }

    std::string getLocation() const {
        return location;
    }

    void teach() {
        std::cout << "Teaching full-time courses" << std::endl;
    }

    void showFaculty() {
        std::cout << "This is the Full-Time Education Department of the Faculty of " << getDepartment() << std::endl;
        std::cout << "The head of this department is " << getHead() << std::endl;
        std::cout << "It offers " << numCourses << " courses and is located at " << location << std::endl;
    }
};

// Класс DistanceEducation (наследник класса Faculty)
class DistanceEducation : public Faculty {
private:
    int numStudents;
    std::string platform;
public:
    DistanceEducation() : Faculty() {
        numStudents = 0;
        platform = "Unknown";
    }

    DistanceEducation(const std::string& dep, const std::string& h, int num, const std::string& plat) :
        Faculty(dep, h), numStudents(num), platform(plat) {
    }

    DistanceEducation(const std::string& dep, const std::string& h, int num) :
        Faculty(dep, h), numStudents(num), platform("Unknown") {
    }

    DistanceEducation(int num) : Faculty(), numStudents(num), platform("Unknown") {
    }

    int getNumStudents() const {
        return numStudents;
    }

    std::string getPlatform() const {
        return platform;
    }

    void teach() {
        std::cout << "Teaching distance education courses" << std::endl;
    }

    void showFaculty() {
        std::cout << "This is the Distance Education Department of the Faculty of " << getDepartment() << std::endl;
        std::cout << "The head of this department is " << getHead() << std::endl;
        std::cout << "It has " << numStudents << " students and uses the " << platform << " platform." << std::endl;
    }
};
int main() {
    Students students(1000);
    Faculty faculty("Computer Science", "John Doe");

    University university("MyUniversity", &students, &faculty);

    Students* universityStudents = university.getStudents();
    Faculty* universityFaculty = university.getFaculty();

    universityStudents->showUniversity(university);
    universityFaculty->showFaculty();

    FullTimeEducation fullTimeEducation("Computer Science", "Jane Smith", 10, "Campus A");
    DistanceEducation distanceEducation("Business", "Alex Johnson", 500, "Online platform");

    fullTimeEducation.showFaculty();
    distanceEducation.showFaculty();

    return 0;
}