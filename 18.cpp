/*### **📌 สรุปเนื้อหา CPE102_18 - Exception Handling ใน C++**  

**💡 Exception Handling คืออะไร?**  
เป็นเทคนิคที่ใช้จัดการข้อผิดพลาด (Error) ที่เกิดขึ้นระหว่างการทำงานของโปรแกรม โดยไม่ให้โปรแกรมปิดตัวลงทันที แต่สามารถควบคุมและจัดการได้  

---

### **📌 โครงสร้างของ Exception Handling ใน C++**  
มี 3 คำสั่งหลัก:  
1. **`try`** → ใส่โค้ดที่อาจเกิดข้อผิดพลาด  
2. **`throw`** → ใช้สำหรับส่งข้อผิดพลาดออกไป  
3. **`catch`** → ใช้ดักจับข้อผิดพลาดและกำหนดการแก้ไข  

**ตัวอย่างโค้ด**  
```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        int a = 10, b = 0;
        if (b == 0) 
            throw "Division by zero error!"; // ส่ง error ออกไป
        cout << a / b << endl;  
    } catch (const char* msg) { // จับ error และแสดงข้อความ
        cout << "Exception: " << msg << endl;
    }
    return 0;
}
```
**💡 อธิบาย**  
- เมื่อ `b = 0` โปรแกรมจะ `throw` error  
- `catch` จะดักจับ error และแสดงข้อความแทนที่จะทำให้โปรแกรมพัง  

---

### **📌 ประเภทของ Exception ใน C++**  
1. **Standard Exceptions (ข้อผิดพลาดที่มีอยู่แล้วใน C++)**  
   - `std::runtime_error` → ข้อผิดพลาดระหว่างรันโปรแกรม  
   - `std::out_of_range` → เข้าถึงข้อมูลเกินขอบเขต  
   - `std::invalid_argument` → อาร์กิวเมนต์ไม่ถูกต้อง  

2. **User-defined Exceptions (ข้อผิดพลาดที่ผู้ใช้กำหนดเอง)**  
   - เราสามารถสร้างคลาส exception ของเราเองโดยสืบทอดจาก `std::exception`  

**ตัวอย่างการสร้าง Custom Exception**  
```cpp
#include <iostream>
#include <exception>

class MyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Custom Exception: Something went wrong!";
    }
};

int main() {
    try {
        throw MyException();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
```
---

### **📌 Multiple Catch Blocks (ดักจับข้อผิดพลาดหลายประเภท)**  
สามารถใช้ `catch` หลายตัวเพื่อจัดการข้อผิดพลาดที่แตกต่างกันได้  
```cpp
try {
    throw 10;
} catch (int e) {
    cout << "Caught an integer: " << e << endl;
} catch (double e) {
    cout << "Caught a double: " << e << endl;
} catch (...) {
    cout << "Caught an unknown exception" << endl;
}
```
**💡 `catch(...)` ใช้จับข้อผิดพลาดทุกประเภท**

---

### **📌 Exception Handling กับ Constructor และ Destructor**  
- ถ้า `constructor` มีข้อผิดพลาด สามารถ `throw` exception ได้  
- ถ้า `destructor` `throw` exception อาจทำให้โปรแกรมทำงานผิดพลาด  

```cpp
class Test {
public:
    Test() {
        throw runtime_error("Error in constructor");
    }
};

int main() {
    try {
        Test obj; // จะเกิด exception ทันที
    } catch (const exception &e) {
        cout << e.what() << endl;
    }
}
```
---

### **📌 `noexcept` – ป้องกัน Exception ในบางฟังก์ชัน**  
ถ้าเรามั่นใจว่าฟังก์ชันจะไม่เกิด exception สามารถใช้ `noexcept` เพื่อลด overhead  
```cpp
void safeFunction() noexcept {
    cout << "This function will not throw exceptions" << endl;
}
```

---

### **📌 สรุปสั้นๆ**  
✅ **Exception Handling** ทำให้โปรแกรมไม่ปิดตัวลงเมื่อเกิดข้อผิดพลาด  
✅ ใช้ `try`, `throw`, `catch` เพื่อดักจับและแก้ไขข้อผิดพลาด  
✅ รองรับการใช้ `catch` หลายตัว และสร้าง `Custom Exception` ได้  
✅ ใช้ `noexcept` เพื่อลด overhead ของ exception handling  

**🔥 ใช้ Exception Handling อย่างเหมาะสม เพื่อให้โปรแกรมมีความเสถียรและไม่พังง่าย!** 🚀*/