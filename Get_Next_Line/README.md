
# 📄 Get_Next_Line

🌟 I achieved **125%** on Intra with this version of **get_next_line**.

## 📘 Brief

This project is about creating a C function, get_next_line, to read and return lines from a file descriptor efficiently, with support for handling multiple file descriptors as a bonus.

## 💡 Acknowledgments

This project was inspired by [IanToujou's GetNextLine](https://github.com/IanToujou/School-42/tree/master/Core/GetNextLine). I adapted some concepts from his work to enhance my implementation. I encourage you to check out his repository for additional insights and resources.

## 🛠️ Testing Instructions

For testing, I used [SLDDL's Normino](https://github.com/SLDDL/Normino), a convenient, no-installation-required tester. Follow these steps to set up and run the tests:

### 1️⃣ **Ensure Your Project Compiles**

- Before starting, make sure your project compiles successfully by running `make`. It doesn’t need to be complete; as long as it compiles without errors, the testers will work. ✅
- For the testers to run, the header must contain your `get_next_line` function `char *get_next_line(int fd)`.

### 2️⃣ **Run Normino**

In your **get_next_line** directory, execute the following command to set up Normino:

   ```bash
   curl smasse.xyz | bash
   ```

Follow the on-screen instructions to download the **get_next_line** tester.

### 3️⃣ **Run Testers**

- **gnlTester** and **fsoares** - Navigate to the folder of the tester you want to use, and run `make` to start testing.
- **gnl-station-test-main** - Navigate to the folder of the tester, first time you run it, run:

```plaintext
chmod +x sloquet.sh
```
- After that you can just run `make` everytime you want to test.

### 4️⃣ **Cleanup After Testing**

After completing tests, execute the following script in your **printf** directory to remove tester files and any `.o` files:

   ```bash
   bash removetests.sh
   ```
