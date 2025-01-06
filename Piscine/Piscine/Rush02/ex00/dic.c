/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:10:51 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/28 23:28:20 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include  "header.h"

// Function to handle errors by writing to stderr
static void handle_error(const char *msg) {
    write(STDERR_FILENO, msg, strlen(msg));
}

// Function to read the contents of a file into a dynamically allocated buffer
char *read_file(char *filename) {
    int fd;
    ssize_t bytes_read;
    char *buffer;
    size_t buffer_size = 1024;
    size_t total_size = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        write(1, "Failed to open file\n", 10);
        return NULL;
    }

    buffer = (char *)malloc(buffer_size);
    if (!buffer) {
        write(1, "Failed to allocate memory\n", 26);
        close(fd);
        return NULL;
    }

    while ((bytes_read = read(fd, buffer + total_size, buffer_size - total_size)) > 0) {
        total_size += bytes_read;
        if (total_size == buffer_size) {
            // Resize buffer directly within read_file
            size_t new_size = buffer_size * 2;
            char *new_buffer = (char *)realloc(buffer, new_size);
            if (!new_buffer) {
                write(1, "Failed to reallocate memory\n", 28);
                free(buffer);
                close(fd);
                return NULL;
            }
            buffer = new_buffer;
            buffer_size = new_size;
        }
    }

    if (bytes_read < 0) {
        handle_error("Failed to read file\n");
        free(buffer);
        close(fd);
        return NULL;
    }

    buffer[total_size] = '\0';
    close(fd);

    return buffer;
}

// Function to find the value associated with a given key in the contents
char *find_value_by_key(char *contents, char *key) {
    size_t key_len = strlen(key);
    size_t line_start = 0, line_end = 0;

    while (contents[line_end] != '\0') {
        while (contents[line_end] != '\0' && contents[line_end] != '\n') line_end++;

        size_t separator = line_start;
        while (separator < line_end && contents[separator] != ':') separator++;

        if (separator < line_end && separator == line_start + key_len && strncmp(key, contents + line_start, key_len) == 0) {
            size_t value_start = separator + 1;
            size_t value_len = line_end - value_start;

            char *value = (char *)malloc(value_len + 1);
            if (!value) {
                write(1, "Failed to read file\n", 20);
                return NULL;
            }
            strncpy(value, contents + value_start, value_len);
            value[value_len] = '\0';
            return value;
        }

        if (contents[line_end] == '\n') line_end++;
        line_start = line_end;
    }

    return NULL;
}