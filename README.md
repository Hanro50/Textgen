# Textgen
A terrible WIP game engine built for the linux Terminal.

This started out as a challenge to write tron. 
But evolved into just writing this engine as my sanity ran out.

Check for the comments in main() to see where you should ideally put game code.

The wchat_t array in the main() function contains the screen date. 
Updating the characters in that array would essentially write the characters to the screen.
Since the terminal is essentially cleared and redrawn each frame using that array to redraw it ..

