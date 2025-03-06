/*### **สรุปเนื้อหาจากสไลด์ Lecture 16: Pointers II**

#### **หัวข้อหลัก**
- Pointer to Arrays
- Pointer Arithmetic
- Pointer Comparison
- Pointer Dereferencing
- Arrays and Pointer Names
- Pointers to 2D Arrays
- Arrays of Pointers
- Example: Destiny Draw

---

### **1. Pointer to Arrays**
- ชื่อตัวแปร Array ถือว่าเป็น Pointer ไปยังตำแหน่งแรกของ Array โดยอัตโนมัติ
- `&x` คืนค่าเป็น `int (*) [3]` (pointer to array)
- `&x[0]` คืนค่าเป็น `int *` (pointer to element)

#### **ตัวอย่าง**
```cpp
int x[] = {1,2,3};
int *a = x;  // ชี้ไปยัง x[0]
int *b = &x[0];  // ชี้ไปยัง x[0]
int (*c)[3] = &x;  // ชี้ไปยังทั้ง array
```
---

### **2. Pointer Arithmetic**
- การเพิ่มค่า Pointer ทำให้ตำแหน่งเปลี่ยนไปตามขนาดของประเภทข้อมูล
- ตัวอย่าง:
    - `p+1` ขยับไปข้างหน้าตามขนาดของชนิดข้อมูล
    - `p2 - p1` คำนวณความต่างของตำแหน่งหน่วยความจำ

#### **ตัวอย่าง**
```cpp
int x = 55;
double y = 55.55;
int *p = &x;
double *q = &y;

cout << p+1;  // เพิ่มขึ้น 4 bytes (int)
cout << q+1;  // เพิ่มขึ้น 8 bytes (double)
```

---

### **3. Pointer Comparison**
- เปรียบเทียบ Pointer โดยใช้ตัวดำเนินการ `<, >, ==`
- ต้องเปรียบเทียบเฉพาะ Pointer ที่ชี้ไปยัง Array เดียวกัน

#### **ตัวอย่าง**
```cpp
int a[3] = {1,2,3};
int *p1 = &a[0], *p2 = &a[2];

if (p1 < p2) {
    cout << "p1 ชี้ไปตำแหน่งที่น้อยกว่า p2";
}
```
---

### **4. Pointer Dereferencing**
- ใช้ `*` เพื่อเข้าถึงค่าที่ Pointer ชี้ไป
- `*(p+1)` เทียบเท่ากับ `x[1]`

#### **ตัวอย่าง**
```cpp
int x[] = {10, 20, 30};
int *p = x;
cout << *p;  // 10
cout << *(p+1);  // 20
```
---

### **5. Arrays and Pointer Names**
- ใช้ Pointer ในการเข้าถึงค่าของ Array โดยสามารถใช้ `*(ptr + index)` แทน `array[index]`
- Array สามารถถูกใช้เป็น Pointer ได้โดยตรง

#### **ตัวอย่าง**
```cpp
int arr[5] = {10, 20, 30, 40, 50};
int *ptr = arr;

cout << *(ptr + 2);  // เทียบเท่า arr[2]
```
---

### **6. Pointers to 2D Arrays**
- การใช้ Pointer กับ 2D Arrays จะมีลักษณะพิเศษ โดยต้องใช้ `int (*) [N]` แทน `int *`

#### **ตัวอย่าง**
```cpp
int score[2][3] = {{92,85,75},{88,79,54}};
int (*sPtr)[3] = score; // ชี้ไปยังแถวแรกของ array

cout << **sPtr;  // 92
cout << *(*(sPtr+1)+2);  // 54
```
---

### **7. Arrays of Pointers**
- Pointer Array (`int *arr[3]`) ต่างจาก Array Pointer (`int (*arr)[3]`)

#### **ตัวอย่าง**
```cpp
int x[] = {1,2,3};
int *ptrArray[3]; // Array ที่เก็บ Pointer
ptrArray[0] = &x[0];
```
---

### **8. Example: Destiny Draw**
- ใช้ Pointer กับการ์ดเกมแบบ 2D Array
- ใช้ Pointer arithmetic เพื่อเลื่อนตำแหน่งของการ์ดที่ถูกจั่ว

---

### **สรุป**
- Pointer และ Array มีความสัมพันธ์กันโดยตรง
- การใช้ Pointer Arithmetic ช่วยให้จัดการข้อมูลได้อย่างมีประสิทธิภาพ
- Pointer สามารถใช้กับ Array 1D และ 2D ได้ แต่ต้องใช้ Syntax ที่ถูกต้อง
- การเปรียบเทียบ Pointer และ Dereferencing ควรทำอย่างระมัดระวัง

---

🔥 **ถัดไปต้องการให้สรุปสไลด์ถัดไปหรือไม่?***/