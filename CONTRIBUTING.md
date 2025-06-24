
## shmake Development Guide

This document defines standards, architecture, and best practices to ensure clean, modular, and maintainable contributions to shmake.


## Architecture and General Standards

### Single Responsibility Principle (SRP)

Each function must do **only one thing**. Multifunctional functions complicate maintenance and testing. Follow SRP to improve scalability and readability.

### Return Convention

- Return `1` for success.  
- Return `-1` for error/failure.  
- **Do not** use `0` for success (C standard).  
This ensures clear and consistent result detection throughout the code.

### Naming

- Use **snake_case** for function names.  
- Source files must have **descriptive names** reflecting their purpose.

---

## System Separation

shmake is organized into independent systems without cross-dependencies:

- **File System:**  
  Handles file operations only (open, read, close).  
  Does not process content.

- **Interpretation System:**  
  Works exclusively with string buffers, never with files directly.  
  Receives strings ready for parsing and processing.

This separation reduces coupling and simplifies unit testing.

---

## Data Flow

1. The **File System** reads file contents into string buffers.  
2. Buffers are passed to the **Interpretation System** for parsing and output generation.  
3. The **Interpretation System** processes only strings, ignoring physical files.

---



## Contribution Rules and Workflow

### Repository Setup

Clone the main repository:

```bash
git clone https://github.com/yourusername/shmake.git
cd shmake
git remote add shmake_contrib https://github.com/otheruser/shmake_contrib.git
