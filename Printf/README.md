
# 🖨️ Printf

I achieved **125%** with this version of **Printf (Printf_With_Bonus)**! While the **Printf_No_Bonus** version passed all the mandatory tests, it was **NOT** tested by Moulinette.

## 💡 Acknowledgments

This project was inspired by [IanToujou's PrintF](https://github.com/IanToujou/School-42/tree/master/Core/PrintF). I adapted some concepts from his work to enhance my implementation. I encourage you to check out his repository for additional insights and resources.

## 🛠️ Testing Instructions

For testing, I used [SLDDL's Normino](https://github.com/SLDDL/Normino), a convenient, no-installation-required tester. Follow these steps to set up and run the tests:

### 1️⃣ **Ensure Your Project Compiles**

   - Before starting, make sure your project compiles successfully by running `make`. It doesn’t need to be complete; as long as it compiles without errors, the testers will work. ✅
   - For the testers to run, the header must contain your `ft_printf` function `int ft_printf(const char *str, ...)`.

### 2️⃣ **Run Normino**

   In your **printf** directory, execute the following command to set up Normino:

   ```bash
   curl smasse.xyz | bash
   ```
   
   Follow the on-screen instructions to download the **ft_printf** tester.

### 3️⃣ **Run Testers**

   Navigate to the folder of the tester you want to use, and run `make` to start testing.

   ⚠️ You may need to run make on your project to be able to run the FasterPrintfTester.

### 4️⃣ **Cleanup After Testing**

   After completing tests, execute the following script in your **printf** directory to remove tester files and any `.o` files:

   ```bash
   bash removetests.sh
   ```

