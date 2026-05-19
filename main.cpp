#include <iostream>
#include <vector>
#include <memory>

using namespace std;
// ABSTRACT BASE CLASS (ABSTRACTION)
class Room{
protected:
    int roomID;
    string roomName;
    int capacity;
    bool available;
public:
Room(int id, string name, int cap, bool status){
        roomID = id;
        roomName = name;
        capacity = cap;
        available = status;
                                               }
    // ENCAPSULATION-using getters and setters
    int getRoomID() const{
        return roomID;
                         }
    int getCapacity() const{
        return capacity;
                           }
    bool isAvailable() const{
        return available;
                            }
    void setAvailability(bool status){
        available = status;
                                     }
    // POLYMORPHISM
    virtual void displayRoom() const{
        cout << "Room ID: " << roomID << endl;
        cout << "Room Name: " << roomName << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Status: " << (available ? "Available" : "Occupied") << endl;
                                    }
    virtual string getType() const = 0;
    virtual ~Room() {}
            };

// INHERITANCE - LECTURE HALL
class LectureHall : public Room{
public:
    LectureHall(int id, string name, int cap, bool status): Room(id, name, cap, status){}
    string getType() const override{
        return "Lecture Hall";
                                   }
    void displayRoom() const override{
        cout << "LECTURE HALL" << endl;
        Room::displayRoom();
                                     }
                               };

// INHERITANCE - LABORATORY
class Laboratory : public Room{
private:
    string labType;
    int equipmentCount;

public:
    Laboratory(int id,string name,int cap,bool status,string type,int equipment): Room(id, name, cap, status){
        labType = type;
        equipmentCount = equipment;
                                                                                                             }
    string getType() const override{
        return "Laboratory";
                                   }
    void displayRoom() const override{
        cout << "LABORATORY" << endl;

        Room::displayRoom();
        cout << "Laboratory Type: "
             << labType << endl;

        cout << "Equipment Count: "
             << equipmentCount << endl;
                                     }
                              };

// CLASS TIMETABLE CLASS
class LectureClass{
private:
    string course;
    string unit;
    int year;
    int students;
    string day;
    string time;
    int assignedRoom;
    bool cancelled;
public:
    LectureClass(string c, string u, int y, int s,string d, string t, int room){
        course = c;
        unit = u;
        year = y;
        students = s;
        day = d;
        time = t;
        assignedRoom = room;
        cancelled = false;
                                                                               }
    string getCourse() const{
        return course;
                            }
    string getDay() const{
        return day;
                         }
    string getTime() const{
        return time;
                          }
    int getRoom() const{
        return assignedRoom;
                       }
    bool isCancelled() const{
        return cancelled;
                            }
    void cancelClass(){
        cancelled = true;
                      }
    void updateSchedule(string newDay, string newTime){
        day = newDay;
        time = newTime;
                                                      }
    void displayClass() const{
        cout << "CLASS TIMETABLE " << endl;
        cout << "Course: " << course << endl;
        cout << "Unit: " << unit << endl;
        cout << "Year: " << year << endl;
        cout << "Students: " << students << endl;
        cout << "Day: " << day << endl;
        cout << "Time: " << time << endl;
        cout << "Assigned Room ID: " << assignedRoom << endl;

        if (cancelled){
            cout << "Status: Cancelled" << endl;
                      }
        else{
            cout << "Status: Active" << endl;
            }
                             }
                     };

// MAIN SYSTEM CLASS
class RoomManager{
private:
    vector<unique_ptr<Room>> rooms;
    vector<LectureClass> timetable;
public:
    // PRELOADED ROOMS
    void loadRooms(){
        rooms.push_back(make_unique<LectureHall>(101, "LH1", 150, true));
        rooms.push_back(make_unique<LectureHall>(102, "LH2", 100, true));
        rooms.push_back(make_unique<Laboratory>(201,"ElectronicsLab",40,true,"Electronics",35));
        rooms.push_back(make_unique<Laboratory>(202,"ChemistryLab",60,true,"Chemistry",50));
                    }

