// ============================================================================
// File: CPersonInfo.cpp
// ============================================================================
// Implementation file for the class CPersonInfo
// ============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include "CPersonInfo.h"

using namespace std;



// ==== CPersonInfo::CPersonInfo ===============================================
//
// This is the CPersonInfo constructor.  It sets the first and last name to the
// empty string and sets age, checking, and savings to zero.
//
// Input:
//       void
//
// Output:
//       Nothing
//
// =============================================================================
CPersonInfo::CPersonInfo() {
   this->m_fname = "";
   this->m_lname = "";
   this->m_age = 0;
   this->m_checking = 0;
   this->m_savings = 0;
}




// ==== CPersonInfo::CPersonInfo ===============================================
//
// This is the CPersonInfo type constructor.  It initializes the private data
// members to the arguments passed.
//
// Input:
//       fname      [IN]    - A const string reference variable that represents
//                              the first name of a person.
//       lname      [IN]    - A const string reference variable that represents
//                              the last name of a person.
//       age        [IN]    - An int for the person's age.
//       checking   [IN]    - A double for person's amount in their checking.
//       savings    [IN]    - A double for person's amount in their savings.
//
// Output:
//       void
//
// =============================================================================
CPersonInfo::CPersonInfo(const string &fname, const std::string &lname, int age, double checking, double savings) {
   this->m_fname = fname;
   this->m_lname = lname;
   this->m_age = age;
   this->m_checking = checking;
   this->m_savings = savings;
}




// ==== CPersonInfo::SetFirstName ==============================================
//
// This function assigns the first name to m_fname.
//
// Input:
//       fname      [IN]    - A const string reference variable that represents
//                              the first name of a person.
//
// Output:
//       void
//
// =============================================================================
void CPersonInfo::SetFirstName(const std::string &fname) {
    this->m_fname = fname;
}




// ==== CPersonInfo::SetLastName ===============================================
//
// This function assigns the last name to m_lname.
//
// Input:
//       lname      [IN]    - A const string reference variable that represents
//                              the last name of a person.
//
// Output:
//       void
//
// =============================================================================
void CPersonInfo::SetLastName(const std::string &lname) {
    this->m_lname = lname;
}




// ==== CPersonInfo::SetAge ====================================================
//
// This function assigns the age to m_age.
//
// Input:
//       age        [IN]    - An int for the person's age.
//
// Output:
//       void
//
// =============================================================================
void CPersonInfo::SetAge(int age) {
    this->m_age = age;
}




// ==== CPersonInfo::SetChecking ===============================================
//
// This function assigns the checking to m_checking.
//
// Input:
//       checking   [IN]    - A double for person's amount in their checking.
//
// Output:
//       void
//
// =============================================================================
void CPersonInfo::SetChecking(double checking) {
    this->m_checking = checking;
}




// ==== CPersonInfo::SetSavings ================================================
//
// This function assigns the savings to m_savings.
//
// Input:
//       savings    [IN]    - A double for person's amount in their savings.
//
// Output:
//       void
//
// =============================================================================
void CPersonInfo::SetSavings(double savings) {
    this->m_savings = savings;
}





// ==== CPersonInfo::GetFirstName ==============================================
//
// This function returns the first name.
//
// Input:
//       void
//
// Output:
//       A string that represents the first name of a person.
//
// =============================================================================
string CPersonInfo::GetFirstName() const{
    return this->m_fname;
}





// ==== CPersonInfo::GetLastName ===============================================
//
// This function returns the last name.
//
// Input:
//       void
//
// Output:
//       A string that represents the last name of a person.
//
// =============================================================================
string CPersonInfo::GetLastName() const {
    return this->m_lname;
}





// ==== CPersonInfo::GetAge ====================================================
//
// This function returns the age.
//
// Input:
//       void
//
// Output:
//       An int that represents the age of a person.
//
// =============================================================================
int CPersonInfo::GetAge() const {
    return this->m_age;
} 




