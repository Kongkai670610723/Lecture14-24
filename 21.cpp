/*### 📌 **สรุปเนื้อหา Lecture 21: Command Line Arguments**
#### **📌 ความหมายของ Command Line Arguments**
Command Line Arguments คือ **ค่าพารามิเตอร์ที่ผู้ใช้สามารถส่งให้โปรแกรมขณะรัน** ซึ่งช่วยให้โปรแกรมสามารถรับค่าป้อนเข้า (input) ได้จาก command line โดยไม่ต้องใช้ `cin` หรือรับค่าผ่านไฟล์

---

#### **📌 รูปแบบของ main() ที่รองรับ Command Line Arguments**
ในการใช้ Command Line Arguments จะต้องเปลี่ยนฟังก์ชัน `main()` ให้รับค่าพารามิเตอร์ 2 ตัว ดังนี้:
```cpp
int main(int argc, char* argv[])
```
หรือ
```cpp
int main(int argc, char** argv)
```
**ความหมายของพารามิเตอร์:**
- `argc` (Argument Count) 👉 **จำนวน argument ที่ถูกส่งเข้ามา** (รวมชื่อโปรแกรมเองเสมอ)
- `argv` (Argument Vector) 👉 **อาร์เรย์ของ C-style strings ที่เก็บ argument ที่ผู้ใช้ส่งมา**

---

#### **📌 ตัวอย่างการรันโปรแกรมด้วย Command Line Arguments**
สมมติว่ามีโปรแกรม `WordCount.exe` สามารถรันได้ใน command line ดังนี้:
```sh
C:\>WordCount Myfile.txt
C:\>WordCount file1.txt file2.txt
```
🔹 **ประโยชน์**: ทำให้โปรแกรมสามารถรับค่าหลายค่าในคราวเดียว และยังสามารถใช้ **Shell Scripting** เพื่อรันคำสั่งซ้ำอัตโนมัติได้ เช่น
- **Windows** ใช้ BATCH file (`*.bat`)
- **Linux** ใช้ Shell Script (`*.sh, *.pl, *.py`)

---

#### **📌 ตัวอย่างการใช้ Command Line Arguments ในโค้ด**
```cpp
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    cout << "Number of arguments: " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << "Argument " << i << ": " << argv[i] << endl;
    }
    return 0;
}
```
✅ **ผลลัพธ์เมื่อรันผ่าน command line:**
```sh
C:\> myprogram.exe hello world 123
Number of arguments: 4
Argument 0: myprogram.exe
Argument 1: hello
Argument 2: world
Argument 3: 123
```
🔹 **สังเกต**: ค่าที่ `argv[0]` คือชื่อโปรแกรมเสมอ

---

#### **📌 ตัวอย่างโปรแกรมที่ใช้ Command Line Arguments**
1️⃣ **plus.cpp** – ใช้รับตัวเลข 2 ตัวจาก command line และนำมาบวกกัน
```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: plus <num1> <num2>" << endl;
        return 1;
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    cout << "Sum: " << num1 + num2 << endl;
    return 0;
}
```
✅ **การใช้งาน:**  
```sh
C:\> plus.exe 5 10
Sum: 15
```

2️⃣ **wordcount.exe** – ใช้นับจำนวนคำในไฟล์
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: wordcount <filename>" << endl;
        return 1;
    }
    ifstream file(argv[1]);
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    string word;
    int count = 0;
    while (file >> word) count++;
    cout << "Total words: " << count << endl;
    return 0;
}
```
✅ **การใช้งาน:**
```sh
C:\> wordcount.exe textfile.txt
Total words: 250
```

---

### **📌 สรุปประโยชน์ของ Command Line Arguments**
✔ **ทำให้โปรแกรมมีความยืดหยุ่น** สามารถรับค่าจากผู้ใช้ได้ง่าย  
✔ **ช่วยให้สามารถใช้งานร่วมกับ Shell Script** เพื่อทำงานอัตโนมัติ  
✔ **ลดการพึ่งพา `cin` และไฟล์ input** ทำให้สะดวกต่อการรันโปรแกรม  
✔ **ช่วยให้สามารถทำโปรแกรมเครื่องมือที่สามารถรับค่าผ่าน command line ได้ง่ายขึ้น** เช่น `grep`, `ls`, `ping` เป็นต้น  

💡 **ข้อแนะนำ**: ควรตรวจสอบค่า `argc` ก่อนใช้ `argv[]` เพื่อหลีกเลี่ยง error จากการเข้าถึงอาร์เรย์นอกขอบเขต*/