    // PRELOADED TIMETABLE
    void loadTimetable(){
        timetable.push_back(LectureClass("ElectricalEngineering","OOP",2,95,"Monday","8AM-10AM",101));
        timetable.push_back(LectureClass("ComputerScience","Programming",1,80,"Tuesday","10AM-12PM",102));
                        }

    // DISPLAY ROOMS
    void displayRooms() const{
        for (const auto &room : rooms){
            room->displayRoom();
                                      }
                             }

    // DISPLAY TIMETABLE
    void displayTimetable() const{
        for (const auto &lesson : timetable){
            lesson.displayClass();
                                            }
                                 }
    // ADD LECTURE HALL
    void addLectureHall(){
        int id;
        int capacity;
        string name;

        cout << "Enter Room ID: ";
        cin >> id;

        cout << "Enter Room Name: ";
        cin >> name;

        cout << "Enter Capacity: ";
        cin >> capacity;

        rooms.push_back(make_unique<LectureHall>(id, name, capacity, true));

        cout << "\nLecture Hall Added Successfully.\n" << endl;
                         }

    // ADD LABORATORY
void addLaboratory(){
    int id;
    int capacity;
    int equipment;

    string name;
    string labType;

    cout << "Enter Laboratory ID: ";
    cin >> id;

    cout << "Enter Laboratory Name: ";
    cin >> name;

    cout << "Enter Laboratory Type: ";
    cin >> labType;

    cout << "Enter Capacity: ";
    cin >> capacity;

    cout << "Enter Equipment Count: ";
    cin >> equipment;

    rooms.push_back(make_unique<Laboratory>(id, name, capacity, true, labType, equipment));

    cout << "\nLaboratory Added Successfully.\n"<< endl;
}

    // SEARCH ROOM BY ID
    void searchRoom(int id) const{
        for (const auto &room : rooms){
            if (room->getRoomID() == id){
                room->displayRoom();
                return;
                                        }
                                      }

        cout << "Room Not Found." << endl;
                                 }

    // SEARCH AVAILABLE ROOMS
    void searchAvailableRooms() const{
        bool found = false;

        for (const auto &room : rooms){
            if (room->isAvailable()){
                room->displayRoom();
                found = true;
                                    }
                                      }

        if (!found){
            cout << "No Available Rooms." << endl;
                   }
                                     }

    // CHECK TIMETABLE CONFLICT
    bool checkConflict(int roomID, string day, string time){
        for (const auto &lesson : timetable){
            if (lesson.getRoom() == roomID &&lesson.getDay() == day &&lesson.getTime() == time &&!lesson.isCancelled()){
                return true;
                                                                                                                       }
                                            }
        return false;
                                                           }

    // BOOK ROOM
    void bookRoom(){
        int roomID;
        string day;
        string time;

        cout << "Enter Room ID: ";
        cin >> roomID;

        cout << "Enter Day: ";
        cin >> day;

        cout << "Enter Time: ";
        cin >> time;

        for (auto &room : rooms){
            if (room->getRoomID() == roomID){
                if (checkConflict(roomID, day, time)){
                    cout << "Timetable Conflict Detected." << endl;
                    return;
                                                     }

                room->setAvailability(false);
                cout << "\nRoom Booked Successfully.\n" << endl;
                return;
                                            }
                                }

        cout << "Room Not Found." << endl;
                   }

    // ADD CLASS TO TIMETABLE
    void addClass(){
        string course;
        string unit;
        string day;
        string time;
        int year;
        int students;
        int roomID;

        cout << "Enter Course Name: ";
        cin >> course;

        cout << "Enter Unit Name: ";
        cin >> unit;

        cout << "Enter Year: ";
        cin >> year;

        cout << "Enter Number Of Students: ";
        cin >> students;

        cout << "Enter Day: ";
        cin >> day;

        cout << "Enter Time: ";
        cin >> time;

        cout << "Enter Assigned Room ID: ";
        cin >> roomID;

        if (checkConflict(roomID, day, time)){
            cout << "Cannot Add Class. Room Occupied." << endl;
            return;
                                             }

        timetable.push_back(LectureClass(course,unit,year,students,day,time,roomID));

        cout << "\nClass Added Successfully.\n" << endl;
                    }

