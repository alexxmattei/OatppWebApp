#include "../HeaderModels/Client.h"

User::User(std::int64_t readId, std::int64_t readRoleId, std::string readUserName, std::string readUserMiddleName, std::string readUserSurname, std::int64_t readUserAge, std::time_t readUserBirthdate,
	std::string readUserPhoneNumber, std::string readUserEmail, std::string readAddress, std::string readPassword)
{
	this->userId = readId;
	this->roleId = readRoleId;
	this->userName = readUserName;
	this->userMiddleName = readUserMiddleName;
	this->userSurname = readUserSurname;
	this->userAge = readUserAge;
	this->userBirthdate = readUserBirthdate;
	this->userPhoneNumber = readUserPhoneNumber;
	this->userEmail = readUserEmail;
	this->userAddress = readAddress;
	this->userPassword = readPassword;


	std::string usersString;
	std::time_t bd = this->GetUserBirthDate();
	std::string u_birthdate = ctime(&bd);
	//usersString.append("|");
	usersString.append(std::to_string(this->GetUserId()));
	usersString.append("|");
	usersString.append(std::to_string(this->GetUserRoleId()));
	usersString.append("|");
	usersString.append(this->GetUserName());
	usersString.append("|");
	usersString.append(this->GetPassword());
	usersString.append("|");
	usersString.append(this->GetUserMiddleName());
	usersString.append("|");
	usersString.append(this->GetUserSurname());
	usersString.append("|");
	usersString.append(std::to_string(this->GetUserAge()));
	usersString.append("|");
	usersString.append(u_birthdate);
	usersString.append("|");
	usersString.append(this->GetUserPhone());
	usersString.append("|");
	usersString.append(this->GetUserEmail());
	usersString.append("|");
	usersString.append(this->GetAdress());


	std::ofstream outfile;

	outfile.open("Clients.txt", std::ios_base::app);
	outfile << usersString << "\n";
	outfile.close();
}

void User::SetUserId(std::int64_t readUserId)
{
	this->userId = readUserId;
}

void User::SetRoleId(std::int64_t readRoleId)
{
	this->roleId = readRoleId;

	if (readRoleId == 0)
	{
		this->userPermission = UserModel::Admin;
	}
	else if (roleId == 1)
	{
		this->userPermission = UserModel::Seller;
	}
	else {
		this->userPermission = UserModel::User;
	}
}

void User::SetUserName(std::string readUserName)
{
	this->userName = readUserName;
}

void User::SetUserMiddleName(std::string readUserMiddleName)
{
	this->userMiddleName = readUserMiddleName;
}

void User::SetUserSurmane(std::string readUserSurname)
{
	this->userSurname = readUserSurname;
}

void User::SetUserAge(std::int64_t readUserAge)
{
	this->userAge = readUserAge;
}

void User::SetUserBirthdate(std::time_t readUserBirthdate)
{
	this->userBirthdate = readUserBirthdate;
}

void User::SetUserBirthdateString(std::string readUserBirthdate)
{
	this->ub = readUserBirthdate;
}

void User::SetUserPhoneNumber(std::string readUserPhoneNumber)
{
	this->userPhoneNumber = readUserPhoneNumber;
}

void User::SetUserEmail(std::string readUserEmail)
{
	this->userEmail = readUserEmail;
}

void User::SetUserAddress(std::string readAddress)
{
	this->userAddress = readAddress;
}


void User::SetUserPassword(std::string readPassword)
{
	this->userPassword = readPassword;
}

std::int64_t User::GetUserId()
{
	return this->userId;
}

std::int64_t User::GetUserRoleId()
{
	return this->roleId;
}

std::string User::GetUserName()
{
	return this->userName;
}

std::string User::GetUserMiddleName()
{
	return this->userMiddleName;
}

std::string User::GetUserSurname()
{
	return this->userSurname;
}

std::int64_t User::GetUserAge()
{
	return this->userAge;
}

std::time_t User::GetUserBirthDate()
{
	return this->userBirthdate;
}

std::string User::GetUserBirthDateString()
{
	/*time_t timeBd = this->userBirthdate;
	std::string u_birthdate = ctime(&timeBd);
	return u_birthdate;*/
	return this->ub;
}

std::string User::GetUserPhone()
{
	return this->userPhoneNumber;
}

std::string User::GetUserEmail()
{
	return this->userEmail;
}

std::string User::GetAdress()
{
	return this->userAddress;
}

std::string User::GetPassword()
{
	return this->userPassword;
}

UserModel User::GetUserPermission()
{
	return this->userPermission;
}
