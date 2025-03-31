#!/bin/bash
rm -r "minitalk-Tester/"
make fclean >/dev/null 2>&1 || true
rm -r "$0"
