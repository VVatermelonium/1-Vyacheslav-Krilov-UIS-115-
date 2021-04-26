#include <iostream>
#include <map>
#include "ATM.h"






int main() {
    setlocale(LC_ALL, "Russian");
    Bankomat b1 = Bankomat();
    b1.init(1);
    std::cout << "Банкомат " << b1.get_id() << " инициализирован. Остаток: " << b1.get_money_left() << std::endl;
    b1.load(1, 2, 3, 14, 0);
    std::cout << "В банкомат " << b1.get_id() << " загружены купюры {10: 1, 50:2, 100:3, 500:14}. Остаток: "
        << b1.get_money_left() << std::endl;
    b1.load(500);
    std::cout << "В банкомат " << b1.get_id() << " загружена сумма 500, представленная минимальным количеством купюр. "
        "Остаток: " << b1.get_money_left() << std::endl;
    std::cout << "Попытка снять меньше разрешенной суммы." << std::endl;
    if (b1.extract(20)) {
        std::cout << "Банкомат " << b1.get_id() << ". Остаток: " << b1.get_money_left() << std::endl;
    }
    std::cout << "Попытка снять больше разрешенной суммы." << std::endl;
    if (b1.extract(1000000)) {
        std::cout << "Банкомат " << b1.get_id() << ". Остаток: " << b1.get_money_left() << std::endl;
    }
    std::cout << "Попытка снять разрешенную сумму 1910." << std::endl;
    if (b1.extract(1910)) {
        std::cout << "Банкомат " << b1.get_id() << ". Остаток: " << b1.get_money_left() << std::endl;
    }
    std::cout << "Попытка снять сумму 1910, десятки которой превышают количество десяток в банкомате." << std::endl;
    if (b1.extract(1910)) {
        std::cout << "Банкомат " << b1.get_id() << ". Остаток: " << b1.get_money_left() << std::endl;
    }
    b1.load(1, 1, 1, 1, 17);
    std::cout << "В банкомат " << b1.get_id() << " загружены купюры {10: 1, 50:1, 100:1, 500:1, 1000:17}." << std::endl;
    std::cout << "Банкомат " << b1.get_id() << ". Остаток: " << b1.toString() << std::endl;
    std::cout << "Попытка снять сумму 6000 в банкомате." << std::endl;
    if (b1.extract(6000)) {
        std::cout << "Банкомат " << b1.get_id() << ". Остаток: " << b1.toString() << std::endl;
    }
    std::cout << "Попытка снять сумму 17660 в банкомате." << std::endl;
    if (b1.extract(17660)) {
        std::cout << "Банкомат " << b1.get_id() << ". Остаток: " << b1.toString() << std::endl;
    }
    return 0;
}