// ==== CPersonInfo::GetChecking ===============================================
//
// This function returns the amount in checking.
//
// Input:
//       void
//
// Output:
//       A double that represents the amount in a person's checking account.
//
// =============================================================================
double CPersonInfo::GetChecking() const {
    return this->m_checking;
}




// ==== CPersonInfo::GetSavings ================================================
//
// This function returns the amount in savings.
//
// Input:
//       void
//
// Output:
//       A double that represents the amount in a person's savings account.
//
// =============================================================================
double CPersonInfo::GetSavings() const{
    return this->m_savings;
}




// ==== CPersonInfo::operator== ================================================
//
// This function checks if two CPersonInfo objects are the same (checks all
// member variables).
//
// Input:
//       rhs    [IN]    - A const CPersonInfo reference object.
//
// Output:
//       Returns true if the objects are the same, false otherwise.
//
// =============================================================================
bool CPersonInfo::operator==(const CPersonInfo &rhs) {
    return this->m_fname == rhs.m_fname &&
    this->m_lname == rhs.m_lname &&
    this->m_age == rhs.m_age &&
    this->m_checking == rhs.m_checking &&
    this->m_savings == rhs.m_savings;
}




// ==== CPersonInfo::operator> =================================================
//
// This function checks if left-hand side CPersonInfo object is greater than
// right-hand side CPersonInfo object.
//
// Note: We are only checking for the data member m_age to be greater than. The
//          goal is to one day test if all data members or others.
//
// Input:
//       rhs    [IN]    - A const CPersonInfo reference object.
//
// Output:
//       Returns true if lhs age is greater than rhs age, otherwise false.
//
//
// =============================================================================
bool CPersonInfo::operator>(const CPersonInfo &rhs) {
    return this->m_age > rhs.m_age;
}




// ==== CPersonInfo::operator< =================================================
//
// This function checks if left-hand side CPersonInfo object is less than
// right-hand side CPersonInfo object.
//
// Note: We are only checking for the data member m_age to be less than. The
//          goal is to one day test if all data members or others.
//
// Input:
//       rhs    [IN]    - A const CPersonInfo reference object.
//
// Output:
//       Returns true if lhs age is less than rhs age, otherwise false.
//
// =============================================================================
bool CPersonInfo::operator<(const CPersonInfo &rhs) {
    return this->m_age < rhs.m_age;
}




// ==== operator>> =============================================================
//
// The function overloads the extraction operator.  Its objective is to read the
// first name, last name, and age from a person and the dollar amount in their
// checking and savings account from the object ins.
//
// Input:
//       ins    [IN]        - An istream reference to read from.
//       person [IN/OUT]    - A CPersonInfo reference object to store what is
//                              read from ins.
// Output:
//       An istream reference.
//
// =============================================================================
std::istream& operator>>(std::istream &ins, CPersonInfo &person) {

    // Vector of string to save tokens
    vector <string> tokens;
    string intermediate;

    std::string  m_fname;
    std::string  m_lname;
    int          m_age;
    double       m_checking;
    double       m_savings;

    ins >> m_fname >> m_lname >> m_age >> m_checking >> m_savings;

    person.SetFirstName(m_fname);
    person.SetLastName(m_lname);
    person.SetAge(m_age);
    person.SetChecking(m_checking);
    person.SetSavings(m_savings);

    return ins;
}




// ==== operator<< =============================================================
//
// This is the overloaded insertion operator. Its objective is to nicely display
// the person's information to the object outs.
//
// Input:
//       outs   [IN]        - An ostream reference to display to.
//       person [IN/OUT]    - A const CPersonInfo reference object to display.
//
// Output:
//       An ostream reference.
//
// =============================================================================
std::ostream& operator<<(std::ostream &outs, const CPersonInfo &person) {
    outs << "FName: " << person.GetFirstName() << "LName: " << person.GetLastName() << "Age: " << person.GetAge() << "Checkings: " << person.GetChecking() << "Savings: " << person.GetSavings();
    cout << endl;
    return outs;
}