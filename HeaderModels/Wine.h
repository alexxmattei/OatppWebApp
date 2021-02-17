#pragma once
#include "Product.h"
class Wine :
    public Product
{
private:
    std::string category;
    int year;
    std::string type;

public:
    Wine();
    Wine(std::int64_t newId, std::string newName, std::string newDescription, double pret, std::string category, int year, std::string type);
    ~Wine();
    void SetCategory(std::string newCategory);
    void SetYear(int newYear);
    void SetType(std::string newType);
    std::string GetCategory();
    int GetYear();
    std::string GetType();
};

