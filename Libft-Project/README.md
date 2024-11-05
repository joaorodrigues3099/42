I achieved **125%** with this version of **libft**!

# Libft Tester Instructions

**Important:** This is NOT my tester. This is **IanToujour's** tester. Please check his [GitHub](https://github.com/IanToujou) and give him some support!

### How to Run the Tester

1. **Make a Backup of Your Libft**
- Before proceeding, ensure you create a backup of your existing **libft** to avoid any data loss.

2. **Required Directory Structure**
- Your project directory should have the following structure:

```plaintext
<Directory Where Libft is Located>
├── libft
│   ├── Makefile
│   ├── libft.h
│   └── all .c files
└── run_ian_tester.sh
```

3. **Add this Rule to your Makefile**

```plaintext
so:
$(CC) -nostartfiles -fPIC ${CFLAGS} ${SRCS}
$(CC) -nostartfiles -shared -o libft.so ${OBJS} $(BONUS_OBJS)
```

4. **Set Permissions for the Tester**
- You need to grant execution permissions to the tester script. You can do this by running the following command in your terminal:

```bash
chmod +x run_ian_tester.sh
```

5. **Run the Tester**

```bash
./run_ian_tester.sh
```
