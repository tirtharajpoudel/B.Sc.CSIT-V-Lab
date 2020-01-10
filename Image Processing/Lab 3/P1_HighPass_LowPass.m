% Program 1: High pass and low pass filter

RGB=imread('image.jpg');
I=rgb2gray(RGB); % Convert the image to grayscale image
A=fft2(double(I)); % Compute the FFT of the grey image
A1=fftshift(A); % Frequency scaling

% Gaussian Filter Response Calculation
[M,N]=size(A); % Image size
R=10; % Filter size parameter
X=0:N-1;
Y=0:M-1;
[X,Y]=meshgrid(X,Y);
Cx=0.5*N;
Cy=0.5*M;
Lo=exp(-((X-Cx).^2+(Y-Cy).^2)./(2*R).^2);
Hi=1-Lo; % High pass filter=1-low pass filter
J=A1.*Lo;
J1=ifftshift(J);
B1=ifft2(J1);
K=A1.*Hi;
K1=ifftshift(K);
B2=ifft2(K1);

% Visualizing the results
figure(1)
imshow(I);colormap gray
title('Original Image','fontsize',14)
figure(2)
imshow(abs(A1),[-12 300000]),colormap gray
title('FFT of original image', 'fontsize',14)
figure(3)
imshow(abs(B1),[12 290]),colormap gray
title('Low pass filtered image','fontsize',14)
figure(4)
imshow(abs(B2),[12 290]),colormap gray
title('High pass filtered image','fontsize',14)
