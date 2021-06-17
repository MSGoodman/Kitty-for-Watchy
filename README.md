
![Kitty Watchy face, featuring Ghost the cat](GhostKittyWatchFace.jpg?raw=true "Title")
# Kitty for Watchy

A watchface for [Watchy](https://watchy.sqfmi.com/) featuring my beloved cat, Ghost. 

Kitty for Watchy was written to be somewhat easy to customize: by editing just a few simple pieces of code you can use either a 12 or 24 hour clock, or swap out Ghost for your own image if desired (although this is not recommended because this picture of my cat is _very good_).

## Customization

### 24-Hour Clock or 12-Hour Clock

By default Kitty for Watchy displays a 12-hour clock with a meridiem indicator (AM or PM). However, if you prefer a 24-hour clock you can change the value of `MILITARY_TIME` in `Ghost.cpp` to `true` and reupload this to your Watchy.

### Substituting your own image

If you'd like to swap out the picture of Ghost for one of your own it is very simple (instructions adapted from the [official Watchy guide](https://watchy.sqfmi.com/docs/create-watchface/)):

1. Crop your image to a 200px square
2. Use [image2cpp](http://javl.github.io/image2cpp/) to convert your image into a byte array
3. Replace the value of `ghostImage` in the file `image.h` with the byte array retrieved from step 2 

You may find that the locations of the text don't quite work with your image. If so, it is also easy to fix this by fiddling with the `OFFSET` `const`s at the top of `Ghost.cpp`.