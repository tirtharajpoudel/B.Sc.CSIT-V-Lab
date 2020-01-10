% Program 1: Smoothing or averaging filter in spatial domain

I=imread('image.jpg');
subplot(1,2,1),imshow(I),title('Original Image');
f=ones(3,3)/100;
h=imfilter(I,f,'circular');
subplot(1,2,2),imshow(h),title('Averaged Image');