#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

json loadData() {
    // Assuming JSON data is in a string for demonstration; it could also be loaded from a file
    std::string jsonData = R"({
      "Majors": {
        "DSAI": {
          "Concentrations": [null]
        },
        "SWD": {
          "Concentrations": ["HCI", "APD", "GD"]
        },
        "IT": {
          "Concentrations": ["NS", "CC"]
        }
      },
      "Years": ["2022", "2023"],

      "canOverload" : false


    })";

    json j = json::parse(jsonData);
    return j;
}

class Student {
private:
    std::string major;
    std::string year;
    std::string concentration;
    double cGPA;
    bool canOverload;



public:

    Student() : cGPA(0.0), canOverload(false) {}

    // Setters for student data
    void setMajor(const std::string& m) { major = m; }
    void setYear(const std::string& y) { year = y; }
    void setConcentration(const std::string& c) { concentration = c; }
    void setCgpa(double g) { cGPA = g; }
    void setCanOverload(bool o) { canOverload = o; }

    // Function to configure student from console input
    bool setDetails(const json& data) {
        std::cout << "Enter your major: ";
        std::cin >> major;
        std::cout << "Enter your concentration: ";
        std::cin >> concentration;
        std::cout << "Enter your year: ";
        std::cin >> year;
        std::cout << "Enter your cGPA: ";
        std::cin >> cGPA;

        if (validateMajorAndConcentration(major, concentration, data) &&
            validateYear(year, data)) {
            if (cGPA > 3.0) {
                std::cout << "Are you able to overload? (1 for yes, 0 for no): ";
                std::cin >> canOverload;
            }
            std::cout << "Student configured successfully." << std::endl;
            return true;
        }
        std::cout << "Failed to configure student with provided data." << std::endl;
        return false;
    }

    // Helper functions to validate inputs against JSON data
    bool validateMajorAndConcentration(const std::string& major, const std::string& concentration, const json& data) {
        auto majors = data["Majors"];
        if (majors.contains(major) &&
            std::find(majors[major]["Concentrations"].begin(), majors[major]["Concentrations"].end(), concentration) != majors[major]["Concentrations"].end()) {
            return true;
        }
        std::cout << "Invalid major or concentration entered." << std::endl;
        return false;
    }

    bool validateYear(const std::string& year, const json& data) {
        auto years = data["Years"];
        if (std::find(years.begin(), years.end(), year) != years.end()) {
            return true;
        }
        std::cout << "Invalid year entered." << std::endl;
        return false;
    }













};


class CLI {

private:
Student studentinput;


     void printSlowly(const std::string& text, unsigned int milliseconds) {
        for (char const &c : text) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
        }
    }


public:

    void run() {

        std::string Zewail_logo =
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡤⡄⠀⠀⢫⣯⡇⡤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡠⠔⡆⡟⢣⠀⣰⢺⡅⣇⠟⣇⡤⡄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡳⣄⢀⡻⢹⣆⣿⢸⡸⣨⠁⠛⠚⠂⠨⢤⣭⣰⡟⠦⡍⢳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⡉⡵⠺⣿⠽⠓⠉⠉⠁⠀⠀⠀⠀⠀⠈⠛⠚⠈⠉⠒⢬⢁⡑⡆⠀⠀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠖⣿⠿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠢⠔⣿⠲⡀⠀⠀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠞⣡⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣌⠢⡀⠀⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⠀⡰⢁⡜⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢢⠈⢄⠀⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⠀⡰⢁⠎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⡼⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠱⡈⢧⠀⠀\n"
                "⠀⠀⠀⠀⠀⠀⡰⠁⡎⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣦⡀⠀⣠⣾⢿⣻⠁⠈⠻⣷⢄⠀⠀⢀⣤⣄⠀⠀⠀⠀⠀⠀⠀⢱⠈⢇⠀\n"
                "⠀⠀⠀⠀⠀⢠⠃⡸⠀⠀⠀⠀⠀⠀⠀⢀⣴⡿⣯⠏⠙⢾⣟⢁⣮⠇⠀⠀⠀⠈⠳⣕⢾⣿⣻⠻⣷⣄⠀⠀⠀⠀⠀⠀⢇⠘⡄\n"
                "⠀⠀⠀⠀⠀⡸⢀⡇⠀⠀⠀⠀⠀⢀⣴⡿⠋⡸⡞⠀⠀⠈⠻⣟⢞⠀⠀⠀⠀⠀⠀⠈⠳⣝⢇⠀⠈⠻⣷⢄⠀⠀⠀⠀⠸⡀⢇\n"
                "⠀⠀⠀⠀⠀⡇⢸⠀⠀⠀⠀⣀⢴⡿⣫⣴⣿⡷⡃⠀⠀⠀⠀⠈⠳⣵⣶⢿⣦⢀⠀⠀⠀⠈⠳⣕⢄⠀⠈⠳⣕⢄⠀⠀⠀⡇⢸\n"
                "⠀⠀⠀⠀⠀⣗⣚⣒⣒⣒⣚⣓⣓⣚⣻⣻⠃⠙⢮⣓⣒⣒⣒⣒⣚⣛⣟⡎⠈⠢⣑⣒⣒⣒⣒⣚⣳⣕⣒⣒⣚⣳⣕⣒⣒⣓⣺\n"
                "⠀⠀⠀⠀⠀⣤⡒⢲⡖⣶⡖⠒⢒⣤⡦⡤⣶⣄⠀⣠⣦⢦⠀⠀⡖⡶⡶⡄⠀⠀⠀⢀⣤⡶⢶⣄⣰⢦⣔⡖⢐⠒⡢⣄⠀⢠⣷\n"
                "⠀⠀⠀⠀⠀⠉⢀⢞⡜⠁⠀⣥⣤⡍⢱⢹⣼⡜⣤⣿⣿⣏⢧⠀⡇⡇⡇⡇⠀⠀⠀⡞⡸⠀⠈⠓⣿⠘⠉⠁⡎⠀⠈⢎⢳⡿⠁\n"
                "⠀⠀⠀⠀⠀⡠⢣⡎⠀⣀⡀⣇⢀⣴⠀⢇⣹⢳⢹⣿⠟⠛⣌⢆⡇⣇⡇⠇⠀⢀⠀⠱⣹⣄⣀⣴⣿⢀⠀⣀⣧⠀⠀⢸⢸⡁⠀\n"
                "⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀⠈⠁⠀⠉⠉⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠀⠀⠈⠉⠉⠁⠈⠉⠀⠈⠉⠀⠀⠀⠉⠀⠀\n"
                "Welcome to the CSAI Study Plan Editor! Enter 'start'.     \n ";

        unsigned int delay = 1;

        printSlowly(Zewail_logo, delay);


        std::string command;

        while (true) {

            std::cout<<"-> ";
            std::getline(std::cin, command);


            if (command == "exit") {
                break;
            }
            else if (command == "start") {
                studentinput.setDetails((loadData()));
            }




        }




    }


};

int main() {
    CLI cli;
    cli.run();
    return 0;


}
