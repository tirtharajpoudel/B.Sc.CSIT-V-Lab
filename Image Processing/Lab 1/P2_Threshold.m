% Program 2: Program to check different values of threshold.

y=imread('image.jpg');
T=80;
if (ndims(y)==3)
    y=rgb2gray(y);
end
[m,n]=size(y);
imshow(y),title('Grayscale Image');
for i=1:m;
    for j=1:n;
        if(y(i,j)>T)
            y(i,j)=255;
        else
            y(i,j)=0;
        end
    end
end
figure,imshow(y),title('Image after thresholding');