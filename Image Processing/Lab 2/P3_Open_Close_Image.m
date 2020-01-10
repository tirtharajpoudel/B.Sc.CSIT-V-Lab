% Program 3: Opening and closing of image

f=imread('image.jpg');
se=strel('square',20);
fo=imopen(f,se);
fc=imclose(f,se);
foc=imclose(fo,se);
figure
subplot(1,4,1),imshow(fo),title('Opening');
subplot(1,4,2),imshow(fc),title('Closing');
subplot(1,4,3),imshow(foc),title('Closing Second');
subplot(1,4,4),imshow(f),title('Original');