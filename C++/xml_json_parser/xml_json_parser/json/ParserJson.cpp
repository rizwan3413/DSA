#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>
#include <vector>
#include <algorithm>

using namespace boost::property_tree;
using namespace std;

const string  DATA_FILE = "data.json";

class Student {
    public:
    string name;
    unsigned int id;
    string address;
    unsigned int age;
    string phoneNo;
    bool operator<(const Student& com) const {
        return id < com.id;
    }
};

class CollegeData {
    public:
    string collegeName;
    string dean;
    vector<Student> students;
    void parser(const string& filename) {
        //Let's create empty tree
        ptree tree;
        //Let's read everything inside tree object
        read_json(filename,tree);

        //Let's store the information from tree to our class variables
        collegeName = tree.get<string>("CollegeData.CollegeName");
        dean = tree.get<string>("CollegeData.Dean");
        for(ptree::value_type &val: tree.get_child("CollegeData.Students")) {
            //if()
            Student temp;
            temp.name = val.second.get<string>("name");
            temp.id = val.second.get<int>("id");
            temp.address = val.second.get<string>("address");
            temp.age = val.second.get<int>("age");
            temp.phoneNo = val.second.get<string>("phone");
            students.push_back(temp);
        }
    }

    void addToFile(const string& filename) {
        ptree tree;
        tree.put("CollegeData.CollegeName",collegeName);
        tree.put("CollegeData.Dean",dean);
        for(const Student& student:students) {
            tree.put("CollegeData.Students.Student.Name",student.name);
            tree.put("CollegeData.Students.Student.ID",student.id);
            tree.put("CollegeData.Students.Student.Addresss",student.address);
            tree.put("CollegeData.Students.Student.Age",student.age);
            tree.put("CollegeData.Students.Student.PhoneNo",student.phoneNo);
        }
        write_json(filename,tree);
    }
    
    friend ostream& operator << (ostream& out, const CollegeData& data) {
        out << "College: " << data.collegeName << endl;
        out << "Dean: " << data.dean<< endl;
        out << "No of Students: " << data.students.size() << endl;
        for(const Student& student: data.students) {
            out << "    Name: " << student.name << endl;
            out << "    ID: " << student.id << endl;
            out << "    Address: " << student.address << endl;
            out << "    Age: " << student.age << endl;
            out << "    Phone Number: " << student.phoneNo << endl;
        }
        return out;
    } 
    

    void printData() {
        cout << "College: " << collegeName << endl;
        cout << "Dean: " << dean<< endl;
        cout << "No of Students: " << students.size() << endl;
        for(const Student& student: students) {
            cout << "    Name: " << student.name << endl;
            cout << "    ID: " << student.id << endl;
            cout << "    Address: " << student.address << endl;
            cout << "    Age: " << student.age << endl;
            cout << "    Phone Number: " << student.phoneNo << endl;
        }

    }

    string getCollegeName() {
        return collegeName;
    }

    string getDean() {
        return dean;
    }
};

int main() {
    CollegeData data;
    data.parser(DATA_FILE);
    data.addToFile("Output.json");
    cout << data << endl;
    //data.printData();
    return 0;
}
