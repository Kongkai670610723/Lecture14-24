/*### 📌 **สรุปเนื้อหาจาก Lecture 20: Classes II (Constructor & Destructor)**
หัวข้อนี้กล่าวถึงการทำงานของ **Constructor** และ **Destructor** ใน C++ ซึ่งเป็นฟังก์ชันพิเศษที่ใช้ในการสร้างและทำลายอ็อบเจ็กต์ของคลาส

---

## 🔹 **1. Constructor คืออะไร?**
**Constructor** คือ ฟังก์ชันพิเศษที่มีชื่อเหมือนกับชื่อคลาสและ **ไม่มีค่าที่ return**  
ใช้สำหรับกำหนดค่าเริ่มต้นให้กับอ็อบเจ็กต์ของคลาสโดยอัตโนมัติเมื่อมีการสร้างอ็อบเจ็กต์

### ✨ **คุณสมบัติของ Constructor**
✅ มีชื่อ **เหมือนชื่อคลาส**  
✅ **ไม่มี `return type`** (แม้แต่ `void` ก็ไม่มี)  
✅ **ถูกเรียกใช้โดยอัตโนมัติ** เมื่อมีการสร้างอ็อบเจ็กต์  
✅ สามารถรับพารามิเตอร์ได้ (แต่ก็ไม่จำเป็นต้องมีเสมอไป)  
✅ สามารถมี **หลายตัว** ในคลาสเดียวกันได้ (Function Overloading)  

### 📌 **ตัวอย่าง Constructor**
```cpp
class Circle {
public:
    double radius; // ขนาดรัศมีของวงกลม

    // Constructor (ไม่มี return type)
    Circle() {  
        radius = 1;  // กำหนดค่าเริ่มต้นให้ radius
    }
};
```
🔹 เมื่อสร้างอ็อบเจ็กต์ `Circle c1;` ตัวแปร `radius` จะถูกกำหนดค่าเป็น `1` โดยอัตโนมัติ

---

## 🔹 **2. Default Constructor**
คือ **Constructor ที่ไม่มีพารามิเตอร์** หรือมีค่าเริ่มต้นให้กับทุกอาร์กิวเมนต์  
ถ้าคลาสไม่มี Constructor ที่กำหนดเอง C++ จะสร้าง Default Constructor ให้อัตโนมัติ

### 📌 **ตัวอย่าง Default Constructor**
```cpp
class Circle {
public:
    double radius;

    // Default Constructor (ไม่มีพารามิเตอร์)
    Circle() {  
        radius = 1;
    }
};

int main() {
    Circle c1; // ถูกเรียกใช้ Default Constructor
    cout << c1.radius; // output: 1
}
```

---

## 🔹 **3. Parameterized Constructor**
คือ **Constructor ที่รับพารามิเตอร์** เพื่อกำหนดค่าตัวแปรต่าง ๆ ของอ็อบเจ็กต์

### 📌 **ตัวอย่าง Parameterized Constructor**
```cpp
class Circle {
public:
    double radius;

    // Parameterized Constructor
    Circle(double r) {
        radius = r;
    }
};

int main() {
    Circle c1(5.0); // กำหนดค่า radius เป็น 5.0
    cout << c1.radius; // output: 5.0
}
```
🔹 Constructor ตัวนี้สามารถกำหนดค่า `radius` ได้ตอนสร้างอ็อบเจ็กต์

---

## 🔹 **4. Constructor Overloading**
C++ **รองรับการใช้ Constructor หลายตัวในคลาสเดียวกัน**  
โดยสามารถใช้ **Function Overloading** เพื่อรองรับอาร์กิวเมนต์ที่แตกต่างกัน

### 📌 **ตัวอย่าง Constructor Overloading**
```cpp
class Circle {
public:
    double radius;

    // Default Constructor
    Circle() {
        radius = 1;
    }

    // Parameterized Constructor
    Circle(double r) {
        radius = r;
    }
};

int main() {
    Circle c1;     // Default Constructor -> radius = 1
    Circle c2(5.0); // Parameterized Constructor -> radius = 5.0
    cout << c1.radius << ", " << c2.radius; // output: 1, 5.0
}
```
🔹 ใช้ **Constructor Overloading** เพื่อให้มีตัวเลือกในการสร้างอ็อบเจ็กต์

---

## 🔹 **5. Constructor แบบใช้ Initialization List**
ใช้สำหรับกำหนดค่าให้สมาชิกของคลาส **โดยตรง** ก่อนที่บอดี้ของ Constructor จะถูกดำเนินการ  
ช่วยให้โค้ดอ่านง่ายและประหยัดเวลา

### 📌 **ตัวอย่าง Initialization List**
```cpp
class Circle {
public:
    double radius;

    // Constructor แบบ Initialization List
    Circle(double r) : radius(r) { }
};

int main() {
    Circle c1(10.0);
    cout << c1.radius; // output: 10.0
}
```
🔹 Initialization List จะทำงานเร็วกว่าการกำหนดค่าภายในบล็อกของ Constructor

---

## 🔹 **6. Destructor คืออะไร?**
**Destructor** คือ ฟังก์ชันพิเศษที่มีชื่อเหมือนคลาสแต่มี `~` นำหน้า  
ใช้สำหรับทำลายอ็อบเจ็กต์และคืนค่าหน่วยความจำ **โดยอัตโนมัติเมื่ออ็อบเจ็กต์หมดอายุการใช้งาน**

### ✨ **คุณสมบัติของ Destructor**
✅ มีชื่อ **เหมือนกับชื่อคลาส** แต่ขึ้นต้นด้วย `~`  
✅ **ไม่มี `return type`**  
✅ **ไม่มีพารามิเตอร์** และไม่สามารถมี Overloading ได้  
✅ ถูกเรียกโดยอัตโนมัติเมื่ออ็อบเจ็กต์ **หมดอายุการใช้งาน**  

### 📌 **ตัวอย่าง Destructor**
```cpp
class Circle {
public:
    double radius;

    // Constructor
    Circle(double r) { radius = r; }

    // Destructor
    ~Circle() { cout << "Circle destroyed\n"; }
};

int main() {
    Circle c1(5.0);
} // เมื่อถึงตรงนี้ Destructor จะทำงาน
```
🔹 เมื่ออ็อบเจ็กต์ `c1` หมดอายุการใช้งาน **Destructor จะถูกเรียกโดยอัตโนมัติ**

---

## 🔹 **7. การใช้ `new` และ `delete` กับ Constructor & Destructor**
- `new` ใช้สร้างอ็อบเจ็กต์แบบไดนามิก
- `delete` ใช้ทำลายอ็อบเจ็กต์และคืนค่าหน่วยความจำ

### 📌 **ตัวอย่างการใช้ `new` และ `delete`**
```cpp
class Circle {
public:
    double radius;
    
    Circle(double r) { radius = r; }
    ~Circle() { cout << "Circle deleted\n"; }
};

int main() {
    Circle *c1 = new Circle(10.0); // สร้างอ็อบเจ็กต์แบบไดนามิก
    delete c1; // เรียก Destructor และคืนค่าหน่วยความจำ
}
```
🔹 ถ้าใช้ `new` ควรใช้ `delete` เสมอ เพื่อป้องกัน Memory Leak

---

## 🔹 **8. ใช้ Constructor & Destructor กับอาร์เรย์**
สามารถใช้ `new` และ `delete[]` เพื่อจัดการอ็อบเจ็กต์แบบอาร์เรย์

### 📌 **ตัวอย่าง**
```cpp
Circle *cArray = new Circle[3];  // สร้างอาร์เรย์ของ Circle
delete[] cArray;                 // ลบอาร์เรย์ทั้งหมด
```
🔹 ใช้ `delete[]` เพื่อลบอ็อบเจ็กต์ที่สร้างขึ้นเป็นอาร์เรย์

---

## 🔹 **9. คำแนะนำและข้อควรระวัง**
❌ **ห้ามลืม `delete` เมื่อใช้ `new`** เพราะอาจเกิด Memory Leak  
❌ **Destructor ไม่สามารถ Overload ได้**  
✅ ใช้ **Constructor Overloading** เพื่อให้โค้ดยืดหยุ่นขึ้น  
✅ ใช้ **Initialization List** เพื่อให้การกำหนดค่าทำได้เร็วขึ้น  

---

## 🎯 **สรุปโดยรวม**
- **Constructor** ใช้สร้างอ็อบเจ็กต์และกำหนดค่าเริ่มต้นให้กับสมาชิกของคลาส  
- **Overloaded Constructor** ช่วยให้กำหนดค่าให้กับอ็อบเจ็กต์ในหลายรูปแบบ  
- **Destructor** ใช้ทำลายอ็อบเจ็กต์และคืนค่าหน่วยความจำ  
- ควรใช้ **`new` และ `delete`** อย่างเหมาะสมเพื่อป้องกัน Memory Leak  
- **Initialization List** ทำให้การกำหนดค่ามีประสิทธิภาพมากขึ้น  

💡 **Constructor และ Destructor เป็นหัวใจสำคัญของ OOP ที่ช่วยจัดการการสร้างและลบอ็อบเจ็กต์ได้อย่างมีประสิทธิภาพ!***/