% Program 2 : Morphological operations : Erosions & Dilation

f=imread('image.jpg');
B=[0 1 1;1 1 1;0 1 0];
f1=imdilate(f,B);
se=strel('disk',10);
f2=imerode(f,se);
figure,imshow(f)
title('Original Image');
figure,imshow(f1)
title('Dilated Image');
figure,imshow(f2)
title('Eroded Image');
