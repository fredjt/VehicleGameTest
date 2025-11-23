//
// Created by fredt on 11/20/25.
//

#ifndef USEDCARGAME_BASE_CATEGORIES_H
#define USEDCARGAME_BASE_CATEGORIES_H

#include <string>

typedef void* Image;

class Object
{
protected:
    static std::string manufacturer_;
    static std::string model_;
    static size_t num_;
    static short year_;
    static Image image_;
    size_t price_;

    explicit Object(const size_t price) : price_(price) {}

public:
    Object() = delete;
    static std::string getManufacturer() { return manufacturer_; }
    static std::string getModel() { return model_; }
    static size_t getNum() { return num_; }
    static short getYear() { return year_; }
    [[nodiscard]] size_t getPrice() const { return price_; }
};

inline std::ostream& operator<<(std::ostream& os, const Object obj)
{
    os << "Object:" << std::endl <<
        "  Manufacturer: " << Object::getManufacturer() << std::endl <<
        "  Model: " << Object::getModel() << std::endl <<
        "  Num: " << Object::getNum() << std::endl <<
        "  Year: " << Object::getYear() << std::endl <<
        "  Price: " << obj.getPrice() << std::endl;
    return os;
}

#endif //USEDCARGAME_BASE_CATEGORIES_H
