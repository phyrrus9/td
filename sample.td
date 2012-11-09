This is an example of a sample file. This program does not have the capacity (as it is right now) to do cursor movement. Instead, it can only use the backspace key. This works fine for programming if you make no mistakes. Copy and paste functions work fine as of now.

Usage:
When this program starts (with your file), it will start in edit mode, meaning you are free to use the program to modify your file. To enter command mode, press the escape key.

Commands:
w: will write any changes to file
q: quits the program, discarding any unsaved changes
i: exit command mode and return to edit mode

Note:
This program uses a lot of buffers. Every time you press a key, a new buffer (of current size + 1) is allocated, the old buffer is copied to it, and the new character is appended. The old buffer is then returned to the operating system. SAVE YOUR WORK OFTEN. This program can be told "no more memory for you!" at any point. It will then try to free an unallocated pointer and fail.

This program will resize itself to fit your terminal window ONCE, and only ONCE. So please maximize your terminal window. Thank you.

~phyrrus9