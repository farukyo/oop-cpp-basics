#include <iostream>
#include <cstdio> // Include for printf
using namespace std;

// int main() {
//     cout << "Hi" << endl;
//     return 0;
// }


// int main() {
//     int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     for (int i: A){
//         cout << i << " ";
//     }
// }


// int main(){
//     string s1 = "Hello";
//     cout << s1.size() << endl;
//     cout << s1.substr(2,4) << endl;
//     const char * ps;
//     ps = s1.c_str();
    
//     string s2;
//     cout << "enter a long line" << endl;
//     getline(cin,s2);
//     cout << s2 << endl;

//     auto x = 5; //x is int 
//     x = 1.0; //(float to int)
//     cout << x << endl;
// }

// declaration vs definiton
// struct ComplexT{
//     float im, re;
// } declaration
// and also void func(int,int);
// same for struct declataionn up, and definiton down

// ComplextT c1; definion

// int x = 1;
// void f (){
//     int x = 5;
//     x++ //5+1
//     ::x++ //1+1
    
// }


// namespace faruk{
//     int flag = 5;
// }

// namespace elif{
//     int flag = 6;
// }
// // int main() {
// //     cout << faruk::flag << " & " << elif::flag << endl;
// //     return 0;
// // }


// int main(){
//     // using namespace elif;
//     // cout << flag;
//     // return 0;
//     // using elif::flag;
//     // cout << flag;
//     // return 0;
//     string selif, sfaruk;
//     cout <<"input 1";
//     cin >> selif >> sfaruk;
//     cout<< selif << sfaruk << endl;
//     cin.ignore();
//     char k; 
//     cin.get(k);
//     cout << k;

// }



// #include <fstream>

// int main(){
// ofstream dosya ("veri.txt", ios::out);
// if (!dosya){
//     cout << "file not found" << endl;
//     return 1;
// }
// for (int i=0; i < 10; i++){
//     dosya << i <<" "<< i*i << endl;
// }

// cout << "dosya bitti" << endl;
// dosya.close();
// ifstream dosya2;
// dosya2.open("veri.txt");
// if (!dosya2.is_open()){
//     cout << "fail amk" << endl;
//     return 1;
// }
// int n, p;
// // while (!dosya2.eof()){
// //     dosya2 >>n >>p;
// //     cout << n << p<< endl;
// // }

// while (dosya2 >> n >> p) {
//     cout << n << p << endl;
// }
// dosya2.close();
// }


// #include <iomanip>

// int main(){
//     int a = 32;
//     auto b = 12;
//     cout << setw(5) << a << setw(8) <<b << endl;
//     cout << left << setw(5) << a << setw(7) <<b << endl;
//     cout << "a = " << setbase(16) << showbase << a  <<  endl;
//     auto c = 12.5;
//     cout << c << endl;
//     cout <<right<< fixed << setw(6)<<setprecision(2)<<setfill('x')<< c << endl;
// }
// int main(){
// using x = int;
// x test = 5;
// cout << test ;

// // const char * p; constant data
// // char * const p; cpnstant ptr
// }

// int main(){
// int i= 7;
// float f;

// f = static_cast <float> (i) /2;
// cout << f;
// }

// int *p;
// p = new int(50);

// delete p;

// int * pa;

// pa = new int[10];
// for (int k=0; k<10; k++)
//     pa[k] = 2*k;

// delete [] pa;


// inline int MAX (int i1, int i2){
//     if (i1>i2) return i1;
//     else return i2;
// }

// int main(){
//     int a=5, b=8;
//     cout << MAX(a,b)<< endl;
// }


// void f (char k, int n1 =0, int n2=6);

// f('a',4,5);
// f('a',4);
// f('a');

//all valid
// f() error k is null

// #include <iostream>

// int main(){
//     int i = 5;
//     int &j = i; // j is a reference to i

