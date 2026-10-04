#include "Reservoir.h"
#include <iostream>

int Reservoir::getStrLen(const char* str) const {
    if (str == nullptr) return 0;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void Reservoir::copyStr(char* dest, const char* src) const {
    if (dest == nullptr || src == nullptr) return;
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

bool Reservoir::compareStr(const char* s1, const char* s2) const {
    if (s1 == nullptr || s2 == nullptr) return s1 == s2;
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return false;
        i++;
    }
    return s1[i] == s2[i];
}

Reservoir::Reservoir()
    : name(nullptr), type(nullptr), width(0.0), length(0.0), maxDepth(0.0) {
    setName("Unknown");
    setType("Unknown");
}

Reservoir::Reservoir(const char* name)
    : name(nullptr), type(nullptr), width(0.0), length(0.0), maxDepth(0.0) {
    setName(name);
    setType("Unknown");
}

Reservoir::Reservoir(const char* name, const char* type, double width, double length, double maxDepth)
    : name(nullptr), type(nullptr), width(width), length(length), maxDepth(maxDepth) {
    setName(name);
    setType(type);
}

Reservoir::Reservoir(const Reservoir& other)
    : name(nullptr), type(nullptr), width(other.width), length(other.length), maxDepth(other.maxDepth) {
    setName(other.name);
    setType(other.type);
}

Reservoir::~Reservoir() {
    delete[] name;
    delete[] type;
}

Reservoir& Reservoir::operator=(const Reservoir& other) {
    if (this != &other) {
        setName(other.name);
        setType(other.type);
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
    }
    return *this;
}

const char* Reservoir::getName() const { return name; }
const char* Reservoir::getType() const { return type; }
double Reservoir::getWidth() const { return width; }
double Reservoir::getLength() const { return length; }
double Reservoir::getMaxDepth() const { return maxDepth; }

void Reservoir::setName(const char* newName) {
    delete[] name;
    if (newName != nullptr) {
        name = new char[getStrLen(newName) + 1];
        copyStr(name, newName);
    }
    else {
        name = nullptr;
    }
}

void Reservoir::setType(const char* newType) {
    delete[] type;
    if (newType != nullptr) {
        type = new char[getStrLen(newType) + 1];
        copyStr(type, newType);
    }
    else {
        type = nullptr;
    }
}

void Reservoir::setWidth(double w) { width = w >= 0 ? w : 0; }
void Reservoir::setLength(double l) { length = l >= 0 ? l : 0; }
void Reservoir::setMaxDepth(double d) { maxDepth = d >= 0 ? d : 0; }

double Reservoir::getVolume() const {
    return width * length * maxDepth;
}

double Reservoir::getSurfaceArea() const {
    return width * length;
}

bool Reservoir::isSameType(const Reservoir& other) const {
    return compareStr(type, other.type);
}

bool Reservoir::isSurfaceAreaGreater(const Reservoir& other) const {
    if (!isSameType(other)) {
        std::cout << "[Увага] Водойми мають різний тип! Порівняння некоректне.\n";
        return false;
    }
    return getSurfaceArea() > other.getSurfaceArea();
}

void Reservoir::print() const {
    std::cout << "Назва: " << (name ? name : "nullptr") << "\n";
    std::cout << "Тип: " << (type ? type : "nullptr") << "\n";
    std::cout << "Розміри (Ш х Л х Г): " << width << "m x " << length << "m x " << maxDepth << "m\n";
    std::cout << "Площа поверхні: " << getSurfaceArea() << " м²\n";
    std::cout << "Об'єм: " << getVolume() << " м³\n";
    std::cout << "-----------------------------------\n";
}

void Reservoir::printTextFormat() const {
    std::cout << name << "\n" << type << "\n"
        << width << " " << length << " " << maxDepth << "\n";
}

void Reservoir::printBinaryFormat() const {
    int nameLen = getStrLen(name);
    int typeLen = getStrLen(type);

    std::cout.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
    std::cout.write(name, nameLen);
    std::cout.write(reinterpret_cast<const char*>(&typeLen), sizeof(typeLen));
    std::cout.write(type, typeLen);
    std::cout.write(reinterpret_cast<const char*>(&width), sizeof(width));
    std::cout.write(reinterpret_cast<const char*>(&length), sizeof(length));
    std::cout.write(reinterpret_cast<const char*>(&maxDepth), sizeof(maxDepth));
}