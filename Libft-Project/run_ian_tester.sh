#!/bin/bash

# URL of the file in the GitHub repository
FILE_URL="https://raw.githubusercontent.com/IanToujou/School-42/refs/heads/master/Test/LibFT/run-test.sh"

# Temp file
TEMP_FILE="ian_tester.sh"

# Download the file
curl -o "$TEMP_FILE" "$FILE_URL"

# Make the downloaded file executable
chmod +x "$TEMP_FILE"

# Execute the downloaded file
bash "$TEMP_FILE" libft

rm "$TEMP_FILE"