//     // Print the value of i
//     std::cout << "Value of i: " << i << std::endl;
//     // Print the value of j
//     std::cout << "Value of j: " << j << std::endl;

//     // Print the address of i using &i
//     std::cout << "Address of i (using &i): " << &i << std::endl;
//     // Print the address of i using &j
//     std::cout << "Address of i (using &j): " << &j << std::endl;

//     return 0; // Added return statement for main
// }

// // call by value
// void c(int i);
// // call by adress;
// void c(int *i){
//     *j = 2;
// }
// int i;
// c(&i);
// // call by ref
// void c(int &j){
//     j = 2;
// }
// int i;
// c(i);

// // return by adress
// // 
// #include <iostream>

// // --- Return by Address ---
// // Bir tamsayı işaretçisi alır, işaret edilen değeri 2 artırır ve işaretçiyi döndürür.
// int* incrementByTwoAddress(int* ptr) {
//     if (ptr) { // İşaretçinin geçerli olup olmadığını kontrol et
//         *ptr += 2;
//     }
//     return ptr; // İşaretçiyi geri döndür
// }

// // --- Return by Reference ---
// // Bir tamsayı referansı alır, referans edilen değeri 2 artırır ve referansı döndürür.
// int& incrementByTwoReference(int& ref) {
//     ref += 2;
//     return ref; // Referansı geri döndür
// }

// int main() {
//     int num1 = 10;
//     int num2 = 20;

//     std::cout << "Baslangic: num1 = " << num1 << ", num2 = " << num2 << std::endl;

//     // Return by Address Kullanımı
//     int* ptrResult = incrementByTwoAddress(&num1);
//     if (ptrResult) {
//         std::cout << "Adresle donus sonrasi num1: " << num1 << " (Donen deger: " << *ptrResult << ")" << std::endl;
//     }

//     // Return by Reference Kullanımı
//     int& refResult = incrementByTwoReference(num2);
//     std::cout << "Referansla donus sonrasi num2: " << num2 << " (Donen deger: " << refResult << ")" << std::endl;


//     return 0;
// }

// class Point{
//     int x,y;
//     public:
//     void move(int,int);
//     void print();
//     bool is_zero();
//     // inline
//     void greet(){
//         cout <<"hi point"<<endl;
//     }
// };

// void Point::move(int nx, int ny){
//     y = ny;
//     x = nx;
// }

// void Point::print(){
//     cout << "x = "<< x << endl;
//     cout << "y = "<< y << endl;
// }

// bool Point::is_zero(){
//     return (x==0) && (y==0);
// }

// int main(){
// Point P1, P2;
// P1.move(100,60);
// P1.print();
// if(!P1.is_zero())
// cout<<"gay";

// Point array[10];
// array[0].move(15,40);
// }


// class A{
//     friend class B; // B can acces A, but a cant acces b
//     private: int i;
//     public: void func();
// };

// class B{
//     int j;
//     public:
//     void func2(A x){
//         cout << j << endl;
//         cout << x.i << endl;
//         x.func;
//     }
// };

// int main(){
//     A a;
//     B b;
//     b.func2(a);
// }



// class Point {
//     // Define a friend function of the Point class 
//     friend void set_to_zero (Point &); // Not a member of Point class
//     int x, y; // private members: x and y coordinates
//     public: // public members bool move (int, int); void print (); bool is_zero ();
// };


//     // Nonmember function // (Not a member of any class)
// void set_to_zero (Point &p) {
//     p . x = 0; p . y = 0;
// } 



// int main() {
//     Point p1;
//     set_to_zero (p1);
// }



// class Point { int x, y;
//     public:
//     // private members // public members
//     bool move (int x, int y);
//     };



//     bool Point :: move (int x, int y) // parameters has the same name as 
//     {
//     // data members x and y
//     if ( x > 0 && x < 500 && y > 0 && y < 300) { this -> x = x;
//     // assigns given x value to member x
//     this -> y = y; return true;
//     }
//     return false;
//     }


