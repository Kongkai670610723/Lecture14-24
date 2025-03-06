/*### สรุปเนื้อหาจากสไลด์ **Lecture 19: Classes I** (CPE102_19_20250211.pdf)

---

### **1. ความหมายของ Class**
- **Class** คือแบบจำลองของวัตถุที่มี **Attributes (data members)** และ **Behaviors (member functions)**
- ใช้ **keyword `class`** ในการกำหนด
- มี **การควบคุมการเข้าถึง (Access control)**
  - `private` (ค่าเริ่มต้น) – ใช้งานได้เฉพาะภายใน class
  - `public` – ใช้งานได้จากภายนอก class
  - `protected` – ใช้สำหรับการสืบทอด (Inheritance)

---

### **2. การกำหนด Class**
```cpp
class Teacher {
public:
    string name;
    int age;
    float height;
    float weight;
    bool handsome;
};
```
- `Teacher` เป็นชื่อของ **class**
- `public:` กำหนดให้สมาชิกสามารถเข้าถึงได้จากภายนอก class
- **สมาชิกของ class (data members)**
  - `name`, `age`, `height`, `weight`, `handsome`

---

### **3. การสร้างวัตถุจาก Class**
```cpp
Teacher k, s, p;      // ประกาศตัวแปร k, s, p เป็น object ของ class Teacher
Teacher allteacher[3]; // ประกาศ array ที่มี 3 object ของ class Teacher
Teacher *tPtr = &k;   // ประกาศ pointer ที่ชี้ไปยัง object k
Teacher &tRef = k;    // ประกาศ reference ที่อ้างอิง object k
```

---

### **4. การเข้าถึงสมาชิกของ Class**
- ใช้ **`.` (dot operator)** สำหรับ object และ reference
- ใช้ **`->` (arrow operator)** สำหรับ pointer
```cpp
k.name = "John";   // ใช้ dot operator กับ object
tPtr->age = 25;    // ใช้ arrow operator กับ pointer
```

---

### **5. ฟังก์ชันสมาชิก (Member Functions)**
- ฟังก์ชันที่อยู่ใน class ทำให้ object มีพฤติกรรม
- สามารถกำหนดฟังก์ชันไว้ **ภายใน class** หรือ **ภายนอก class**
  - **ภายใน class**
    ```cpp
    class Rect {
    public:
        int width, height;
        void setValues(int w, int h) {
            width = w;
            height = h;
        }
    };
    ```
  - **ภายนอก class**
    ```cpp
    class Rect {
    public:
        int width, height;
        void setValues(int w, int h);
    };

    void Rect::setValues(int w, int h) {
        width = w;
        height = h;
    }
    ```

---

### **6. การควบคุมการเข้าถึง (Access Control)**
- `private` – ไม่สามารถเข้าถึงจากภายนอก class
- `public` – เข้าถึงจากภายนอก class ได้
- `protected` – ใช้ในกรณีของ Inheritance

```cpp
class User {
private:
    int password = 1234;  // ไม่สามารถเข้าถึงจากภายนอก class
};
```
หากพยายามเข้าถึง `password` จากภายนอก class จะเกิด error

---

### **7. ตัวอย่างการใช้ Class**
**ตัวอย่าง: การสร้าง Hero ที่มีพลังโจมตีและป้องกัน**
```cpp
class Hero {
public:
    string name;
    int hp, atk, def;

    void boostStats(int value) {
        atk += value;
        def += value;
    }
};
```
การใช้งาน:
```cpp
Hero superman = {"Superman", 10, 5, 5};
Hero batman = {"Batman", 10, 5, 5};

superman.boostStats(3);
batman.boostStats(3);
```
**ผลลัพธ์**
```
Superman: HP = 10/10 ATK = 8 DEF = 8
Batman: HP = 10/10 ATK = 8 DEF = 8
```

---

### **8. `this` Pointer**
- `this` เป็น pointer ที่ใช้ชี้ไปยัง object ปัจจุบันภายใน class
```cpp
class Player {
public:
    string name;
    void showName() {
        cout << "Name: " << this->name << endl;
    }
};
```
**ตัวอย่าง**
```cpp
Player p1;
p1.name = "Kaiba";
p1.showName();  // Output: Name: Kaiba
```

---

### **สรุป**
1. **Class** เป็นโครงสร้างที่ใช้จำลองวัตถุ มีทั้ง **data members** และ **member functions**
2. การควบคุมการเข้าถึง (`private`, `public`, `protected`) ช่วยให้เขียนโค้ดที่ปลอดภัยขึ้น
3. **ฟังก์ชันสมาชิก** สามารถกำหนดได้ทั้งในและนอก class
4. ใช้ **pointer (`this`)** เพื่ออ้างอิง object ปัจจุบัน
5. **Class สามารถใช้สร้าง object ที่โต้ตอบกันได้** เช่น ตัวละครเกม

---

### 🔥 **บทเรียนสำคัญ**
✔ การใช้ **class** ช่วยให้โค้ดเป็นระบบ และสามารถใช้ OOP ได้ง่ายขึ้น  
✔ เข้าใจ **access control** (`private`, `public`) เพื่อป้องกันการเข้าถึงข้อมูลโดยไม่ได้รับอนุญาต  
✔ **Member functions** ทำให้ object มีพฤติกรรมเฉพาะตัว  
✔ **ตัวชี้ (`this`)** ใช้ในการอ้างถึง object ปัจจุบัน  
✔ **ตัวอย่าง Hero** แสดงให้เห็นถึงการปรับค่าสถานะของ object ในเกม  

📌 **บทเรียนต่อไป: สืบทอดคลาส (Inheritance) และ Constructor/Destructor!** 🚀*/