    // UPDATE TIMETABLE
    void updateTimetable(string course){
        for (auto &lesson : timetable){
            if (lesson.getCourse() == course){
                string newDay;
                string newTime;

                cout << "Enter New Day: ";
                cin >> newDay;

                cout << "Enter New Time: ";
                cin >> newTime;

                lesson.updateSchedule(newDay, newTime);

                cout << "\nTimetable Updated Successfully\n." << endl;
                return;
                                             }
                                      }

        cout << "Course Not Found." << endl;
                                       }

    // CANCEL CLASS
    void cancelClass(string course){
        for (auto &lesson : timetable){
            if (lesson.getCourse() == course){
                lesson.cancelClass();
                cout << "\nClass Cancelled Successfully.\n" << endl;
                return;
                                             }
                                      }

        cout << "Course Not Found." << endl;
                                   }

    // DELETE ROOM
    void deleteRoom(int id){
        for (auto it = rooms.begin(); it != rooms.end(); ++it){
            if ((*it)->getRoomID() == id){
                rooms.erase(it);
                cout << "\nRoom Deleted Successfully.\n" << endl;
                return;
                                         }
                                                              }

        cout << "Room Not Found." << endl;
                           }
                };
// MENU FUNCTION
void menu(){
    cout << endl <<" =========================" << endl;
    cout << " SMART LECTURE ROOM SYSTEM" << endl;
    cout << " =========================" << endl << endl;

    cout << "1. Display Rooms" << endl;
    cout << "2. Display Timetable" << endl;
    cout << "3. Search Room By ID" << endl;
    cout << "4. Display Available Rooms" << endl;
    cout << "5. Book Room" << endl;
    cout << "6. Add Lecture Hall" << endl;
    cout << "7. Add Laboratory" << endl;
    cout << "8. Add Class To Timetable" << endl;
    cout << "9. Update Timetable" << endl;
    cout << "10. Cancel Class" << endl;
    cout << "11. Delete Room" << endl;
    cout << "0. Exit" << endl;
    cout << endl;

    cout << "Enter Choice: ";
           }

// MAIN FUNCTION
int main()
{
    RoomManager manager;
    manager.loadRooms();
    manager.loadTimetable();

    int choice;

    do{
        menu();
        cin >> choice;

        if (choice == 1){
            manager.displayRooms();
                        }
        else if (choice == 2){
            manager.displayTimetable();
                             }
        else if (choice == 3){
            int id;

            cout << "Enter Room ID: ";
            cin >> id;

            manager.searchRoom(id);
                             }
        else if (choice == 4){
            manager.searchAvailableRooms();
                             }
        else if (choice == 5){
            manager.bookRoom();
                             }
        else if (choice == 6){
            manager.addLectureHall();
                             }
        else if (choice == 7){
            manager.addLaboratory();
                             }
        else if (choice == 8){
            manager.addClass();
                             }
        else if (choice == 9){
            string course;

            cout << "Enter Course Name: ";
            cin >> course;

            manager.updateTimetable(course);
                             }
        else if (choice == 10){
            string course;

            cout << "Enter Course Name: ";
            cin >> course;

            manager.cancelClass(course);
                              }
        else if (choice == 11){
            int id;

            cout << "Enter Room ID To Delete: ";
            cin >> id;

            manager.deleteRoom(id);
                              }
        else if (choice == 0){
            cout << "Exiting System..." << endl;
                             }

        else{
            cout << "Invalid Choice." << endl;
            }

      }
      while (choice != 0);

    return 0;
}

