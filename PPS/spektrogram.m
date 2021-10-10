% skrypt generuje spektrogramy sygnalu modelowego
% w postaci szumu bialego i sygnalu chirp oraz sygnalu
% mowy

% generacja sygnalu modelowego
N = 5000;
fp = 2000;
t = 0:1/fp:(N-1)/fp;
x = chirp (t, 100, 2.5, 900, 'q');

% narysowanie wykresow czasowych
subplot(221);
plot(t,x);
xlabel('czas [s]');
ylabel('x(n)');

% generacja spektrogramow
subplot (222);
spectrogram (x, 512, 256, 512, fp);
%specgram(x,128,120,128,fp);

set (gcf,'Position',[50 50 1200 700]);