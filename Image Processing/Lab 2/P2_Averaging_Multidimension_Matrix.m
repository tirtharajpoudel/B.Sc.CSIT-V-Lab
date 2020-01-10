% Program 2: Averaging in multidimensional matrix

I=imread('image.jpg');
subplot(1,3,1),imshow(I),title('Original');
H=fspecial('Average',3);
M=imfilter(I,H,'replicate');
subplot(1,3,2),imshow(M),title('Average 3*3');
H=fspecial('Average',25);
M=imfilter(I,H,'replicate');
subplot(1,3,3),imshow(M),title('Average 5*5')