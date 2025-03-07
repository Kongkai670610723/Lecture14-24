/*### สรุปเนื้อหาสไลด์ 24: Containers (CPE102_24_20250228.pdf)

---

## **1. Containers คืออะไร?**
- **Containers** เป็นออบเจ็กต์ที่ใช้เก็บคอลเลกชันของข้อมูลอื่น ๆ
- ใช้ **class template** ทำให้สามารถรองรับประเภทข้อมูลที่หลากหลาย
- คอนเทนเนอร์ช่วยจัดการ **พื้นที่เก็บข้อมูล** และมีฟังก์ชันในการเข้าถึงข้อมูลผ่าน **iterators**

### **ตัวอย่างของ Containers ใน C++**
- **Dynamic Arrays:** `std::vector`
- **Queues:** `std::queue`
- **Stacks:** `std::stack`
- **Heaps:** `std::priority_queue`
- **Linked Lists:** `std::list`
- **Trees:** `std::set`
- **Associative Arrays:** `std::map`

---

## **2. Array**
- **เป็นโครงสร้างข้อมูลที่ใช้หน่วยความจำแบบต่อเนื่อง (Contiguous Memory)**
- มีขนาด **คงที่** และไม่สามารถเพิ่ม/ลดขนาดได้โดยตรง
- หากต้องการแทรกข้อมูลในอาร์เรย์ที่มีขนาดเต็ม จำเป็นต้องสร้างอาร์เรย์ใหม่ที่มีขนาดใหญ่ขึ้น

> **ข้อจำกัด:** หากต้องการเพิ่มข้อมูลเกินขนาดที่กำหนด ต้องเตรียมอาร์เรย์ที่มีขนาดใหญ่พอ

---

## **3. Dynamic Array (`std::vector`)**
- ใช้ **dynamic allocation** เพื่อให้ขนาดของอาร์เรย์สามารถเปลี่ยนแปลงได้
- ใช้ **หน่วยความจำแบบต่อเนื่อง**
- ไม่สามารถใช้ **initializer list** ได้
- มีฟังก์ชันที่ช่วยให้สามารถ **เพิ่มและลบข้อมูล** ได้สะดวก

> **ข้อดี:** สามารถเพิ่มขนาดได้อัตโนมัติเมื่อมีการเพิ่มข้อมูลใหม่

---

## **4. `std::vector` (Vector Class in C++)**
- เป็นคอนเทนเนอร์แบบลำดับ (Sequence Container) คล้ายอาร์เรย์
- สามารถเข้าถึงข้อมูลได้โดยใช้ **pointer offset**
- ใช้ **dynamic memory allocation** เมื่อมีการเพิ่มข้อมูลใหม่

### **วิธีใช้งาน `std::vector`**
- **เพิ่มข้อมูล**
  ```cpp
  vectorName.push_back(value);  // เพิ่มค่าที่ท้ายเวกเตอร์
  vectorName.insert(position, value); // แทรกค่าที่ตำแหน่งที่กำหนด
  ```
- **ลบข้อมูล**
  ```cpp
  vectorName.pop_back(); // ลบค่าตัวสุดท้าย
  vectorName.erase(position); // ลบค่าที่ตำแหน่งที่กำหนด
  vectorName.clear(); // ลบค่าทั้งหมด
  ```

> **ข้อเสีย:** การขยายขนาดทำให้ต้องสร้างอาร์เรย์ใหม่และคัดลอกข้อมูลเดิม ซึ่งใช้เวลาและหน่วยความจำมากขึ้น

---

## **5. Linked List**
- คอนเทนเนอร์ที่ใช้ **หน่วยความจำแบบไม่ต่อเนื่อง (Non-contiguous Memory)**
- **แต่ละโหนด** เก็บข้อมูลและพอยน์เตอร์ไปยังโหนดถัดไป
- **ไม่สามารถเข้าถึงข้อมูลแบบสุ่ม (Random Access) ได้**
- **โครงสร้างของโหนด**
  ```cpp
  struct Node {
      int data;
      Node* next;
  };
  ```

### **ประเภทของ Linked List**
- **Singly Linked List**: โหนดแต่ละตัวชี้ไปยังโหนดถัดไป
- **Doubly Linked List**: มีพอยน์เตอร์ทั้งไปข้างหน้าและถอยหลัง
- **Circular Linked List**: โหนดสุดท้ายเชื่อมโยงกลับไปที่โหนดแรก

### **การเพิ่มโหนดใหม่**
1. **เพิ่มโหนดที่จุดเริ่มต้น**
2. **เพิ่มโหนดที่ท้ายรายการ**
3. **เพิ่มโหนดระหว่างรายการ**

> **ข้อดี:** การเพิ่ม/ลบข้อมูลทำได้เร็วกว่าอาร์เรย์
>
> **ข้อเสีย:** ใช้หน่วยความจำมากขึ้น เพราะต้องเก็บพอยน์เตอร์เพิ่ม

---

## **6. `std::list`**
- เป็นคอนเทนเนอร์แบบ **Doubly Linked List**
- สามารถ **เพิ่ม/ลบข้อมูลได้เร็ว** กว่า `vector`
- ใช้ **iterator** เพื่อเข้าถึงข้อมูล

### **การใช้งาน `std::list`**
- **เพิ่มข้อมูล**
  ```cpp
  listName.push_back(value);   // เพิ่มค่าที่ท้ายรายการ
  listName.push_front(value);  // เพิ่มค่าที่จุดเริ่มต้น
  listName.insert(position, value);  // แทรกค่าที่ตำแหน่งที่กำหนด
  ```
- **ลบข้อมูล**
  ```cpp
  listName.pop_back();   // ลบค่าตัวสุดท้าย
  listName.pop_front();  // ลบค่าตัวแรก
  listName.erase(position);  // ลบค่าที่ตำแหน่งที่กำหนด
  listName.clear();  // ลบค่าทั้งหมด
  ```

> **ข้อดี:** สามารถเพิ่ม/ลบข้อมูลที่ตำแหน่งใดก็ได้โดยไม่ต้องขยับข้อมูลเหมือน `vector`
>
> **ข้อเสีย:** เข้าถึงข้อมูลแบบสุ่มไม่ได้ (ต้องใช้ iterator)

---

## **7. `std::set`**
- **Set** เป็นคอนเทนเนอร์ที่เก็บ **ค่าไม่ซ้ำกัน** และเรียงลำดับอัตโนมัติ
- **ไม่สามารถแก้ไขค่าใน `set` ได้** แต่สามารถเพิ่ม/ลบค่าได้

### **การใช้งาน `std::set`**
- **เพิ่มข้อมูล**
  ```cpp
  setName.insert(value); // เพิ่มค่า (หากมีค่าเดิมจะไม่เพิ่มซ้ำ)
  ```
- **ลบข้อมูล**
  ```cpp
  setName.erase(value); // ลบค่าที่กำหนด
  setName.clear();  // ลบค่าทั้งหมด
  ```

> **ข้อดี:** ค่าไม่ซ้ำกัน และเรียงลำดับอัตโนมัติ
>
> **ข้อเสีย:** ไม่สามารถเข้าถึงข้อมูลตามตำแหน่งได้ ต้องใช้ iterator

---

## **สรุป**
| Container | ประเภทของข้อมูล | ข้อดี | ข้อเสีย |
|-----------|---------------|-------|--------|
| **Array** | ข้อมูลคงที่ | ใช้หน่วยความจำน้อย | ไม่สามารถเปลี่ยนขนาดได้ |
| **Vector** | ข้อมูลแบบไดนามิก | ขยายขนาดได้อัตโนมัติ | ต้องคัดลอกข้อมูลเมื่อขยาย |
| **Linked List** | ข้อมูลแบบไดนามิก | เพิ่ม/ลบข้อมูลได้ง่าย | ใช้หน่วยความจำมากขึ้น |
| **List (std::list)** | Doubly Linked List | เพิ่ม/ลบข้อมูลได้เร็ว | ไม่สามารถเข้าถึงข้อมูลแบบสุ่ม |
| **Set (std::set)** | ข้อมูลไม่ซ้ำกัน | เรียงลำดับอัตโนมัติ | ไม่สามารถเปลี่ยนค่าของข้อมูลได้ |

---

### **สรุปแนวคิดสำคัญ**
1. **`Array`** ใช้หน่วยความจำต่อเนื่อง แต่ขนาดคงที่
2. **`std::vector`** ใช้ dynamic memory allocation และปรับขนาดได้
3. **`Linked List`** ใช้หน่วยความจำไม่ต่อเนื่อง และสามารถเพิ่ม/ลบข้อมูลได้ง่าย
4. **`std::list`** ดีกว่า `vector` ในการเพิ่ม/ลบข้อมูล แต่เข้าถึงข้อมูลแบบสุ่มไม่ได้
5. **`std::set`** ใช้เก็บข้อมูลไม่ซ้ำกันและเรียงลำดับอัตโนมัติ

---

### **📌 สรุปโดยรวม**
- การเลือกใช้ **Container** ขึ้นอยู่กับลักษณะของข้อมูลและความต้องการของโปรแกรม
- **ถ้าต้องการเข้าถึงข้อมูลเร็ว → `std::vector`**
- **ถ้าต้องการเพิ่ม/ลบข้อมูลบ่อย → `std::list` หรือ `Linked List`**
- **ถ้าต้องการข้อมูลไม่ซ้ำกัน → `std::set`**
- **ถ้าต้องการจัดเก็บแบบ key-value → `std::map`** (ไม่ได้กล่าวถึงในสไลด์นี้)

---
**🌟 หวังว่าสรุปนี้จะช่วยให้เข้าใจเนื้อหาของ Containers ได้ง่ายขึ้น! 😊***/