% Program 2 : Fourier Transformation

I=imread('image.jpg');
I=im2double(I);
%(DFT) get the frequency for the image
FI=fft2(I);
%Shift zero-frequency component to center of img_spectrum
FI_S=abs(fftshift(FI));
I1=ifft2(FI);
I2=real(I1);

subplot(131),imshow(I),title('Original');
subplot(132),imagesc(0.5*log(1+FI_S)),title('Fourier Spectrum'),axis off
subplot(133),imshow(I2),title('Reconstructed')