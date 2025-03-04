#!/bin/bash
rm -r "fsoares/"
rm -r "gnl-station-tester-main/"
rm -r "gnlTester/"
make fclean >/dev/null 2>&1 || true
rm -r "$0"
