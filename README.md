## DIFFERENCE BETWEEN A NORMAL VARIABLE AND A POINTER.

### Normal Variable
A normal variable stores the **actual value**.

- **What it stores:** The data value (e.g., integer, float)  
- **Memory access:** Directly using the variable name  
- **Reading value:** Use the variable name  
- **Modifying value:** Assign a new value  

**Example:**

int x = 10;
x = 20;

###  **Pointer**

A pointer stores the address of another variable.

-**What it stores**: Memory address of a variable

-**Memory access**: Indirect, via the pointer

-**Reading value**: Dereference using *

-**Modifying value**: Change the value at the stored address

**Example:**

int x = 10;
int *p = &x;
*p = 20;
## **Variable vs Pointer Declaration and Definition**
### **Variable Declaration and Definition**
**Declaration**: Introduces the variable name and type

**Definition**: Allocates memory and optionally initializes

**Example:**

int a;   // declaration
a = 5;   // definition

### **Pointer Declaration and Definition**
**Declaration**: Specifies the pointer variable

**Definition**: Assigns it the address of another variable

**Operators**:

* → declares a pointer / dereferences it

& → gets the address of a variable

**Example:**

int a = 5;
int *p;   // declaration
p = &a;   // definition

### **Dereferencing a Pointer**
Dereferencing means accessing or modifying the value at the memory address stored in a pointer.

**Example:**

int a = 10;
int *p = &a;

printf("%d", *p); // reads value of a
*p = 25;          // modifies value of a
## **When Pointers Are Preferred**
### **Modifying Variables Inside Functions**
This allows functions to modify the original variable

It is useful for updating values such as balances

**Example:**

void update(int *x) {
    *x = 100;
}
### **Working with Arrays and Strings**
Arrays can be efficiently accessed using pointers

It reduces memory overhead

**Example:**

int arr[3] = {1, 2, 3};
int *p = arr;
### **Dynamic Memory Allocation**
Pointers are required for memory allocated at runtime

Uses malloc() and free()

**Example:**

int *p = (int*)malloc(sizeof(int));
## **Limitations and Risks of Pointers**
-Segmentation faults from invalid memory access

-Dangling pointers after freeing memory

-Memory leaks if not released

-Harder to debug than normal variables

-Accidental data modification

## **Call by Value vs Call by Reference**
### **Call by Value**
Copies the variable into the function

Original variable cannot modified

Is safer for small data

**Example:**

void change(int x) {
    x = 10;
}
### **Call by Reference (Pointer)**
Passes the address of the variable

Original variable can be modified

Is more efficient for large data

**Example:**

void change(int *x) {
    *x = 10;
}
## **Practical Scenarios**
### **When Call by Value is Preferred**
Original data must not change

Small data types

Calculations without side effects

### **When Call by Reference is Preferred**
Function must modify original data

Working with arrays, strings, or structures

Avoid copying large data for efficiency

## **Summary**
Pointers allow indirect memory access, efficient data handling, and call by reference.
They must be used carefully to avoid segmentation faults and memory leaks.