// Point * Point :: find_furthest_point (Point & p) {
//     int distance1, distance2; //Distance from point p to the origin (0,0) 
//     distance1 = sqrt ( ( x * x) + (y * y) );
//     // Hypothenus formula 
//     distance2 = sqrt ( ( p.x * p.x) + (p.y * p.y) ); // Hypothenus formula
//     if (distance1 > distance2 ) 
//     return this; // Object returns its own address.
//     else return &p; // Else returns the address of the p object.
//     }


// class A{
//     const int n;
//     int x;
// public:
// A(int num1, int num2) : n(num1), x(num2){
//     //bla bla
// }
// };

// class B{
//     const int n;
//     int x;
// public:
// B(const int n, int x) : n(n), x(x){
//     //bla bla
// }
// ~B();
// };

// int main (){
//     A a1(-5,7);
//     B b1(-8,149);
// }


//copy constuctor

// String::String(const String & data){
//     size = data.size;
//     contents = new char[size+1];
//     strcpy(contents, data.contents);
// }

// int main() //
// // Test program
// {
// String s1 ("ABCDE"); //
// // Parametered constructor is invoked
// String s2 = s1; //
// // Copy constructor is invoked (user-written)
// String s3 (s1); //
// // Copy constructor is invoked (user-written)
// s1 . print();
// s2 . print();
// s3 . print();
// }




// const function cant modify data

// class Point
// {
// int x, y;
// public:
// Point (int, int);
// bool move (int, int);
// void print () const;
// // Constant function
// };
// //
// Constant function
// void Point :: print () const
// {
// cout << "X= " << x
// << ", Y= " << y << endl;
// x=0; y=0;
// // Compiler errors
// }


// int main()
// {
// const Point A (10, 20); //
// A is a constant object
// A . print (); //
// OK. Const function operates on const object
// A . move (30, 15); //
// ERROR Non-const function on const object
// //
// A is not modifiable
// Point B (0, 50); // B is a
// non-constant object
// B . print (); //
// OK
// B . move (100, 45); //
// OK
// }



// class A {
//     public:
//     static int x;
//     };
//     //Required definition in global scope
//     int A :: x = 5;
//     int main () {
//     A p, q, r;
//     A :: x ++;
//     cout << A :: x << endl ;
//     cout << p . x << endl ;
//     cout << q . x << endl ;
//     cout << r . x << endl ;
//     }


// non member  !!!!
// ComplexT operator+ (ComplexT v1 , ComplexT v2)
// {
// ComplexT result;
// // local result variable
// result . re = v1 . re + v2 . re;
// result . im = v1 . im + v2 . im;
// return result;
// // Object of ComplexT class


// int main()
// {
// ComplexT c1, c2, c3, c4;
// // Complex number objects
// c3 = c1 + c2;
// // The function operator+ is called
// c4 = operator+ (c1, c2);
// // Alternative calling method
// }


//member overload !!!!

// class ComplexT
// {
// double re, im;
// public:
// // Member function prototype
// ComplexT operator+ (ComplexT &);
// };

// ComplexT ComplexT :: operator+ (ComplexT & z )
// {
// double re_result, im_result; //Local variables
// re_result = re + z.re;
// im_result = im + z.im;
// return ComplexT (re_result , im_result); //Constructor
// }


// int main()
// {
// // Complex number objects
// ComplexT z1 (10, 10), z2 (20, 20) , z3;
// // Calling the overloaded + operator
// z3 = z1 + z2;
// // Alternative calling methods
// z3 = z1 . operator+ (z2);
// z3 = z2 . operator+ (z1);
// }
// 12
// class String
// {
// int size;
// char contents [20];
// //Array member
// public:
// void print();
// String (const char *);
// //Constructor
// };


int main(){
    int x[2] = {5,6};
    int y[2];
    y = x;
    x[1]++;
    cout << x << " " << y;
}