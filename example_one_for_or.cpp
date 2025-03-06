/*นี่คือตัวอย่างโปรแกรม **10 โปรแกรม** ใน **C++** ที่ครอบคลุมเนื้อหาทั้งหมดตั้งแต่สไลด์ที่ 14 ถึงสไลด์ที่ 24 แต่ละโปรแกรมมีคำอธิบายที่ชัดเจนเข้าใจง่าย และ **3 โปรแกรมสุดท้ายเป็นโค้ดใหญ่ๆ** ที่ซับซ้อนขึ้น 🚀

---

### 🟢 **1. โปรแกรมแสดงตัวเลขเฉพาะ (Prime Numbers - Loops & Conditionals)**
**📌 หัวข้อที่เกี่ยวข้อง:** Loops, Conditional Statements

```cpp
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "กรอกตัวเลขที่ต้องการตรวจสอบ: ";
    cin >> n;

    if (isPrime(n)) {
        cout << n << " เป็นจำนวนเฉพาะ\n";
    } else {
        cout << n << " ไม่ใช่จำนวนเฉพาะ\n";
    }

    return 0;
}
```

---

### 🟢 **2. โปรแกรมจัดการข้อมูลนักศึกษา (Arrays & Structs)**
**📌 หัวข้อที่เกี่ยวข้อง:** Arrays, Structs

```cpp
#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

int main() {
    Student students[3];

    for (int i = 0; i < 3; i++) {
        cout << "กรอกชื่อ: ";
        cin >> students[i].name;
        cout << "กรอกอายุ: ";
        cin >> students[i].age;
        cout << "กรอกเกรดเฉลี่ย: ";
        cin >> students[i].gpa;
    }

    cout << "\nข้อมูลนักศึกษา:\n";
    for (int i = 0; i < 3; i++) {
        cout << "ชื่อ: " << students[i].name
             << ", อายุ: " << students[i].age
             << ", GPA: " << students[i].gpa << endl;
    }

    return 0;
}
```

---

### 🟢 **3. โปรแกรมคำนวณหาผลรวมของตัวเลขในอาเรย์ (Array & Loop)**
**📌 หัวข้อที่เกี่ยวข้อง:** Arrays, Loops

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5], sum = 0;
    
    for (int i = 0; i < 5; i++) {
        cout << "กรอกตัวเลขที่ " << i + 1 << ": ";
        cin >> numbers[i];
        sum += numbers[i];
    }

    cout << "ผลรวมของตัวเลขทั้งหมดคือ: " << sum << endl;
    return 0;
}
```

---

### 🟢 **4. โปรแกรมตรวจสอบเลขคู่-คี่ และหาผลรวม (Conditionals & Loops)**
**📌 หัวข้อที่เกี่ยวข้อง:** Conditionals, Loops

```cpp
#include <iostream>
using namespace std;

int main() {
    int num, evenSum = 0, oddSum = 0;

    for (int i = 0; i < 5; i++) {
        cout << "กรอกตัวเลข: ";
        cin >> num;

        if (num % 2 == 0) evenSum += num;
        else oddSum += num;
    }

    cout << "ผลรวมของเลขคู่: " << evenSum << endl;
    cout << "ผลรวมของเลขคี่: " << oddSum << endl;

    return 0;
}
```

---

### 🟢 **5. โปรแกรมคำนวณค่าดัชนีมวลกาย (BMI) (Functions & Conditionals)**
**📌 หัวข้อที่เกี่ยวข้อง:** Functions, Conditional Statements

```cpp
#include <iostream>
using namespace std;

double calculateBMI(double weight, double height) {
    return weight / (height * height);
}

int main() {
    double weight, height;
    cout << "กรอกน้ำหนัก (kg): ";
    cin >> weight;
    cout << "กรอกส่วนสูง (m): ";
    cin >> height;

    double bmi = calculateBMI(weight, height);
    cout << "ค่า BMI ของคุณคือ: " << bmi << endl;

    return 0;
}
```

---

### 🟢 **6. โปรแกรมเก็บข้อมูลลูกค้าในร้าน (Vectors & Loops)**
**📌 หัวข้อที่เกี่ยวข้อง:** Vectors, Loops

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> customers;
    string name;

    for (int i = 0; i < 3; i++) {
        cout << "กรอกชื่อลูกค้า: ";
        cin >> name;
        customers.push_back(name);
    }

    cout << "\nรายชื่อลูกค้าทั้งหมด:\n";
    for (string c : customers) {
        cout << "- " << c << endl;
    }

    return 0;
}
```

---

## 🔥 **โค้ดใหญ่ 3 โปรแกรมสุดท้าย**

### 🟠 **7. ระบบจัดการสินค้าในร้านค้า (Structs & Vectors)**
```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Product {
    string name;
    double price;
};

int main() {
    vector<Product> products;
    int choice;

    do {
        cout << "\n1. เพิ่มสินค้า\n2. แสดงสินค้า\n3. ออกจากโปรแกรม\nเลือก: ";
        cin >> choice;
        
        if (choice == 1) {
            Product p;
            cout << "ชื่อสินค้า: ";
            cin >> p.name;
            cout << "ราคาสินค้า: ";
            cin >> p.price;
            products.push_back(p);
        } else if (choice == 2) {
            for (size_t i = 0; i < products.size(); i++) {
                cout << i + 1 << ". " << products[i].name << " - " << products[i].price << " บาท\n";
            }
        }

    } while (choice != 3);

    return 0;
}
```

---

### 🟠 **8. โปรแกรมอ่าน-เขียนไฟล์ข้อมูลนักศึกษา (File Handling)**
```cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int score;
};

int main() {
    ofstream file("students.txt");
    if (!file) {
        cout << "ไม่สามารถเปิดไฟล์ได้\n";
        return 1;
    }

    int n;
    cout << "กรอกจำนวนข้อมูลนักศึกษา: ";
    cin >> n;
    Student students[n];

    for (int i = 0; i < n; i++) {
        cout << "ชื่อนักเรียน: ";
        cin >> students[i].name;
        cout << "คะแนน: ";
        cin >> students[i].score;
        file << students[i].name << " " << students[i].score << "\n";
    }
    file.close();

    ifstream inputFile("students.txt");
    string name;
    int score;
    while (inputFile >> name >> score) {
        cout << "ชื่อ: " << name << " | คะแนน: " << score << "\n";
    }
    inputFile.close();

    return 0;
}
```

---

### 🟠 **9. โปรแกรมเชื่อมต่อโครงสร้างข้อมูลแบบลิงค์ลิสต์ (Linked List)**
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    
    cout << "Linked List:\n";
    display(head);

    return 0;
}
```

---

## **🔥 สรุป**
**โปรแกรมทั้งหมดนี้ครอบคลุมเนื้อหาหลักใน C++** ได้แก่  
✅ Loops & Conditionals  
✅ Arrays & Structs  
✅ Functions & Vectors  
✅ File Handling  
✅ Linked List  

สามารถนำไปทดสอบและพัฒนาเพิ่มเติมใน **VS Code** 🚀*/