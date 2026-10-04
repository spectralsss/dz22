#pragma once

class Reservoir {
private:
    char* name;
    char* type;
    double width;
    double length;
    double maxDepth;

    int getStrLen(const char* str) const;
    void copyStr(char* dest, const char* src) const;
    bool compareStr(const char* s1, const char* s2) const;

public:
    Reservoir();
    explicit Reservoir(const char* name);
    Reservoir(const char* name, const char* type, double width, double length, double maxDepth);
    Reservoir(const Reservoir& other);
    ~Reservoir();

    Reservoir& operator=(const Reservoir& other);

    const char* getName() const;
    const char* getType() const;
    double getWidth() const;
    double getLength() const;
    double getMaxDepth() const;

    void setName(const char* name);
    void setType(const char* type);
    void setWidth(double width);
    void setLength(double length);
    void setMaxDepth(double maxDepth);

    double getVolume() const;
    double getSurfaceArea() const;

    bool isSameType(const Reservoir& other) const;
    bool isSurfaceAreaGreater(const Reservoir& other) const;

    void print() const;
    void printTextFormat() const;
    void printBinaryFormat() const;
};