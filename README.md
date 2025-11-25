# Bank System CLI (C++)

A compact, educational command-line bank account demo written in C++.

This project shows a small class hierarchy representing bank accounts and demonstrates
basic operations like creating accounts, checking balances, depositing, and (for derived
types) applying rules such as overdraft or interest.

---

## What this code demonstrates

- Object-oriented design with base and derived classes (`Account`, `savings_account`, `current_account`)
- Encapsulation of account data (owner, balance, PIN)
- Safe user input for a 4-digit PIN during creation
- Simple account operations: deposit, withdraw, display

This small project is intentionally kept simple so you can study and extend it.

---

## Files

- `main.cpp` — the entire program (single-file demo). It includes:
  - `Account` base class with common operations
  - `savings_account` and `current_account` derived classes
  - A short demo `main()` that creates an account, shows balances, and deposits money

---

## Behavior notes / Important details

- When creating an `Account`, the program **requires** you to enter a numeric 4-digit PIN.
  The PIN must be between `1000` and `9999`. The program will keep asking until a valid PIN is entered.
- A random account number (prefixed by `ACC`) is assigned automatically.
- The `generatePIN()` helper used earlier has been removed — the PIN is provided by the user.

---

## Build & Run (Linux)

1. Build with g++ (debug build):

```bash
g++ -g main.cpp -o main
```

2. Run the program:

```bash
./main
```

