% Program 1 : Thinning Image

image=imread('image.jpg');
image1=rgb2gray(image);
figure;imshow(image);title('Original Image');

% Noise Removal
image_denoised=medfilt2(image1);
% Remove corner pixels
image_denoised=image_denoised(2:end-1,2:end-1);
figure;imshow(image_denoised);title('Denoised Image');

% Image Transformation
% Image Transformation by discrete fourier transform
gamma=1;low_in=0;high_in=1;low_out=1;high_out=0;
image_transformed = imadjust(image_denoised,[low_in high_in],[low_out high_out],gamma);
figure;imshow(image_transformed);title('Transformed Image');

% Image Binarization
% Otsu's method for finding global threshold
threshold=graythresh(image_transformed);
image_binarized= im2bw(image_transformed, threshold);
figure;imshow(image_binarized);title('Binarized Image');

% Block Filter
image_thinned=bwmorph(image_binarized,'thin','Inf');
figure;imshow(image_thinned);title('Thinned Image');
