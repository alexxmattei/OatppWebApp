#pragma once

#include "Product.h"
#include "oatpp/orm/DbClient.hpp"

class Accessory :
    public Product
{
private:
    std::string category;
    std::string gender;

public:
    Accessory();
    Accessory(std::int64_t newId, std::string newName, std::string newDescription, double pret, std::string category, std::string gender);
    ~Accessory();
    void SetCategory(std::string newCategory);
    void SetGender(std::string newGender);
    std::string GetCategory();
    std::string GetGender();
};


