#!/bin/bash
rm -r "42-philosophers-tester/"
rm -r "Tester_philosophers/"
make fclean >/dev/null 2>&1 || true
rm -r "$0"
