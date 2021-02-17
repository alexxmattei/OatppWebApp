#pragma once
#include "Product.h"

class Tea :
    public Product
{
private:
    std::string category;
    std::string origin;
    int quantity;
public:
    Tea();
    Tea(std::int64_t newId, std::string newName, std::string newDescription, double pret, std::string category, std::string newOrigin, int newQuantity);
    ~Tea();

    void SetCategory(std::string newCategory);
    void SetQuantity(int newQuantity);
    void SetOrigin(std::string newOrigin);

    std::string GetCategory();
    std::string GetOrigin();
    int GetQuantity();
};

