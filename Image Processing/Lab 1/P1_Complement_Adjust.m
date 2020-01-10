% Program 1: Program to study the image processing concept.

I=imread('image.jpg');
J=imcomplement(I);
figure, imshow(I), title('Original Image');
figure, imshow(J), title ('Complemented Image');
K=imadjust(I,[0;0.4],[0.5;1]);
figure, imshow(K),title('Adjusted Image');