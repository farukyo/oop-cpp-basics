#include <iostream>
#include <string>
#include <vector> // String kullanimi icin gerekli

using namespace std;

// Global sabit N [cite: 12]
const int N = 5;

// PRODUCT CLASS [cite: 9]
class Product
{
public:
    string name; // [cite: 11]
    float price; // [cite: 11]

    // Default constructor [cite: 10]
    Product() {}

    // Parameterized constructor [cite: 10]
    Product(string n, float p) : name(n), price(p) {} // [cite: 11]
};

// CUSTOMER CLASS
class Customer
{
public:
    string customer_name;                // [cite: 16]
    float credit_card_limit;             // [cite: 16]
    Product list_of_ordered_products[N]; // [cite: 16]
    int count_of_ordered_products;       // [cite: 16]

    // Parameterized constructor with default credit card limit [cite: 13]
    Customer(string cname, float cclimit = 1000.0) : customer_name(cname), credit_card_limit(cclimit)
    {
        count_of_ordered_products = 0; // [cite: 14]
    }

    // Overloaded operator+ member function [cite: 17]
    void operator+(Product P)
    {
        cout << "Add product " << P.name << " " << P.price << endl; // [cite: 35]

        // Constraint 1: Toplam borcun kredi kartı limitini aşmaması kontrolü [cite: 20]
        if (calculate_total_debt() + P.price > credit_card_limit)
        {
            cout << "Total debt exceeded the credit card limit." << endl; // [cite: 19, 38]
            cout << "Product add operation is not done." << endl;         // [cite: 19, 38]
            return;
        }

        // Constraint 2: Sipariş edilen ürün sayısının N'i aşmaması kontrolü [cite: 21]
        if (count_of_ordered_products >= N)
        {
            cout << "Count of ordered products exceeded the maximum number." << endl; // [cite: 19, 43]
            cout << "Product add operation is not done." << endl;                     // [cite: 19, 43]
            return;
        }

        // Ürünü listeye ekle ve sayacı artır [cite: 17, 18]
        list_of_ordered_products[count_of_ordered_products] = P;
        count_of_ordered_products++;
        cout << "Product is added to customer successfully." << endl; // [cite: 35]
    }

    // calculate_total_debt fonksiyonu [cite: 14]
    float calculate_total_debt()
    {
        float total_debt = 0;
        for (int i = 0; i < count_of_ordered_products; ++i)
        {
            total_debt += list_of_ordered_products[i].price;
        }
        return total_debt;
    }

    // print fonksiyonu [cite: 15]
    void print()
    {
        cout << "--------------------" << endl;
        cout << "Customer name          : " << customer_name << endl;               // [cite: 37]
        cout << "Credit card Limit      : " << credit_card_limit << endl;           // [cite: 37]
        cout << "Count of ordered products: " << count_of_ordered_products << endl; // [cite: 37]
        cout << "List of Ordered Products :" << endl;                               // [cite: 37]
        for (int i = 0; i < count_of_ordered_products; ++i)
        {
            cout << i + 1 << ". Name: " << list_of_ordered_products[i].name
                 << "\t Price: " << list_of_ordered_products[i].price << endl; // [cite: 37]
        }
        cout << "TOTAL DEBT = " << calculate_total_debt() << endl; // [cite: 37]
        cout << "--------------------" << endl;
    }
};

// MAIN PROGRAM [cite: 22]
// STL kullanılmayacak [cite: 22]
// Kullanıcıdan girdi alınmayacak [cite: 24]
int main()
{
    cout << "PROGRAM STARTED" << endl
         << endl; // [cite: 35]

    // Müşteri nesnelerini oluştur [cite: 25]
    Customer customer1("JOHN FISHER", 2000);  // [cite: 26]
    Customer customer2("RONALD CRAIG");       // [cite: 26] // Default limit 1000 [cite: 13]
    Customer customer3("THOMAS AUSTIN", 750); // [cite: 26]

    // Ürünleri müşterilere ekle [cite: 28]

    // Müşteri 1'e ürün ekle [cite: 29]
    customer1 + Product("Panasonic Phone", 800); // [cite: 30]
    customer1 + Product("Toshiba Battery", 300); // [cite: 30]
    customer1 + Product("Kenwood DVD", 400);     // [cite: 30]
    cout << endl;

    // Müşteri 2'ye ürün ekle [cite: 31]
    customer2 + Product("Canon Battery", 500);    // [cite: 32]
    customer2 + Product("Nikon Accessory", 600);  // [cite: 32] // Limiti aşacak [cite: 38]
    customer2 + Product("Yamaha Subwoofer", 200); // [cite: 32]
    cout << endl;

    // Müşteri 3'e ürün ekle [cite: 33]
    customer3 + Product("Whirlpool Charger", 90);  // [cite: 33]
    customer3 + Product("Logitech Remote", 20);    // [cite: 33]
    customer3 + Product("LG Dryer", 100);          // [cite: 33]
    customer3 + Product("Linksys Router", 60);     // [cite: 33]
    customer3 + Product("Nintendo Portable", 150); // [cite: 33]
    customer3 + Product("Mitsubishi Stand", 50);   // [cite: 33] // N limitini aşacak [cite: 43]
    cout << endl;

    // Müşteri bilgilerini yazdır [cite: 34]
    customer1.print(); // [cite: 37]
    customer2.print(); // [cite: 40]
    customer3.print(); // [cite: 44]

    cout << endl
         << "PROGRAM FINISHED" << endl; // [cite: 44]

    return 0;
}