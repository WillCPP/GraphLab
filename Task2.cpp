//Task2.cpp, will include all of the functions 
#include <time.h>
#include <iostream> 
#include <iomanip>

Student::Student(string firstName, string lastName, string mNumber, string birthday, double GPA = 0){
      newfirstName = firstName; //This will access the private members of the class, using a copy constructor.
      newlastName = lastName; //A copy constructor will initialize one object from another of the same type, from the student class
      newmNumber = mNumber; //This will assign the members so that new students can be added into the inventory.
      newGPA = GPA;
      newbirthday = birthday
    //find a way to call all of themembers from the student class constructor using a pointer
    //GPA is optional, but still can be pointed to and accessed.

}

//look in pg. 829 in book if redoing in future


//GetAge() function, using birthday. 
//Basically an age calculator
int Student::GetAge() {

//got local time function reference here: https://codereview.stackexchange.com/questions/124898/calculate-age-in-seconds
time_t now = time(0); 
tm *ltm = localtime(&now);

//type referenced from: http://www.cplusplus.com/reference/ctime/tm/
//year
int currentYear = 1990 + (ltm->tm_year);
//month
int currentMonth = 1 + (ltm->tm_month);
//day
int currentDay = ltm->tm_mday;


//substr. function reference: http://www.cplusplus.com/reference/string/string/substr/
int y = stoi(birthday.substr(6,4)); //this will pull out the numerical values and below, it will allow the age to be calculated.
int m = stoi(birthday.substr(0,2));
int d = stoi(birthday.substr(3,2));
int age = currentYear-y;


//if the monthh now is less than or equal to current month (and todays date is less than birthday, return age-1)
if(currentMonth < m || currentMonth == m && currentDay < d) {
      age--;
}
else {
      return age; //otherwise, just return the age
}
}


//overload operators
bool Student::operator > (const Student &){
      //if the MNumber is > another Mnumber, return the higher one.
}
bool Student::operator < (const Student &){
      //if the MNumber is < another Mnumber, return the lower one.
      
}
bool Student::operator == (const Student &){
      //will compare the MNumbers, if they are equal, return. 
      
}

void Student::Display() {
//Display() function (not done)
//Will display all of the student information formatted correctly 
//Will display the name, age, id, and GPA if given.
//using a pointer to access the functions GetName(), GetNUmber(), GetAge(), and the function to get the GPA.

}     

