import ctypes
import sys

def copy_bytes(destination, source, num_bytes):
    """
    Copies a number of bytes from one memory location to another.

    Args:
        destination (ctypes POINTER(ctypes.c_char)): The destination for copies.
        source (str): The source where the information is copied from.
        num_bytes (int): The number of bytes to copy.

    Returns:
        None
    """
    source_bytes = ctypes.create_string_buffer(source.encode(), len(source))
    ctypes.memmove(destination, source_bytes, num_bytes)

def string_length(string):
    """
    Returns the length of a string.

    Args:
        string (str): Input string.

    Returns:
        int: Length of the input string.
    """
    return len(string)

# Use the functions
message = "Hello, World!"
buffer = ctypes.create_string_buffer(string_length(message))

copy_bytes(buffer, message, sys.getsizeof(message))
print(buffer.value.decode())