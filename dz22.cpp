#include <iostream>
#include "Reservoir.h"

void addReservoir(Reservoir*& arr, int& size, const Reservoir& item) {
    Reservoir* temp = new Reservoir[size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    temp[size] = item;
    delete[] arr;
    arr = temp;
    size++;
}

void removeReservoir(Reservoir*& arr, int& size, int index) {
    if (index < 0 || index >= size) return;

    Reservoir* temp = new Reservoir[size - 1];
    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            temp[j++] = arr[i];
        }
    }
    delete[] arr;
    arr = temp;
    size--;
}

void printAllAsText(const Reservoir* arr, int size) {
    std::cout << "=== ТЕКСТОВИЙ ВИВІД МАСИВУ ===\n";
    std::cout << size << "\n";
    for (int i = 0; i < size; i++) {
        arr[i].printTextFormat();
    }
    std::cout << "==============================\n\n";
}

void printAllAsBinary(const Reservoir* arr, int size) {
    std::cout << "=== БІНАРНИЙ ВИВІД МАСИВУ (байтовий потік) ===\n";
    std::cout.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (int i = 0; i < size; i++) {
        arr[i].printBinaryFormat();
    }
    std::cout << "\n============================================\n\n";
}

int main() {
    int size = 0;
    Reservoir* array = nullptr;

    addReservoir(array, size, Reservoir("Чорне море", "Море", 580000, 1150000, 2212));
    addReservoir(array, size, Reservoir("Азовське море", "Море", 200000, 380000, 14));
    addReservoir(array, size, Reservoir("Світязь", "Озеро", 3000, 7800, 58.4));

    std::cout << "--- Список водойм у масиві ---\n";
    for (int i = 0; i < size; i++) {
        std::cout << "[" << i << "]\n";
        array[i].print();
    }

    std::cout << "--- Перевірка типу та порівняння площі ---\n";
    if (array[0].isSameType(array[1])) {
        std::cout << array[0].getName() << " та " << array[1].getName() << " належать до одного типу.\n";
        if (array[0].isSurfaceAreaGreater(array[1])) {
            std::cout << array[0].getName() << " має більшу площу.\n";
        }
        else {
            std::cout << array[1].getName() << " має більшу площу.\n";
        }
    }
    std::cout << "-----------------------------------\n\n";

    printAllAsText(array, size);
    printAllAsBinary(array, size);

    std::cout << "--- Видалення елемента з індексом 1 ---\n";
    removeReservoir(array, size, 1);

    std::cout << "--- Масив після видалення ---\n";
    for (int i = 0; i < size; i++) {
        std::cout << "[" << i << "]\n";
        array[i].print();
    }

    delete[] array;
    return 0;
}