% Program 1 : Image Segmentation

im=imread('number_plate.jpg');
im1=rgb2gray(im);
% Median filtering the image to remove noise
im1=medfilt2(im1,[3 3]);
% Finding edges
BW = edge(im1,'sobel');  
[imx,imy]=size(BW);
msk=[0 0 0 0 0;
     0 1 1 1 0;
     0 1 1 1 0;
     0 1 1 1 0;
     0 0 0 0 0;];
% Smoothing  image to reduce the number of connected components
B=conv2(double(BW),double(msk));
% Calculating connected components
L = bwlabel(B,8); 
mx=max(max(L));
[r,c] = find(L==17);  
rc = [r c];
[sx, sy]=size(rc);
n1=zeros(imx,imy); 
for i=1:sx
    x1=rc(i,1);
    y1=rc(i,2);
    n1(x1,y1)=255;
end % Storing the extracted image in an array
% figure,imshow(im),title('Original Image');
figure,imshow(im1),title('Image in Grayscale');
figure,imshow(B),title('Segmented Image');
figure,imshow(n1,[]),title('In array');