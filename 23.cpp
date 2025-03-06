/*### **สรุปเนื้อหาสไลด์ CPE102_23 (String Processing)**

#### **1. พื้นฐานของ Character และ String**
- **Character Constant:** ค่าจำนวนเต็มที่แทนตัวอักษร ใช้เครื่องหมาย ‘ ’ เช่น `'z'` มีค่าเป็น 122 ใน ASCII
- **String:** ลำดับของตัวอักษรที่ถูกมองเป็นหน่วยเดียวกัน
  - ประกอบด้วยตัวอักษร, ตัวเลข, และอักขระพิเศษ เช่น `+`, `-`, `*`
  - String Literal ใช้เครื่องหมาย `""` เช่น `"I like C++"`
  - เป็น **Array ของ Character** ที่ลงท้ายด้วย `'\0'`
  - **เป็น Pointer** ที่ชี้ไปยังตัวอักษรแรกของ String (เหมือน Array)

---

#### **2. ASCII Code**
- **American Standard Code for Information Interchange (ASCII)**
- ใช้แทนตัวอักษรเป็นค่าตัวเลข เช่น `A = 65`, `a = 97`

---

#### **3. C-Style String (`char []`)**
- การกำหนดค่าให้ String สามารถทำได้ 2 วิธีหลัก:
  1. **Character Array:**  
     ```cpp
     char color[] = "blue";  // สร้างอาร์เรย์ขนาด 5 ('b', 'l', 'u', 'e', '\0')
     ```
  2. **Pointer to Character:**  
     ```cpp
     char *colorPtr = "blue";  // สร้าง pointer ไปยังตัว 'b'
     ```
  3. **อีกวิธีในการกำหนดค่า String ด้วย Character Array:**  
     ```cpp
     char color[] = {'b', 'l', 'u', 'e', '\0'};
     ```

---

#### **4. C++ String Class (`string`)**
- ใช้ `#include <string>` เพื่อใช้ **C++ String**
- การกำหนดค่า:
  ```cpp
  string color = "blue";
  ```
- **แปลง C++ String เป็น C-String**
  ```cpp
  string cppStr = "Hello";
  const char *cStr = cppStr.c_str();
  ```
- **แปลง C-String เป็น C++ String**
  ```cpp
  char cStr[] = "Hello";
  string cppStr = cStr;
  ```

---

#### **5. ฟังก์ชันจัดการ String**
| ฟังก์ชัน  | C Style | C++ Style |
|------------|------------|------------|
| **วัดความยาว** | `strlen(s)` | `s.size()` |
| **คัดลอก String** | `strcpy(s1, s2)` | `s1 = s2;` |
| **ต่อ String** | `strcat(s1, s2)` | `s1 + s2;` |
| **เปรียบเทียบ String** | `strcmp(s1, s2)` | `s1.compare(s2);` |

เพิ่มเติม:
- **เข้าถึงตัวอักษรใน String**
  - C-Style: `s[idx]`
  - C++-Style: `s.at(idx)`

- **ค้นหาตัวอักษร**
  - C-Style: `strpbrk(s1, s2)`
  - C++-Style: `s1.find_first_of(s2)`

- **ค้นหาชุดข้อความ**
  - C-Style: `strstr(s1, s2)`
  - C++-Style: `s1.find(s2)`

- **ตัด String**
  - `s1.substr(idx, length)`

- **แทรกข้อความ**
  - `s1.insert(idx, s2)`

- **ลบข้อความ**
  - `s.erase(idx, length)`

---

#### **6. sscanf()**
- ใช้ในการอ่านค่าจาก String แล้วแปลงเป็นตัวเลข เช่น
  ```cpp
  sscanf("590610999", "%d", &num);  // อ่านเป็นจำนวนเต็ม
  sscanf("29.7", "%f", &num);       // อ่านเป็นจำนวนทศนิยม
  sscanf("KarnInwZaa = 29.7 = A+", "%s %f %s", name, &score, grade);
  ```

---

#### **7. printf()**
- ใช้พิมพ์ค่าที่จัดรูปแบบ เช่น
  ```cpp
  printf("[261102] Kasemsit InWJrimJirm:\n-> score = 69, 99, 96, and 66\n-> grade = 3.70");
  ```

---

### **สรุปโดยรวม**
- **C-Style String** ใช้ `char []` และต้องปิดท้ายด้วย `'\0'`
- **C++ String Class** มี `#include <string>` และใช้ `string` เป็นตัวแปร
- **มีฟังก์ชันช่วยในการจัดการ String** เช่น คัดลอก (`strcpy`), ต่อ (`strcat`), ค้นหา (`find`), ตัด (`substr`), แทรก (`insert`), และลบ (`erase`)
- **`sscanf()` และ `printf()`** ช่วยแปลงและแสดงผลข้อมูล String

---

### **ข้อสังเกต**
- การใช้ `string` ของ C++ นั้น **ปลอดภัยกว่าและใช้งานง่ายกว่า** C-Style String (`char[]`)
- การใช้ฟังก์ชัน `sscanf()` **ช่วยให้อ่านค่าและแปลงข้อมูลจาก String ได้สะดวกขึ้น**
- ควรใช้ `std::string` หากเขียนโปรแกรมด้วย C++ เพื่อหลีกเลี่ยงปัญหาหน่วยความจำจาก C-Style String (`char *`)

---

**✅ สรุปเข้าใจง่าย ครอบคลุม ถูกต้อง และครบถ้วน!** 🚀*/