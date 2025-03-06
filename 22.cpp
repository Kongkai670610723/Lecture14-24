/*### สรุปเนื้อหาสไลด์ **CPE102_22_20250221** (Lecture 22: Classes III - Operator Overloading)

#### **1. Operator Overloading คืออะไร**
- การใช้ **operator** กับ object เช่น:
  - `object2 = object1.add(object2);` (ใช้ฟังก์ชัน)
  - `object2 = object1 + object2;` (ใช้ operator)
- ทำให้โค้ดอ่านง่ายกว่าการเรียกใช้ฟังก์ชันปกติ
- ตัวอย่าง operator ที่ใช้บ่อย:
  - `<<` : Stream insertion, Bitwise left-shift
  - `+`  : บวกค่าตัวเลข หรือ object ต่าง ๆ
  - `&`  : คืนค่าที่อยู่ของ object หรือ Bitwise AND

---

#### **2. การ Overload Operator**
- ใช้ฟังก์ชันใน class เพื่อกำหนดพฤติกรรมของ operator
- ใช้คำว่า `operator` ตามด้วยสัญลักษณ์ เช่น `operator+`
- สามารถใช้ operator กับ user-defined types ได้
- **ไม่สามารถสร้าง operator ใหม่ขึ้นมาเองได้**

---

#### **3. Operator ที่ Overload ได้และไม่ได้**
- **Overload ไม่ได้** เช่น:
  - `.`, `.*`, `::`, `?:`, `sizeof`
- **Overload ได้** เช่น:
  - `+`, `-`, `*`, `/`, `%`, `&`, `|`, `~`, `!`, `=`, `==`, `!=`, `<=`, `>=`, `&&`, `||`, `++`, `--`, `->`, `()`, `new`, `delete`, `<<`, `>>`

---

#### **4. ข้อจำกัดของ Operator Overloading**
- **เปลี่ยนพฤติกรรมของ built-in data types ไม่ได้** (เช่น การเปลี่ยนพฤติกรรมของ `int + int`)
- **เปลี่ยนลำดับ precedence ของ operator ไม่ได้** (ต้องใช้ `()` จัดลำดับการคำนวณเอง)
- **เปลี่ยน associativity ไม่ได้** (เช่น `*` คำนวณจากซ้ายไปขวาอยู่แล้ว)
- **เปลี่ยนจำนวน operand ไม่ได้** (เช่น `&` เป็น unary operator เสมอ)
- **ต้อง Overload ทีละตัว** (`+` ไม่ได้ Overload `+=` ให้อัตโนมัติ)

---

#### **5. การ Overload Operator แบบต่างๆ**
##### **5.1 Overloading ด้วย Member Function**
- สามารถเข้าถึง **private data members** ได้
- `operator+` จะรับแค่ **right operand** เป็นพารามิเตอร์

```cpp
class Circle {
public:
    Circle operator+(const Circle& c) {
        Circle temp;
        temp.radius = this->radius + c.radius;
        return temp;
    }
};
```

---

##### **5.2 Overloading ด้วย Non-Member Function**
- ฟังก์ชันปกติที่ไม่อยู่ใน class (แต่เข้าถึง **public data members** เท่านั้น)

```cpp
Circle operator+(const Circle& c1, const Circle& c2) {
    Circle temp;
    temp.radius = c1.radius + c2.radius;
    return temp;
}
```

---

##### **5.3 Overloading ด้วย Friend Function**
- ใช้ `friend` ให้ฟังก์ชันสามารถเข้าถึง **private data members** ได้
- เหมาะกับ operator ที่ต้องเข้าถึงค่าภายใน object

```cpp
class Circle {
    friend Circle operator+(const Circle& c1, const Circle& c2);
};
```

---

#### **6. Overload Unary Operator (`++` และ `--`)**
- **Prefix (`++A`)** : ดำเนินการก่อนส่งค่า
- **Postfix (`A++`)** : ส่งค่าก่อนดำเนินการ

```cpp
Circle& operator++() {   // Prefix
    ++radius;
    return *this;
}

Circle operator++(int) { // Postfix
    Circle temp = *this;
    ++radius;
    return temp;
}
```

---

#### **7. Overloading `<<` และ `>>`**
- ใช้กับ **cin และ cout**
- ต้องเป็น **friend function** เพราะ `cout` และ `cin` ไม่ได้เป็นสมาชิกของ class

```cpp
ostream& operator<<(ostream& out, const Circle& c) {
    out << "Radius: " << c.radius;
    return out;
}
```

---

#### **8. Commutative Operator**
- ทำให้ `a + b` และ `b + a` ใช้งานได้เหมือนกัน
- ถ้าต้องการให้ `Long int + MyClass` ทำงานได้ ต้องใช้ **non-member function**
  
```cpp
Circle operator+(double num, const Circle& c) {
    Circle temp;
    temp.radius = num + c.radius;
    return temp;
}
```

---

#### **9. ตัวอย่าง: การ Overload Operator สำหรับ Complex Number**
- Overload `+`, `-`, และ `<<`
- ใช้ **constructor** สำหรับรองรับค่าต่าง ๆ
- **Error Handling**: ถ้า `double + ComplexNumber` ไม่มี operator ที่รองรับ จะเกิด error

```cpp
class ComplexNumber {
    double real, imag;
public:
    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}

    ComplexNumber operator+(const ComplexNumber& c) {
        return ComplexNumber(real + c.real, imag + c.imag);
    }

    friend ostream& operator<<(ostream& out, const ComplexNumber& c);
};

ostream& operator<<(ostream& out, const ComplexNumber& c) {
    out << c.real << "+" << c.imag << "*i";
    return out;
}
```

---

### **สรุปสั้นๆ**
1. **Operator Overloading** ช่วยให้โค้ดอ่านง่ายขึ้น เช่น `a + b` แทน `a.add(b)`.
2. ใช้ฟังก์ชัน `operator+` และอื่นๆ ใน **class** เพื่อ overload.
3. **Member function** ใช้กับ operator ที่มี left operand เป็น object ของ class นั้น.
4. **Non-member function** ใช้กับ operator ที่ left operand เป็นค่าประเภทอื่น.
5. **Friend function** ใช้เข้าถึง private data members.
6. Overload `<<` และ `>>` ต้องเป็น **non-member function**.
7. ไม่สามารถเปลี่ยน precedence หรือ associativity ของ operator ได้.
8. ถ้าต้องการ **commutative operation** ต้อง overload function ให้รองรับหลายรูปแบบ.

---

### **ตัวอย่างการใช้งาน**
```cpp
ComplexNumber c1(1, 2), c2(3, 4);
ComplexNumber c3 = c1 + c2; 
cout << c3; // Output: 4+6*i
```

---

### **ประโยชน์ของ Operator Overloading**
✅ ทำให้โค้ด **อ่านง่ายขึ้น**  
✅ ลดการใช้ฟังก์ชันแบบยาวๆ (`a.add(b)` -> `a + b`)  
✅ ใช้งานกับ `cout`, `cin`, และ arithmetic operators ได้  
✅ เพิ่มความสามารถให้กับ user-defined types  

---

### **ข้อควรระวัง**
⚠️ อย่าทำให้ operator ทำงานแตกต่างจากที่ควรเป็น (เช่น `+` ควรเป็นการบวก ไม่ใช่ลบ)  
⚠️ Overload เฉพาะ operator ที่จำเป็น  
⚠️ ต้องแน่ใจว่า operator ที่ overload **เข้าใจง่ายและคาดเดาได้**  

---

### **จบการสรุป** 🎯  
✅ **เข้าใจง่าย**  
✅ **ครอบคลุม**  
✅ **ถูกต้องและชัดเจน***/