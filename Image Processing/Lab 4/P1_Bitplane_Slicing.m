% Program 1 : Bit plane Slicing

a=imread('image.jpg');

im=rgb2gray(a);

img=double(im);
bp0=mod(img,2);
bp1=mod(floor(img/2),2);
bp2=mod(floor(img/4),2);
bp3=mod(floor(img/8),2);
bp4=mod(floor(img/16),2);
bp5=mod(floor(img/32),2);
bp6=mod(floor(img/64),2);
bp7=mod(floor(img/128),2);

% Merging all bit planes

bp_all=2*(2*(2*(2*(2*(2*(2*bp7+bp6)+bp5)+bp4)+bp3)+bp2)+bp1)+bp0;

subplot(241);imshow(bp0);title('Bit-Plane 0 : LSB');
subplot(242);imshow(bp1);title('Bit-Plane 1');
subplot(243);imshow(bp2);title('Bit-Plane 2');
subplot(244);imshow(bp3);title('Bit-Plane 3');
subplot(245);imshow(bp4);title('Bit-Plane 4');
subplot(246);imshow(bp5);title('Bit-Plane 5');
subplot(247);imshow(bp6);title('Bit-Plane 6');
subplot(248);imshow(bp7);title('Bit-Plane 7 : MSB');

figure
subplot(121),imshow(uint8(bp_all)),title('Processed');
subplot(122),imshow(im),title('Original')