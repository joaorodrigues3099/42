#!/bin/bash
rm -r "so_long_tester/"
rm -r "So_long-Tester-main/"
make fclean >/dev/null 2>&1 || true
rm -r "$0"
