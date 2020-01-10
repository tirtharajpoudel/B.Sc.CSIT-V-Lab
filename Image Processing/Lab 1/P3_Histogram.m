% Program 3: Program to obtain the histogram.

I=imread('image.jpg');
J=rgb2gray(I);
figure,imshow(J);
title('Grayscale');
figure
imhist(J);
title('Histogram');