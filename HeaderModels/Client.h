#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

enum class UserModel
{
    Admin = 0,
    User,
    Seller
};

class User
{
private:
    std::int64_t userId;
    std::int64_t roleId; //ajuta la filtrarea la Auth 
    std::string userName;
    std::string userMiddleName;
    std::string userSurname;
    std::int64_t userAge;
    std::time_t userBirthdate; 
    std::string ub;
    std::string userPhoneNumber;
    std::string userEmail;
    std::string userAddress;
    std::string userPassword;
    UserModel userPermission;

public:

    template<class Action>
    void persist(Action& a)
    {
    }

    User() {};
    User(std::int64_t readUserId, std::int64_t readRoleId, std::string readUserName, std::string readUserMiddleName, std::string readUserSurname, std::int64_t readUserAge, std::time_t readUserBirthdate,
        std::string readUserPhoneNumber, std::string readUserEmail, std::string readAddress, std::string readPassword);

    void SetUserId(std::int64_t readUserId);
    void SetRoleId(std::int64_t readRoleId);
    void SetUserName(std::string readUserName);
    void SetUserMiddleName(std::string readUserMiddleName);
    void SetUserSurmane(std::string readUserSurname);
    void SetUserAge(std::int64_t readUserAge);
    void SetUserBirthdate(std::time_t readUserBirthdate);
    void SetUserBirthdateString(std::string readUserBirthdate);
    void SetUserPhoneNumber(std::string readUserPhoneNumber);
    void SetUserEmail(std::string readUserEmail);
    void SetUserAddress(std::string readAddress);
    void SetUserPassword(std::string readPassword);
    std::int64_t GetUserId();
    std::int64_t GetUserRoleId();
    std::string GetUserName();
    std::string GetUserMiddleName();
    std::string GetUserSurname();
    std::int64_t GetUserAge();
    std::time_t GetUserBirthDate();
    std::string GetUserBirthDateString();
    std::string GetUserPhone();
    std::string GetUserEmail();
    std::string GetAdress();
    std::string GetPassword();
    UserModel GetUserPermission();
};

