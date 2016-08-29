# First try

OF basic structure.
1. `setup()` runs only once.
2. `update()` & `draw()` runs until the program is finished externally, e.g., by you pressing the ESC in the keyboard.

This concept need to be understood. Mobile (iOS, Android) applicatins have all the same basic structure.

Pixel loading
- `ofImage::setFromPixels(uchar*, int width, int height, format)`
- indexing the RGB pixel at (x,y)
- changing the color value
- `ofImage::update()` : don't forget before you try to draw on the OF canvas. Before this call, GPU buffer is not updated, and you won't see any change in the display.
