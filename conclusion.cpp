/*### **สรุปเนื้อหาสไลด์ CPE102 ตั้งแต่สไลด์ 14 - 24**  
*(แบบเข้าใจง่าย ครอบคลุม ถูกต้อง และละเอียด)*  

---

## **🟢 สไลด์ 14: Function in C++**  
### **📌 ฟังก์ชันคืออะไร?**  
- ฟังก์ชัน (Function) คือ **กลุ่มของคำสั่งที่ทำงานร่วมกัน** เพื่อให้สามารถใช้งานซ้ำได้โดยไม่ต้องเขียนโค้ดเดิมหลายครั้ง  
- ช่วยให้โค้ด **อ่านง่ายขึ้น ดูแลรักษาง่ายขึ้น** และ **ลดความซ้ำซ้อน**  

### **📌 รูปแบบของฟังก์ชันใน C++**
```cpp
returnType functionName(parameter_list) {
    // คำสั่งที่ทำงานภายในฟังก์ชัน
    return value; // (ถ้ามี)
}
```
- `returnType` → ประเภทของค่าที่ฟังก์ชันจะส่งคืน  
- `functionName` → ชื่อของฟังก์ชัน  
- `parameter_list` → รายการตัวแปรที่รับเข้ามา (อาจมีหรือไม่มี)  
- `return value;` → ส่งค่ากลับไป (ถ้าฟังก์ชันไม่คืนค่า ใช้ `void`)  

### **📌 การใช้ฟังก์ชัน**
1. **ฟังก์ชันที่มีค่า return**
   ```cpp
   int add(int a, int b) {
       return a + b;
   }
   ```
2. **ฟังก์ชันที่ไม่มีค่า return (`void`)**
   ```cpp
   void printMessage() {
       cout << "Hello, World!";
   }
   ```
3. **ฟังก์ชันแบบ Overloading** (ฟังก์ชันที่มีชื่อเหมือนกัน แต่พารามิเตอร์ต่างกัน)
   ```cpp
   int add(int a, int b);
   double add(double a, double b);
   ```

---

## **🟢 สไลด์ 15: Recursive Function**  
### **📌 การเรียกใช้ฟังก์ชันซ้ำตัวเอง (Recursion)**
- ฟังก์ชันสามารถ **เรียกใช้ตัวเอง** ได้ โดยต้องมี **เงื่อนไขหยุด (Base Case)** มิฉะนั้นจะเกิด **infinite loop**  

### **📌 ตัวอย่างการใช้ Recursive Function**
1. **Factorial (n!)**
   ```cpp
   int factorial(int n) {
       if (n == 0) return 1;  // Base Case
       return n * factorial(n - 1);
   }
   ```
2. **Fibonacci**
   ```cpp
   int fibonacci(int n) {
       if (n <= 1) return n;  // Base Case
       return fibonacci(n - 1) + fibonacci(n - 2);
   }
   ```

> **ข้อดี**: ใช้โค้ดสั้น อ่านง่าย  
> **ข้อเสีย**: ใช้หน่วยความจำมาก (เนื่องจากต้องจัดเก็บการเรียกซ้อนกันใน Stack)  

---

## **🟢 สไลด์ 16: Pointer & Memory Management**  
### **📌 Pointer คืออะไร?**
- Pointer เป็นตัวแปรที่เก็บ **ที่อยู่ของหน่วยความจำ**  
- ใช้ `*` ในการประกาศ และ `&` เพื่ออ้างอิงตำแหน่งที่อยู่  
  ```cpp
  int a = 10;
  int *ptr = &a; // ptr เก็บที่อยู่ของ a
  ```

### **📌 Dynamic Memory Allocation**
- ใช้ `new` และ `delete` เพื่อจัดการหน่วยความจำเอง  
  ```cpp
  int *ptr = new int; // จองหน่วยความจำ
  delete ptr;         // คืนหน่วยความจำ
  ```

---

## **🟢 สไลด์ 17: File Handling**  
### **📌 การอ่าน/เขียนไฟล์ใน C++**
- ใช้ **ifstream** (อ่าน), **ofstream** (เขียน)  
  ```cpp
  ofstream file("data.txt");
  file << "Hello, File!";
  file.close();
  ```
- อ่านไฟล์  
  ```cpp
  ifstream file("data.txt");
  string line;
  while (getline(file, line)) {
      cout << line << endl;
  }
  file.close();
  ```

---

## **🟢 สไลด์ 18: Function Pointer**  
- ใช้ pointer เพื่อเก็บ **ที่อยู่ของฟังก์ชัน** และเรียกใช้แบบ Dynamic  
  ```cpp
  int add(int a, int b) { return a + b; }
  int (*funcPtr)(int, int) = &add;
  cout << funcPtr(2, 3); // Output: 5
  ```

---

## **🟢 สไลด์ 19: Object-Oriented Programming (OOP)**  
### **📌 แนวคิด OOP**
1. **Encapsulation** → ห่อหุ้มข้อมูล  
2. **Inheritance** → การสืบทอด  
3. **Polymorphism** → ความสามารถเปลี่ยนแปลงการทำงาน  
4. **Abstraction** → ซ่อนรายละเอียดที่ไม่จำเป็น  

### **📌 การใช้งาน Class และ Object**
```cpp
class Car {
public:
    string brand;
    void drive() {
        cout << "Driving " << brand;
    }
};
Car myCar;
myCar.brand = "Toyota";
myCar.drive();
```

---

## **🟢 สไลด์ 20: Operator Overloading**  
- ใช้กำหนดการทำงานของ **Operators** ใหม่  
```cpp
class Complex {
public:
    int real, img;
    Complex operator+(const Complex &c) {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
};
```

---

## **🟢 สไลด์ 21: Template in C++**  
- ใช้สร้างฟังก์ชัน/คลาสที่รองรับหลายประเภทข้อมูล  
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```
- ใช้กับคลาส  
```cpp
template <typename T>
class Box {
public:
    T value;
};
```

---

## **🟢 สไลด์ 22: Exception Handling**  
- ใช้ `try`, `catch`, `throw` จัดการข้อผิดพลาด  
```cpp
try {
    throw "Error!";
} catch (const char* msg) {
    cout << msg;
}
```

---

## **🟢 สไลด์ 23: STL (Standard Template Library)**  
### **📌 STL คืออะไร?**
- STL คือ **คลังเครื่องมือมาตรฐานของ C++**  
- มีโครงสร้างข้อมูลและอัลกอริทึมที่พร้อมใช้งาน  

### **📌 ส่วนประกอบของ STL**
1. **Containers** → เก็บข้อมูล (`vector`, `list`, `map`, `set`)
2. **Algorithms** → ใช้จัดการข้อมูล (`sort`, `find`, `reverse`)
3. **Iterators** → ใช้เข้าถึงข้อมูลใน Containers

> **ตัวอย่าง: ใช้ `vector` และ `sort`**
```cpp
vector<int> nums = {4, 2, 5, 1};
sort(nums.begin(), nums.end());
```

---

## **🟢 สไลด์ 24: Containers**  
### **📌 Containers คืออะไร?**
- เป็นคลาสใน STL ที่ใช้เก็บข้อมูลเป็นโครงสร้างต่าง ๆ  
- **ชนิดของ Containers**
  - **Sequence Containers:** `vector`, `list`
  - **Associative Containers:** `map`, `set`
  - **Adaptors:** `stack`, `queue`

### **📌 ตัวอย่างการใช้ `vector`**
```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);
v.pop_back();
```

> **📌 การเลือกใช้ Containers**
- ถ้าต้องการ **เข้าถึงข้อมูลเร็ว** → `vector`
- ถ้าต้องการ **เพิ่ม/ลบข้อมูลเร็ว** → `list`
- ถ้าต้องการ **ข้อมูลไม่ซ้ำกัน** → `set`
- ถ้าต้องการ **จับคู่ key-value** → `map`

---

## **🎯 สรุปสั้น ๆ**
- **ฟังก์ชัน** ช่วยให้โค้ดเป็นระบบ  
- **Recursion** ใช้ให้โค้ดสั้นแต่ใช้หน่วยความจำเยอะ  
- **Pointer** ใช้จัดการหน่วยความจำ  
- **File Handling** ใช้อ่าน/เขียนไฟล์  
- **OOP** ทำให้โปรแกรมโครงสร้างดีขึ้น  
- **STL & Containers** ใช้เก็บและจัดการข้อมูลง่ายขึ้น  

---
**✨ หวังว่าสรุปนี้จะช่วยให้เข้าใจเนื้อหาของ C++ ได้ง่ายขึ้น! 😊***/