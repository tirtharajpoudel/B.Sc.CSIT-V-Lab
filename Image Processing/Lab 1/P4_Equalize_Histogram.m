% Program 4: Program to equalize histogram.

A=imread('image.jpg');
I=rgb2gray(A);
figure
subplot(1,2,1),imshow(I)
subplot(1,2,2),imhist(I,64)
title('Original');
J=histeq(I);
figure
subplot(1,2,1),imshow(J)
subplot(1,2,2),imhist(J,64)
title('Equalized');
[J,T]=histeq(I);
figure
plot((0:255)/255,T);
