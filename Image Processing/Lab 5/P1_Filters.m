% Program 1 : Different Filters
% Laplacian filter
newImg = imread('image.jpg');
figure(1);
imshow(newImg),title('Original Image');
H=fspecial('laplacian');
blurred= imfilter(newImg,H); %Apply Laplacian Filter
figure(2),imshow(blurred);
title('Edge Detected Image')

% Mean filter
im=imread('image.jpg');
G=imnoise(im,'Gaussian',0.0005,0.0019);
figure,
imshow(G),title('Image with Gaussian noise');
figure;
h=fspecial('average',3);
F=imfilter(G,h);
imshow(F),title('Gaussian Noise Removed')

% Geometric filter
[a,map]=imread('image.jpg');
b=im2double(a);
w=fspecial('Gaussian',[3,3]);
geom=exp(imfilter(log(b),ones(3,3),'replicate')).^(1/3/3);
fname=imfilter(b,w,'replicate');
figure,imshow(fname),title('Geometric Mean Filter');

% Harmonic filter
Im=imread('image.jpg');
Im=double(Im);
S_=size(Im);
Mask=7;
for i=1:S_(1)
    j=1;
    while(j<S_(2)-Mask)
        T(1:Mask)=Im(i,j:j+(Mask-1));
        Data=harmmean(T);
        Im(i,j+1)=Data;
        j=j+1;
    end;
end;
figure(6),imshow(uint8(Im)),title('Harmonic Mean Filter');