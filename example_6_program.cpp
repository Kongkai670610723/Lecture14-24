/*นี่คือตัวอย่างโปรแกรม 6 โปรแกรมในภาษา C++ ที่ครอบคลุมเนื้อหาทั้งหมดตั้งแต่สไลด์ที่ 14 ถึงสไลด์ที่ 24

---

### 1️⃣ **โปรแกรมคำนวณค่าใช้จ่ายและหารเฉลี่ย (Array & Loop)**
**📌 หัวข้อที่เกี่ยวข้อง:** Arrays, Loops, Functions

```cpp
#include <iostream>
using namespace std;

void calculateExpenses(double expenses[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += expenses[i];
    }
    cout << "ค่าใช้จ่ายทั้งหมด: " << total << " บาท\n";
    cout << "ค่าใช้จ่ายเฉลี่ยต่อคน: " << total / size << " บาท\n";
}

int main() {
    int n;
    cout << "กรุณากรอกจำนวนคน: ";
    cin >> n;
    double expenses[n];

    for (int i = 0; i < n; i++) {
        cout << "กรอกค่าใช้จ่ายของคนที่ " << i + 1 << ": ";
        cin >> expenses[i];
    }

    calculateExpenses(expenses, n);
    return 0;
}
```

---

### 2️⃣ **โปรแกรมเช็คเลขคู่-คี่ และการใช้ฟังก์ชัน (Functions & Conditionals)**
**📌 หัวข้อที่เกี่ยวข้อง:** Functions, Conditional Statements

```cpp
#include <iostream>
using namespace std;

bool isEven(int num) {
    return num % 2 == 0;
}

int main() {
    int number;
    cout << "กรอกตัวเลข: ";
    cin >> number;

    if (isEven(number)) {
        cout << number << " เป็นเลขคู่\n";
    } else {
        cout << number << " เป็นเลขคี่\n";
    }

    return 0;
}
```

---

### 3️⃣ **โปรแกรมคำนวณเงินเดือนและโบนัส (Structures & Loops)**
**📌 หัวข้อที่เกี่ยวข้อง:** Struct, Loops, Conditionals

```cpp
#include <iostream>
using namespace std;

struct Employee {
    string name;
    double salary;
    double bonus;
};

int main() {
    int n;
    cout << "กรอกจำนวนพนักงาน: ";
    cin >> n;
    Employee employees[n];

    for (int i = 0; i < n; i++) {
        cout << "ชื่อพนักงานคนที่ " << i + 1 << ": ";
        cin >> employees[i].name;
        cout << "เงินเดือน: ";
        cin >> employees[i].salary;
        employees[i].bonus = employees[i].salary * 0.1;  // โบนัส 10%
    }

    cout << "\n=== รายละเอียดเงินเดือน ===\n";
    for (int i = 0; i < n; i++) {
        cout << "ชื่อ: " << employees[i].name
             << " | เงินเดือน: " << employees[i].salary
             << " | โบนัส: " << employees[i].bonus << "\n";
    }

    return 0;
}
```

---

### 4️⃣ **โปรแกรมจัดการสินค้าในร้านค้า (Vectors & Menu Selection)**
**📌 หัวข้อที่เกี่ยวข้อง:** Vectors, Loops, Switch Case

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Product {
    string name;
    double price;
};

int main() {
    vector<Product> inventory;
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
            inventory.push_back(p);
        } else if (choice == 2) {
            cout << "\n=== รายการสินค้า ===\n";
            for (size_t i = 0; i < inventory.size(); i++) {
                cout << i + 1 << ". " << inventory[i].name << " - " << inventory[i].price << " บาท\n";
            }
        }
        
    } while (choice != 3);

    return 0;
}
```

---

### 5️⃣ **โปรแกรมอ่าน-เขียนไฟล์ข้อมูลนักเรียน (File Handling)**
**📌 หัวข้อที่เกี่ยวข้อง:** File I/O

```cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string name;
    int score;
};

int main() {
    ofstream file("students.txt");  // สร้างไฟล์
    if (!file) {
        cout << "ไม่สามารถเปิดไฟล์ได้\n";
        return 1;
    }

    int n;
    cout << "กรอกจำนวนข้อมูลนักเรียน: ";
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

    cout << "\nอ่านข้อมูลจากไฟล์:\n";
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

### 6️⃣ **โปรแกรมเชื่อมต่อโครงสร้างข้อมูลแบบลิงค์ลิสต์ (Linked List)**
**📌 หัวข้อที่เกี่ยวข้อง:** Linked List, Dynamic Memory

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
    
    cout << "รายการข้อมูลใน Linked List:\n";
    display(head);

    return 0;
}
```

---

### 🔥 **สรุป**
โปรแกรมทั้ง 6 นี้ครอบคลุมหัวข้อจากสไลด์ที่ 14 ถึง 24 ได้แก่
✅ การใช้ **Arrays & Loops**  
✅ การใช้ **Functions & Conditional Statements**  
✅ การใช้ **Structures & Loops**  
✅ การใช้ **Vectors & Menu Selection**  
✅ การอ่าน-เขียน **File Handling**  
✅ การสร้าง **Linked List (Dynamic Memory)**  

แต่ละโปรแกรมสามารถนำไปใช้ทดสอบและพัฒนาเพิ่มเติมได้ใน **VS Code** พร้อมกับ **g++ compiler** 🚀*/