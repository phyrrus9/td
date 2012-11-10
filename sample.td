This is an example of a sample file. This program does not have the capacity (as it is right now) to do insertions. You may fix simple errors, but it is overtype. Sorry. I will add insert functions a little bit later.

Usage:
When this program starts (with your file), it will start in edit mode, meaning you are free to use the program to modify your file. To enter command mode, press the escape key.

Commands:
ESC: Enter command mode (you will see a : at the bottom of your file)
w: will write any changes to file
q: quits the program, discarding any unsaved changes
i: exit command mode and return to edit mode
a: move position left
d: move position right
e: move position to end of file
b: move position to beginning of file

Note:
This program uses a lot of buffers. Every time you press a key, a new buffer (of current size + 1) is allocated, the old buffer is copied to it, and the new character is appended. The old buffer is then returned to the operating system. SAVE YOUR WORK OFTEN. This program can be told "no more memory for you!" at any point. It will then try to free an unallocated pointer and fail.

This program will resize itself on demand depending on your terminal window. This can not be changed, and I highly reccomend that you do NOT resize your terminal on the fly. Please, just maximize your terminal. Thank you.

~phyrrus9
